/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser/matcha.y"

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

#line 85 "parser/matcha.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "matcha.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FIELD = 3,                      /* FIELD  */
  YYSYMBOL_OBJECT = 4,                     /* OBJECT  */
  YYSYMBOL_SYSTEM = 5,                     /* SYSTEM  */
  YYSYMBOL_INCLUDE = 6,                    /* INCLUDE  */
  YYSYMBOL_QUERY = 7,                      /* QUERY  */
  YYSYMBOL_RUN = 8,                        /* RUN  */
  YYSYMBOL_TYPE_INT = 9,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_STRING = 10,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_DOUBLE = 11,               /* TYPE_DOUBLE  */
  YYSYMBOL_TYPE_BOOL = 12,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_AUTO = 13,                 /* TYPE_AUTO  */
  YYSYMBOL_LIT_INTEGER = 14,               /* LIT_INTEGER  */
  YYSYMBOL_LIT_DOUBLE = 15,                /* LIT_DOUBLE  */
  YYSYMBOL_LIT_STRING = 16,                /* LIT_STRING  */
  YYSYMBOL_LIT_BOOL = 17,                  /* LIT_BOOL  */
  YYSYMBOL_IDENTIFIER = 18,                /* IDENTIFIER  */
  YYSYMBOL_EQEQ = 19,                      /* EQEQ  */
  YYSYMBOL_NOTEQ = 20,                     /* NOTEQ  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_ADD_ASSIGN = 26,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 27,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 28,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 29,                /* DIV_ASSIGN  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* '>'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* ':'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '.'  */
  YYSYMBOL_47_ = 47,                       /* '\\'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Program = 49,                   /* Program  */
  YYSYMBOL_Declarations = 50,              /* Declarations  */
  YYSYMBOL_Declaration = 51,               /* Declaration  */
  YYSYMBOL_ExternalRunDecl = 52,           /* ExternalRunDecl  */
  YYSYMBOL_FieldDecl = 53,                 /* FieldDecl  */
  YYSYMBOL_StructBlock = 54,               /* StructBlock  */
  YYSYMBOL_VarDecls = 55,                  /* VarDecls  */
  YYSYMBOL_VarDecl = 56,                   /* VarDecl  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_ObjectDecl = 58,                /* ObjectDecl  */
  YYSYMBOL_OptionalBase = 59,              /* OptionalBase  */
  YYSYMBOL_ComponentInits = 60,            /* ComponentInits  */
  YYSYMBOL_ComponentInit = 61,             /* ComponentInit  */
  YYSYMBOL_ArrayInit = 62,                 /* ArrayInit  */
  YYSYMBOL_ObjectInit = 63,                /* ObjectInit  */
  YYSYMBOL_InitListOpt = 64,               /* InitListOpt  */
  YYSYMBOL_InitList = 65,                  /* InitList  */
  YYSYMBOL_InitElement = 66,               /* InitElement  */
  YYSYMBOL_ExpressionListOpt = 67,         /* ExpressionListOpt  */
  YYSYMBOL_ExpressionList = 68,            /* ExpressionList  */
  YYSYMBOL_SystemDecl = 69,                /* SystemDecl  */
  YYSYMBOL_QueryDecls = 70,                /* QueryDecls  */
  YYSYMBOL_QueryDecl = 71,                 /* QueryDecl  */
  YYSYMBOL_OptAlias = 72,                  /* OptAlias  */
  YYSYMBOL_RunDecls = 73,                  /* RunDecls  */
  YYSYMBOL_RunDecl = 74,                   /* RunDecl  */
  YYSYMBOL_Block = 75,                     /* Block  */
  YYSYMBOL_StatementsOpt = 76,             /* StatementsOpt  */
  YYSYMBOL_Statements = 77,                /* Statements  */
  YYSYMBOL_Statement = 78,                 /* Statement  */
  YYSYMBOL_ExpressionStatement = 79,       /* ExpressionStatement  */
  YYSYMBOL_IfStatement = 80,               /* IfStatement  */
  YYSYMBOL_WhileStatement = 81,            /* WhileStatement  */
  YYSYMBOL_ForStatement = 82,              /* ForStatement  */
  YYSYMBOL_ForInitOpt = 83,                /* ForInitOpt  */
  YYSYMBOL_ExpressionOpt = 84,             /* ExpressionOpt  */
  YYSYMBOL_ForEachStatement = 85,          /* ForEachStatement  */
  YYSYMBOL_ReturnStatement = 86,           /* ReturnStatement  */
  YYSYMBOL_ParamListOpt = 87,              /* ParamListOpt  */
  YYSYMBOL_ParamList = 88,                 /* ParamList  */
  YYSYMBOL_Param = 89,                     /* Param  */
  YYSYMBOL_Expression = 90,                /* Expression  */
  YYSYMBOL_Lvalue = 91,                    /* Lvalue  */
  YYSYMBOL_AssignOp = 92,                  /* AssignOp  */
  YYSYMBOL_Literal = 93,                   /* Literal  */
  YYSYMBOL_BinOp = 94,                     /* BinOp  */
  YYSYMBOL_Accessor = 95,                  /* Accessor  */
  YYSYMBOL_IncludeDecl = 96,               /* IncludeDecl  */
  YYSYMBOL_ExcludeListOpt = 97,            /* ExcludeListOpt  */
  YYSYMBOL_ExcludeList = 98                /* ExcludeList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,    34,    32,    45,    33,    46,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    41,
      30,    36,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,    47,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    68,    69,    80,    81,    82,    83,    84,
      88,    97,   103,   104,   108,   109,   120,   123,   126,   130,
     131,   132,   133,   134,   135,   139,   145,   146,   150,   151,
     162,   168,   174,   180,   184,   191,   198,   199,   203,   207,
     213,   216,   220,   221,   225,   229,   235,   241,   242,   253,
     259,   260,   264,   265,   276,   279,   285,   292,   293,   297,
     301,   307,   308,   309,   310,   311,   312,   313,   314,   318,
     322,   325,   331,   337,   343,   344,   345,   349,   350,   354,
     360,   367,   368,   372,   376,   382,   390,   391,   392,   393,
     394,   398,   405,   409,   410,   411,   412,   413,   417,   418,
     419,   420,   424,   425,   426,   427,   428,   429,   430,   431,
     435,   436,   444,   452,   453,   457,   461
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FIELD", "OBJECT",
  "SYSTEM", "INCLUDE", "QUERY", "RUN", "TYPE_INT", "TYPE_STRING",
  "TYPE_DOUBLE", "TYPE_BOOL", "TYPE_AUTO", "LIT_INTEGER", "LIT_DOUBLE",
  "LIT_STRING", "LIT_BOOL", "IDENTIFIER", "EQEQ", "NOTEQ", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'='", "'('",
  "')'", "'{'", "'}'", "';'", "':'", "'['", "']'", "','", "'.'", "'\\\\'",
  "$accept", "Program", "Declarations", "Declaration", "ExternalRunDecl",
  "FieldDecl", "StructBlock", "VarDecls", "VarDecl", "Type", "ObjectDecl",
  "OptionalBase", "ComponentInits", "ComponentInit", "ArrayInit",
  "ObjectInit", "InitListOpt", "InitList", "InitElement",
  "ExpressionListOpt", "ExpressionList", "SystemDecl", "QueryDecls",
  "QueryDecl", "OptAlias", "RunDecls", "RunDecl", "Block", "StatementsOpt",
  "Statements", "Statement", "ExpressionStatement", "IfStatement",
  "WhileStatement", "ForStatement", "ForInitOpt", "ExpressionOpt",
  "ForEachStatement", "ReturnStatement", "ParamListOpt", "ParamList",
  "Param", "Expression", "Lvalue", "AssignOp", "Literal", "BinOp",
  "Accessor", "IncludeDecl", "ExcludeListOpt", "ExcludeList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -94,     9,   196,   -94,   -10,     0,    11,    12,    18,   -94,
     -94,   -94,   -94,   -94,   -94,   -12,    -6,    13,    -5,    14,
     -94,   -94,   -94,    27,    23,   -94,    30,    22,   162,   132,
      10,   -94,   -94,    40,   -94,    35,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,    67,    49,    43,   -94,   -94,   -94,    71,
     -94,   -94,     6,    74,   -94,     3,    78,   -94,    59,   162,
       8,    83,   -94,   -94,   -94,   -94,    66,    68,   -94,   -94,
     -94,    58,   -94,   -94,    93,   -94,   -26,    94,   162,   -94,
     -94,   -94,   -94,    95,    77,    81,    92,    93,    93,   110,
     -94,   -94,   -94,    96,    58,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   157,    29,   -94,   218,   -94,   147,   174,    93,
     102,    99,   101,    93,    93,   142,   191,   236,   -11,   100,
     121,   -94,   157,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,    93,   -94,   -94,   -94,   -94,   -94,
      93,   149,   126,   288,   -94,   128,   208,   146,   137,    20,
     253,   262,   -94,   165,   144,   288,   -94,   -94,    93,   -94,
     147,   288,   288,   -94,   -94,   -94,   156,   -94,   -94,   -94,
      58,    58,    -4,    93,   288,   -94,    93,   155,   175,   -94,
      93,   171,   288,   163,   168,   288,   -94,    58,   279,    93,
     -94,    93,   -94,    58,   178,   288,   -94,    58,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     4,
       9,     5,     6,     7,     8,     0,    26,     0,   113,     0,
      14,    14,    11,     0,     0,    47,     0,     0,    81,     0,
       0,    27,    28,    52,   115,   114,   112,    19,    20,    21,
      22,    23,    24,     0,     0,    82,    83,    13,    15,     0,
      18,    12,     0,    50,    48,     0,     0,    85,     0,     0,
       0,     0,    25,    29,    33,    51,     0,     0,    46,    53,
     116,    57,    10,    84,     0,    16,     0,     0,    81,    98,
      99,   100,   101,   110,     0,     0,     0,     0,     0,    36,
      67,    87,    68,     0,    58,    59,    61,    64,    65,    62,
      63,    66,     0,     0,    86,    88,   110,    36,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,   110,     0,
      37,    38,    41,    56,    60,   106,   107,   108,   109,   102,
     103,   104,   105,    69,     0,    94,    95,    96,    97,    93,
       0,     0,   110,    41,    17,    87,     0,     0,     0,     0,
       0,     0,    75,     0,     0,    76,    80,    89,     0,    35,
       0,    90,    91,   111,    32,    30,     0,    49,    54,    55,
       0,     0,     0,    77,    40,    39,    42,     0,    70,    72,
       0,     0,    78,     0,    43,    44,    31,     0,     0,    77,
      34,     0,    71,     0,     0,    45,    79,     0,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   197,   -24,   -25,
     -94,   -94,   -94,   -94,   -94,   108,   -94,   -94,    60,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -56,   -94,   -94,
     -93,   -94,   -94,   -94,   -94,   -94,    41,   -94,   -94,   141,
     -94,   170,   -74,   -94,   -94,   -94,   -94,   -94,     2,   -94,
     -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     9,    10,    11,    22,    29,    90,    49,
      12,    24,    52,    63,   177,    91,   119,   120,   121,   183,
     184,    13,    33,    54,    66,    55,    69,    92,    93,    94,
      95,    96,    97,    98,    99,   154,   181,   100,   101,    44,
      45,    46,   102,   103,   140,   104,   134,   105,    50,    27,
      35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   124,    72,    43,    14,    48,    48,   -24,    15,     3,
     109,    67,     7,   116,   117,   122,     7,   110,    16,    37,
      38,    39,    40,    41,    61,    20,    19,    21,    42,    17,
      18,   158,    74,   143,    43,   146,    23,    75,   180,   150,
     151,   155,    26,    68,    74,    31,    62,    53,    34,    75,
      51,    28,    25,    43,    64,   135,   136,   137,   138,    71,
     161,   168,    32,    36,     7,   139,   162,    37,    38,    39,
      40,    41,    79,    80,    81,    82,    83,   178,   179,    84,
      56,    85,    86,    87,   174,    57,   143,    58,    59,    60,
     153,   152,    65,   169,   192,    88,    70,    89,    71,   182,
     196,    76,   185,    77,   198,    78,   188,    79,    80,    81,
      82,   106,   111,   -24,   113,   182,     7,   195,   114,    37,
      38,    39,    40,    41,    79,    80,    81,    82,   118,   115,
      88,    84,   107,    85,    86,    87,   123,   148,     7,   149,
     159,    37,    38,    39,    40,    41,   147,    88,     7,    89,
      42,    37,    38,    39,    40,    41,    79,    80,    81,    82,
      83,    79,    80,    81,    82,   142,   160,   163,   158,   164,
      47,    37,    38,    39,    40,    41,   125,   126,   167,    88,
      42,   107,   166,   172,    88,   173,   107,   127,   128,   129,
     130,   131,   132,   125,   126,   176,   186,   187,   133,     4,
       5,     6,     7,   190,   127,   128,   129,   130,   131,   132,
     125,   126,   189,   191,     8,   144,   197,   145,    30,   112,
     175,   127,   128,   129,   130,   131,   132,   125,   126,    73,
     194,     0,   156,     0,     0,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   -92,   -92,   -92,   -92,     0,   165,
       0,     0,     0,     0,   -92,   125,   126,     0,     0,     0,
       0,     0,     0,     0,   141,     0,   127,   128,   129,   130,
     131,   132,   125,   126,   157,     0,     0,     0,     0,     0,
       0,   125,   126,   127,   128,   129,   130,   131,   132,     0,
       0,   170,   127,   128,   129,   130,   131,   132,   125,   126,
     171,     0,     0,     0,     0,     0,     0,   125,   126,   127,
     128,   129,   130,   131,   132,     0,     0,   193,   127,   128,
     129,   130,   131,   132
};

static const yytype_int16 yycheck[] =
{
      74,    94,    58,    28,     2,    29,    30,    18,    18,     0,
      36,     8,     6,    87,    88,    89,     6,    43,    18,     9,
      10,    11,    12,    13,    18,    37,     8,    39,    18,    18,
      18,    42,    36,   107,    59,   109,    42,    41,    42,   113,
     114,   115,    47,    40,    36,    18,    40,     7,    18,    41,
      40,    37,    39,    78,    52,    26,    27,    28,    29,    39,
     134,    41,    39,    41,     6,    36,   140,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   170,   171,    21,
      45,    23,    24,    25,   158,    18,   160,    38,    45,    18,
     115,   115,    18,   149,   187,    37,    18,    39,    39,   173,
     193,    18,   176,    37,   197,    37,   180,    14,    15,    16,
      17,    18,    18,    18,    37,   189,     6,   191,    37,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    37,
      37,    21,    39,    23,    24,    25,    40,    38,     6,    38,
      40,     9,    10,    11,    12,    13,    44,    37,     6,    39,
      18,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    14,    15,    16,    17,    18,    45,    18,    42,    41,
      38,     9,    10,    11,    12,    13,    19,    20,    41,    37,
      18,    39,    36,    18,    37,    41,    39,    30,    31,    32,
      33,    34,    35,    19,    20,    39,    41,    22,    41,     3,
       4,     5,     6,    40,    30,    31,    32,    33,    34,    35,
      19,    20,    41,    45,    18,    41,    38,   109,    21,    78,
     160,    30,    31,    32,    33,    34,    35,    19,    20,    59,
     189,    -1,    41,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    26,    27,    28,    29,    -1,    41,
      -1,    -1,    -1,    -1,    36,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    30,    31,    32,    33,
      34,    35,    19,    20,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    30,    31,    32,    33,    34,    35,    -1,
      -1,    38,    30,    31,    32,    33,    34,    35,    19,    20,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    30,
      31,    32,    33,    34,    35,    -1,    -1,    38,    30,    31,
      32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,     0,     3,     4,     5,     6,    18,    51,
      52,    53,    58,    69,    96,    18,    18,    18,    18,     8,
      37,    39,    54,    42,    59,    39,    47,    97,    37,    55,
      55,    18,    39,    70,    18,    98,    41,     9,    10,    11,
      12,    13,    18,    57,    87,    88,    89,    38,    56,    57,
      96,    40,    60,     7,    71,    73,    45,    18,    38,    45,
      18,    18,    40,    61,    96,    18,    72,     8,    40,    74,
      18,    39,    75,    89,    36,    41,    18,    37,    37,    14,
      15,    16,    17,    18,    21,    23,    24,    25,    37,    39,
      56,    63,    75,    76,    77,    78,    79,    80,    81,    82,
      85,    86,    90,    91,    93,    95,    18,    39,    90,    36,
      43,    18,    87,    37,    37,    37,    90,    90,    18,    64,
      65,    66,    90,    40,    78,    19,    20,    30,    31,    32,
      33,    34,    35,    41,    94,    26,    27,    28,    29,    36,
      92,    46,    18,    90,    41,    63,    90,    44,    38,    38,
      90,    90,    56,    57,    83,    90,    41,    38,    42,    40,
      45,    90,    90,    18,    41,    41,    36,    41,    41,    75,
      38,    38,    18,    41,    90,    66,    39,    62,    78,    78,
      42,    84,    90,    67,    68,    90,    41,    22,    90,    41,
      40,    45,    78,    38,    84,    90,    78,    38,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      52,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    62,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      80,    80,    81,    82,    83,    83,    83,    84,    84,    85,
      86,    87,    87,    88,    88,    89,    90,    90,    90,    90,
      90,    90,    91,    92,    92,    92,    92,    92,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    97,    97,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       6,     3,     3,     3,     0,     2,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     6,     0,     2,     0,     2,
       5,     7,     5,     1,     3,     3,     0,     1,     1,     3,
       3,     1,     0,     1,     1,     3,     6,     0,     2,     6,
       0,     1,     0,     2,     5,     5,     3,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       5,     7,     5,     9,     0,     1,     1,     0,     1,     8,
       3,     0,     1,     1,     3,     2,     1,     1,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     0,     2,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: Declarations  */
