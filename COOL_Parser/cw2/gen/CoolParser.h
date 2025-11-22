
// Generated from /home/student/my-code/cw2/tools/../src/CoolParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  CoolParser : public antlr4::Parser {
public:
  enum {
    SEMI = 1, OCURLY = 2, CCURLY = 3, OPAREN = 4, COMMA = 5, CPAREN = 6, 
    COLON = 7, AT = 8, DOT = 9, PLUS = 10, MINUS = 11, STAR = 12, SLASH = 13, 
    TILDE = 14, LT = 15, EQ = 16, DARROW = 17, ASSIGN = 18, LE = 19, CLASS = 20, 
    ELSE = 21, FI = 22, IF = 23, IN = 24, INHERITS = 25, ISVOID = 26, LET = 27, 
    LOOP = 28, POOL = 29, THEN = 30, WHILE = 31, CASE = 32, ESAC = 33, NEW = 34, 
    OF = 35, NOT = 36, BOOL_CONST = 37, INT_CONST = 38, OBJECTID = 39, TYPEID = 40, 
    WS = 41, STR_BEGIN = 42, COMM_BEGIN = 43, COMM_ERR1 = 44, LCOMM_BEGIN = 45, 
    ERROR = 46, STR_CONST = 47, STR_END = 48, STR_ESC_NL = 49, ESC_BS = 50, 
    ESC_FF = 51, ESC_TAB = 52, ESC_NULL = 53, ESC_ANY = 54, NULL_ = 55, 
    STR_NL = 56, STR_ERR = 57, STR_ANY = 58, ESTR_END = 59, ESTR_ESC_NL = 60, 
    ESTR_NL = 61, ESTR_ANY = 62, OCOMM = 63, CCOMM = 64, COMM_SKIP = 65, 
    COMM_ERR = 66, LCOMM_END = 67, LCOMM_SKIP = 68
  };

  enum {
    RuleProgram = 0, RuleClass = 1, RuleInheritance = 2, RuleFeature = 3, 
    RuleFormal_list = 4, RuleFormal = 5, RuleExpr = 6, RuleAssignExpr = 7, 
    RuleNotExpr = 8, RuleCompareExpr = 9, RuleArithExpr = 10, RuleTerm = 11, 
    RuleFactor = 12, RuleDispatchExpr = 13, RuleArg_list = 14, RulePrimary = 15, 
    RuleBlock_expr = 16, RuleBranch = 17, RuleLet_binding = 18
  };

  explicit CoolParser(antlr4::TokenStream *input);

  CoolParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CoolParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class ClassContext;
  class InheritanceContext;
  class FeatureContext;
  class Formal_listContext;
  class FormalContext;
  class ExprContext;
  class AssignExprContext;
  class NotExprContext;
  class CompareExprContext;
  class ArithExprContext;
  class TermContext;
  class FactorContext;
  class DispatchExprContext;
  class Arg_listContext;
  class PrimaryContext;
  class Block_exprContext;
  class BranchContext;
  class Let_bindingContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ClassContext *> class_();
    ClassContext* class_(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ClassContext : public antlr4::ParserRuleContext {
  public:
    ClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *TYPEID();
    antlr4::tree::TerminalNode *OCURLY();
    antlr4::tree::TerminalNode *CCURLY();
    InheritanceContext *inheritance();
    std::vector<FeatureContext *> feature();
    FeatureContext* feature(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassContext* class_();

  class  InheritanceContext : public antlr4::ParserRuleContext {
  public:
    InheritanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INHERITS();
    antlr4::tree::TerminalNode *TYPEID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InheritanceContext* inheritance();

  class  FeatureContext : public antlr4::ParserRuleContext {
  public:
    FeatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECTID();
    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *TYPEID();
    antlr4::tree::TerminalNode *OCURLY();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CCURLY();
    Formal_listContext *formal_list();
    antlr4::tree::TerminalNode *ASSIGN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FeatureContext* feature();

  class  Formal_listContext : public antlr4::ParserRuleContext {
  public:
    Formal_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FormalContext *> formal();
    FormalContext* formal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Formal_listContext* formal_list();

  class  FormalContext : public antlr4::ParserRuleContext {
  public:
    FormalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECTID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *TYPEID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalContext* formal();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignExprContext *assignExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  AssignExprContext : public antlr4::ParserRuleContext {
  public:
    AssignExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECTID();
    antlr4::tree::TerminalNode *ASSIGN();
    AssignExprContext *assignExpr();
    NotExprContext *notExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignExprContext* assignExpr();

  class  NotExprContext : public antlr4::ParserRuleContext {
  public:
    NotExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    NotExprContext *notExpr();
    CompareExprContext *compareExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotExprContext* notExpr();

  class  CompareExprContext : public antlr4::ParserRuleContext {
  public:
    CompareExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArithExprContext *> arithExpr();
    ArithExprContext* arithExpr(size_t i);
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *EQ();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompareExprContext* compareExpr();

  class  ArithExprContext : public antlr4::ParserRuleContext {
  public:
    ArithExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArithExprContext* arithExpr();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SLASH();
    antlr4::tree::TerminalNode* SLASH(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ISVOID();
    FactorContext *factor();
    antlr4::tree::TerminalNode *TILDE();
    DispatchExprContext *dispatchExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  DispatchExprContext : public antlr4::ParserRuleContext {
  public:
    DispatchExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OBJECTID();
    antlr4::tree::TerminalNode* OBJECTID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OPAREN();
    antlr4::tree::TerminalNode* OPAREN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CPAREN();
    antlr4::tree::TerminalNode* CPAREN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AT();
    antlr4::tree::TerminalNode* AT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> TYPEID();
    antlr4::tree::TerminalNode* TYPEID(size_t i);
    std::vector<Arg_listContext *> arg_list();
    Arg_listContext* arg_list(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DispatchExprContext* dispatchExpr();

  class  Arg_listContext : public antlr4::ParserRuleContext {
  public:
    Arg_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arg_listContext* arg_list();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *FI();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *POOL();
    antlr4::tree::TerminalNode *OCURLY();
    Block_exprContext *block_expr();
    antlr4::tree::TerminalNode *CCURLY();
    antlr4::tree::TerminalNode *LET();
    std::vector<Let_bindingContext *> let_binding();
    Let_bindingContext* let_binding(size_t i);
    antlr4::tree::TerminalNode *IN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *CASE();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *ESAC();
    std::vector<BranchContext *> branch();
    BranchContext* branch(size_t i);
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *TYPEID();
    antlr4::tree::TerminalNode *OPAREN();
    antlr4::tree::TerminalNode *CPAREN();
    antlr4::tree::TerminalNode *OBJECTID();
    Arg_listContext *arg_list();
    antlr4::tree::TerminalNode *INT_CONST();
    antlr4::tree::TerminalNode *STR_CONST();
    antlr4::tree::TerminalNode *BOOL_CONST();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();

  class  Block_exprContext : public antlr4::ParserRuleContext {
  public:
    Block_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_exprContext* block_expr();

  class  BranchContext : public antlr4::ParserRuleContext {
  public:
    BranchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECTID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *TYPEID();
    antlr4::tree::TerminalNode *DARROW();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchContext* branch();

  class  Let_bindingContext : public antlr4::ParserRuleContext {
  public:
    Let_bindingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECTID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *TYPEID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_bindingContext* let_binding();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

