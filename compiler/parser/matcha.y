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
    uint8_t bool_val;
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
    Declarations { 
        $$ = createNode(NODE_PROGRAM);
        $$->left = $1;
        root = $$; 
    }
;

Declarations:
    /* empty */ { $$ = NULL; }
    | Declarations Declaration {
        if ($2 == NULL) {
            // Declaration вернул NULL (например, успешно обработанный external run)
            $$ = $1;
        } else if ($1 == NULL) {
            $$ = makeListNode(NODE_DECLARATION_LIST);
            $$->left = $2;
        } else {
            $$ = appendToList($1, $2);
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
IDENTIFIER RUN '(' ParamListOpt ')' Block {
    $$ = linkExternalRunToSystem($1, $4, $6);
}

FieldDecl:
    FIELD IDENTIFIER StructBlock { 
        $$ = makeFieldDeclNode($2, $3);
    }
;

StructBlock:
      '{' VarDecls '}' { $$ = $2; }
    | '(' VarDecls ')' { $$ = $2; }
;

VarDecls:
      /* empty */ { $$ = NULL; }
    | VarDecls VarDecl { 
        if ($2 == NULL) {
            // VarDecl может вернуть NULL для некоторых случаев
            $$ = $1;
        } else if ($1 == NULL) {
            $$ = makeListNode(NODE_VAR_DECL_LIST);
            $$->left = $2;
        } else {
            $$ = appendToList($1, $2);
        }
      }
;

VarDecl:
      Type IDENTIFIER ';' { 
        $$ = makeVarDeclNode($1, $2, NULL);
      }
    | Type IDENTIFIER '=' Expression ';' { 
        $$ = makeVarDeclNode($1, $2, $4);
      }
    | IncludeDecl { $$ = $1; }
;

Type:
      TYPE_INT { $$ = makeTypeNode(TYPE_INT); }
    | TYPE_STRING { $$ = makeTypeNode(TYPE_STRING); }
    | TYPE_DOUBLE { $$ = makeTypeNode(TYPE_DOUBLE); }
    | TYPE_BOOL { $$ = makeTypeNode(TYPE_BOOL); }
    | TYPE_AUTO { $$ = makeTypeNode(TYPE_AUTO); }
    | IDENTIFIER { $$ = makeIdentifierNode($1); }
;

ObjectDecl:
    OBJECT IDENTIFIER OptionalBase '{' ComponentInits '}' { 
        $$ = makeObjectDeclNode($2, $3, $5);
    }
;

OptionalBase:
      /* empty */ { $$ = NULL; }
    | ':' IDENTIFIER { $$ = makeIdentifierNode($2); }
;

ComponentInits:
      /* empty */ { $$ = NULL; }
    | ComponentInits ComponentInit { 
        if ($2 == NULL) {
            // ComponentInit может вернуть NULL
            $$ = $1;
        } else if ($1 == NULL) {
            $$ = makeListNode(NODE_INIT_LIST);
            $$->left = $2;
        } else {
            $$ = appendToList($1, $2);
        }
      }
;

ComponentInit:
      IDENTIFIER IDENTIFIER '=' Expression ';' { 
        ASTNode* type = makeIdentifierNode($1);
        ASTNode* var = makeVarDeclNode(type, $2, $4);
        $$ = makeVoidNode(NODE_COMPONENT_INIT);
        $$->left = var;
      }
    | IDENTIFIER IDENTIFIER '[' ']' '=' ArrayInit ';' { 
        ASTNode* type = makeIdentifierNode($1);
        ASTNode* var = makeVarDeclNode(type, $2, $6);
        $$ = makeVoidNode(NODE_COMPONENT_INIT);
        $$->left = var;
      }
    | IDENTIFIER IDENTIFIER '=' ObjectInit ';' { 
        ASTNode* type = makeIdentifierNode($1);
        ASTNode* var = makeVarDeclNode(type, $2, $4);
        $$ = makeVoidNode(NODE_COMPONENT_INIT);
        $$->left = var;
      }
    | IncludeDecl { $$ = $1; }
;

ArrayInit:
    '{' ExpressionListOpt '}' { 
        $$ = makeVoidNode(NODE_ARRAY_INIT);
        $$->left = $2;
    }
;

ObjectInit:
    '{' InitListOpt '}' { 
        $$ = makeVoidNode(NODE_OBJECT_INIT);
        $$->left = $2;
    }
;

InitListOpt:
    /* empty */ { $$ = NULL; }
    | InitList { $$ = $1; }
;

InitList:
    InitElement { 
        $$ = makeListNode(NODE_INIT_LIST);
        $$->left = $1;
    }
    | InitList ',' InitElement { 
        $$ = appendToList($1, $3);
    }
;

InitElement:
    IDENTIFIER ':' Expression { 
        $$ = makeBinOpNode(NODE_ASSIGN, makeIdentifierNode($1), $3);
    }
    | Expression { $$ = $1; }
;

ExpressionListOpt:
      /* empty */ { $$ = NULL; }
    | ExpressionList { $$ = $1; }
;

ExpressionList:
      Expression { 
        $$ = makeListNode(NODE_EXPRESSION_LIST);
        $$->left = $1;
      }
    | ExpressionList ',' Expression { 
        $$ = appendToList($1, $3);
      }
;

SystemDecl:
SYSTEM IDENTIFIER '{' QueryDecls RunDecls '}' { 
    $$ = makeSystemDeclNode($2, $4, $5);
}

QueryDecls:
      /* empty */ { $$ = NULL; }
    | QueryDecls QueryDecl { 
        if ($2 == NULL) {
            $$ = $1;
        } else if ($1 == NULL) {
            $$ = makeListNode(NODE_QUERY_LIST);
            $$->left = $2;
        } else {
            $$ = appendToList($1, $2);
        }
      }
;

QueryDecl:
    QUERY OptAlias '(' IDENTIFIER ')' ';' { 
        // Исправляем логику алиасов
        char* alias = NULL;
        char* type_name = $4;
        
        if ($2 && $2->string_val) {
            alias = $2->string_val;
        } else {
            // Алиас по умолчанию
            alias = "item";
        }
        
        $$ = makeQueryDeclNode(alias, type_name);
    }
;

OptAlias:
      /* empty */ { $$ = NULL; }
    | IDENTIFIER { $$ = makeIdentifierNode($1); }
;

RunDecls:
      /* empty */ { $$ = NULL; }
    | RunDecls RunDecl { 
        if ($2 == NULL) {
            $$ = $1;
        } else if ($1 == NULL) {
            $$ = makeListNode(NODE_RUN_LIST);
            $$->left = $2;
        } else {
            $$ = appendToList($1, $2);
        }
      }
;

RunDecl:
      RUN '(' ParamListOpt ')' ';' { 
        $$ = makeRunDeclNode($3, NULL);
      }
    | RUN '(' ParamListOpt ')' Block { 
        $$ = makeRunDeclNode($3, $5);
      }
;

Block:
    '{' StatementsOpt '}' { 
        $$ = makeVoidNode(NODE_BLOCK);
        $$->left = $2;
    }
;

StatementsOpt:
      /* empty */ { $$ = NULL; }
    | Statements { $$ = $1; }
;

Statements:
      Statement { 
        if ($1 == NULL) {
            $$ = NULL;
        } else {
            $$ = makeListNode(NODE_STATEMENT_LIST);
            $$->left = $1;
        }
      }
    | Statements Statement { 
        if ($2 == NULL) {
            $$ = $1;
        } else if ($1 == NULL) {
            $$ = makeListNode(NODE_STATEMENT_LIST);
            $$->left = $2;
        } else {
            $$ = appendToList($1, $2);
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
      IF '(' Expression ')' Statement { 
        $$ = makeIfNode($3, $5, NULL);
      }
    | IF '(' Expression ')' Statement ELSE Statement { 
        $$ = makeIfNode($3, $5, $7);
      }
;

WhileStatement:
    WHILE '(' Expression ')' Statement { 
        $$ = makeWhileNode($3, $5);
    }
;

ForStatement:
    FOR '(' ForInitOpt ';' ExpressionOpt ';' ExpressionOpt ')' Statement { 
        $$ = makeForNode($3, $5, $7, $9);
    }
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
    FOR '(' Type IDENTIFIER ':' Expression ')' Statement { 
        $$ = makeForEachNode($3, $4, $6, $8);
    }
;

ReturnStatement:
    RETURN Expression ';' { 
        $$ = makeVoidNode(NODE_RETURN);
        $$->left = $2;
    }
;

ParamListOpt:
      /* empty */ { $$ = NULL; }
    | ParamList { $$ = $1; }
;

ParamList:
      Param { 
        $$ = makeListNode(NODE_PARAM_LIST);
        $$->left = $1;
      }
    | ParamList ',' Param { 
        $$ = appendToList($1, $3);
      }
;

Param:
    Type IDENTIFIER { 
        $$ = makeVoidNode(NODE_PARAM);
        $$->left = $1;
        $$->right = makeIdentifierNode($2);
    }
;

Expression:
      Literal { $$ = $1; }
    | ObjectInit { $$ = $1; }
    | Accessor { $$ = $1; }
    | '(' Expression ')' { $$ = $2; }
    | Expression BinOp Expression { 
        $$ = makeBinOpNode($2->type, $1, $3);
        free($2); // освобождаем временный узел оператора
      }
    | Lvalue AssignOp Expression { 
        $$ = makeBinOpNode($2->type, $1, $3);
        free($2); // освобождаем временный узел оператора
      }
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
      IDENTIFIER { $$ = makeIdentifierNode($1); }
    | Accessor '.' IDENTIFIER { 
        $$ = makeVoidNode(NODE_MEMBER_ACCESS);
        $$->left = $1;
        $$->right = makeIdentifierNode($3);
      }
;

IncludeDecl:
    INCLUDE IDENTIFIER ExcludeListOpt ';' { 
        $$ = makeVoidNode(NODE_INCLUDE);
        $$->left = makeIdentifierNode($2);
        $$->right = $3;
    }
;

ExcludeListOpt:
      /* empty */ { $$ = NULL; }
    | '\\' ExcludeList { $$ = $2; }
;

ExcludeList:
      IDENTIFIER { 
        $$ = makeListNode(NODE_EXPRESSION_LIST);
        $$->left = makeIdentifierNode($1);
      }
    | ExcludeList ',' IDENTIFIER { 
        $$ = appendToList($1, makeIdentifierNode($3));
      }
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d, column %d: %s\n", line_num, col_num, s);
    if (yytext) fprintf(stderr, "Near '%s'\n", yytext);
}