#line 60 "parser/matcha.y"
                 { 
        (yyval.node) = createNode(NODE_PROGRAM);
        (yyval.node)->left = (yyvsp[0].node);
        root = (yyval.node); 
    }
#line 1343 "parser/matcha.tab.c"
    break;

  case 3: /* Declarations: %empty  */
#line 68 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1349 "parser/matcha.tab.c"
    break;

  case 4: /* Declarations: Declarations Declaration  */
#line 69 "parser/matcha.y"
                               { 
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = makeListNode(NODE_DECLARATION_LIST);
            (yyval.node)->left = (yyvsp[0].node);
        } else {
            (yyval.node) = appendToList((yyvsp[-1].node), (yyvsp[0].node));
        }
      }
#line 1362 "parser/matcha.tab.c"
    break;

  case 5: /* Declaration: FieldDecl  */
#line 80 "parser/matcha.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1368 "parser/matcha.tab.c"
    break;

  case 6: /* Declaration: ObjectDecl  */
#line 81 "parser/matcha.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1374 "parser/matcha.tab.c"
    break;

  case 7: /* Declaration: SystemDecl  */
#line 82 "parser/matcha.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1380 "parser/matcha.tab.c"
    break;

  case 8: /* Declaration: IncludeDecl  */
#line 83 "parser/matcha.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1386 "parser/matcha.tab.c"
    break;

  case 9: /* Declaration: ExternalRunDecl  */
