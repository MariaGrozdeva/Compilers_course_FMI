
// Generated from /home/student/my-code/cw2/tools/../src/CoolParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CoolParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CoolParser.
 */
class  CoolParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CoolParser.
   */
    virtual std::any visitProgram(CoolParser::ProgramContext *context) = 0;

    virtual std::any visitClass(CoolParser::ClassContext *context) = 0;

    virtual std::any visitInheritance(CoolParser::InheritanceContext *context) = 0;

    virtual std::any visitFeature(CoolParser::FeatureContext *context) = 0;

    virtual std::any visitFormal_list(CoolParser::Formal_listContext *context) = 0;

    virtual std::any visitFormal(CoolParser::FormalContext *context) = 0;

    virtual std::any visitExpr(CoolParser::ExprContext *context) = 0;

    virtual std::any visitAssignExpr(CoolParser::AssignExprContext *context) = 0;

    virtual std::any visitNotExpr(CoolParser::NotExprContext *context) = 0;

    virtual std::any visitCompareExpr(CoolParser::CompareExprContext *context) = 0;

    virtual std::any visitArithExpr(CoolParser::ArithExprContext *context) = 0;

    virtual std::any visitTerm(CoolParser::TermContext *context) = 0;

    virtual std::any visitFactor(CoolParser::FactorContext *context) = 0;

    virtual std::any visitDispatchExpr(CoolParser::DispatchExprContext *context) = 0;

    virtual std::any visitArg_list(CoolParser::Arg_listContext *context) = 0;

    virtual std::any visitPrimary(CoolParser::PrimaryContext *context) = 0;

    virtual std::any visitBlock_expr(CoolParser::Block_exprContext *context) = 0;

    virtual std::any visitBranch(CoolParser::BranchContext *context) = 0;

    virtual std::any visitLet_binding(CoolParser::Let_bindingContext *context) = 0;


};

