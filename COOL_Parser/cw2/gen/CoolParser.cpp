
// Generated from /home/student/my-code/cw2/tools/../src/CoolParser.g4 by ANTLR 4.13.2


#include "CoolParserVisitor.h"

#include "CoolParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CoolParserStaticData final {
  CoolParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CoolParserStaticData(const CoolParserStaticData&) = delete;
  CoolParserStaticData(CoolParserStaticData&&) = delete;
  CoolParserStaticData& operator=(const CoolParserStaticData&) = delete;
  CoolParserStaticData& operator=(CoolParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag coolparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CoolParserStaticData> coolparserParserStaticData = nullptr;

void coolparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (coolparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(coolparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CoolParserStaticData>(
    std::vector<std::string>{
      "program", "class", "inheritance", "feature", "formal_list", "formal", 
      "expr", "assignExpr", "notExpr", "compareExpr", "arithExpr", "term", 
      "factor", "dispatchExpr", "arg_list", "primary", "block_expr", "branch", 
      "let_binding"
    },
    std::vector<std::string>{
      "", "';'", "'{'", "'}'", "'('", "','", "')'", "':'", "'@'", "'.'", 
      "'+'", "'-'", "'*'", "'/'", "'~'", "'<'", "'='", "'=>'", "'<-'", "'<='", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "'--'", "", "'\\u003F'", "", "", "", 
      "", "", "", "", "", "", "", "", "", "'\\n'", "", "", "", "", "", "", 
      "'\\n'"
    },
    std::vector<std::string>{
      "", "SEMI", "OCURLY", "CCURLY", "OPAREN", "COMMA", "CPAREN", "COLON", 
      "AT", "DOT", "PLUS", "MINUS", "STAR", "SLASH", "TILDE", "LT", "EQ", 
      "DARROW", "ASSIGN", "LE", "CLASS", "ELSE", "FI", "IF", "IN", "INHERITS", 
      "ISVOID", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", 
      "NEW", "OF", "NOT", "BOOL_CONST", "INT_CONST", "OBJECTID", "TYPEID", 
      "WS", "STR_BEGIN", "COMM_BEGIN", "COMM_ERR1", "LCOMM_BEGIN", "ERROR", 
      "STR_CONST", "STR_END", "STR_ESC_NL", "ESC_BS", "ESC_FF", "ESC_TAB", 
      "ESC_NULL", "ESC_ANY", "NULL", "STR_NL", "STR_ERR", "STR_ANY", "ESTR_END", 
      "ESTR_ESC_NL", "ESTR_NL", "ESTR_ANY", "OCOMM", "CCOMM", "COMM_SKIP", 
      "COMM_ERR", "LCOMM_END", "LCOMM_SKIP"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,68,246,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,0,4,0,42,8,0,11,
  	0,12,0,43,1,1,1,1,1,1,3,1,49,8,1,1,1,1,1,1,1,1,1,5,1,55,8,1,10,1,12,1,
  	58,9,1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,3,3,68,8,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,82,8,3,3,3,84,8,3,1,4,1,4,1,4,5,4,89,
  	8,4,10,4,12,4,92,9,4,1,5,1,5,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,7,3,7,104,
  	8,7,1,8,1,8,1,8,3,8,109,8,8,1,9,1,9,1,9,3,9,114,8,9,1,10,1,10,1,10,5,
  	10,119,8,10,10,10,12,10,122,9,10,1,11,1,11,1,11,5,11,127,8,11,10,11,12,
  	11,130,9,11,1,12,1,12,1,12,1,12,1,12,3,12,137,8,12,1,13,1,13,1,13,3,13,
  	142,8,13,1,13,1,13,1,13,1,13,3,13,148,8,13,1,13,5,13,151,8,13,10,13,12,
  	13,154,9,13,1,14,1,14,1,14,5,14,159,8,14,10,14,12,14,162,9,14,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,5,15,186,8,15,10,15,12,15,189,9,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,4,15,198,8,15,11,15,12,15,199,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,213,8,15,1,15,1,
  	15,1,15,1,15,1,15,3,15,220,8,15,1,16,1,16,1,16,1,16,1,16,5,16,227,8,16,
  	10,16,12,16,230,9,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,
  	1,18,1,18,3,18,244,8,18,1,18,0,0,19,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,0,3,2,0,15,16,19,19,1,0,10,11,1,0,12,13,260,0,41,1,
  	0,0,0,2,45,1,0,0,0,4,61,1,0,0,0,6,83,1,0,0,0,8,85,1,0,0,0,10,93,1,0,0,
  	0,12,97,1,0,0,0,14,103,1,0,0,0,16,108,1,0,0,0,18,110,1,0,0,0,20,115,1,
  	0,0,0,22,123,1,0,0,0,24,136,1,0,0,0,26,138,1,0,0,0,28,155,1,0,0,0,30,
  	219,1,0,0,0,32,221,1,0,0,0,34,231,1,0,0,0,36,238,1,0,0,0,38,39,3,2,1,
  	0,39,40,5,1,0,0,40,42,1,0,0,0,41,38,1,0,0,0,42,43,1,0,0,0,43,41,1,0,0,
  	0,43,44,1,0,0,0,44,1,1,0,0,0,45,46,5,20,0,0,46,48,5,40,0,0,47,49,3,4,
  	2,0,48,47,1,0,0,0,48,49,1,0,0,0,49,50,1,0,0,0,50,56,5,2,0,0,51,52,3,6,
  	3,0,52,53,5,1,0,0,53,55,1,0,0,0,54,51,1,0,0,0,55,58,1,0,0,0,56,54,1,0,
  	0,0,56,57,1,0,0,0,57,59,1,0,0,0,58,56,1,0,0,0,59,60,5,3,0,0,60,3,1,0,
  	0,0,61,62,5,25,0,0,62,63,5,40,0,0,63,5,1,0,0,0,64,65,5,39,0,0,65,67,5,
  	4,0,0,66,68,3,8,4,0,67,66,1,0,0,0,67,68,1,0,0,0,68,69,1,0,0,0,69,70,5,
  	6,0,0,70,71,5,7,0,0,71,72,5,40,0,0,72,73,5,2,0,0,73,74,3,12,6,0,74,75,
  	5,3,0,0,75,84,1,0,0,0,76,77,5,39,0,0,77,78,5,7,0,0,78,81,5,40,0,0,79,
  	80,5,18,0,0,80,82,3,12,6,0,81,79,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,0,
  	83,64,1,0,0,0,83,76,1,0,0,0,84,7,1,0,0,0,85,90,3,10,5,0,86,87,5,5,0,0,
  	87,89,3,10,5,0,88,86,1,0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,
  	0,91,9,1,0,0,0,92,90,1,0,0,0,93,94,5,39,0,0,94,95,5,7,0,0,95,96,5,40,
  	0,0,96,11,1,0,0,0,97,98,3,14,7,0,98,13,1,0,0,0,99,100,5,39,0,0,100,101,
  	5,18,0,0,101,104,3,14,7,0,102,104,3,16,8,0,103,99,1,0,0,0,103,102,1,0,
  	0,0,104,15,1,0,0,0,105,106,5,36,0,0,106,109,3,16,8,0,107,109,3,18,9,0,
  	108,105,1,0,0,0,108,107,1,0,0,0,109,17,1,0,0,0,110,113,3,20,10,0,111,
  	112,7,0,0,0,112,114,3,20,10,0,113,111,1,0,0,0,113,114,1,0,0,0,114,19,
  	1,0,0,0,115,120,3,22,11,0,116,117,7,1,0,0,117,119,3,22,11,0,118,116,1,
  	0,0,0,119,122,1,0,0,0,120,118,1,0,0,0,120,121,1,0,0,0,121,21,1,0,0,0,
  	122,120,1,0,0,0,123,128,3,24,12,0,124,125,7,2,0,0,125,127,3,24,12,0,126,
  	124,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,23,1,
  	0,0,0,130,128,1,0,0,0,131,132,5,26,0,0,132,137,3,24,12,0,133,134,5,14,
  	0,0,134,137,3,24,12,0,135,137,3,26,13,0,136,131,1,0,0,0,136,133,1,0,0,
  	0,136,135,1,0,0,0,137,25,1,0,0,0,138,152,3,30,15,0,139,140,5,8,0,0,140,
  	142,5,40,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,143,1,0,0,0,143,144,
  	5,9,0,0,144,145,5,39,0,0,145,147,5,4,0,0,146,148,3,28,14,0,147,146,1,
  	0,0,0,147,148,1,0,0,0,148,149,1,0,0,0,149,151,5,6,0,0,150,141,1,0,0,0,
  	151,154,1,0,0,0,152,150,1,0,0,0,152,153,1,0,0,0,153,27,1,0,0,0,154,152,
  	1,0,0,0,155,160,3,12,6,0,156,157,5,5,0,0,157,159,3,12,6,0,158,156,1,0,
  	0,0,159,162,1,0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,29,1,0,0,0,162,
  	160,1,0,0,0,163,164,5,23,0,0,164,165,3,12,6,0,165,166,5,30,0,0,166,167,
  	3,12,6,0,167,168,5,21,0,0,168,169,3,12,6,0,169,170,5,22,0,0,170,220,1,
  	0,0,0,171,172,5,31,0,0,172,173,3,12,6,0,173,174,5,28,0,0,174,175,3,12,
  	6,0,175,176,5,29,0,0,176,220,1,0,0,0,177,178,5,2,0,0,178,179,3,32,16,
  	0,179,180,5,3,0,0,180,220,1,0,0,0,181,182,5,27,0,0,182,187,3,36,18,0,
  	183,184,5,5,0,0,184,186,3,36,18,0,185,183,1,0,0,0,186,189,1,0,0,0,187,
  	185,1,0,0,0,187,188,1,0,0,0,188,190,1,0,0,0,189,187,1,0,0,0,190,191,5,
  	24,0,0,191,192,3,12,6,0,192,220,1,0,0,0,193,194,5,32,0,0,194,195,3,12,
  	6,0,195,197,5,35,0,0,196,198,3,34,17,0,197,196,1,0,0,0,198,199,1,0,0,
  	0,199,197,1,0,0,0,199,200,1,0,0,0,200,201,1,0,0,0,201,202,5,33,0,0,202,
  	220,1,0,0,0,203,204,5,34,0,0,204,220,5,40,0,0,205,206,5,4,0,0,206,207,
  	3,12,6,0,207,208,5,6,0,0,208,220,1,0,0,0,209,210,5,39,0,0,210,212,5,4,
  	0,0,211,213,3,28,14,0,212,211,1,0,0,0,212,213,1,0,0,0,213,214,1,0,0,0,
  	214,220,5,6,0,0,215,220,5,39,0,0,216,220,5,38,0,0,217,220,5,47,0,0,218,
  	220,5,37,0,0,219,163,1,0,0,0,219,171,1,0,0,0,219,177,1,0,0,0,219,181,
  	1,0,0,0,219,193,1,0,0,0,219,203,1,0,0,0,219,205,1,0,0,0,219,209,1,0,0,
  	0,219,215,1,0,0,0,219,216,1,0,0,0,219,217,1,0,0,0,219,218,1,0,0,0,220,
  	31,1,0,0,0,221,222,3,12,6,0,222,228,5,1,0,0,223,224,3,12,6,0,224,225,
  	5,1,0,0,225,227,1,0,0,0,226,223,1,0,0,0,227,230,1,0,0,0,228,226,1,0,0,
  	0,228,229,1,0,0,0,229,33,1,0,0,0,230,228,1,0,0,0,231,232,5,39,0,0,232,
  	233,5,7,0,0,233,234,5,40,0,0,234,235,5,17,0,0,235,236,3,12,6,0,236,237,
  	5,1,0,0,237,35,1,0,0,0,238,239,5,39,0,0,239,240,5,7,0,0,240,243,5,40,
  	0,0,241,242,5,18,0,0,242,244,3,12,6,0,243,241,1,0,0,0,243,244,1,0,0,0,
  	244,37,1,0,0,0,23,43,48,56,67,81,83,90,103,108,113,120,128,136,141,147,
  	152,160,187,199,212,219,228,243
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  coolparserParserStaticData = std::move(staticData);
}

}

CoolParser::CoolParser(TokenStream *input) : CoolParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CoolParser::CoolParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CoolParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *coolparserParserStaticData->atn, coolparserParserStaticData->decisionToDFA, coolparserParserStaticData->sharedContextCache, options);
}

CoolParser::~CoolParser() {
  delete _interpreter;
}

const atn::ATN& CoolParser::getATN() const {
  return *coolparserParserStaticData->atn;
}

std::string CoolParser::getGrammarFileName() const {
  return "CoolParser.g4";
}

const std::vector<std::string>& CoolParser::getRuleNames() const {
  return coolparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& CoolParser::getVocabulary() const {
  return coolparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CoolParser::getSerializedATN() const {
  return coolparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

CoolParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoolParser::ClassContext *> CoolParser::ProgramContext::class_() {
  return getRuleContexts<CoolParser::ClassContext>();
}

CoolParser::ClassContext* CoolParser::ProgramContext::class_(size_t i) {
  return getRuleContext<CoolParser::ClassContext>(i);
}

std::vector<tree::TerminalNode *> CoolParser::ProgramContext::SEMI() {
  return getTokens(CoolParser::SEMI);
}

tree::TerminalNode* CoolParser::ProgramContext::SEMI(size_t i) {
  return getToken(CoolParser::SEMI, i);
}


size_t CoolParser::ProgramContext::getRuleIndex() const {
  return CoolParser::RuleProgram;
}


std::any CoolParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::ProgramContext* CoolParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, CoolParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(38);
      class_();
      setState(39);
      match(CoolParser::SEMI);
      setState(43); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CoolParser::CLASS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassContext ------------------------------------------------------------------

CoolParser::ClassContext::ClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::ClassContext::CLASS() {
  return getToken(CoolParser::CLASS, 0);
}

tree::TerminalNode* CoolParser::ClassContext::TYPEID() {
  return getToken(CoolParser::TYPEID, 0);
}

tree::TerminalNode* CoolParser::ClassContext::OCURLY() {
  return getToken(CoolParser::OCURLY, 0);
}

tree::TerminalNode* CoolParser::ClassContext::CCURLY() {
  return getToken(CoolParser::CCURLY, 0);
}

CoolParser::InheritanceContext* CoolParser::ClassContext::inheritance() {
  return getRuleContext<CoolParser::InheritanceContext>(0);
}

std::vector<CoolParser::FeatureContext *> CoolParser::ClassContext::feature() {
  return getRuleContexts<CoolParser::FeatureContext>();
}

CoolParser::FeatureContext* CoolParser::ClassContext::feature(size_t i) {
  return getRuleContext<CoolParser::FeatureContext>(i);
}

std::vector<tree::TerminalNode *> CoolParser::ClassContext::SEMI() {
  return getTokens(CoolParser::SEMI);
}

tree::TerminalNode* CoolParser::ClassContext::SEMI(size_t i) {
  return getToken(CoolParser::SEMI, i);
}


size_t CoolParser::ClassContext::getRuleIndex() const {
  return CoolParser::RuleClass;
}


std::any CoolParser::ClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitClass(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::ClassContext* CoolParser::class_() {
  ClassContext *_localctx = _tracker.createInstance<ClassContext>(_ctx, getState());
  enterRule(_localctx, 2, CoolParser::RuleClass);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    match(CoolParser::CLASS);
    setState(46);
    match(CoolParser::TYPEID);
    setState(48);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoolParser::INHERITS) {
      setState(47);
      inheritance();
    }
    setState(50);
    match(CoolParser::OCURLY);
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoolParser::OBJECTID) {
      setState(51);
      feature();
      setState(52);
      match(CoolParser::SEMI);
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(59);
    match(CoolParser::CCURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InheritanceContext ------------------------------------------------------------------

CoolParser::InheritanceContext::InheritanceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::InheritanceContext::INHERITS() {
  return getToken(CoolParser::INHERITS, 0);
}

tree::TerminalNode* CoolParser::InheritanceContext::TYPEID() {
  return getToken(CoolParser::TYPEID, 0);
}


size_t CoolParser::InheritanceContext::getRuleIndex() const {
  return CoolParser::RuleInheritance;
}


std::any CoolParser::InheritanceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitInheritance(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::InheritanceContext* CoolParser::inheritance() {
  InheritanceContext *_localctx = _tracker.createInstance<InheritanceContext>(_ctx, getState());
  enterRule(_localctx, 4, CoolParser::RuleInheritance);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(CoolParser::INHERITS);
    setState(62);
    match(CoolParser::TYPEID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FeatureContext ------------------------------------------------------------------

CoolParser::FeatureContext::FeatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::FeatureContext::OBJECTID() {
  return getToken(CoolParser::OBJECTID, 0);
}

tree::TerminalNode* CoolParser::FeatureContext::OPAREN() {
  return getToken(CoolParser::OPAREN, 0);
}

tree::TerminalNode* CoolParser::FeatureContext::CPAREN() {
  return getToken(CoolParser::CPAREN, 0);
}

tree::TerminalNode* CoolParser::FeatureContext::COLON() {
  return getToken(CoolParser::COLON, 0);
}

tree::TerminalNode* CoolParser::FeatureContext::TYPEID() {
  return getToken(CoolParser::TYPEID, 0);
}

tree::TerminalNode* CoolParser::FeatureContext::OCURLY() {
  return getToken(CoolParser::OCURLY, 0);
}

CoolParser::ExprContext* CoolParser::FeatureContext::expr() {
  return getRuleContext<CoolParser::ExprContext>(0);
}

tree::TerminalNode* CoolParser::FeatureContext::CCURLY() {
  return getToken(CoolParser::CCURLY, 0);
}

CoolParser::Formal_listContext* CoolParser::FeatureContext::formal_list() {
  return getRuleContext<CoolParser::Formal_listContext>(0);
}

tree::TerminalNode* CoolParser::FeatureContext::ASSIGN() {
  return getToken(CoolParser::ASSIGN, 0);
}


size_t CoolParser::FeatureContext::getRuleIndex() const {
  return CoolParser::RuleFeature;
}


std::any CoolParser::FeatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitFeature(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::FeatureContext* CoolParser::feature() {
  FeatureContext *_localctx = _tracker.createInstance<FeatureContext>(_ctx, getState());
  enterRule(_localctx, 6, CoolParser::RuleFeature);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      match(CoolParser::OBJECTID);
      setState(65);
      match(CoolParser::OPAREN);
      setState(67);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoolParser::OBJECTID) {
        setState(66);
        formal_list();
      }
      setState(69);
      match(CoolParser::CPAREN);
      setState(70);
      match(CoolParser::COLON);
      setState(71);
      match(CoolParser::TYPEID);
      setState(72);
      match(CoolParser::OCURLY);
      setState(73);
      expr();
      setState(74);
      match(CoolParser::CCURLY);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(76);
      match(CoolParser::OBJECTID);
      setState(77);
      match(CoolParser::COLON);
      setState(78);
      match(CoolParser::TYPEID);
      setState(81);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CoolParser::ASSIGN) {
        setState(79);
        match(CoolParser::ASSIGN);
        setState(80);
        expr();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formal_listContext ------------------------------------------------------------------

CoolParser::Formal_listContext::Formal_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoolParser::FormalContext *> CoolParser::Formal_listContext::formal() {
  return getRuleContexts<CoolParser::FormalContext>();
}

CoolParser::FormalContext* CoolParser::Formal_listContext::formal(size_t i) {
  return getRuleContext<CoolParser::FormalContext>(i);
}

std::vector<tree::TerminalNode *> CoolParser::Formal_listContext::COMMA() {
  return getTokens(CoolParser::COMMA);
}

tree::TerminalNode* CoolParser::Formal_listContext::COMMA(size_t i) {
  return getToken(CoolParser::COMMA, i);
}


size_t CoolParser::Formal_listContext::getRuleIndex() const {
  return CoolParser::RuleFormal_list;
}


std::any CoolParser::Formal_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitFormal_list(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::Formal_listContext* CoolParser::formal_list() {
  Formal_listContext *_localctx = _tracker.createInstance<Formal_listContext>(_ctx, getState());
  enterRule(_localctx, 8, CoolParser::RuleFormal_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    formal();
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoolParser::COMMA) {
      setState(86);
      match(CoolParser::COMMA);
      setState(87);
      formal();
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalContext ------------------------------------------------------------------

CoolParser::FormalContext::FormalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::FormalContext::OBJECTID() {
  return getToken(CoolParser::OBJECTID, 0);
}

tree::TerminalNode* CoolParser::FormalContext::COLON() {
  return getToken(CoolParser::COLON, 0);
}

tree::TerminalNode* CoolParser::FormalContext::TYPEID() {
  return getToken(CoolParser::TYPEID, 0);
}


size_t CoolParser::FormalContext::getRuleIndex() const {
  return CoolParser::RuleFormal;
}


std::any CoolParser::FormalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitFormal(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::FormalContext* CoolParser::formal() {
  FormalContext *_localctx = _tracker.createInstance<FormalContext>(_ctx, getState());
  enterRule(_localctx, 10, CoolParser::RuleFormal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(CoolParser::OBJECTID);
    setState(94);
    match(CoolParser::COLON);
    setState(95);
    match(CoolParser::TYPEID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

CoolParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoolParser::AssignExprContext* CoolParser::ExprContext::assignExpr() {
  return getRuleContext<CoolParser::AssignExprContext>(0);
}


size_t CoolParser::ExprContext::getRuleIndex() const {
  return CoolParser::RuleExpr;
}


std::any CoolParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::ExprContext* CoolParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 12, CoolParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    assignExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignExprContext ------------------------------------------------------------------

CoolParser::AssignExprContext::AssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::AssignExprContext::OBJECTID() {
  return getToken(CoolParser::OBJECTID, 0);
}

tree::TerminalNode* CoolParser::AssignExprContext::ASSIGN() {
  return getToken(CoolParser::ASSIGN, 0);
}

CoolParser::AssignExprContext* CoolParser::AssignExprContext::assignExpr() {
  return getRuleContext<CoolParser::AssignExprContext>(0);
}

CoolParser::NotExprContext* CoolParser::AssignExprContext::notExpr() {
  return getRuleContext<CoolParser::NotExprContext>(0);
}


size_t CoolParser::AssignExprContext::getRuleIndex() const {
  return CoolParser::RuleAssignExpr;
}


std::any CoolParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::AssignExprContext* CoolParser::assignExpr() {
  AssignExprContext *_localctx = _tracker.createInstance<AssignExprContext>(_ctx, getState());
  enterRule(_localctx, 14, CoolParser::RuleAssignExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(99);
      match(CoolParser::OBJECTID);
      setState(100);
      match(CoolParser::ASSIGN);
      setState(101);
      assignExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(102);
      notExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotExprContext ------------------------------------------------------------------

CoolParser::NotExprContext::NotExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::NotExprContext::NOT() {
  return getToken(CoolParser::NOT, 0);
}

CoolParser::NotExprContext* CoolParser::NotExprContext::notExpr() {
  return getRuleContext<CoolParser::NotExprContext>(0);
}

CoolParser::CompareExprContext* CoolParser::NotExprContext::compareExpr() {
  return getRuleContext<CoolParser::CompareExprContext>(0);
}


size_t CoolParser::NotExprContext::getRuleIndex() const {
  return CoolParser::RuleNotExpr;
}


std::any CoolParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::NotExprContext* CoolParser::notExpr() {
  NotExprContext *_localctx = _tracker.createInstance<NotExprContext>(_ctx, getState());
  enterRule(_localctx, 16, CoolParser::RuleNotExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoolParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(105);
        match(CoolParser::NOT);
        setState(106);
        notExpr();
        break;
      }

      case CoolParser::OCURLY:
      case CoolParser::OPAREN:
      case CoolParser::TILDE:
      case CoolParser::IF:
      case CoolParser::ISVOID:
      case CoolParser::LET:
      case CoolParser::WHILE:
      case CoolParser::CASE:
      case CoolParser::NEW:
      case CoolParser::BOOL_CONST:
      case CoolParser::INT_CONST:
      case CoolParser::OBJECTID:
      case CoolParser::STR_CONST: {
        enterOuterAlt(_localctx, 2);
        setState(107);
        compareExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompareExprContext ------------------------------------------------------------------

CoolParser::CompareExprContext::CompareExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoolParser::ArithExprContext *> CoolParser::CompareExprContext::arithExpr() {
  return getRuleContexts<CoolParser::ArithExprContext>();
}

CoolParser::ArithExprContext* CoolParser::CompareExprContext::arithExpr(size_t i) {
  return getRuleContext<CoolParser::ArithExprContext>(i);
}

tree::TerminalNode* CoolParser::CompareExprContext::LT() {
  return getToken(CoolParser::LT, 0);
}

tree::TerminalNode* CoolParser::CompareExprContext::LE() {
  return getToken(CoolParser::LE, 0);
}

tree::TerminalNode* CoolParser::CompareExprContext::EQ() {
  return getToken(CoolParser::EQ, 0);
}


size_t CoolParser::CompareExprContext::getRuleIndex() const {
  return CoolParser::RuleCompareExpr;
}


std::any CoolParser::CompareExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitCompareExpr(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::CompareExprContext* CoolParser::compareExpr() {
  CompareExprContext *_localctx = _tracker.createInstance<CompareExprContext>(_ctx, getState());
  enterRule(_localctx, 18, CoolParser::RuleCompareExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    arithExpr();
    setState(113);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(111);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 622592) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(112);
      arithExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArithExprContext ------------------------------------------------------------------

CoolParser::ArithExprContext::ArithExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoolParser::TermContext *> CoolParser::ArithExprContext::term() {
  return getRuleContexts<CoolParser::TermContext>();
}

CoolParser::TermContext* CoolParser::ArithExprContext::term(size_t i) {
  return getRuleContext<CoolParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> CoolParser::ArithExprContext::PLUS() {
  return getTokens(CoolParser::PLUS);
}

tree::TerminalNode* CoolParser::ArithExprContext::PLUS(size_t i) {
  return getToken(CoolParser::PLUS, i);
}

std::vector<tree::TerminalNode *> CoolParser::ArithExprContext::MINUS() {
  return getTokens(CoolParser::MINUS);
}

tree::TerminalNode* CoolParser::ArithExprContext::MINUS(size_t i) {
  return getToken(CoolParser::MINUS, i);
}


size_t CoolParser::ArithExprContext::getRuleIndex() const {
  return CoolParser::RuleArithExpr;
}


std::any CoolParser::ArithExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitArithExpr(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::ArithExprContext* CoolParser::arithExpr() {
  ArithExprContext *_localctx = _tracker.createInstance<ArithExprContext>(_ctx, getState());
  enterRule(_localctx, 20, CoolParser::RuleArithExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(115);
    term();
    setState(120);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(116);
        _la = _input->LA(1);
        if (!(_la == CoolParser::PLUS

        || _la == CoolParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(117);
        term(); 
      }
      setState(122);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

CoolParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoolParser::FactorContext *> CoolParser::TermContext::factor() {
  return getRuleContexts<CoolParser::FactorContext>();
}

CoolParser::FactorContext* CoolParser::TermContext::factor(size_t i) {
  return getRuleContext<CoolParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> CoolParser::TermContext::STAR() {
  return getTokens(CoolParser::STAR);
}

tree::TerminalNode* CoolParser::TermContext::STAR(size_t i) {
  return getToken(CoolParser::STAR, i);
}

std::vector<tree::TerminalNode *> CoolParser::TermContext::SLASH() {
  return getTokens(CoolParser::SLASH);
}

tree::TerminalNode* CoolParser::TermContext::SLASH(size_t i) {
  return getToken(CoolParser::SLASH, i);
}


size_t CoolParser::TermContext::getRuleIndex() const {
  return CoolParser::RuleTerm;
}


std::any CoolParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::TermContext* CoolParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 22, CoolParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(123);
    factor();
    setState(128);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(124);
        _la = _input->LA(1);
        if (!(_la == CoolParser::STAR

        || _la == CoolParser::SLASH)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(125);
        factor(); 
      }
      setState(130);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

CoolParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::FactorContext::ISVOID() {
  return getToken(CoolParser::ISVOID, 0);
}

CoolParser::FactorContext* CoolParser::FactorContext::factor() {
  return getRuleContext<CoolParser::FactorContext>(0);
}

tree::TerminalNode* CoolParser::FactorContext::TILDE() {
  return getToken(CoolParser::TILDE, 0);
}

CoolParser::DispatchExprContext* CoolParser::FactorContext::dispatchExpr() {
  return getRuleContext<CoolParser::DispatchExprContext>(0);
}


size_t CoolParser::FactorContext::getRuleIndex() const {
  return CoolParser::RuleFactor;
}


std::any CoolParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::FactorContext* CoolParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 24, CoolParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CoolParser::ISVOID: {
        enterOuterAlt(_localctx, 1);
        setState(131);
        match(CoolParser::ISVOID);
        setState(132);
        factor();
        break;
      }

      case CoolParser::TILDE: {
        enterOuterAlt(_localctx, 2);
        setState(133);
        match(CoolParser::TILDE);
        setState(134);
        factor();
        break;
      }

      case CoolParser::OCURLY:
      case CoolParser::OPAREN:
      case CoolParser::IF:
      case CoolParser::LET:
      case CoolParser::WHILE:
      case CoolParser::CASE:
      case CoolParser::NEW:
      case CoolParser::BOOL_CONST:
      case CoolParser::INT_CONST:
      case CoolParser::OBJECTID:
      case CoolParser::STR_CONST: {
        enterOuterAlt(_localctx, 3);
        setState(135);
        dispatchExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DispatchExprContext ------------------------------------------------------------------

CoolParser::DispatchExprContext::DispatchExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CoolParser::PrimaryContext* CoolParser::DispatchExprContext::primary() {
  return getRuleContext<CoolParser::PrimaryContext>(0);
}

std::vector<tree::TerminalNode *> CoolParser::DispatchExprContext::DOT() {
  return getTokens(CoolParser::DOT);
}

tree::TerminalNode* CoolParser::DispatchExprContext::DOT(size_t i) {
  return getToken(CoolParser::DOT, i);
}

std::vector<tree::TerminalNode *> CoolParser::DispatchExprContext::OBJECTID() {
  return getTokens(CoolParser::OBJECTID);
}

tree::TerminalNode* CoolParser::DispatchExprContext::OBJECTID(size_t i) {
  return getToken(CoolParser::OBJECTID, i);
}

std::vector<tree::TerminalNode *> CoolParser::DispatchExprContext::OPAREN() {
  return getTokens(CoolParser::OPAREN);
}

tree::TerminalNode* CoolParser::DispatchExprContext::OPAREN(size_t i) {
  return getToken(CoolParser::OPAREN, i);
}

std::vector<tree::TerminalNode *> CoolParser::DispatchExprContext::CPAREN() {
  return getTokens(CoolParser::CPAREN);
}

tree::TerminalNode* CoolParser::DispatchExprContext::CPAREN(size_t i) {
  return getToken(CoolParser::CPAREN, i);
}

std::vector<tree::TerminalNode *> CoolParser::DispatchExprContext::AT() {
  return getTokens(CoolParser::AT);
}

tree::TerminalNode* CoolParser::DispatchExprContext::AT(size_t i) {
  return getToken(CoolParser::AT, i);
}

std::vector<tree::TerminalNode *> CoolParser::DispatchExprContext::TYPEID() {
  return getTokens(CoolParser::TYPEID);
}

tree::TerminalNode* CoolParser::DispatchExprContext::TYPEID(size_t i) {
  return getToken(CoolParser::TYPEID, i);
}

std::vector<CoolParser::Arg_listContext *> CoolParser::DispatchExprContext::arg_list() {
  return getRuleContexts<CoolParser::Arg_listContext>();
}

CoolParser::Arg_listContext* CoolParser::DispatchExprContext::arg_list(size_t i) {
  return getRuleContext<CoolParser::Arg_listContext>(i);
}


size_t CoolParser::DispatchExprContext::getRuleIndex() const {
  return CoolParser::RuleDispatchExpr;
}


std::any CoolParser::DispatchExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitDispatchExpr(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::DispatchExprContext* CoolParser::dispatchExpr() {
  DispatchExprContext *_localctx = _tracker.createInstance<DispatchExprContext>(_ctx, getState());
  enterRule(_localctx, 26, CoolParser::RuleDispatchExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(138);
    primary();
    setState(152);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(141);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CoolParser::AT) {
          setState(139);
          match(CoolParser::AT);
          setState(140);
          match(CoolParser::TYPEID);
        }
        setState(143);
        match(CoolParser::DOT);
        setState(144);
        match(CoolParser::OBJECTID);
        setState(145);
        match(CoolParser::OPAREN);
        setState(147);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 141792112558100) != 0)) {
          setState(146);
          arg_list();
        }
        setState(149);
        match(CoolParser::CPAREN); 
      }
      setState(154);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arg_listContext ------------------------------------------------------------------

CoolParser::Arg_listContext::Arg_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoolParser::ExprContext *> CoolParser::Arg_listContext::expr() {
  return getRuleContexts<CoolParser::ExprContext>();
}

CoolParser::ExprContext* CoolParser::Arg_listContext::expr(size_t i) {
  return getRuleContext<CoolParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> CoolParser::Arg_listContext::COMMA() {
  return getTokens(CoolParser::COMMA);
}

tree::TerminalNode* CoolParser::Arg_listContext::COMMA(size_t i) {
  return getToken(CoolParser::COMMA, i);
}


size_t CoolParser::Arg_listContext::getRuleIndex() const {
  return CoolParser::RuleArg_list;
}


std::any CoolParser::Arg_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitArg_list(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::Arg_listContext* CoolParser::arg_list() {
  Arg_listContext *_localctx = _tracker.createInstance<Arg_listContext>(_ctx, getState());
  enterRule(_localctx, 28, CoolParser::RuleArg_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    expr();
    setState(160);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CoolParser::COMMA) {
      setState(156);
      match(CoolParser::COMMA);
      setState(157);
      expr();
      setState(162);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

CoolParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::PrimaryContext::IF() {
  return getToken(CoolParser::IF, 0);
}

std::vector<CoolParser::ExprContext *> CoolParser::PrimaryContext::expr() {
  return getRuleContexts<CoolParser::ExprContext>();
}

CoolParser::ExprContext* CoolParser::PrimaryContext::expr(size_t i) {
  return getRuleContext<CoolParser::ExprContext>(i);
}

tree::TerminalNode* CoolParser::PrimaryContext::THEN() {
  return getToken(CoolParser::THEN, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::ELSE() {
  return getToken(CoolParser::ELSE, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::FI() {
  return getToken(CoolParser::FI, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::WHILE() {
  return getToken(CoolParser::WHILE, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::LOOP() {
  return getToken(CoolParser::LOOP, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::POOL() {
  return getToken(CoolParser::POOL, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::OCURLY() {
  return getToken(CoolParser::OCURLY, 0);
}

CoolParser::Block_exprContext* CoolParser::PrimaryContext::block_expr() {
  return getRuleContext<CoolParser::Block_exprContext>(0);
}

tree::TerminalNode* CoolParser::PrimaryContext::CCURLY() {
  return getToken(CoolParser::CCURLY, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::LET() {
  return getToken(CoolParser::LET, 0);
}

std::vector<CoolParser::Let_bindingContext *> CoolParser::PrimaryContext::let_binding() {
  return getRuleContexts<CoolParser::Let_bindingContext>();
}

CoolParser::Let_bindingContext* CoolParser::PrimaryContext::let_binding(size_t i) {
  return getRuleContext<CoolParser::Let_bindingContext>(i);
}

tree::TerminalNode* CoolParser::PrimaryContext::IN() {
  return getToken(CoolParser::IN, 0);
}

std::vector<tree::TerminalNode *> CoolParser::PrimaryContext::COMMA() {
  return getTokens(CoolParser::COMMA);
}

tree::TerminalNode* CoolParser::PrimaryContext::COMMA(size_t i) {
  return getToken(CoolParser::COMMA, i);
}

tree::TerminalNode* CoolParser::PrimaryContext::CASE() {
  return getToken(CoolParser::CASE, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::OF() {
  return getToken(CoolParser::OF, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::ESAC() {
  return getToken(CoolParser::ESAC, 0);
}

std::vector<CoolParser::BranchContext *> CoolParser::PrimaryContext::branch() {
  return getRuleContexts<CoolParser::BranchContext>();
}

CoolParser::BranchContext* CoolParser::PrimaryContext::branch(size_t i) {
  return getRuleContext<CoolParser::BranchContext>(i);
}

tree::TerminalNode* CoolParser::PrimaryContext::NEW() {
  return getToken(CoolParser::NEW, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::TYPEID() {
  return getToken(CoolParser::TYPEID, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::OPAREN() {
  return getToken(CoolParser::OPAREN, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::CPAREN() {
  return getToken(CoolParser::CPAREN, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::OBJECTID() {
  return getToken(CoolParser::OBJECTID, 0);
}

CoolParser::Arg_listContext* CoolParser::PrimaryContext::arg_list() {
  return getRuleContext<CoolParser::Arg_listContext>(0);
}

tree::TerminalNode* CoolParser::PrimaryContext::INT_CONST() {
  return getToken(CoolParser::INT_CONST, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::STR_CONST() {
  return getToken(CoolParser::STR_CONST, 0);
}

tree::TerminalNode* CoolParser::PrimaryContext::BOOL_CONST() {
  return getToken(CoolParser::BOOL_CONST, 0);
}


size_t CoolParser::PrimaryContext::getRuleIndex() const {
  return CoolParser::RulePrimary;
}


std::any CoolParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::PrimaryContext* CoolParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 30, CoolParser::RulePrimary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      match(CoolParser::IF);
      setState(164);
      expr();
      setState(165);
      match(CoolParser::THEN);
      setState(166);
      expr();
      setState(167);
      match(CoolParser::ELSE);
      setState(168);
      expr();
      setState(169);
      match(CoolParser::FI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(171);
      match(CoolParser::WHILE);
      setState(172);
      expr();
      setState(173);
      match(CoolParser::LOOP);
      setState(174);
      expr();
      setState(175);
      match(CoolParser::POOL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(177);
      match(CoolParser::OCURLY);
      setState(178);
      block_expr();
      setState(179);
      match(CoolParser::CCURLY);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(181);
      match(CoolParser::LET);
      setState(182);
      let_binding();
      setState(187);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CoolParser::COMMA) {
        setState(183);
        match(CoolParser::COMMA);
        setState(184);
        let_binding();
        setState(189);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(190);
      match(CoolParser::IN);
      setState(191);
      expr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(193);
      match(CoolParser::CASE);
      setState(194);
      expr();
      setState(195);
      match(CoolParser::OF);
      setState(197); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(196);
        branch();
        setState(199); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == CoolParser::OBJECTID);
      setState(201);
      match(CoolParser::ESAC);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(203);
      match(CoolParser::NEW);
      setState(204);
      match(CoolParser::TYPEID);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(205);
      match(CoolParser::OPAREN);
      setState(206);
      expr();
      setState(207);
      match(CoolParser::CPAREN);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(209);
      match(CoolParser::OBJECTID);
      setState(210);
      match(CoolParser::OPAREN);
      setState(212);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 141792112558100) != 0)) {
        setState(211);
        arg_list();
      }
      setState(214);
      match(CoolParser::CPAREN);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(215);
      match(CoolParser::OBJECTID);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(216);
      match(CoolParser::INT_CONST);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(217);
      match(CoolParser::STR_CONST);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(218);
      match(CoolParser::BOOL_CONST);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_exprContext ------------------------------------------------------------------

CoolParser::Block_exprContext::Block_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoolParser::ExprContext *> CoolParser::Block_exprContext::expr() {
  return getRuleContexts<CoolParser::ExprContext>();
}

CoolParser::ExprContext* CoolParser::Block_exprContext::expr(size_t i) {
  return getRuleContext<CoolParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> CoolParser::Block_exprContext::SEMI() {
  return getTokens(CoolParser::SEMI);
}

tree::TerminalNode* CoolParser::Block_exprContext::SEMI(size_t i) {
  return getToken(CoolParser::SEMI, i);
}


size_t CoolParser::Block_exprContext::getRuleIndex() const {
  return CoolParser::RuleBlock_expr;
}


std::any CoolParser::Block_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitBlock_expr(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::Block_exprContext* CoolParser::block_expr() {
  Block_exprContext *_localctx = _tracker.createInstance<Block_exprContext>(_ctx, getState());
  enterRule(_localctx, 32, CoolParser::RuleBlock_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    expr();
    setState(222);
    match(CoolParser::SEMI);
    setState(228);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 141792112558100) != 0)) {
      setState(223);
      expr();
      setState(224);
      match(CoolParser::SEMI);
      setState(230);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchContext ------------------------------------------------------------------

CoolParser::BranchContext::BranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::BranchContext::OBJECTID() {
  return getToken(CoolParser::OBJECTID, 0);
}

tree::TerminalNode* CoolParser::BranchContext::COLON() {
  return getToken(CoolParser::COLON, 0);
}

tree::TerminalNode* CoolParser::BranchContext::TYPEID() {
  return getToken(CoolParser::TYPEID, 0);
}

tree::TerminalNode* CoolParser::BranchContext::DARROW() {
  return getToken(CoolParser::DARROW, 0);
}

CoolParser::ExprContext* CoolParser::BranchContext::expr() {
  return getRuleContext<CoolParser::ExprContext>(0);
}

tree::TerminalNode* CoolParser::BranchContext::SEMI() {
  return getToken(CoolParser::SEMI, 0);
}


size_t CoolParser::BranchContext::getRuleIndex() const {
  return CoolParser::RuleBranch;
}


std::any CoolParser::BranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitBranch(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::BranchContext* CoolParser::branch() {
  BranchContext *_localctx = _tracker.createInstance<BranchContext>(_ctx, getState());
  enterRule(_localctx, 34, CoolParser::RuleBranch);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    match(CoolParser::OBJECTID);
    setState(232);
    match(CoolParser::COLON);
    setState(233);
    match(CoolParser::TYPEID);
    setState(234);
    match(CoolParser::DARROW);
    setState(235);
    expr();
    setState(236);
    match(CoolParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Let_bindingContext ------------------------------------------------------------------

CoolParser::Let_bindingContext::Let_bindingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::Let_bindingContext::OBJECTID() {
  return getToken(CoolParser::OBJECTID, 0);
}

tree::TerminalNode* CoolParser::Let_bindingContext::COLON() {
  return getToken(CoolParser::COLON, 0);
}

tree::TerminalNode* CoolParser::Let_bindingContext::TYPEID() {
  return getToken(CoolParser::TYPEID, 0);
}

tree::TerminalNode* CoolParser::Let_bindingContext::ASSIGN() {
  return getToken(CoolParser::ASSIGN, 0);
}

CoolParser::ExprContext* CoolParser::Let_bindingContext::expr() {
  return getRuleContext<CoolParser::ExprContext>(0);
}


size_t CoolParser::Let_bindingContext::getRuleIndex() const {
  return CoolParser::RuleLet_binding;
}


std::any CoolParser::Let_bindingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitLet_binding(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::Let_bindingContext* CoolParser::let_binding() {
  Let_bindingContext *_localctx = _tracker.createInstance<Let_bindingContext>(_ctx, getState());
  enterRule(_localctx, 36, CoolParser::RuleLet_binding);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(CoolParser::OBJECTID);
    setState(239);
    match(CoolParser::COLON);
    setState(240);
    match(CoolParser::TYPEID);
    setState(243);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CoolParser::ASSIGN) {
      setState(241);
      match(CoolParser::ASSIGN);
      setState(242);
      expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void CoolParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  coolparserParserInitialize();
#else
  ::antlr4::internal::call_once(coolparserParserOnceFlag, coolparserParserInitialize);
#endif
}