#line 84 "parser/matcha.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1392 "parser/matcha.tab.c"
    break;

  case 10: /* ExternalRunDecl: IDENTIFIER RUN '(' ParamListOpt ')' Block  */
#line 88 "parser/matcha.y"
                                              { 
        (yyval.node) = makeVoidNode(NODE_EXTERNAL_RUN);
        (yyval.node)->left = makeIdentifierNode((yyvsp[-5].id));
        (yyval.node)->middle = (yyvsp[-2].node);  // parameters
        (yyval.node)->right = (yyvsp[0].node);   // body
    }
#line 1403 "parser/matcha.tab.c"
    break;

  case 11: /* FieldDecl: FIELD IDENTIFIER StructBlock  */
#line 97 "parser/matcha.y"
                                 { 
        (yyval.node) = makeFieldDeclNode((yyvsp[-1].id), (yyvsp[0].node));
    }
#line 1411 "parser/matcha.tab.c"
    break;

  case 12: /* StructBlock: '{' VarDecls '}'  */
#line 103 "parser/matcha.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1417 "parser/matcha.tab.c"
    break;

  case 13: /* StructBlock: '(' VarDecls ')'  */
#line 104 "parser/matcha.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1423 "parser/matcha.tab.c"
    break;

  case 14: /* VarDecls: %empty  */
