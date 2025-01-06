/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "yaccfile.yacc"

#include "absyn.hpp"
#include "lexer.h"
#include <iostream>

extern int line_nr;
extern int col_nr;
void yyerror(const char* str);

Stm tree;

/* Line 371 of yacc.c  */
#line 80 "y.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FN = 258,
     LPAREN = 259,
     RPAREN = 260,
     ARROW = 261,
     LBRACE = 262,
     RBRACE = 263,
     SEMICOLON = 264,
     COLON = 265,
     LET = 266,
     ANDAND = 267,
     OROR = 268,
     NOT = 269,
     GT = 270,
     GE = 271,
     LT = 272,
     LE = 273,
     EQEQ = 274,
     NE = 275,
     AMPERSAND = 276,
     IF = 277,
     ELSE = 278,
     WHILE = 279,
     MUT = 280,
     COMMA = 281,
     INT = 282,
     BOOL = 283,
     MINUS = 284,
     PLUS = 285,
     SLASH = 286,
     STAR = 287,
     IDENTIFIER = 288,
     PRINTSTRING = 289,
     DEC_LITERAL = 290,
     PLUSEQ = 291,
     MINUSEQ = 292,
     EQ = 293,
     PRINTVAR = 294,
     TRUE = 295,
     FALSE = 296
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 23 "yaccfile.yacc"

    char* id;
    int num;
    bool boolean;

    Exp exp;
    Stm stm;
    ExpList explist;
    Func func;
    FuncList funclist;

    Program *program;

    DataType dtype;
    Binop binop;
    AssignOp assignop;
    ConditionalOp condop;

    LetStm *letstm;
    AssignStm *assignstm;
    BlockStm *blockstm;
    DeclarationStm *decstm;
    IfStm *ifstm;
    PrintStm *printstm;
    VarPrintStm *varprintstm;
    ExprStm *exprstm;
    WhileStm *whilestm;

    IdExp *idexp;
    BoolExp *boolexp;
    NumExp *numexp;
    BinopExp *binopexp;
    BlockExp *blockexp;
    GroupedExp *groupexp;
    FunctionExp *funcexp;
    IfExp *ifexp;

    PairArgsExpList *arglist;
    LastArgsExpList *lastarglist;
    PairParamExpList *parmlist;
    LastParamExpList *lastparmlist;
    LastFuncList *lastfunclist;
    PairFuncList *pairfunclist;

    ConditionalExp *condexp;
    NotCondExp *notcondexp;
    CompareCondExp *compcondexp;
    AndCond *andcond;
    OrCond *orcond;
    EqualCond *eqcond;

    CompoundStm *compoundstm;
    FuncDefStm *funcdefstm;
    FuncDefExp *funcdefexp;


