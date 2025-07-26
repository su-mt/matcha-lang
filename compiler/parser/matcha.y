// matcha.y

%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int line_num;
extern int col_num;
extern char* yytext;
void yyerror(const char* s);
ASTNode* root = NULL;

%}

%union {
    int int_val;
    double double_val;
    u_int8_t bool_val;
    char* str_val;
    char* id;
    ASTNode* node;
}

%token FIELD OBJECT SYSTEM INCLUDE QUERY RUN
%token TYPE_INT TYPE_STRING TYPE_DOUBLE TYPE_BOOL TYPE_AUTO
%token <int_val>LIT_INTEGER 
%token <double_val>LIT_DOUBLE 
%token <str_val>LIT_STRING 
%token <bool_val>LIT_BOOL
%token <id>IDENTIFIER
%token EQEQ NOTEQ
%token IF ELSE WHILE FOR RETURN
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN

// Non-terminals with AST node types
%type <node> Program Declarations Declaration
%type <node> FieldDecl ObjectDecl SystemDecl IncludeDecl ExternalRunDecl
%type <node> Expression Literal BinOp Accessor Lvalue
%type <node> Statement ExpressionStatement IfStatement WhileStatement
%type <node> ForStatement ForEachStatement ReturnStatement Block
%type <node> VarDecl ComponentInit ArrayInit ObjectInit
%type <node> QueryDecl RunDecl
%type <node> StructBlock VarDecls Type OptionalBase ComponentInits
%type <node> InitListOpt InitList InitElement ExpressionListOpt ExpressionList
%type <node> QueryDecls OptAlias RunDecls StatementsOpt Statements
%type <node> ForInitOpt ExpressionOpt ParamListOpt ParamList Param
%type <node> AssignOp ExcludeListOpt ExcludeList

// Operator precedences to resolve ambiguities
%left EQEQ NOTEQ '<' '>'
%left '+' '-'
%left '*' '/'
%right '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN 

%%

Program:
    Declarations { $$ = $1; root = $$; }
;

Declarations:
      /* empty */ { $$ = NULL; }
    | Declarations Declaration { 
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = makeBinOpNode(NODE_DECLARATION_LIST, $1, $2); // используем как список
        }
      }
;

Declaration:
      FieldDecl { $$ = $1; }
    | ObjectDecl { $$ = $1; }
    | SystemDecl { $$ = $1; }
    | IncludeDecl { $$ = $1; }
    | ExternalRunDecl { $$ = $1; }
;

ExternalRunDecl:
    IDENTIFIER RUN '(' ParamListOpt ')' Block { $$ = makeVoidNode(NODE_RUN); }
;

FieldDecl:
    FIELD IDENTIFIER StructBlock { 
        // Создаем узел с именем поля
        ASTNode* nameNode = makeIdentifierNode($2); // Нужна функция для создания узла с именем
        $$ = makeBinOpNode(NODE_FIELD_DECL, nameNode, $3); 
    }
;

StructBlock:
      '{' VarDecls '}' { $$ = $2; }
    | '(' VarDecls ')' { $$ = $2; }
;

VarDecls:
      /* empty */ { $$ = NULL; }
    | VarDecls VarDecl { 
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = makeBinOpNode(NODE_IDENTIFIER, $1, $2);
        }
      }
;

VarDecl:
      Type IDENTIFIER ';' { 
        ASTNode* nameNode = makeIdentifierNode($2);
        $$ = makeBinOpNode(NODE_VAR_DECL, $1, nameNode); 
      }
    | Type IDENTIFIER '=' Expression ';' { 
        ASTNode* nameNode = makeIdentifierNode($2);
        ASTNode* varNode = makeBinOpNode(NODE_VAR_DECL, $1, nameNode);
        $$ = makeBinOpNode(NODE_ASSIGN, varNode, $4); 
      }
    | IncludeDecl { $$ = $1; }
;

Type:
      TYPE_INT { $$ = makeTypeNode(TYPE_INT); }    // Нужна функция makeTypeNode
    | TYPE_STRING { $$ = makeTypeNode(TYPE_STRING); }
    | TYPE_DOUBLE { $$ = makeTypeNode(TYPE_DOUBLE); }
    | TYPE_BOOL { $$ = makeTypeNode(TYPE_BOOL); }
    | TYPE_AUTO { $$ = makeTypeNode(TYPE_AUTO); }
    | IDENTIFIER { $$ = makeIdentifierNode($1); }   // $1 содержит имя типа
