#include <cctype>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "antlr4-runtime/antlr4-runtime.h"

#include "CoolLexer.h"
#include "CoolParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

namespace fs = std::filesystem;

string cool_token_to_string(CoolLexer *lexer, Token *token)
{
    auto token_type = token->getType();

    switch (token_type)
    {
    case static_cast<size_t>(-1):
        return "EOF";

    case CoolLexer::SEMI:
        return "';'";
    case CoolLexer::OCURLY:
        return "'{'";
    case CoolLexer::CCURLY:
        return "'}'";
    case CoolLexer::OPAREN:
        return "'('";
    case CoolLexer::COMMA:
        return "','";
    case CoolLexer::CPAREN:
        return "')'";
    case CoolLexer::COLON:
        return "':'";
    case CoolLexer::AT:
        return "'@'";
    case CoolLexer::DOT:
        return "'.'";
    case CoolLexer::PLUS:
        return "'+'";
    case CoolLexer::MINUS:
        return "'-'";
    case CoolLexer::STAR:
        return "'*'";
    case CoolLexer::SLASH:
        return "'/'";
    case CoolLexer::TILDE:
        return "'~'";
    case CoolLexer::LT:
        return "'<'";
    case CoolLexer::EQ:
        return "'='";

    case CoolLexer::DARROW:
        return "DARROW";
    case CoolLexer::ASSIGN:
        return "ASSIGN";
    case CoolLexer::LE:
        return "LE";

    case CoolLexer::CLASS:
        return "CLASS";
    case CoolLexer::ELSE:
        return "ELSE";
    case CoolLexer::FI:
        return "FI";
    case CoolLexer::IF:
        return "IF";
    case CoolLexer::IN:
        return "IN";
    case CoolLexer::INHERITS:
        return "INHERITS";
    case CoolLexer::ISVOID:
        return "ISVOID";
    case CoolLexer::LET:
        return "LET";
    case CoolLexer::LOOP:
        return "LOOP";
    case CoolLexer::POOL:
        return "POOL";
    case CoolLexer::THEN:
        return "THEN";
    case CoolLexer::WHILE:
        return "WHILE";
    case CoolLexer::CASE:
        return "CASE";
    case CoolLexer::ESAC:
        return "ESAC";
    case CoolLexer::NEW:
        return "NEW";
    case CoolLexer::OF:
        return "OF";
    case CoolLexer::NOT:
        return "NOT";

    case CoolLexer::BOOL_CONST:
        return "BOOL_CONST";
    case CoolLexer::INT_CONST:
        return "INT_CONST = " + token->getText();
    case CoolLexer::STR_CONST:
        return "STR_CONST";
    case CoolLexer::TYPEID:
        return "TYPEID = " + token->getText();
    case CoolLexer::OBJECTID:
        return "OBJECTID = " + token->getText();
    case CoolLexer::ERROR:
        return "ERROR";

    default:
        return "<Invalid Token>: " + token->toString();
    }
}

class ErrorPrinter : public BaseErrorListener
{
private:
    string file_name_;
    CoolLexer *lexer_;
    bool has_error_ = false;

public:
    ErrorPrinter(const string &file_name, CoolLexer *lexer)
        : file_name_(file_name), lexer_(lexer) {}

    virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol,
                             size_t line, size_t charPositionInLine,
                             const std::string &msg,
                             std::exception_ptr e) override
    {
        has_error_ = true;
        cout << '"' << file_name_ << "\", line " << line
             << ": syntax error at or near "
             << cool_token_to_string(lexer_, offendingSymbol) << endl;
    }

    bool has_error() const { return has_error_; }
};

class TreePrinter
{
private:
    CoolLexer *lexer_;
    string file_name_;

    struct DispatchSuffix
    {
        bool isStatic = false;
        string staticType;
        string methodName;
        CoolParser::Arg_listContext *args = nullptr;
        int line = 0;
    };

    void indent(int n) const
    {
        for (int i = 0; i < n; ++i)
            cout << ' ';
    }

    static string escape_string(const string &s)
    {
        ostringstream out;
        out << '"';
        for (unsigned char c : s)
        {
            switch (c)
            {
            case '\\':
                out << "\\\\";
                break;
            case '\n':
                out << "\\n";
                break;
            case '\t':
                out << "\\t";
                break;
            case '\b':
                out << "\\b";
                break;
            case '\f':
                out << "\\f";
                break;
            case '\"':
                out << "\\\"";
                break;
            default:
                if (isprint(c))
                    out << c;
                else
                {
                    out << '\\';
                    out << oct << setw(3) << setfill('0') << (int)c << dec;
                }
            }
        }
        out << '"';
        return out.str();
    }

