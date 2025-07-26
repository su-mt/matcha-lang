    // matcha.l
%{
#include "ast.h"
#include "matcha.tab.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int line_num = 1;
int col_num = 1;

#define YY_USER_ACTION col_num += yyleng;
%}

%%

"auto"             { return TYPE_AUTO; }

"{"                { return '{'; }
"}"                { return '}'; }
"("                { return '('; }
")"                { return ')'; }
":"                { return ':'; }
";"                { return ';'; }
","                { return ','; }
"="                { return '='; }
"\["               { return '['; }
"\]"               { return ']'; }
"\\"               { return '\\'; }
"+"                { return '+'; }
"-"                { return '-'; }
"*"                { return '*'; }
"/"                { return '/'; }
"=="               { return EQEQ; }
"!="               { return NOTEQ; }
"<"                { return '<'; }
">"                { return '>'; }
"\."               { return '.'; }


"\+="  { return ADD_ASSIGN; }
"-="   { return SUB_ASSIGN; }
"\*="  { return MUL_ASSIGN; }
"/="   { return DIV_ASSIGN; }


"field"            { return FIELD; }
"object"           { return OBJECT; }
"system"           { return SYSTEM; }
"include"          { return INCLUDE; }
"query"            { return QUERY; }
"run"              { return RUN; }


"for"     { return FOR; }
"return"  { return RETURN; }
"if"      { return IF;}
"else"    { return ELSE;}
"while"   {return WHILE; }      


"int"              { return TYPE_INT; }
"string"           { return TYPE_STRING; }
"double"           { return TYPE_DOUBLE; }
"bool"             { return TYPE_BOOL; }


"true"             { yylval.bool_val = 1; return LIT_BOOL; }
"false"            { yylval.bool_val = 0; return LIT_BOOL; }

[0-9]+\.[0-9]+     { 
    yylval.double_val = atof(yytext); 
    // printf("DEBUG: Parsed double: %f\n", yylval.double_val);
    return LIT_DOUBLE; 
}
[0-9]+             { yylval.int_val = atoi(yytext); return LIT_INTEGER; }

\"([^\\\"]|\\.)*\" {
    int len = strlen(yytext);
    yylval.str_val = (char*)malloc(len - 1);
    memcpy(yylval.str_val, yytext + 1, len - 2);
    yylval.str_val[len - 2] = '\0';
    return LIT_STRING;
}

[[:alpha:]][[:alnum:]_]* {
    yylval.id = strdup(yytext);
    return IDENTIFIER;
}

"//".*             { /* skip comments */ }

\n                 { 
    line_num++; 
    col_num = 1; 
}

[ \t\r]+           { /* skip whitespace */ }

.                  { 
    fprintf(stderr, "Unexpected character '%c' at line %d, column %d\n", 
            yytext[0], line_num, col_num);
    return yytext[0]; 
}

%%

int yywrap() { 
    return 1; 
}