;

ObjectDecl:
    OBJECT IDENTIFIER OptionalBase '{' ComponentInits '}' { $$ = makeVoidNode(NODE_OBJECT_DECL); }
;

OptionalBase:
      /* empty */ { $$ = NULL; }
    | ':' IDENTIFIER { $$ = makeVoidNode(NODE_IDENTIFIER); }
;

ComponentInits:
      /* empty */ { $$ = NULL; }
    | ComponentInits ComponentInit { $$ = $2; }
;

ComponentInit:
      IDENTIFIER IDENTIFIER '=' Expression ';' { $$ = makeBinOpNode(NODE_ASSIGN, makeVoidNode(NODE_IDENTIFIER), $4); }
    | IDENTIFIER IDENTIFIER '[' ']' '=' ArrayInit ';' { $$ = makeBinOpNode(NODE_ASSIGN, makeVoidNode(NODE_IDENTIFIER), $6); }
    | IDENTIFIER IDENTIFIER '=' ObjectInit ';' { $$ = makeBinOpNode(NODE_ASSIGN, makeVoidNode(NODE_IDENTIFIER), $4); }
    | IncludeDecl { $$ = $1; }
;

ArrayInit:
    '{' ExpressionListOpt '}' { $$ = $2; }
;

ObjectInit:
    '{' InitListOpt '}' { $$ = $2; }
;

InitListOpt:
    /* empty */ { $$ = NULL; }
    | InitList { $$ = $1; }
;

InitList:
    InitElement { $$ = $1; }
    | InitList ',' InitElement { $$ = $3; }
;

InitElement:
    IDENTIFIER ':' Expression { $$ = makeBinOpNode(NODE_ASSIGN, makeVoidNode(NODE_IDENTIFIER), $3); }
    | Expression { $$ = $1; }
;

ExpressionListOpt:
      /* empty */ { $$ = NULL; }
    | ExpressionList { $$ = $1; }
;

ExpressionList:
      Expression { $$ = $1; }
    | ExpressionList ',' Expression { $$ = $3; }
;

SystemDecl:
    SYSTEM IDENTIFIER '{' QueryDecls RunDecls '}' { $$ = makeVoidNode(NODE_SYSTEM_DECL); }
;

QueryDecls:
      /* empty */ { $$ = NULL; }
    | QueryDecls QueryDecl { $$ = $2; }
;

QueryDecl:
    QUERY OptAlias '(' IDENTIFIER ')' ';' { $$ = makeVoidNode(NODE_QUERY); }
;

OptAlias:
      /* empty */ { $$ = NULL; }
    | IDENTIFIER { $$ = makeVoidNode(NODE_IDENTIFIER); }
;

RunDecls:
      /* empty */ { $$ = NULL; }
    | RunDecls RunDecl { $$ = $2; }
;

RunDecl:
      RUN '(' ParamListOpt ')' ';' { $$ = makeVoidNode(NODE_RUN); }
    | RUN '(' ParamListOpt ')' Block { $$ = makeVoidNode(NODE_RUN); }
;

Block:
    '{' StatementsOpt '}' { $$ = $2; }
;

StatementsOpt:
      /* empty */ { $$ = NULL; }
    | Statements { $$ = $1; }
;

Statements:
      Statement { $$ = $1; }
    | Statements Statement { 
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $$ = makeBinOpNode(NODE_STATEMENT_LIST, $1, $2);
        }
      }
;

Statement:
      ExpressionStatement { $$ = $1; }
    | ForStatement { $$ = $1; }
    | ForEachStatement { $$ = $1; }
    | IfStatement { $$ = $1; }
    | WhileStatement { $$ = $1; }
    | ReturnStatement { $$ = $1; }
    | VarDecl { $$ = $1; }
    | Block { $$ = $1; }
;

ExpressionStatement:
      Expression ';' { $$ = $1; }
;