#line 108 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1429 "parser/matcha.tab.c"
    break;

  case 15: /* VarDecls: VarDecls VarDecl  */
#line 109 "parser/matcha.y"
                       { 
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = makeListNode(NODE_VAR_DECL_LIST);
            (yyval.node)->left = (yyvsp[0].node);
        } else {
            (yyval.node) = appendToList((yyvsp[-1].node), (yyvsp[0].node));
        }
      }
#line 1442 "parser/matcha.tab.c"
    break;

  case 16: /* VarDecl: Type IDENTIFIER ';'  */
#line 120 "parser/matcha.y"
                          { 
        (yyval.node) = makeVarDeclNode((yyvsp[-2].node), (yyvsp[-1].id), NULL);
      }
#line 1450 "parser/matcha.tab.c"
    break;

  case 17: /* VarDecl: Type IDENTIFIER '=' Expression ';'  */
#line 123 "parser/matcha.y"
                                         { 
        (yyval.node) = makeVarDeclNode((yyvsp[-4].node), (yyvsp[-3].id), (yyvsp[-1].node));
      }
#line 1458 "parser/matcha.tab.c"
    break;

  case 18: /* VarDecl: IncludeDecl  */
#line 126 "parser/matcha.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1464 "parser/matcha.tab.c"
    break;

  case 19: /* Type: TYPE_INT  */
#line 130 "parser/matcha.y"
               { (yyval.node) = makeTypeNode(TYPE_INT); }
#line 1470 "parser/matcha.tab.c"
    break;

  case 20: /* Type: TYPE_STRING  */
#line 131 "parser/matcha.y"
                  { (yyval.node) = makeTypeNode(TYPE_STRING); }
#line 1476 "parser/matcha.tab.c"
    break;

  case 21: /* Type: TYPE_DOUBLE  */
#line 132 "parser/matcha.y"
                  { (yyval.node) = makeTypeNode(TYPE_DOUBLE); }
