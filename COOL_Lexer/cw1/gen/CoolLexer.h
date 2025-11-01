
// Generated from /home/student/my-code/COOL_Lexer/cw1/tools/../src/CoolLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  CoolLexer : public antlr4::Lexer {
public:
  enum {
    STR_CONST = 1, ERROR = 2, ASSIGN = 3, LE = 4, LT = 5, EQUALS = 6, DARROW = 7, 
    LPAREN = 8, RPAREN = 9, LBRACE = 10, RBRACE = 11, PLUS = 12, MINUS = 13, 
    MULT = 14, DIV = 15, COMMA = 16, COLON = 17, SEMI = 18, DOT = 19, AT = 20, 
    TILDE = 21, BOOL_CONST = 22, INT_CONST = 23, STRING_START = 24, LINE_COMMENT = 25, 
    COMM_BEGIN = 26, COMM_ERR1 = 27, CASE = 28, CLASS = 29, ELSE = 30, ESAC = 31, 
    FI = 32, IF = 33, IN = 34, INHERITS = 35, ISVOID = 36, LET = 37, LOOP = 38, 
    NEW = 39, NOT = 40, OF = 41, POOL = 42, THEN = 43, WHILE = 44, TYPEID = 45, 
    OBJECTID = 46, WS = 47, INVALID = 48, MULTI_COMMENT_START = 49, MULTI_COMMENT_END = 50, 
    MULTI_COMMENT_BODY = 51, MULTI_COMMENT_ERROR = 52, STRING_END = 53, 
    STRING_CHAR_BEFORE_EOF = 54, STRING_ESC_NL = 55, STRING_ESCAPED_NUL = 56, 
    STRING_ESC_STD = 57, STRING_ESC_OTHER = 58, STRING_CHAR = 59, STRING_NUL = 60, 
    STRING_UNESCAPED_NL = 61, STRING_EOF = 62, TRASH_QUOTE = 63, TRASH_ANY = 64
  };

  enum {
    MULTI_COMMENT = 1, STRING = 2, STRING_TRASH = 3
  };

  explicit CoolLexer(antlr4::CharStream *input);

  ~CoolLexer() override;


      const unsigned MAX_STR_CONST = 1024;
      std::vector<char> string_buffer;

      enum class ErrorCode {
          UNMATCHED_COMMENT_END,
          COMMENT_CONTAINS_EOF,
          STRING_TOO_LONG,
          STRING_CONTAINS_NULL_CHAR,
          STRING_CONTAINS_ESCAPED_NULL_CHAR,
          STRING_CONTAINS_UNESCAPED_NL,
          STRING_CONTAINS_EOF
      };

      static std::string error_message(ErrorCode code) {
          switch (code) {
              case ErrorCode::UNMATCHED_COMMENT_END: return "Unmatched *)";
              case ErrorCode::COMMENT_CONTAINS_EOF: return "EOF in comment";
              case ErrorCode::STRING_TOO_LONG: return "String constant too long";
              case ErrorCode::STRING_CONTAINS_NULL_CHAR: return "String contains null character";
              case ErrorCode::STRING_CONTAINS_ESCAPED_NULL_CHAR: return "String contains escaped null character";
              case ErrorCode::STRING_CONTAINS_UNESCAPED_NL: return "String contains unescaped new line";
              case ErrorCode::STRING_CONTAINS_EOF: return "Unterminated string at EOF";
          }
          return "Unknown error";
      }

      void register_error(ErrorCode code) {
          setText(error_message(code));
          setType(ERROR);
      }

      static std::string fmt_invalid_symbol(unsigned char c) {
          if (c < 0x20 || c == 0x7F) {
              char buf[16];
              std::snprintf(buf, sizeof(buf), "<0x%02X>", c);
              return std::string("Invalid symbol \"") + buf + "\"";
          }
          if (c == '\\') return "Invalid symbol \"\\\\\"";
          if (c == '\"') return "Invalid symbol \"\\\"\"";
          return std::string("Invalid symbol \"") + static_cast<char>(c) + "\"";
      }

      std::string quote_and_escape(const std::vector<char>& buf) {
          std::string out;
          out.reserve(buf.size() + 2);
          out.push_back('"');
          for (unsigned char c : buf) {
              switch (c) {
                  case '\\': out += "\\\\"; break;
                  case '\"': out += "\\\""; break;
                  case '\n': out += "\\n"; break;
                  case '\t': out += "\\t"; break;
                  case '\b': out += "\\b"; break;
                  case '\f': out += "\\f"; break;
                  default:
                      if (c < 0x20 || c == 0x7F) {
                          char buf16[16];
                          std::snprintf(buf16, sizeof(buf16), "<0x%02x>", c);
                          out += buf16;
                      } else {
                          out.push_back(static_cast<char>(c));
                      }
                      break;
              }
          }
          out.push_back('"');
          return out;
      }

      std::map<int, bool> bool_values;

      void assoc_bool_with_token(bool value) {
          bool_values[tokenStartCharIndex] = value;
      }

      bool get_bool_value(int token_start_char_index) {
          return bool_values.at(token_start_char_index);
      }


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void BOOL_CONSTAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_STARTAction(antlr4::RuleContext *context, size_t actionIndex);
  void COMM_ERR1Action(antlr4::RuleContext *context, size_t actionIndex);
  void INVALIDAction(antlr4::RuleContext *context, size_t actionIndex);
  void MULTI_COMMENT_ERRORAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ENDAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_CHAR_BEFORE_EOFAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ESC_NLAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ESCAPED_NULAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ESC_STDAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ESC_OTHERAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_CHARAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_NULAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_UNESCAPED_NLAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_EOFAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