IfStatement:
      IF '(' Expression ')' Statement { $$ = makeBinOpNode(NODE_IF, $3, $5); }
    | IF '(' Expression ')' Statement ELSE Statement { 
        ASTNode* ifNode = makeBinOpNode(NODE_IF, $3, $5);
        $$ = makeBinOpNode(NODE_ELSE, ifNode, $7); 
      }
;

WhileStatement:
    WHILE '(' Expression ')' Statement { $$ = makeBinOpNode(NODE_WHILE, $3, $5); }
;

ForStatement:
    FOR '(' ForInitOpt ';' ExpressionOpt ';' ExpressionOpt ')' Statement { $$ = makeVoidNode(NODE_FOR); }
;

ForInitOpt:
      /* empty */ { $$ = NULL; }
    | VarDecl { $$ = $1; }
    | Expression { $$ = $1; }
;

ExpressionOpt:
      /* empty */ { $$ = NULL; }
    | Expression { $$ = $1; }
;

ForEachStatement:
    FOR '(' Type IDENTIFIER ':' Expression ')' Statement { $$ = makeVoidNode(NODE_FOR); }
;

ReturnStatement:
    RETURN Expression ';' { $$ = makeBinOpNode(NODE_RETURN, $2, NULL); }
;

ParamListOpt:
      /* empty */ { $$ = NULL; }
    | ParamList { $$ = $1; }
;

ParamList:
      Param { $$ = $1; }
    | ParamList ',' Param { $$ = $3; }
;

Param:
    Type IDENTIFIER { $$ = makeVoidNode(NODE_IDENTIFIER); }
;

Expression:
      Literal { $$ = $1; }
    | ObjectInit { $$ = $1; }
    | Accessor { $$ = $1; }
    | '(' Expression ')' { $$ = $2; }
    | Expression BinOp Expression { $$ = makeBinOpNode($2->type, $1, $3); }
    | Lvalue AssignOp Expression { $$ = makeBinOpNode($2->type, $1, $3); }
;

Lvalue:
    Accessor { $$ = $1; }
;

AssignOp:
      '=' { $$ = makeVoidNode(NODE_ASSIGN); }
    | ADD_ASSIGN { $$ = makeVoidNode(NODE_ADD_ASSIGN); }
    | SUB_ASSIGN { $$ = makeVoidNode(NODE_SUB_ASSIGN); }
    | MUL_ASSIGN { $$ = makeVoidNode(NODE_MUL_ASSIGN); }
    | DIV_ASSIGN { $$ = makeVoidNode(NODE_DIV_ASSIGN); }
;

Literal:
      LIT_INTEGER { $$ = makeIntNode($1); }
    | LIT_DOUBLE { $$ = makeDoubleNode($1); }
    | LIT_STRING { $$ = makeStringNode($1); }
    | LIT_BOOL { $$ = makeBoolNode($1); }
;

BinOp:
    '+' { $$ = makeVoidNode(NODE_ADD); }
    | '-' { $$ = makeVoidNode(NODE_SUB); }
    | '*' { $$ = makeVoidNode(NODE_MUL); }
    | '/' { $$ = makeVoidNode(NODE_DIV); }
    | EQEQ { $$ = makeVoidNode(NODE_EQ); }
    | NOTEQ { $$ = makeVoidNode(NODE_NEQ); }
    | '<' { $$ = makeVoidNode(NODE_LT); }
    | '>' { $$ = makeVoidNode(NODE_GT); }
;

Accessor:
      IDENTIFIER { $$ = makeVoidNode(NODE_IDENTIFIER); }
    | Accessor '.' IDENTIFIER { $$ = makeVoidNode(NODE_IDENTIFIER); /* или создать NODE_MEMBER_ACCESS */ }
;

IncludeDecl:
    INCLUDE IDENTIFIER ExcludeListOpt ';' { $$ = makeVoidNode(NODE_INCLUDE); }
;

ExcludeListOpt:
      /* empty */ { $$ = NULL; }
    | '\\' ExcludeList { $$ = $2; }
;

ExcludeList:
      IDENTIFIER { $$ = makeVoidNode(NODE_IDENTIFIER); }
    | ExcludeList ',' IDENTIFIER { $$ = makeVoidNode(NODE_IDENTIFIER); }
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d, column %d: %s\n", line_num, col_num, s);
    if (yytext) fprintf(stderr, "Near '%s'\n", yytext);
}