    void print_no_expr(int line, int ind)
    {
        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << "_no_expr\n";
        indent(ind);
        cout << ": _no_type\n";
    }

    void printProgram(CoolParser::ProgramContext *ctx)
    {
        int last_line = static_cast<int>(ctx->getStop()->getLine());
        cout << '#' << last_line << '\n';
        cout << "_program\n";
        for (auto cls : ctx->class_())
            printClass(cls, 2);
    }

    void printClass(CoolParser::ClassContext *ctx, int ind)
    {
        int line = static_cast<int>(ctx->getStop()->getLine());
        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << "_class\n";

        indent(ind + 2);
        cout << ctx->TYPEID()->getText() << '\n';

        if (auto inh = ctx->inheritance())
        {
            indent(ind + 2);
            cout << inh->TYPEID()->getText() << '\n';
        }
        else
        {
            indent(ind + 2);
            cout << "Object\n";
        }

        indent(ind + 2);
        cout << '"' << file_name_ << '"' << '\n';

        indent(ind + 2);
        cout << "(\n";
        for (auto feat : ctx->feature())
            printFeature(feat, ind + 2);
        indent(ind + 2);
        cout << ")\n";
    }

    void printFeature(CoolParser::FeatureContext *ctx, int ind)
    {
        if (ctx->OPAREN() != nullptr)
            printMethod(ctx, ind);
        else
            printAttr(ctx, ind);
    }

    void printFormal(CoolParser::FormalContext *ctx, int ind)
    {
        int line = static_cast<int>(ctx->getStart()->getLine());
        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << "_formal\n";
        indent(ind + 2);
        cout << ctx->OBJECTID()->getText() << '\n';
        indent(ind + 2);
        cout << ctx->TYPEID()->getText() << '\n';
    }

    void printAttr(CoolParser::FeatureContext *ctx, int ind)
    {
        int line = static_cast<int>(ctx->getStart()->getLine());
        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << "_attr\n";

        indent(ind + 2);
        cout << ctx->OBJECTID()->getText() << '\n';
        indent(ind + 2);
        cout << ctx->TYPEID()->getText() << '\n';

        auto init = ctx->expr();
        if (init)
            printExpr(init, ind + 2);
        else
            print_no_expr(line, ind + 2);
    }

    void printMethod(CoolParser::FeatureContext *ctx, int ind)
    {
        int line = static_cast<int>(ctx->getStop()->getLine());
        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << "_method\n";

        indent(ind + 2);
        cout << ctx->OBJECTID()->getText() << '\n';

        if (auto fl = ctx->formal_list())
            for (auto f : fl->formal())
                printFormal(f, ind + 2);

        indent(ind + 2);
        cout << ctx->TYPEID()->getText() << '\n';

        auto body = ctx->expr();
        if (body)
            printExpr(body, ind + 2);
        else
            print_no_expr(line, ind + 2);
    }

    void printExpr(CoolParser::ExprContext *ctx, int ind)
    {
        printAssignExpr(ctx->assignExpr(), ind);
    }

