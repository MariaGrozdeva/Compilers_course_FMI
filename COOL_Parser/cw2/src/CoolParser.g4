parser grammar CoolParser;

options { tokenVocab = CoolLexer; }

program
    : (class SEMI)+
    ;

class
    : CLASS TYPEID inheritance? OCURLY (feature SEMI)* CCURLY
    ;

inheritance
    : INHERITS TYPEID
    ;

feature
    : OBJECTID OPAREN formal_list? CPAREN COLON TYPEID OCURLY expr CCURLY
    | OBJECTID COLON TYPEID (ASSIGN expr)?
    ;

formal_list
    : formal (COMMA formal)*
    ;

formal
    : OBJECTID COLON TYPEID
    ;

expr
    : assignExpr
    ;

assignExpr
    : OBJECTID ASSIGN assignExpr
    | notExpr
    ;

notExpr
    : NOT notExpr
    | compareExpr
    ;

compareExpr
    : arithExpr ((LT | LE | EQ) arithExpr)?
    ;

arithExpr
    : term ((PLUS | MINUS) term)*
    ;

term
    : factor ((STAR | SLASH) factor)*
    ;

factor
    : ISVOID factor
    | TILDE factor
    | dispatchExpr
    ;

dispatchExpr
    : primary
      ( (AT TYPEID)? DOT OBJECTID OPAREN arg_list? CPAREN )*
    ;

arg_list
    : expr (COMMA expr)*
    ;

primary
    : IF expr THEN expr ELSE expr FI
    | WHILE expr LOOP expr POOL
    | OCURLY block_expr CCURLY
    | LET let_binding (COMMA let_binding)* IN expr
    | CASE expr OF branch+ ESAC
    | NEW TYPEID
    | OPAREN expr CPAREN
    | OBJECTID OPAREN arg_list? CPAREN
    | OBJECTID
    | INT_CONST
    | STR_CONST
    | BOOL_CONST
    ;

block_expr
    : expr SEMI (expr SEMI)*
    ;

branch
    : OBJECTID COLON TYPEID DARROW expr SEMI
    ;

let_binding
    : OBJECTID COLON TYPEID (ASSIGN expr)?
    ;