/* Line 387 of yacc.c  */
#line 221 "y.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 249 "y.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    15,    17,    20,
      22,    25,    28,    31,    33,    41,    47,    51,    55,    61,
      65,    71,    73,    75,    79,    83,    87,    91,    93,    95,
      97,    99,   101,   103,   105,   107,   109,   111,   113,   115,
     117,   119,   121,   123,   125,   127,   129,   131,   133,   135,
     139,   143,   147,   151,   156,   160,   165,   169,   175,   182,
     191,   198,   207,   210,   212,   215,   216,   218,   220,   222,
     223,   227,   229,   230,   236,   240,   242,   244,   246,   248,
     250,   252,   254,   256
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    66,    -1,    -1,    44,    45,    -1,    46,
       9,    -1,    47,     9,    -1,    48,    -1,    49,     9,    -1,
      50,    -1,    51,     9,    -1,    52,     9,    -1,    55,     9,
      -1,    53,    -1,    11,    68,    33,    10,    69,    38,    55,
      -1,    11,    68,    33,    38,    55,    -1,    33,    73,    55,
      -1,     7,    44,     8,    -1,    11,    68,    33,    10,    69,
      -1,    22,    55,    48,    -1,    22,    55,    48,    23,    48,
      -1,    34,    -1,    39,    -1,    24,    55,    48,    -1,    55,
      72,    56,    -1,    55,    12,    55,    -1,    55,    13,    55,
      -1,    54,    -1,    59,    -1,    57,    -1,    60,    -1,    61,
      -1,    62,    -1,    58,    -1,    63,    -1,    64,    -1,    67,
      -1,    59,    -1,    57,    -1,    58,    -1,    61,    -1,    63,
      -1,    60,    -1,    62,    -1,    64,    -1,    33,    -1,    40,
      -1,    41,    -1,    35,    -1,    56,    30,    56,    -1,    56,
      29,    56,    -1,    56,    32,    56,    -1,    56,    31,    56,
      -1,     7,    44,    55,     8,    -1,     4,    55,     5,    -1,
      33,     4,    70,     5,    -1,    22,    55,    61,    -1,    22,
      55,    61,    23,    61,    -1,     3,    33,     4,    71,     5,
      48,    -1,     3,    33,     4,    71,     5,     6,    69,    48,
      -1,     3,    33,     4,    71,     5,    61,    -1,     3,    33,
       4,    71,     5,     6,    69,    61,    -1,    66,    65,    -1,
      65,    -1,    14,    55,    -1,    -1,    25,    -1,    27,    -1,
      28,    -1,    -1,    70,    26,    55,    -1,    55,    -1,    -1,
      71,    26,    33,    10,    69,    -1,    33,    10,    69,    -1,
      17,    -1,    18,    -1,    15,    -1,    16,    -1,    19,    -1,
      20,    -1,    38,    -1,    36,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   132,   133,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   147,   148,   151,   154,   157,   160,
     161,   164,   167,   170,   175,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   193,   194,   195,
     196,   197,   198,   199,   200,   205,   208,   209,   212,   215,
     216,   217,   218,   221,   224,   227,   230,   231,   236,   237,
     238,   239,   242,   243,   246,   252,   253,   256,   257,   260,
     261,   262,   265,   266,   267,   270,   271,   272,   273,   274,
     275,   278,   279,   280
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FN", "LPAREN", "RPAREN", "ARROW",
  "LBRACE", "RBRACE", "SEMICOLON", "COLON", "LET", "ANDAND", "OROR", "NOT",
  "GT", "GE", "LT", "LE", "EQEQ", "NE", "AMPERSAND", "IF", "ELSE", "WHILE",
  "MUT", "COMMA", "INT", "BOOL", "MINUS", "PLUS", "SLASH", "STAR",
  "IDENTIFIER", "PRINTSTRING", "DEC_LITERAL", "PLUSEQ", "MINUSEQ", "EQ",
  "PRINTVAR", "TRUE", "FALSE", "$accept", "ProgramType", "CompoundStmType",
  "StmType", "LetStmType", "AssignStmType", "BlockStmType", "DecStmType",
  "IfStmType", "PrintStmType", "VarPrintStmType", "WhileStmStype",
  "CompareCondExpType", "ExpType", "Term", "IdExpType", "BoolExpType",
  "NumExpType", "BinopExpType", "BlockExpType", "GroupExpType",
  "FunctionExpType", "IfExpType", "FunctionType", "function_list",
  "NotCondType", "mutability", "type", "argument_list", "parameter_list",
  "conditional_operator", "assignment_operator", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    47,    48,    49,    50,
      50,    51,    52,    53,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    58,    59,    60,
      60,    60,    60,    61,    62,    63,    64,    64,    65,    65,
      65,    65,    66,    66,    67,    68,    68,    69,    69,    70,
      70,    70,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    73,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     1,     2,     1,
       2,     2,     2,     1,     7,     5,     3,     3,     5,     3,
       5,     1,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     4,     3,     4,     3,     5,     6,     8,
       6,     8,     2,     1,     2,     0,     1,     1,     1,     0,
       3,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    63,     2,     0,     1,    62,    72,     0,
       0,     0,     0,     0,    67,    68,    74,     0,     3,    58,
      60,     0,     0,     0,     0,    59,    61,     0,    17,    65,
       0,     0,     0,    45,    21,    48,    22,    46,    47,     4,
       0,     0,     7,     0,     9,     0,     0,    13,    27,     0,
       0,    29,    33,    28,    30,    31,    32,    34,    35,    36,
      73,     3,     0,    45,     0,    66,     0,    64,     0,     0,
      69,    82,    83,    81,     0,     5,     6,     8,    10,    11,
      53,    12,     0,     0,    77,    78,    75,    76,    79,    80,
       0,     0,     0,     0,     0,     0,     0,    54,     0,    19,
      56,     3,    23,    71,     0,    16,    25,    26,    24,    38,
      39,    37,    42,    40,    43,    41,    44,    50,    49,    52,
      51,     0,     0,     0,     0,     0,    55,     0,    18,    15,
      20,    57,     0,    70,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    23,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     3,     4,    59,    66,    16,   104,    10,
      90,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const yytype_int16 yypact[] =
{
       4,   -24,    16,   -59,     4,     9,   -59,   -59,   -13,    15,
       0,     8,    32,    -3,   -59,   -59,   -59,     8,   -59,   -59,
     -59,    18,    26,     7,     8,   -59,   -59,    30,   -59,    20,
      30,    30,    30,    13,   -59,   -59,   -59,   -59,   -59,   -59,
      44,    46,   -59,    48,   -59,    55,    58,   -59,   -59,   188,
     140,   230,   234,   238,   242,   246,   250,   254,   258,   -59,
     -59,   -59,    30,    64,    78,   -59,    36,   -59,   147,   161,
      30,   -59,   -59,   -59,    30,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,    30,    30,   -59,   -59,   -59,   -59,   -59,   -59,
     117,   117,   117,   117,   117,    96,   175,   -59,    -6,    49,
      50,   -59,   -59,   197,     1,   197,   203,   203,   140,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,    29,    29,   -59,
     -59,     8,    30,    69,    70,     7,   -59,    30,    54,   197,
     -59,   -59,   129,   197,    30,   197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -58,   -59,   -59,   -59,   -10,   -59,   -59,   -59,
     -59,   -59,   -59,    -8,    -5,   134,   139,   144,   149,   -12,
     154,   159,   164,    95,   -59,   -59,   -59,   -16,   -59,   -59,
     -59,   -59
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int16 yytable[] =
{
      20,    22,    19,    95,   121,    12,   126,     1,    60,     5,
      26,    27,    25,     8,    18,    28,     6,    70,    29,    64,
       9,    30,    67,    68,    69,    11,    13,   127,    24,    31,
      21,    32,   122,    18,    27,    14,    15,    61,    17,    18,
      33,    34,    35,   125,    30,    65,    36,    37,    38,    71,
      72,    73,    62,    75,    96,    76,   100,    77,    99,   102,
      93,    94,   103,    63,    78,    35,   105,    79,    70,    98,
      37,    38,   123,   124,   106,   107,   101,    61,   113,   113,
     113,   113,   113,    97,   100,   108,   117,   118,   119,   120,
      82,    83,   134,    84,    85,    86,    87,    88,    89,     7,
      27,     0,     0,    18,     0,   128,     0,    29,     0,     0,
      30,     0,   131,   130,   129,     0,     0,   132,    31,   133,
      32,    27,     0,     0,    61,     0,   135,     0,     0,    33,
      34,    35,     0,     0,     0,    36,    37,    38,    81,    62,
       0,    82,    83,     0,    84,    85,    86,    87,    88,    89,
      63,     0,    35,     0,    18,     0,     0,    37,    38,    82,
      83,     0,    84,    85,    86,    87,    88,    89,   101,    91,
      92,    93,    94,    82,    83,     0,    84,    85,    86,    87,
      88,    89,    61,     0,     0,     0,     0,    82,    83,     0,
      84,    85,    86,    87,    88,    89,    80,    81,     0,     0,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    82,
      83,     0,    84,    85,    86,    87,    88,    89,    84,    85,
      86,    87,    88,    89,   109,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   114,   114,   114,   114,   114,   115,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   -38,
     -38,   -38,   -38,   -39,   -39,   -39,   -39,   -37,   -37,   -37,
     -37,   -42,   -42,   -42,   -42,   -40,   -40,   -40,   -40,   -43,
     -43,   -43,   -43,   -41,   -41,   -41,   -41,   -44,   -44,   -44,
     -44
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      12,    17,    12,    61,    10,     5,     5,     3,    24,    33,
      22,     4,    22,     4,     7,     8,     0,     4,    11,    27,
      33,    14,    30,    31,    32,    10,    26,    26,    10,    22,
      33,    24,    38,     7,     4,    27,    28,     7,     6,     7,
      33,    34,    35,   101,    14,    25,    39,    40,    41,    36,
      37,    38,    22,     9,    62,     9,    68,     9,    68,    69,
      31,    32,    70,    33,     9,    35,    74,     9,     4,    33,
      40,    41,    23,    23,    82,    83,     7,     7,    90,    91,
      92,    93,    94,     5,    96,    90,    91,    92,    93,    94,
      12,    13,    38,    15,    16,    17,    18,    19,    20,     4,
       4,    -1,    -1,     7,    -1,   121,    -1,    11,    -1,    -1,
      14,    -1,   124,   123,   122,    -1,    -1,   125,    22,   127,
      24,     4,    -1,    -1,     7,    -1,   134,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,     9,    22,
      -1,    12,    13,    -1,    15,    16,    17,    18,    19,    20,
      33,    -1,    35,    -1,     7,    -1,    -1,    40,    41,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,     7,    29,
      30,    31,    32,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,     7,    -1,    -1,    -1,    -1,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,     8,     9,    -1,    -1,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    15,    16,
      17,    18,    19,    20,    90,    91,    92,    93,    94,    90,
      91,    92,    93,    94,    90,    91,    92,    93,    94,    90,
      91,    92,    93,    94,    90,    91,    92,    93,    94,    90,
      91,    92,    93,    94,    90,    91,    92,    93,    94,    29,
      30,    31,    32,    29,    30,    31,    32,    29,    30,    31,
      32,    29,    30,    31,    32,    29,    30,    31,    32,    29,
      30,    31,    32,    29,    30,    31,    32,    29,    30,    31,
      32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    65,    66,    33,     0,    65,     4,    33,
      71,    10,     5,    26,    27,    28,    69,     6,     7,    48,
      61,    33,    69,    44,    10,    48,    61,     4,     8,    11,
      14,    22,    24,    33,    34,    35,    39,    40,    41,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    67,
      69,     7,    22,    33,    55,    25,    68,    55,    55,    55,
       4,    36,    37,    38,    73,     9,     9,     9,     9,     9,
       8,     9,    12,    13,    15,    16,    17,    18,    19,    20,
      72,    29,    30,    31,    32,    44,    55,     5,    33,    48,
      61,     7,    48,    55,    70,    55,    55,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    56,    56,    56,
      56,    10,    38,    23,    23,    44,     5,    26,    69,    55,
      48,    61,    55,    55,    38,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 127 "yaccfile.yacc"
    {(yyval.program) = new Program((yyvsp[(1) - (1)].funclist)); tree = (yyval.program);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 132 "yaccfile.yacc"
    { (yyval.compoundstm) = nullptr;}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 133 "yaccfile.yacc"
    {(yyval.compoundstm) = new CompoundStm((yyvsp[(1) - (2)].compoundstm), (yyvsp[(2) - (2)].stm));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 136 "yaccfile.yacc"
    {(yyval.stm) = (yyvsp[(1) - (2)].letstm);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 137 "yaccfile.yacc"
    {(yyval.stm) = (yyvsp[(1) - (2)].assignstm);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 138 "yaccfile.yacc"
    {(yyval.stm) = (yyvsp[(1) - (1)].blockstm);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 139 "yaccfile.yacc"
    {(yyval.stm) = (yyvsp[(1) - (2)].decstm);}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 140 "yaccfile.yacc"
    {(yyval.stm) = (yyvsp[(1) - (1)].ifstm);}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 141 "yaccfile.yacc"
    {(yyval.stm) = (yyvsp[(1) - (2)].printstm);}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 142 "yaccfile.yacc"
    {(yyval.stm) = (yyvsp[(1) - (2)].varprintstm);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 143 "yaccfile.yacc"
    {(yyval.stm) = new ExprStm((yyvsp[(1) - (2)].exp));}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 144 "yaccfile.yacc"
    { (yyval.stm) = (yyvsp[(1) - (1)].whilestm);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 147 "yaccfile.yacc"
    {(yyval.letstm) = new LetStm((yyvsp[(3) - (7)].id), (yyvsp[(7) - (7)].exp), (yyvsp[(5) - (7)].dtype), (yyvsp[(2) - (7)].boolean));}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 148 "yaccfile.yacc"
    {(yyval.letstm) = new LetStm((yyvsp[(3) - (5)].id), (yyvsp[(5) - (5)].exp), (yyvsp[(2) - (5)].boolean));}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 151 "yaccfile.yacc"
    {(yyval.assignstm) = new AssignStm((yyvsp[(1) - (3)].id), (yyvsp[(2) - (3)].assignop), (yyvsp[(3) - (3)].exp));}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 154 "yaccfile.yacc"
    {(yyval.blockstm) = new BlockStm((yyvsp[(2) - (3)].compoundstm));}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 157 "yaccfile.yacc"
    {(yyval.decstm) = new DeclarationStm((yyvsp[(3) - (5)].id), (yyvsp[(5) - (5)].dtype), (yyvsp[(2) - (5)].boolean));}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 160 "yaccfile.yacc"
    {(yyval.ifstm) = new IfStm((yyvsp[(2) - (3)].exp), (yyvsp[(3) - (3)].blockstm));}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 161 "yaccfile.yacc"
    {(yyval.ifstm) = new IfStm((yyvsp[(2) - (5)].exp), (yyvsp[(3) - (5)].blockstm), (yyvsp[(5) - (5)].blockstm));}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 164 "yaccfile.yacc"
    { (yyval.printstm) = new PrintStm((yyvsp[(1) - (1)].id));}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 167 "yaccfile.yacc"
    { (yyval.varprintstm) = new VarPrintStm((yyvsp[(1) - (1)].exp));}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 170 "yaccfile.yacc"
    { (yyval.whilestm) = new WhileStm((yyvsp[(2) - (3)].exp), (yyvsp[(3) - (3)].blockstm));}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 175 "yaccfile.yacc"
    {(yyval.compcondexp) = new CompareCondExp((yyvsp[(1) - (3)].exp), (yyvsp[(2) - (3)].condop), (yyvsp[(3) - (3)].exp));}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 179 "yaccfile.yacc"
    {(yyval.exp) = new AndCond((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 180 "yaccfile.yacc"
    {(yyval.exp) = new OrCond((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 181 "yaccfile.yacc"
    {(yyval.exp) = (yyvsp[(1) - (1)].compcondexp);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 182 "yaccfile.yacc"
    {(yyval.exp) = (yyvsp[(1) - (1)].numexp);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 183 "yaccfile.yacc"
    {(yyval.exp) = (yyvsp[(1) - (1)].idexp);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 184 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].binopexp);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 185 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].blockexp);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 186 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].groupexp);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 187 "yaccfile.yacc"
    {(yyval.exp) = (yyvsp[(1) - (1)].boolexp);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 188 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].funcexp);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 189 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].ifexp);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 190 "yaccfile.yacc"
    {(yyval.exp) = (yyvsp[(1) - (1)].notcondexp);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 193 "yaccfile.yacc"
    {(yyval.exp) = (yyvsp[(1) - (1)].numexp);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 194 "yaccfile.yacc"
    {(yyval.exp) = (yyvsp[(1) - (1)].idexp);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 195 "yaccfile.yacc"
    {(yyval.exp) = (yyvsp[(1) - (1)].boolexp);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 196 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].blockexp);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 197 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].funcexp);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 198 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].binopexp);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 199 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].groupexp);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 200 "yaccfile.yacc"
    { (yyval.exp) = (yyvsp[(1) - (1)].ifexp);}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 205 "yaccfile.yacc"
    {(yyval.idexp) = new IdExp((yyvsp[(1) - (1)].id));}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 208 "yaccfile.yacc"
    { (yyval.boolexp) = new BoolExp(true);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 209 "yaccfile.yacc"
    { (yyval.boolexp) = new BoolExp(false);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 212 "yaccfile.yacc"
    {(yyval.numexp) = new NumExp((yyvsp[(1) - (1)].num));}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 215 "yaccfile.yacc"
    {(yyval.binopexp) = new BinopExp((yyvsp[(1) - (3)].exp), Plus, (yyvsp[(3) - (3)].exp));}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 216 "yaccfile.yacc"
    {(yyval.binopexp) = new BinopExp((yyvsp[(1) - (3)].exp), Minus, (yyvsp[(3) - (3)].exp));}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 217 "yaccfile.yacc"
    {(yyval.binopexp) = new BinopExp((yyvsp[(1) - (3)].exp), Times, (yyvsp[(3) - (3)].exp));}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 218 "yaccfile.yacc"
    {(yyval.binopexp) = new BinopExp((yyvsp[(1) - (3)].exp), Divide, (yyvsp[(3) - (3)].exp));}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 221 "yaccfile.yacc"
    {(yyval.blockexp) = new BlockExp((yyvsp[(2) - (4)].compoundstm), (yyvsp[(3) - (4)].exp));}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 224 "yaccfile.yacc"
    { (yyval.groupexp) = new GroupedExp((yyvsp[(2) - (3)].exp));}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 227 "yaccfile.yacc"
    { (yyval.funcexp) = new FunctionExp((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].explist));}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 230 "yaccfile.yacc"
    {(yyval.ifexp) = new IfExp((yyvsp[(2) - (3)].exp), (yyvsp[(3) - (3)].blockexp));}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 231 "yaccfile.yacc"
    {(yyval.ifexp) = new IfExp((yyvsp[(2) - (5)].exp), (yyvsp[(3) - (5)].blockexp), (yyvsp[(5) - (5)].blockexp));}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 236 "yaccfile.yacc"
    {(yyval.func) = new FuncDefStm((yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].explist), (yyvsp[(6) - (6)].blockstm));}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 237 "yaccfile.yacc"
    {(yyval.func) = new FuncDefStm((yyvsp[(2) - (8)].id), (yyvsp[(4) - (8)].explist), (yyvsp[(7) - (8)].dtype), (yyvsp[(8) - (8)].blockstm));}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 238 "yaccfile.yacc"
    {(yyval.func) = new FuncDefExp((yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].explist), (yyvsp[(6) - (6)].blockexp));}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 239 "yaccfile.yacc"
    {(yyval.func) = new FuncDefExp((yyvsp[(2) - (8)].id), (yyvsp[(4) - (8)].explist), (yyvsp[(7) - (8)].dtype), (yyvsp[(8) - (8)].blockexp));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 242 "yaccfile.yacc"
    { (yyval.funclist) = new PairFuncList((yyvsp[(2) - (2)].func), (yyvsp[(1) - (2)].funclist));}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 243 "yaccfile.yacc"
    { (yyval.funclist) = new LastFuncList((yyvsp[(1) - (1)].func));}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 246 "yaccfile.yacc"
    {(yyval.notcondexp) = new NotCondExp((yyvsp[(2) - (2)].exp));}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 252 "yaccfile.yacc"
    {(yyval.boolean) = false;}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 253 "yaccfile.yacc"
    {(yyval.boolean) = true;}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 256 "yaccfile.yacc"
    { (yyval.dtype) = Int;}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 257 "yaccfile.yacc"
    {(yyval.dtype) = Bool;}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 260 "yaccfile.yacc"
    { (yyval.explist) = nullptr;}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 261 "yaccfile.yacc"
    { (yyval.explist) = new PairArgsExpList((yyvsp[(3) - (3)].exp), (yyvsp[(1) - (3)].explist));}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 262 "yaccfile.yacc"
    {(yyval.explist) = new LastArgsExpList((yyvsp[(1) - (1)].exp));}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 265 "yaccfile.yacc"
    { (yyval.explist) = nullptr;}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 266 "yaccfile.yacc"
    { (yyval.explist) = new PairParamExpList((yyvsp[(3) - (5)].id), (yyvsp[(5) - (5)].dtype), (yyvsp[(1) - (5)].explist));}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 267 "yaccfile.yacc"
    { (yyval.explist) = new LastParamExpList((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].dtype));}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 270 "yaccfile.yacc"
    {(yyval.condop) = Less;}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 271 "yaccfile.yacc"
    {(yyval.condop) = LessEqual;}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 272 "yaccfile.yacc"
    {(yyval.condop) = Greater;}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 273 "yaccfile.yacc"
    {(yyval.condop) = GreaterEqual;}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 274 "yaccfile.yacc"
    {(yyval.condop) = EqualEqual;}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 275 "yaccfile.yacc"
    {(yyval.condop) = NotEqual;}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 278 "yaccfile.yacc"
    {(yyval.assignop) = Equals;}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 279 "yaccfile.yacc"
    {(yyval.assignop) = PlusEquals;}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 280 "yaccfile.yacc"
    {(yyval.assignop) = MinusEquals;}
    break;


/* Line 1792 of yacc.c  */
#line 2095 "y.tab.cpp"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 283 "yaccfile.yacc"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s on at %i:%i\n", s, line_nr, col_nr);

    if (yytext) {
        fprintf(stderr, "Offending token: '%s'\n", yytext);
    } else {
        fprintf(stderr, "Unknown error at token.\n");
    }
}