    void printAssignExpr(CoolParser::AssignExprContext *ctx, int ind)
    {
        if (ctx->ASSIGN() != nullptr)
        {
            int line = static_cast<int>(ctx->ASSIGN()->getSymbol()->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_assign\n";

            indent(ind + 2);
            cout << ctx->OBJECTID()->getText() << '\n';

            printAssignExpr(ctx->assignExpr(), ind + 2);

            indent(ind);
            cout << ": _no_type\n";
        }
        else
        {
            printNotExpr(ctx->notExpr(), ind);
        }
    }

    void printNotExpr(CoolParser::NotExprContext *ctx, int ind)
    {
        if (ctx->NOT() != nullptr)
        {
            int line = static_cast<int>(ctx->NOT()->getSymbol()->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_comp\n";
            printNotExpr(ctx->notExpr(), ind + 2);
            indent(ind);
            cout << ": _no_type\n";
        }
        else
        {
            printCompareExpr(ctx->compareExpr(), ind);
        }
    }

    void collectCompareOps(CoolParser::CompareExprContext *ctx,
                           vector<Token *> &ops)
    {
        if (ctx->children.empty())
            return;
        for (auto child : ctx->children)
        {
            auto tnode = dynamic_cast<TerminalNode *>(child);
            if (!tnode)
                continue;
            int ttype = tnode->getSymbol()->getType();
            if (ttype == CoolLexer::LT ||
                ttype == CoolLexer::LE ||
                ttype == CoolLexer::EQ)
                ops.push_back(tnode->getSymbol());
        }
    }

    void collectAddOps(CoolParser::ArithExprContext *ctx,
                       vector<Token *> &ops)
    {
        if (ctx->children.empty())
            return;
        for (auto child : ctx->children)
        {
            auto tnode = dynamic_cast<TerminalNode *>(child);
            if (!tnode)
                continue;
            int ttype = tnode->getSymbol()->getType();
            if (ttype == CoolLexer::PLUS || ttype == CoolLexer::MINUS)
                ops.push_back(tnode->getSymbol());
        }
    }

    void collectMulOps(CoolParser::TermContext *ctx,
                       vector<Token *> &ops)
    {
        if (ctx->children.empty())
            return;
        for (auto child : ctx->children)
        {
            auto tnode = dynamic_cast<TerminalNode *>(child);
            if (!tnode)
                continue;
            int ttype = tnode->getSymbol()->getType();
            if (ttype == CoolLexer::STAR || ttype == CoolLexer::SLASH)
                ops.push_back(tnode->getSymbol());
        }
    }

    void printCompareChain(const vector<CoolParser::ArithExprContext *> &terms,
                           const vector<Token *> &ops,
                           int idx,
                           int ind)
    {
        Token *opTok = ops[idx];
        int line = opTok->getLine();
        int ttype = opTok->getType();

        string node;
        if (ttype == CoolLexer::LT)
            node = "_lt";
        else if (ttype == CoolLexer::LE)
            node = "_leq";
        else
            node = "_eq";

        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << node << '\n';

        if (idx == 0)
        {
            printArithExpr(terms[0], ind + 2);
            printArithExpr(terms[1], ind + 2);
        }
        else
        {
            printCompareChain(terms, ops, idx - 1, ind + 2);
            printArithExpr(terms[idx + 1], ind + 2);
        }

        indent(ind);
        cout << ": _no_type\n";
    }

    void printCompareExpr(CoolParser::CompareExprContext *ctx, int ind)
    {
        auto terms = ctx->arithExpr();
        vector<Token *> ops;
        collectCompareOps(ctx, ops);

        if (ops.empty())
            printArithExpr(terms[0], ind);
        else
            printCompareChain(terms, ops, static_cast<int>(ops.size()) - 1, ind);
    }

    void printAddChain(const vector<CoolParser::TermContext *> &terms,
                       const vector<Token *> &ops,
                       int idx,
                       int ind)
    {
        Token *opTok = ops[idx];
        int line = opTok->getLine();
        int ttype = opTok->getType();

        string node = (ttype == CoolLexer::PLUS) ? "_plus" : "_sub";

        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << node << '\n';

        if (idx == 0)
        {
            printTerm(terms[0], ind + 2);
            printTerm(terms[1], ind + 2);
        }
        else
        {
            printAddChain(terms, ops, idx - 1, ind + 2);
            printTerm(terms[idx + 1], ind + 2);
        }

        indent(ind);
        cout << ": _no_type\n";
    }

    void printArithExpr(CoolParser::ArithExprContext *ctx, int ind)
    {
        auto terms = ctx->term();
        vector<Token *> ops;
        collectAddOps(ctx, ops);

        if (ops.empty())
            printTerm(terms[0], ind);
        else
            printAddChain(terms, ops, static_cast<int>(ops.size()) - 1, ind);
    }

    void printMulChain(const vector<CoolParser::FactorContext *> &factors,
                       const vector<Token *> &ops,
                       int idx,
                       int ind)
    {
        Token *opTok = ops[idx];
        int line = opTok->getLine();
        int ttype = opTok->getType();

        string node = (ttype == CoolLexer::STAR) ? "_mul" : "_divide";

        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << node << '\n';

        if (idx == 0)
        {
            printFactor(factors[0], ind + 2);
            printFactor(factors[1], ind + 2);
        }
        else
        {
            printMulChain(factors, ops, idx - 1, ind + 2);
            printFactor(factors[idx + 1], ind + 2);
        }

        indent(ind);
        cout << ": _no_type\n";
    }

    void printTerm(CoolParser::TermContext *ctx, int ind)
    {
        auto factors = ctx->factor();
        vector<Token *> ops;
        collectMulOps(ctx, ops);

        if (ops.empty())
            printFactor(factors[0], ind);
        else
            printMulChain(factors, ops, static_cast<int>(ops.size()) - 1, ind);
    }

    void printFactor(CoolParser::FactorContext *ctx, int ind)
    {
        if (ctx->ISVOID())
        {
            int line = static_cast<int>(ctx->ISVOID()->getSymbol()->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_isvoid\n";
            printFactor(ctx->factor(), ind + 2);
            indent(ind);
            cout << ": _no_type\n";
        }
        else if (ctx->TILDE())
        {
            int line = static_cast<int>(ctx->TILDE()->getSymbol()->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_neg\n";
            printFactor(ctx->factor(), ind + 2);
            indent(ind);
            cout << ": _no_type\n";
        }
        else
        {
            printDispatchExpr(ctx->dispatchExpr(), ind);
        }
    }

    void collectDispatchSuffixes(CoolParser::DispatchExprContext *ctx,
                                 vector<DispatchSuffix> &out)
    {
        auto &children = ctx->children;
        if (children.size() <= 1)
            return;

        size_t i = 1; // skip primary
        while (i < children.size())
        {
            auto tnode = dynamic_cast<TerminalNode *>(children[i]);
            if (!tnode)
            {
                ++i;
                continue;
            }

            int type = tnode->getSymbol()->getType();
            if (type != CoolLexer::AT && type != CoolLexer::DOT)
            {
                ++i;
                continue;
            }

            DispatchSuffix suf;
            suf.args = nullptr;
            suf.isStatic = false;

            if (type == CoolLexer::AT)
            {
                auto typeNode = dynamic_cast<TerminalNode *>(children[i + 1]);
                auto dotNode = dynamic_cast<TerminalNode *>(children[i + 2]);
                suf.isStatic = true;
                suf.staticType = typeNode->getSymbol()->getText();
                suf.line = dotNode->getSymbol()->getLine();
                i += 3;
            }
            else
            {
                suf.line = tnode->getSymbol()->getLine();
                i += 1;
            }

            auto idNode = dynamic_cast<TerminalNode *>(children[i]);
            suf.methodName = idNode->getSymbol()->getText();
            ++i;

            ++i; // skip '('

            if (i < children.size())
            {
                if (auto argCtx = dynamic_cast<CoolParser::Arg_listContext *>(children[i]))
                {
                    suf.args = argCtx;
                    ++i;
                }
            }

            if (i < children.size())
                ++i; // skip ')'

            out.push_back(suf);
        }
    }

    void printDispatchChain(CoolParser::PrimaryContext *base,
                            const vector<DispatchSuffix> &suffixes,
                            int idx,
                            int ind)
    {
        const auto &suf = suffixes[idx];
        string nodeName = suf.isStatic ? "_static_dispatch" : "_dispatch";

        indent(ind);
        cout << '#' << suf.line << '\n';
        indent(ind);
        cout << nodeName << '\n';

        int childInd = ind + 2;

        if (idx == 0)
            printPrimary(base, childInd);
        else
            printDispatchChain(base, suffixes, idx - 1, childInd);

        if (suf.isStatic)
        {
            indent(childInd);
            cout << suf.staticType << '\n';
        }

        indent(childInd);
        cout << suf.methodName << '\n';

        indent(childInd);
        cout << "(\n";
        if (suf.args)
            for (auto e : suf.args->expr())
                printExpr(e, childInd);
        indent(childInd);
        cout << ")\n";

        indent(ind);
        cout << ": _no_type\n";
    }

    void printDispatchExpr(CoolParser::DispatchExprContext *ctx, int ind)
    {
        auto base = ctx->primary();
        vector<DispatchSuffix> suffixes;
        collectDispatchSuffixes(ctx, suffixes);

        if (suffixes.empty())
            printPrimary(base, ind);
        else
            printDispatchChain(base, suffixes,
                               static_cast<int>(suffixes.size()) - 1, ind);
    }

    void printBlockExpr(CoolParser::Block_exprContext *ctx,
                        int ind,
                        int blockLine)
    {
        // composite block
        if (ctx->expr().size() == 1)
        {
            auto innerExpr = ctx->expr(0);
            auto aexpr = innerExpr->assignExpr();
            if (aexpr && !aexpr->ASSIGN())
            {
                auto nctx = aexpr->notExpr();
                if (nctx && !nctx->NOT())
                {
                    auto cctx = nctx->compareExpr();
                    if (cctx && cctx->arithExpr().size() == 1)
                    {
                        auto actx = cctx->arithExpr(0);
                        if (actx && actx->term().size() == 1)
                        {
                            auto tctx = actx->term(0);
                            if (tctx && tctx->factor().size() == 1)
                            {
                                auto fctx = tctx->factor(0);
                                if (fctx && !fctx->ISVOID() && !fctx->TILDE())
                                {
                                    auto dctx = fctx->dispatchExpr();
                                    if (dctx)
                                    {
                                        vector<DispatchSuffix> suffixes;
                                        collectDispatchSuffixes(dctx, suffixes);
                                        if (suffixes.empty())
                                        {
                                            auto prim = dctx->primary();
                                            if (prim && prim->OCURLY())
                                            {
                                                auto innerBlock = prim->block_expr();
                                                if (innerBlock &&
                                                    innerBlock->expr().size() > 1)
                                                {
                                                    indent(ind);
                                                    cout << '#' << blockLine << '\n';
                                                    indent(ind);
                                                    cout << "_block\n";
                                                    int childInd = ind + 2;
                                                    for (auto e : innerBlock->expr())
                                                        printExpr(e, childInd);
                                                    indent(ind);
                                                    cout << ": _no_type\n";
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // normal block
        indent(ind);
        cout << '#' << blockLine << '\n';
        indent(ind);
        cout << "_block\n";
        int childInd = ind + 2;
        for (auto e : ctx->expr())
            printExpr(e, childInd);
        indent(ind);
        cout << ": _no_type\n";
    }

    void printLetChain(
        const vector<CoolParser::Let_bindingContext *> &bindings,
        CoolParser::ExprContext *body,
        int idx,
        int ind,
        int letLine)
    {
        auto bind = bindings[idx];

        indent(ind);
        cout << '#' << letLine << '\n';
        indent(ind);
        cout << "_let\n";

        int childInd = ind + 2;

        indent(childInd);
        cout << bind->OBJECTID()->getText() << '\n';

        indent(childInd);
        cout << bind->TYPEID()->getText() << '\n';

        int bind_line = static_cast<int>(bind->getStart()->getLine());
        if (auto init = bind->expr())
            printExpr(init, childInd);
        else
            print_no_expr(bind_line, childInd);

        if (idx + 1 < static_cast<int>(bindings.size()))
            printLetChain(bindings, body, idx + 1, childInd, letLine);
        else
            printExpr(body, childInd);

        indent(ind);
        cout << ": _no_type\n";
    }

    void printBranch(CoolParser::BranchContext *ctx, int ind)
    {
        int line = static_cast<int>(ctx->getStart()->getLine());
        indent(ind);
        cout << '#' << line << '\n';
        indent(ind);
        cout << "_branch\n";

        int childInd = ind + 2;
        indent(childInd);
        cout << ctx->OBJECTID()->getText() << '\n';
        indent(childInd);
        cout << ctx->TYPEID()->getText() << '\n';

        printExpr(ctx->expr(), childInd);
    }

    void printPrimary(CoolParser::PrimaryContext *ctx, int ind)
    {
        if (ctx->IF())
        {
            int line = static_cast<int>(ctx->FI()->getSymbol()->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_cond\n";

            int childInd = ind + 2;
            auto exps = ctx->expr();
            printExpr(exps[0], childInd);
            printExpr(exps[1], childInd);
            printExpr(exps[2], childInd);

            indent(ind);
            cout << ": _no_type\n";
            return;
        }

        if (ctx->WHILE())
        {
            int line = static_cast<int>(ctx->POOL()->getSymbol()->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_loop\n";

            int childInd = ind + 2;
            auto exps = ctx->expr();
            printExpr(exps[0], childInd);
            printExpr(exps[1], childInd);

            indent(ind);
            cout << ": _no_type\n";
            return;
        }

        if (ctx->OCURLY())
        {
            int blockLine =
                static_cast<int>(ctx->CCURLY()->getSymbol()->getLine());
            printBlockExpr(ctx->block_expr(), ind, blockLine);
            return;
        }

        if (ctx->LET())
        {
            auto bindings = ctx->let_binding();
            auto body = ctx->expr(0);
            int letLine = static_cast<int>(body->getStop()->getLine());
            printLetChain(bindings, body, 0, ind, letLine);
            return;
        }

        if (ctx->CASE())
        {
            int line = static_cast<int>(ctx->ESAC()->getSymbol()->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_typcase\n";

            int childInd = ind + 2;
            printExpr(ctx->expr(0), childInd);
            for (auto b : ctx->branch())
                printBranch(b, childInd);

            indent(ind);
            cout << ": _no_type\n";
            return;
        }

        if (ctx->NEW())
        {
            int line = static_cast<int>(ctx->NEW()->getSymbol()->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_new\n";
            indent(ind + 2);
            cout << ctx->TYPEID()->getText() << '\n';
            indent(ind);
            cout << ": _no_type\n";
            return;
        }

        if (ctx->OPAREN() && ctx->CPAREN() && !ctx->expr().empty())
        {
            printExpr(ctx->expr(0), ind);
            return;
        }

        if (ctx->OBJECTID() && ctx->OPAREN() && ctx->CPAREN())
        {
            auto idTok = ctx->OBJECTID()->getSymbol();
            int line = static_cast<int>(idTok->getLine());
            string methodName = idTok->getText();

            vector<CoolParser::ExprContext *> args;
            if (auto al = ctx->arg_list())
                for (auto e : al->expr())
                    args.push_back(e);

            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_dispatch\n";

            int childInd = ind + 2;

            indent(childInd);
            cout << '#' << line << '\n';
            indent(childInd);
            cout << "_object\n";
            indent(childInd + 2);
            cout << "self\n";
            indent(childInd);
            cout << ": _no_type\n";

            indent(childInd);
            cout << methodName << '\n';

            indent(childInd);
            cout << "(\n";
            for (auto e : args)
                printExpr(e, childInd);
            indent(childInd);
            cout << ")\n";

            indent(ind);
            cout << ": _no_type\n";
            return;
        }

        if (ctx->OBJECTID() && !ctx->OPAREN())
        {
            auto *tok = ctx->OBJECTID()->getSymbol();
            int line = static_cast<int>(tok->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_object\n";
            indent(ind + 2);
            cout << tok->getText() << '\n';
            indent(ind);
            cout << ": _no_type\n";
            return;
        }

        if (ctx->INT_CONST())
        {
            auto *tok = ctx->INT_CONST()->getSymbol();
            int line = static_cast<int>(tok->getLine());
            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_int\n";
            indent(ind + 2);
            cout << tok->getText() << '\n';
            indent(ind);
            cout << ": _no_type\n";
            return;
        }

        if (ctx->STR_CONST())
        {
            auto *tok = ctx->STR_CONST()->getSymbol();
            int line = static_cast<int>(tok->getLine());
            int char_index = static_cast<int>(tok->getStartIndex());
            std::string canonical = lexer_->get_csl_text(char_index);
            std::string escaped = escape_string(canonical);

            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_string\n";
            indent(ind + 2);
            cout << escaped << '\n';
            indent(ind);
            cout << ": _no_type\n";
            return;
        }

        if (ctx->BOOL_CONST())
        {
            auto *tok = ctx->BOOL_CONST()->getSymbol();
            int line = static_cast<int>(tok->getLine());
            int char_index = static_cast<int>(tok->getStartIndex());
            bool value = lexer_->get_bool_value(char_index);

            indent(ind);
            cout << '#' << line << '\n';
            indent(ind);
            cout << "_bool\n";
            indent(ind + 2);
            cout << (value ? 1 : 0) << '\n';
            indent(ind);
            cout << ": _no_type\n";
            return;
        }
    }

public:
    TreePrinter(CoolLexer *lexer, const string &file_name)
        : lexer_(lexer), file_name_(file_name) {}

    void print(CoolParser::ProgramContext *root)
    {
        printProgram(root);
    }
};

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        cerr << "Expecting exactly one argument: name of input file\n";
        return 1;
    }

    auto file_path = argv[1];
    ifstream fin(file_path);
    if (!fin)
    {
        cerr << "Could not open input file: " << file_path << '\n';
        return 1;
    }

    auto file_name = fs::path(file_path).filename().string();

    ANTLRInputStream input(fin);
    CoolLexer lexer(&input);
    CommonTokenStream tokenStream(&lexer);
    CoolParser parser(&tokenStream);

    ErrorPrinter error_printer(file_name, &lexer);
    parser.removeErrorListener(&ConsoleErrorListener::INSTANCE);
    parser.addErrorListener(&error_printer);

    CoolParser::ProgramContext *tree = parser.program();

    if (!error_printer.has_error())
    {
        TreePrinter(&lexer, file_name).print(tree);
    }
    else
    {
        cout << "Compilation halted due to lex and parse errors\n";
    }

    return 0;
}
