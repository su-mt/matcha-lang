/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_MATCHA_TAB_H_INCLUDED
# define YY_YY_PARSER_MATCHA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FIELD = 258,                   /* FIELD  */
    OBJECT = 259,                  /* OBJECT  */
    SYSTEM = 260,                  /* SYSTEM  */
    INCLUDE = 261,                 /* INCLUDE  */
    QUERY = 262,                   /* QUERY  */
    RUN = 263,                     /* RUN  */
    TYPE_INT = 264,                /* TYPE_INT  */
    TYPE_STRING = 265,             /* TYPE_STRING  */
    TYPE_DOUBLE = 266,             /* TYPE_DOUBLE  */
    TYPE_BOOL = 267,               /* TYPE_BOOL  */
    TYPE_AUTO = 268,               /* TYPE_AUTO  */
    LIT_INTEGER = 269,             /* LIT_INTEGER  */
    LIT_DOUBLE = 270,              /* LIT_DOUBLE  */
    LIT_STRING = 271,              /* LIT_STRING  */
    LIT_BOOL = 272,                /* LIT_BOOL  */
    IDENTIFIER = 273,              /* IDENTIFIER  */
    EQEQ = 274,                    /* EQEQ  */
    NOTEQ = 275,                   /* NOTEQ  */
    IF = 276,                      /* IF  */
    ELSE = 277,                    /* ELSE  */
    WHILE = 278,                   /* WHILE  */
    FOR = 279,                     /* FOR  */
    RETURN = 280,                  /* RETURN  */
    ADD_ASSIGN = 281,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 282,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 283,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 284               /* DIV_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser/matcha.y"

    int int_val;
    double double_val;
    uint8_t bool_val;
    char* str_val;
    char* id;
    ASTNode* node;

#line 102 "parser/matcha.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_MATCHA_TAB_H_INCLUDED  */
