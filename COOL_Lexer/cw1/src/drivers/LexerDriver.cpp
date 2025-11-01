#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "antlr4-runtime/antlr4-runtime.h"
#include "CoolLexer.h"

using namespace std;
using namespace antlr4;

string cool_token_to_string(Token *token)
{
    auto token_type = token->getType();

    switch (token_type)
    {
    case static_cast<size_t>(-1):
        return "EOF";

    case CoolLexer::SEMI:
        return "';'";
    case CoolLexer::LPAREN:
        return "'('";
    case CoolLexer::RPAREN:
        return "')'";
    case CoolLexer::LBRACE:
        return "'{'";
    case CoolLexer::RBRACE:
        return "'}'";
    case CoolLexer::COMMA:
        return "','";
    case CoolLexer::COLON:
        return "':'";
    case CoolLexer::DOT:
        return "'.'";
    case CoolLexer::PLUS:
        return "'+'";
    case CoolLexer::MINUS:
        return "'-'";
    case CoolLexer::MULT:
        return "'*'";
    case CoolLexer::DIV:
        return "'/'";
    case CoolLexer::LT:
        return "'<'";
    case CoolLexer::EQUALS:
        return "'='";
    case CoolLexer::AT:
        return "'@'";
    case CoolLexer::TILDE:
        return "'~'";

    case CoolLexer::LE:
        return "LE";
    case CoolLexer::ASSIGN:
        return "ASSIGN";
    case CoolLexer::DARROW:
        return "DARROW";

    case CoolLexer::CASE:
        return "CASE";
    case CoolLexer::CLASS:
        return "CLASS";
    case CoolLexer::ELSE:
        return "ELSE";
    case CoolLexer::ESAC:
        return "ESAC";
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
    case CoolLexer::NEW:
        return "NEW";
    case CoolLexer::NOT:
        return "NOT";
    case CoolLexer::OF:
        return "OF";
    case CoolLexer::POOL:
        return "POOL";
    case CoolLexer::THEN:
        return "THEN";
    case CoolLexer::WHILE:
        return "WHILE";

    case CoolLexer::BOOL_CONST:
        return "BOOL_CONST";
    case CoolLexer::INT_CONST:
        return "INT_CONST";
    case CoolLexer::STR_CONST:
        return "STR_CONST";
    case CoolLexer::OBJECTID:
        return "OBJECTID";
    case CoolLexer::TYPEID:
        return "TYPEID";
    case CoolLexer::ERROR:
        return "ERROR";

    default:
        return "<Invalid Token>: " + token->toString();
    }
}

void dump_cool_token(CoolLexer *lexer, ostream &out, Token *token)
{
    if (token->getType() == static_cast<size_t>(-1))
        return;

    out << "#" << token->getLine() << " " << cool_token_to_string(token);

    auto token_type = token->getType();
    auto token_start_char_index = token->getStartIndex();

    switch (token_type)
    {
    case CoolLexer::BOOL_CONST:
        out << " " << (lexer->get_bool_value(token_start_char_index) ? "true" : "false");
        break;

    case CoolLexer::INT_CONST:
    case CoolLexer::STR_CONST:
    case CoolLexer::TYPEID:
    case CoolLexer::OBJECTID:
        out << " " << token->getText();
        break;

    case CoolLexer::ERROR:
        out << ": " << token->getText();
        break;

    default:
        break;
    }

    out << endl;
}

int main(int argc, const char *argv[])
{
    ANTLRInputStream input(cin);
    CoolLexer lexer(&input);

    CommonTokenStream tokenStream(&lexer);
    tokenStream.fill();

    vector<Token *> tokens = tokenStream.getTokens();
    for (Token *token : tokens)
    {
        dump_cool_token(&lexer, cout, token);
    }

    return 0;
}