#line 1482 "parser/matcha.tab.c"
    break;

  case 22: /* Type: TYPE_BOOL  */
#line 133 "parser/matcha.y"
                { (yyval.node) = makeTypeNode(TYPE_BOOL); }
#line 1488 "parser/matcha.tab.c"
    break;

  case 23: /* Type: TYPE_AUTO  */
#line 134 "parser/matcha.y"
                { (yyval.node) = makeTypeNode(TYPE_AUTO); }
#line 1494 "parser/matcha.tab.c"
    break;

  case 24: /* Type: IDENTIFIER  */
#line 135 "parser/matcha.y"
                 { (yyval.node) = makeIdentifierNode((yyvsp[0].id)); }
#line 1500 "parser/matcha.tab.c"
    break;

  case 25: /* ObjectDecl: OBJECT IDENTIFIER OptionalBase '{' ComponentInits '}'  */
#line 139 "parser/matcha.y"
                                                          { 
        (yyval.node) = makeObjectDeclNode((yyvsp[-4].id), (yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 1508 "parser/matcha.tab.c"
    break;

  case 26: /* OptionalBase: %empty  */
#line 145 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1514 "parser/matcha.tab.c"
    break;

  case 27: /* OptionalBase: ':' IDENTIFIER  */
#line 146 "parser/matcha.y"
                     { (yyval.node) = makeIdentifierNode((yyvsp[0].id)); }
#line 1520 "parser/matcha.tab.c"
    break;

  case 28: /* ComponentInits: %empty  */
#line 150 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1526 "parser/matcha.tab.c"
    break;

  case 29: /* ComponentInits: ComponentInits ComponentInit  */
#line 151 "parser/matcha.y"
                                   { 
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = makeListNode(NODE_INIT_LIST);
            (yyval.node)->left = (yyvsp[0].node);
        } else {
            (yyval.node) = appendToList((yyvsp[-1].node), (yyvsp[0].node));
        }
      }
#line 1539 "parser/matcha.tab.c"
    break;

  case 30: /* ComponentInit: IDENTIFIER IDENTIFIER '=' Expression ';'  */
#line 162 "parser/matcha.y"
                                               { 
        ASTNode* type = makeIdentifierNode((yyvsp[-4].id));
        ASTNode* var = makeVarDeclNode(type, (yyvsp[-3].id), (yyvsp[-1].node));
        (yyval.node) = makeVoidNode(NODE_COMPONENT_INIT);
        (yyval.node)->left = var;
      }
#line 1550 "parser/matcha.tab.c"
    break;

  case 31: /* ComponentInit: IDENTIFIER IDENTIFIER '[' ']' '=' ArrayInit ';'  */
#line 168 "parser/matcha.y"
                                                      { 
        ASTNode* type = makeIdentifierNode((yyvsp[-6].id));
        ASTNode* var = makeVarDeclNode(type, (yyvsp[-5].id), (yyvsp[-1].node));
        (yyval.node) = makeVoidNode(NODE_COMPONENT_INIT);
        (yyval.node)->left = var;
      }
#line 1561 "parser/matcha.tab.c"
    break;

  case 32: /* ComponentInit: IDENTIFIER IDENTIFIER '=' ObjectInit ';'  */
#line 174 "parser/matcha.y"
                                               { 
        ASTNode* type = makeIdentifierNode((yyvsp[-4].id));
        ASTNode* var = makeVarDeclNode(type, (yyvsp[-3].id), (yyvsp[-1].node));
        (yyval.node) = makeVoidNode(NODE_COMPONENT_INIT);
        (yyval.node)->left = var;
      }
#line 1572 "parser/matcha.tab.c"
    break;

  case 33: /* ComponentInit: IncludeDecl  */
#line 180 "parser/matcha.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1578 "parser/matcha.tab.c"
    break;

  case 34: /* ArrayInit: '{' ExpressionListOpt '}'  */
#line 184 "parser/matcha.y"
                              { 
        (yyval.node) = makeVoidNode(NODE_ARRAY_INIT);
        (yyval.node)->left = (yyvsp[-1].node);
    }
#line 1587 "parser/matcha.tab.c"
    break;

  case 35: /* ObjectInit: '{' InitListOpt '}'  */
#line 191 "parser/matcha.y"
                        { 
        (yyval.node) = makeVoidNode(NODE_OBJECT_INIT);
        (yyval.node)->left = (yyvsp[-1].node);
    }
#line 1596 "parser/matcha.tab.c"
    break;

  case 36: /* InitListOpt: %empty  */
#line 198 "parser/matcha.y"
                { (yyval.node) = NULL; }
#line 1602 "parser/matcha.tab.c"
    break;

  case 37: /* InitListOpt: InitList  */
#line 199 "parser/matcha.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1608 "parser/matcha.tab.c"
    break;

  case 38: /* InitList: InitElement  */
#line 203 "parser/matcha.y"
                { 
        (yyval.node) = makeListNode(NODE_INIT_LIST);
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 1617 "parser/matcha.tab.c"
    break;

  case 39: /* InitList: InitList ',' InitElement  */
#line 207 "parser/matcha.y"
                               { 
        (yyval.node) = appendToList((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1625 "parser/matcha.tab.c"
    break;

  case 40: /* InitElement: IDENTIFIER ':' Expression  */
#line 213 "parser/matcha.y"
                              { 
        (yyval.node) = makeBinOpNode(NODE_ASSIGN, makeIdentifierNode((yyvsp[-2].id)), (yyvsp[0].node));
    }
#line 1633 "parser/matcha.tab.c"
    break;

  case 41: /* InitElement: Expression  */
#line 216 "parser/matcha.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1639 "parser/matcha.tab.c"
    break;

  case 42: /* ExpressionListOpt: %empty  */
#line 220 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1645 "parser/matcha.tab.c"
    break;

  case 43: /* ExpressionListOpt: ExpressionList  */
#line 221 "parser/matcha.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1651 "parser/matcha.tab.c"
    break;

  case 44: /* ExpressionList: Expression  */
#line 225 "parser/matcha.y"
                 { 
        (yyval.node) = makeListNode(NODE_EXPRESSION_LIST);
        (yyval.node)->left = (yyvsp[0].node);
      }
#line 1660 "parser/matcha.tab.c"
    break;

  case 45: /* ExpressionList: ExpressionList ',' Expression  */
#line 229 "parser/matcha.y"
                                    { 
        (yyval.node) = appendToList((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1668 "parser/matcha.tab.c"
    break;

  case 46: /* SystemDecl: SYSTEM IDENTIFIER '{' QueryDecls RunDecls '}'  */
#line 235 "parser/matcha.y"
                                                  { 
        (yyval.node) = makeSystemDeclNode((yyvsp[-4].id), (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1676 "parser/matcha.tab.c"
    break;

  case 47: /* QueryDecls: %empty  */
#line 241 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1682 "parser/matcha.tab.c"
    break;

  case 48: /* QueryDecls: QueryDecls QueryDecl  */
#line 242 "parser/matcha.y"
                           { 
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = makeListNode(NODE_EXPRESSION_LIST);
            (yyval.node)->left = (yyvsp[0].node);
        } else {
            (yyval.node) = appendToList((yyvsp[-1].node), (yyvsp[0].node));
        }
      }
#line 1695 "parser/matcha.tab.c"
    break;

  case 49: /* QueryDecl: QUERY OptAlias '(' IDENTIFIER ')' ';'  */
#line 253 "parser/matcha.y"
                                          { 
        (yyval.node) = makeQueryDeclNode((yyvsp[-4].node) ? (yyvsp[-4].node)->string_val : NULL, (yyvsp[-2].id));
    }
#line 1703 "parser/matcha.tab.c"
    break;

  case 50: /* OptAlias: %empty  */
#line 259 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1709 "parser/matcha.tab.c"
    break;

  case 51: /* OptAlias: IDENTIFIER  */
#line 260 "parser/matcha.y"
                 { (yyval.node) = makeIdentifierNode((yyvsp[0].id)); }
#line 1715 "parser/matcha.tab.c"
    break;

  case 52: /* RunDecls: %empty  */
#line 264 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1721 "parser/matcha.tab.c"
    break;

  case 53: /* RunDecls: RunDecls RunDecl  */
#line 265 "parser/matcha.y"
                       { 
        if ((yyvsp[-1].node) == NULL) {
            (yyval.node) = makeListNode(NODE_EXPRESSION_LIST);
            (yyval.node)->left = (yyvsp[0].node);
        } else {
            (yyval.node) = appendToList((yyvsp[-1].node), (yyvsp[0].node));
        }
      }
#line 1734 "parser/matcha.tab.c"
    break;

  case 54: /* RunDecl: RUN '(' ParamListOpt ')' ';'  */
#line 276 "parser/matcha.y"
                                   { 
        (yyval.node) = makeRunDeclNode((yyvsp[-2].node), NULL);
      }
#line 1742 "parser/matcha.tab.c"
    break;

  case 55: /* RunDecl: RUN '(' ParamListOpt ')' Block  */
#line 279 "parser/matcha.y"
                                     { 
        (yyval.node) = makeRunDeclNode((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1750 "parser/matcha.tab.c"
    break;

  case 56: /* Block: '{' StatementsOpt '}'  */
#line 285 "parser/matcha.y"
                          { 
        (yyval.node) = makeVoidNode(NODE_BLOCK);
        (yyval.node)->left = (yyvsp[-1].node);
    }
#line 1759 "parser/matcha.tab.c"
    break;

  case 57: /* StatementsOpt: %empty  */
#line 292 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1765 "parser/matcha.tab.c"
    break;

  case 58: /* StatementsOpt: Statements  */
#line 293 "parser/matcha.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1771 "parser/matcha.tab.c"
    break;

  case 59: /* Statements: Statement  */
#line 297 "parser/matcha.y"
                { 
        (yyval.node) = makeListNode(NODE_STATEMENT_LIST);
        (yyval.node)->left = (yyvsp[0].node);
      }
#line 1780 "parser/matcha.tab.c"
    break;

  case 60: /* Statements: Statements Statement  */
#line 301 "parser/matcha.y"
                           { 
        (yyval.node) = appendToList((yyvsp[-1].node), (yyvsp[0].node));
      }
#line 1788 "parser/matcha.tab.c"
    break;

  case 61: /* Statement: ExpressionStatement  */
#line 307 "parser/matcha.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1794 "parser/matcha.tab.c"
    break;

  case 62: /* Statement: ForStatement  */
#line 308 "parser/matcha.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1800 "parser/matcha.tab.c"
    break;

  case 63: /* Statement: ForEachStatement  */
#line 309 "parser/matcha.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1806 "parser/matcha.tab.c"
    break;

  case 64: /* Statement: IfStatement  */
#line 310 "parser/matcha.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1812 "parser/matcha.tab.c"
    break;

  case 65: /* Statement: WhileStatement  */
#line 311 "parser/matcha.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1818 "parser/matcha.tab.c"
    break;

  case 66: /* Statement: ReturnStatement  */
#line 312 "parser/matcha.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1824 "parser/matcha.tab.c"
    break;

  case 67: /* Statement: VarDecl  */
#line 313 "parser/matcha.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1830 "parser/matcha.tab.c"
    break;

  case 68: /* Statement: Block  */
#line 314 "parser/matcha.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1836 "parser/matcha.tab.c"
    break;

  case 69: /* ExpressionStatement: Expression ';'  */
#line 318 "parser/matcha.y"
                     { (yyval.node) = (yyvsp[-1].node); }
#line 1842 "parser/matcha.tab.c"
    break;

  case 70: /* IfStatement: IF '(' Expression ')' Statement  */
#line 322 "parser/matcha.y"
                                      { 
        (yyval.node) = makeIfNode((yyvsp[-2].node), (yyvsp[0].node), NULL);
      }
#line 1850 "parser/matcha.tab.c"
    break;

  case 71: /* IfStatement: IF '(' Expression ')' Statement ELSE Statement  */
#line 325 "parser/matcha.y"
                                                     { 
        (yyval.node) = makeIfNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1858 "parser/matcha.tab.c"
    break;

  case 72: /* WhileStatement: WHILE '(' Expression ')' Statement  */
#line 331 "parser/matcha.y"
                                       { 
        (yyval.node) = makeWhileNode((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1866 "parser/matcha.tab.c"
    break;

  case 73: /* ForStatement: FOR '(' ForInitOpt ';' ExpressionOpt ';' ExpressionOpt ')' Statement  */
#line 337 "parser/matcha.y"
                                                                         { 
        (yyval.node) = makeForNode((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1874 "parser/matcha.tab.c"
    break;

  case 74: /* ForInitOpt: %empty  */
#line 343 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1880 "parser/matcha.tab.c"
    break;

  case 75: /* ForInitOpt: VarDecl  */
#line 344 "parser/matcha.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1886 "parser/matcha.tab.c"
    break;

  case 76: /* ForInitOpt: Expression  */
#line 345 "parser/matcha.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1892 "parser/matcha.tab.c"
    break;

  case 77: /* ExpressionOpt: %empty  */
#line 349 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1898 "parser/matcha.tab.c"
    break;

  case 78: /* ExpressionOpt: Expression  */
#line 350 "parser/matcha.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1904 "parser/matcha.tab.c"
    break;

  case 79: /* ForEachStatement: FOR '(' Type IDENTIFIER ':' Expression ')' Statement  */
#line 354 "parser/matcha.y"
                                                         { 
        (yyval.node) = makeForEachNode((yyvsp[-5].node), (yyvsp[-4].id), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1912 "parser/matcha.tab.c"
    break;

  case 80: /* ReturnStatement: RETURN Expression ';'  */
#line 360 "parser/matcha.y"
                          { 
        (yyval.node) = makeVoidNode(NODE_RETURN);
        (yyval.node)->left = (yyvsp[-1].node);
    }
#line 1921 "parser/matcha.tab.c"
    break;

  case 81: /* ParamListOpt: %empty  */
#line 367 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 1927 "parser/matcha.tab.c"
    break;

  case 82: /* ParamListOpt: ParamList  */
#line 368 "parser/matcha.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1933 "parser/matcha.tab.c"
    break;

  case 83: /* ParamList: Param  */
#line 372 "parser/matcha.y"
            { 
        (yyval.node) = makeListNode(NODE_PARAM_LIST);
        (yyval.node)->left = (yyvsp[0].node);
      }
#line 1942 "parser/matcha.tab.c"
    break;

  case 84: /* ParamList: ParamList ',' Param  */
#line 376 "parser/matcha.y"
                          { 
        (yyval.node) = appendToList((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1950 "parser/matcha.tab.c"
    break;

  case 85: /* Param: Type IDENTIFIER  */
#line 382 "parser/matcha.y"
                    { 
        (yyval.node) = makeVoidNode(NODE_PARAM);
        (yyval.node)->left = (yyvsp[-1].node);
        (yyval.node)->right = makeIdentifierNode((yyvsp[0].id));
    }
#line 1960 "parser/matcha.tab.c"
    break;

  case 86: /* Expression: Literal  */
#line 390 "parser/matcha.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1966 "parser/matcha.tab.c"
    break;

  case 87: /* Expression: ObjectInit  */
#line 391 "parser/matcha.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1972 "parser/matcha.tab.c"
    break;

  case 88: /* Expression: Accessor  */
#line 392 "parser/matcha.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1978 "parser/matcha.tab.c"
    break;

  case 89: /* Expression: '(' Expression ')'  */
#line 393 "parser/matcha.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1984 "parser/matcha.tab.c"
    break;

  case 90: /* Expression: Expression BinOp Expression  */
#line 394 "parser/matcha.y"
                                  { 
        (yyval.node) = makeBinOpNode((yyvsp[-1].node)->type, (yyvsp[-2].node), (yyvsp[0].node));
        free((yyvsp[-1].node)); // освобождаем временный узел оператора
      }
#line 1993 "parser/matcha.tab.c"
    break;

  case 91: /* Expression: Lvalue AssignOp Expression  */
#line 398 "parser/matcha.y"
                                 { 
        (yyval.node) = makeBinOpNode((yyvsp[-1].node)->type, (yyvsp[-2].node), (yyvsp[0].node));
        free((yyvsp[-1].node)); // освобождаем временный узел оператора
      }
#line 2002 "parser/matcha.tab.c"
    break;

  case 92: /* Lvalue: Accessor  */
#line 405 "parser/matcha.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 2008 "parser/matcha.tab.c"
    break;

  case 93: /* AssignOp: '='  */
#line 409 "parser/matcha.y"
          { (yyval.node) = makeVoidNode(NODE_ASSIGN); }
#line 2014 "parser/matcha.tab.c"
    break;

  case 94: /* AssignOp: ADD_ASSIGN  */
#line 410 "parser/matcha.y"
                 { (yyval.node) = makeVoidNode(NODE_ADD_ASSIGN); }
#line 2020 "parser/matcha.tab.c"
    break;

  case 95: /* AssignOp: SUB_ASSIGN  */
#line 411 "parser/matcha.y"
                 { (yyval.node) = makeVoidNode(NODE_SUB_ASSIGN); }
#line 2026 "parser/matcha.tab.c"
    break;

  case 96: /* AssignOp: MUL_ASSIGN  */
#line 412 "parser/matcha.y"
                 { (yyval.node) = makeVoidNode(NODE_MUL_ASSIGN); }
#line 2032 "parser/matcha.tab.c"
    break;

  case 97: /* AssignOp: DIV_ASSIGN  */
#line 413 "parser/matcha.y"
                 { (yyval.node) = makeVoidNode(NODE_DIV_ASSIGN); }
#line 2038 "parser/matcha.tab.c"
    break;

  case 98: /* Literal: LIT_INTEGER  */
#line 417 "parser/matcha.y"
                  { (yyval.node) = makeIntNode((yyvsp[0].int_val)); }
#line 2044 "parser/matcha.tab.c"
    break;

  case 99: /* Literal: LIT_DOUBLE  */
#line 418 "parser/matcha.y"
                 { (yyval.node) = makeDoubleNode((yyvsp[0].double_val)); }
#line 2050 "parser/matcha.tab.c"
    break;

  case 100: /* Literal: LIT_STRING  */
#line 419 "parser/matcha.y"
                 { (yyval.node) = makeStringNode((yyvsp[0].str_val)); }
#line 2056 "parser/matcha.tab.c"
    break;

  case 101: /* Literal: LIT_BOOL  */
#line 420 "parser/matcha.y"
               { (yyval.node) = makeBoolNode((yyvsp[0].bool_val)); }
#line 2062 "parser/matcha.tab.c"
    break;

  case 102: /* BinOp: '+'  */
#line 424 "parser/matcha.y"
        { (yyval.node) = makeVoidNode(NODE_ADD); }
#line 2068 "parser/matcha.tab.c"
    break;

  case 103: /* BinOp: '-'  */
#line 425 "parser/matcha.y"
          { (yyval.node) = makeVoidNode(NODE_SUB); }
#line 2074 "parser/matcha.tab.c"
    break;

  case 104: /* BinOp: '*'  */
#line 426 "parser/matcha.y"
          { (yyval.node) = makeVoidNode(NODE_MUL); }
#line 2080 "parser/matcha.tab.c"
    break;

  case 105: /* BinOp: '/'  */
#line 427 "parser/matcha.y"
          { (yyval.node) = makeVoidNode(NODE_DIV); }
#line 2086 "parser/matcha.tab.c"
    break;

  case 106: /* BinOp: EQEQ  */
#line 428 "parser/matcha.y"
           { (yyval.node) = makeVoidNode(NODE_EQ); }
#line 2092 "parser/matcha.tab.c"
    break;

  case 107: /* BinOp: NOTEQ  */
#line 429 "parser/matcha.y"
            { (yyval.node) = makeVoidNode(NODE_NEQ); }
#line 2098 "parser/matcha.tab.c"
    break;

  case 108: /* BinOp: '<'  */
#line 430 "parser/matcha.y"
          { (yyval.node) = makeVoidNode(NODE_LT); }
#line 2104 "parser/matcha.tab.c"
    break;

  case 109: /* BinOp: '>'  */
#line 431 "parser/matcha.y"
          { (yyval.node) = makeVoidNode(NODE_GT); }
#line 2110 "parser/matcha.tab.c"
    break;

  case 110: /* Accessor: IDENTIFIER  */
#line 435 "parser/matcha.y"
                 { (yyval.node) = makeIdentifierNode((yyvsp[0].id)); }
#line 2116 "parser/matcha.tab.c"
    break;

  case 111: /* Accessor: Accessor '.' IDENTIFIER  */
#line 436 "parser/matcha.y"
                              { 
        (yyval.node) = makeVoidNode(NODE_MEMBER_ACCESS);
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = makeIdentifierNode((yyvsp[0].id));
      }
#line 2126 "parser/matcha.tab.c"
    break;

  case 112: /* IncludeDecl: INCLUDE IDENTIFIER ExcludeListOpt ';'  */
#line 444 "parser/matcha.y"
                                          { 
        (yyval.node) = makeVoidNode(NODE_INCLUDE);
        (yyval.node)->left = makeIdentifierNode((yyvsp[-2].id));
        (yyval.node)->right = (yyvsp[-1].node);
    }
#line 2136 "parser/matcha.tab.c"
    break;

  case 113: /* ExcludeListOpt: %empty  */
#line 452 "parser/matcha.y"
                  { (yyval.node) = NULL; }
#line 2142 "parser/matcha.tab.c"
    break;

  case 114: /* ExcludeListOpt: '\\' ExcludeList  */
#line 453 "parser/matcha.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2148 "parser/matcha.tab.c"
    break;

  case 115: /* ExcludeList: IDENTIFIER  */
#line 457 "parser/matcha.y"
                 { 
        (yyval.node) = makeListNode(NODE_EXPRESSION_LIST);
        (yyval.node)->left = makeIdentifierNode((yyvsp[0].id));
      }
#line 2157 "parser/matcha.tab.c"
    break;

  case 116: /* ExcludeList: ExcludeList ',' IDENTIFIER  */
#line 461 "parser/matcha.y"
                                 { 
        (yyval.node) = appendToList((yyvsp[-2].node), makeIdentifierNode((yyvsp[0].id)));
      }
#line 2165 "parser/matcha.tab.c"
    break;


#line 2169 "parser/matcha.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 466 "parser/matcha.y"


void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d, column %d: %s\n", line_num, col_num, s);
    if (yytext) fprintf(stderr, "Near '%s'\n", yytext);
}
