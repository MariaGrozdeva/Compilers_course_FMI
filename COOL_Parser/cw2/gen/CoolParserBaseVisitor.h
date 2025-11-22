
// Generated from /home/student/my-code/cw2/tools/../src/CoolParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CoolParserVisitor.h"


/**
 * This class provides an empty implementation of CoolParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CoolParserBaseVisitor : public CoolParserVisitor {
public:

  virtual std::any visitProgram(CoolParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass(CoolParser::ClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInheritance(CoolParser::InheritanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFeature(CoolParser::FeatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormal_list(CoolParser::Formal_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormal(CoolParser::FormalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(CoolParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(CoolParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(CoolParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompareExpr(CoolParser::CompareExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArithExpr(CoolParser::ArithExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(CoolParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(CoolParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDispatchExpr(CoolParser::DispatchExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg_list(CoolParser::Arg_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(CoolParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_expr(CoolParser::Block_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBranch(CoolParser::BranchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLet_binding(CoolParser::Let_bindingContext *ctx) override {
    return visitChildren(ctx);
  }


};

