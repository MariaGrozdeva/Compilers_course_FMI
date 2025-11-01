lexer grammar CoolLexer;

tokens { STR_CONST, ERROR }

@lexer::members {
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
}

// --------------- tokens -------------------

ASSIGN : '<-' ;
LE     : '<=' ;
LT     : '<' ;
EQUALS : '=' ;
DARROW : '=>' ;
LPAREN : '(' ;
RPAREN : ')' ;
LBRACE : '{' ;
RBRACE : '}' ;
PLUS   : '+' ;
MINUS  : '-' ;
MULT   : '*' ;
DIV    : '/' ;
COMMA  : ',' ;
COLON  : ':' ;
SEMI   : ';' ;
DOT    : '.' ;
AT     : '@' ;
TILDE  : '~' ;

// --------------- boolean constants -------------------

BOOL_CONST
    : 't'[rR][uU][eE] { assoc_bool_with_token(true); }
    | 'f'[aA][lL][sS][eE] { assoc_bool_with_token(false); }
    ;

// --------------- integer constants -------------------

INT_CONST : [0-9]+ ;

// --------------- string constants -------------------

STRING_START
    : '"' { string_buffer.clear(); pushMode(STRING); } -> skip
    ;

// --------------- comments -------------------

LINE_COMMENT : '--' ~[\n]* ( '\r'? '\n' | EOF ) -> skip ;

COMM_BEGIN : '(*' -> pushMode(MULTI_COMMENT), skip ;
COMM_ERR1  : '*)' { register_error(ErrorCode::UNMATCHED_COMMENT_END); } ;

// --------------- keywords -------------------

CASE     : [cC][aA][sS][eE] ;
CLASS    : [cC][lL][aA][sS][sS] ;
ELSE     : [eE][lL][sS][eE] ;
ESAC     : [eE][sS][aA][cC] ;
FI       : [fF][iI] ;
IF       : [iI][fF] ;
IN       : [iI][nN] ;
INHERITS : [iI][nN][hH][eE][rR][iI][tT][sS] ;
ISVOID   : [iI][sS][vV][oO][iI][dD] ;
LET      : [lL][eE][tT] ;
LOOP     : [lL][oO][oO][pP] ;
NEW      : [nN][eE][wW] ;
NOT      : [nN][oO][tT] ;
OF       : [oO][fF] ;
POOL     : [pP][oO][oO][lL] ;
THEN     : [tT][hH][eE][nN] ;
WHILE    : [wW][hH][iI][lL][eE] ;

TYPEID   : [A-Z][a-zA-Z0-9_]* ;
OBJECTID : [a-z][a-zA-Z0-9_]* ;

WS : [ \t\r\n\f]+ -> skip ;

INVALID
    : . {
        setText(fmt_invalid_symbol(static_cast<unsigned char>(getText()[0])));
        setType(ERROR);
      }
    ;

mode MULTI_COMMENT;

MULTI_COMMENT_START : '(*' -> pushMode(MULTI_COMMENT), skip ;
MULTI_COMMENT_END   : '*)' -> popMode, skip ;
MULTI_COMMENT_BODY  : .    -> skip ;
MULTI_COMMENT_ERROR : . EOF { register_error(ErrorCode::COMMENT_CONTAINS_EOF); } ;

mode STRING;

STRING_END
  : '"' {
      if (string_buffer.size() > MAX_STR_CONST) {
        register_error(ErrorCode::STRING_TOO_LONG);
      } else {
        setText(quote_and_escape(string_buffer));
        setType(STR_CONST);
      }
      popMode();
    }
  ;

STRING_CHAR_BEFORE_EOF
  : ~["\\\n\u0000\r] EOF {
      register_error(ErrorCode::STRING_CONTAINS_EOF);
      popMode();
    }
  ;

STRING_ESC_NL
  : '\\' '\r'? '\n' { string_buffer.push_back('\n'); } -> skip
  ;

STRING_ESCAPED_NUL
  : '\\' '\u0000' {
      register_error(ErrorCode::STRING_CONTAINS_ESCAPED_NULL_CHAR);
      pushMode(STRING_TRASH);
    }
  ;

STRING_ESC_STD
  : '\\' [btnf"\\] {
      switch (getText()[1]) {
        case 'b': string_buffer.push_back('\b'); break;
        case 't': string_buffer.push_back('\t'); break;
        case 'n': string_buffer.push_back('\n'); break;
        case 'f': string_buffer.push_back('\f'); break;
        case '"': string_buffer.push_back('"');  break;
        case '\\': string_buffer.push_back('\\'); break;
      }
    } -> skip
  ;

STRING_ESC_OTHER
  : '\\' . { string_buffer.push_back(getText()[1]); } -> skip
  ;

STRING_CHAR
  : ~["\\\n\u0000] { string_buffer.push_back(getText()[0]); } -> skip
  ;

STRING_NUL
  : '\u0000' {
      register_error(ErrorCode::STRING_CONTAINS_NULL_CHAR);
      pushMode(STRING_TRASH);
    }
  ;

STRING_UNESCAPED_NL
  : '\r'? '\n' {
      register_error(ErrorCode::STRING_CONTAINS_UNESCAPED_NL);
      popMode();
    }
  ;

STRING_EOF
  : EOF {
      setText("Unterminated string at EOF");
      setType(ERROR);
      popMode();
    }
  ;

mode STRING_TRASH;

TRASH_QUOTE : '"' -> popMode, popMode, skip ;
TRASH_ANY   : .   -> skip ;
