/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGN = 258,
     NOT_EQUAL = 259,
     LESS_THAN = 260,
     GREATER_THAN = 261,
     LESS_OR_EQUAL = 262,
     GREATER_OR_EQUAL = 263,
     EQUAL_EQUAL = 264,
     AND = 265,
     OR = 266,
     PLUS = 267,
     MINUS = 268,
     TIMES = 269,
     DIVIDE = 270,
     COLON = 271,
     SEMICOLON = 272,
     COMMA = 273,
     LEFT_BRACES = 274,
     RIGHT_BRACES = 275,
     LEFT_SQUARE = 276,
     RIGHT_SQUARE = 277,
     LEFT_PARENTHESIS = 278,
     RIGHT_PARENTHESIS = 279,
     NOT = 280,
     UNKNOWN = 281,
     T_TRUE = 282,
     T_FALSE = 283,
     CHARACTER = 284,
     STRINGVAL = 285,
     ID = 286,
     NUMERAL = 287,
     INTEGER = 288,
     CHAR = 289,
     BOOLEAN = 290,
     STRING = 291,
     VAR = 292,
     IF = 293,
     ELSE = 294,
     WHILE = 295,
     DO = 296,
     BREAK = 297
   };
#endif
/* Tokens.  */
#define ASSIGN 258
#define NOT_EQUAL 259
#define LESS_THAN 260
#define GREATER_THAN 261
#define LESS_OR_EQUAL 262
#define GREATER_OR_EQUAL 263
#define EQUAL_EQUAL 264
#define AND 265
#define OR 266
#define PLUS 267
#define MINUS 268
#define TIMES 269
#define DIVIDE 270
#define COLON 271
#define SEMICOLON 272
#define COMMA 273
#define LEFT_BRACES 274
#define RIGHT_BRACES 275
#define LEFT_SQUARE 276
#define RIGHT_SQUARE 277
#define LEFT_PARENTHESIS 278
#define RIGHT_PARENTHESIS 279
#define NOT 280
#define UNKNOWN 281
#define T_TRUE 282
#define T_FALSE 283
#define CHARACTER 284
#define STRINGVAL 285
#define ID 286
#define NUMERAL 287
#define INTEGER 288
#define CHAR 289
#define BOOLEAN 290
#define STRING 291
#define VAR 292
#define IF 293
#define ELSE 294
#define WHILE 295
#define DO 296
#define BREAK 297




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

	#include <stdio.h>
        #include <stdlib.h>
        #include "type_analisys.h"
        #include "lexical.h"
	#include "scope.h"
        #include "code_generation.h"

	#include "utils.h"

	extern int yylex( void );
	
	int yyerror( char *s)
	{
	fprintf( stderr, "Erro bison: %s \n", s);
	return 1;
	}

        pobject p, t, t1, t2;
        int l, l1, l2, n, s;

        FILE* f ;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "parser.y"
{
        int boolean;
        int tokenSecundario;
        t_attrib attributedSymbol;
}
/* Line 193 of yacc.c.  */
#line 210 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 223 "parser.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  93

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    12,    14,    16,    22,
      26,    28,    30,    32,    34,    36,    41,    42,    45,    48,
      49,    50,    51,    52,    59,    69,    77,    79,    82,    85,
      87,    91,    95,    99,   103,   107,   111,   115,   119,   123,
     127,   131,   135,   137,   140,   142,   144,   146,   148,   150,
     152,   156,   158,   160,   162,   164,   166,   168
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    46,    -1,    -1,    46,    47,    -1,
      47,    -1,    48,    -1,    51,    -1,    37,    49,    16,    50,
      17,    -1,    49,    18,    61,    -1,    61,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    52,    19,    53,    20,
      -1,    -1,    58,    54,    -1,    58,    54,    -1,    -1,    -1,
      -1,    -1,    38,    23,    59,    24,    55,    58,    -1,    38,
      23,    59,    24,    55,    58,    39,    56,    58,    -1,    40,
      57,    23,    59,    24,    55,    58,    -1,    51,    -1,    59,
      17,    -1,    42,    17,    -1,    48,    -1,    59,    10,    60,
      -1,    59,    11,    60,    -1,    59,     5,    60,    -1,    59,
       6,    60,    -1,    59,     7,    60,    -1,    59,     8,    60,
      -1,    59,     9,    60,    -1,    59,     4,    60,    -1,    59,
      12,    60,    -1,    59,    13,    60,    -1,    59,    14,    60,
      -1,    59,    15,    60,    -1,    60,    -1,    25,    60,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
      62,    -1,    62,     3,    59,    -1,    31,    -1,    31,    -1,
      27,    -1,    28,    -1,    29,    -1,    30,    -1,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    87,    93,    94,    97,    98,   101,   116,
     120,   123,   126,   129,   132,   137,   141,   147,   149,   150,
     154,   162,   171,   178,   187,   197,   211,   217,   220,   224,
     227,   242,   257,   271,   285,   299,   313,   327,   341,   355,
     369,   383,   398,   403,   411,   416,   421,   426,   431,   436,
     451,   477,   492,   507,   512,   517,   523,   528
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "NOT_EQUAL", "LESS_THAN",
  "GREATER_THAN", "LESS_OR_EQUAL", "GREATER_OR_EQUAL", "EQUAL_EQUAL",
  "AND", "OR", "PLUS", "MINUS", "TIMES", "DIVIDE", "COLON", "SEMICOLON",
  "COMMA", "LEFT_BRACES", "RIGHT_BRACES", "LEFT_SQUARE", "RIGHT_SQUARE",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "NOT", "UNKNOWN", "T_TRUE",
  "T_FALSE", "CHARACTER", "STRINGVAL", "ID", "NUMERAL", "INTEGER", "CHAR",
  "BOOLEAN", "STRING", "VAR", "IF", "ELSE", "WHILE", "DO", "BREAK",
  "$accept", "PROGRAM", "OPEN", "LDE", "DE", "DV", "LI", "TP", "BLOCK",
  "NB", "LS", "LS1", "MT", "ME", "MW", "S", "E", "F", "IDD", "IDU",
  "TRUE_", "FALSE_", "CHR", "STR", "NUM", 0
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
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    46,    47,    47,    48,    49,
      49,    50,    50,    50,    50,    51,    52,    53,    54,    54,
      55,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    62,    63,    64,    65,    66,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     5,     3,
       1,     1,     1,     1,     1,     4,     0,     2,     2,     0,
       0,     0,     0,     6,     9,     7,     1,     2,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    16,     1,     0,     2,     5,     6,     7,     0,
      51,     0,    10,     4,    16,     0,     0,     0,    53,    54,
      55,    56,    52,    57,     0,    22,     0,    29,    26,     0,
      16,     0,    42,    49,    44,    45,    46,    47,    48,    11,
      12,    13,    14,     0,     9,    43,     0,     0,    28,    15,
      17,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     8,     0,     0,    18,
      37,    32,    33,    34,    35,    36,    30,    31,    38,    39,
      40,    41,    50,    20,     0,    16,    20,    23,    16,    21,
      25,    16,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    27,    11,    43,    28,     9,
      29,    50,    85,    91,    47,    51,    31,    32,    12,    33,
      34,    35,    36,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int8 yypact[] =
{
     -43,    16,   -20,   -43,   -13,    -4,   -43,   -43,   -43,     2,
     -43,    48,   -43,   -43,    65,    27,   -13,     0,   -43,   -43,
     -43,   -43,   -43,   -43,    11,   -43,    18,   -43,   -43,    45,
     -18,   104,   -43,    64,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,    52,   -43,   -43,     0,    47,   -43,   -43,
     -43,   -18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -43,     0,   -43,    44,     0,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   118,   -43,    74,    65,   -43,    33,    65,   -43,
     -43,    65,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -43,   -43,    68,     1,   -43,   -43,     3,   -43,
     -43,    24,   -10,   -43,   -43,   -14,   -42,   -16,    75,   -43,
     -43,   -43,   -43,   -43,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -20
static const yytype_int8 yytable[] =
{
      30,    45,   -19,     7,    67,     8,     7,    17,     8,    18,
      19,    20,    21,    22,    23,   -16,     3,     4,    10,     4,
      24,    14,    25,    82,    26,    17,    84,    18,    19,    20,
      21,    22,    23,     4,    46,    48,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      39,    40,    41,    42,    15,    49,    16,    65,    83,    66,
      68,    87,    89,    13,    90,    69,    88,    92,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      17,    44,    18,    19,    20,    21,    22,    23,    86,     0,
       0,     0,     4,    24,     0,    25,     0,    26,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63
};

static const yytype_int8 yycheck[] =
{
      14,    17,    20,     2,    46,     2,     5,    25,     5,    27,
      28,    29,    30,    31,    32,    19,     0,    37,    31,    37,
      38,    19,    40,    65,    42,    25,    68,    27,    28,    29,
      30,    31,    32,    37,    23,    17,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      33,    34,    35,    36,    16,    20,    18,     3,    24,    17,
      23,    85,    39,     5,    88,    51,    86,    91,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      25,    16,    27,    28,    29,    30,    31,    32,    24,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,    37,    46,    47,    48,    51,    52,
      31,    49,    61,    47,    19,    16,    18,    25,    27,    28,
      29,    30,    31,    32,    38,    40,    42,    48,    51,    53,
      58,    59,    60,    62,    63,    64,    65,    66,    67,    33,
      34,    35,    36,    50,    61,    60,    23,    57,    17,    20,
      54,    58,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    17,     3,    17,    59,    23,    54,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    59,    24,    59,    55,    24,    58,    55,    39,
      58,    56,    58
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 83 "parser.y"
    { fclose(f); ;}
    break;

  case 3:
#line 87 "parser.y"
    {
                    f = fopen("compiled_code.txt", "w");
                    NewBlock();
                ;}
    break;

  case 8:
#line 101 "parser.y"
    {
                                                p = (yyvsp[(2) - (5)].attributedSymbol)._.LI.list;
                                                t = (yyvsp[(4) - (5)].attributedSymbol)._.TP.type;
                                                while( p != NULL && p->eKind == NO_KIND_DEF_)
                                                {
                                                    p->eKind = VAR_;
                                                    p->_.Var.pType = t;

                                                    p->_.Var.nSize = (yyvsp[(4) - (5)].attributedSymbol)._.TP.size;

                                                    p = p->pNext;
                                                }
                                            ;}
    break;

  case 9:
#line 116 "parser.y"
    {
                                    (yyvsp[(3) - (3)].attributedSymbol)._.IDD.obj->pNext = (yyvsp[(1) - (3)].attributedSymbol)._.LI.list;
                                    (yyval.attributedSymbol)._.LI.list = (yyvsp[(3) - (3)].attributedSymbol)._.IDD.obj;
                                ;}
    break;

  case 10:
#line 120 "parser.y"
    { (yyval.attributedSymbol)._.LI.list = (yyvsp[(1) - (1)].attributedSymbol)._.IDD.obj; ;}
    break;

  case 11:
#line 123 "parser.y"
    { (yyval.attributedSymbol)._.TP.type = pInt;
                          (yyval.attributedSymbol)._.TP.size = 1;
                        ;}
    break;

  case 12:
#line 126 "parser.y"
    { (yyval.attributedSymbol)._.TP.type = pChar;
                          (yyval.attributedSymbol)._.TP.size = 1;
                        ;}
    break;

  case 13:
#line 129 "parser.y"
    { (yyval.attributedSymbol)._.TP.type = pBool;
                          (yyval.attributedSymbol)._.TP.size = 1;
                        ;}
    break;

  case 14:
#line 132 "parser.y"
    { (yyval.attributedSymbol)._.TP.type = pString;
                          (yyval.attributedSymbol)._.TP.size = 1;
                        ;}
    break;

  case 16:
#line 141 "parser.y"
    {
	NewBlock();
;}
    break;

  case 20:
#line 154 "parser.y"
    {
                    (yyval.attributedSymbol)._.MT.label = newLabel();
                    fprintf(f, "\tTJMP_FW L%d\n", (yyval.attributedSymbol)._.MT.label);
                ;}
    break;

  case 21:
#line 162 "parser.y"
    {
                    l2 = newLabel();
                    l1 = l2 - 1;
                    (yyval.attributedSymbol)._.ME.label = l2;
                    fprintf(f, "\tJMP_FW L%d\nL%d\n", l2, l1);
                ;}
    break;

  case 22:
#line 171 "parser.y"
    {
                    l = newLabel();
                    (yyval.attributedSymbol)._.MW.label = l;
                    fprintf(f, "L%d\n", 1);
                ;}
    break;

  case 23:
#line 178 "parser.y"
    {
                                                                    t = (yyvsp[(3) - (6)].attributedSymbol)._.E.type;
                                                                    l = (yyvsp[(5) - (6)].attributedSymbol)._.MT.label;
                                                                    if(!CheckTypes(t, pBool))
                                                                    {
                                                                        printf("Erro, bool expected\n");
                                                                    }
                                                                    fprintf(f, "L%d:\n", l);
                                                                ;}
    break;

  case 24:
#line 187 "parser.y"
    {
                                                                            t = (yyvsp[(3) - (9)].attributedSymbol)._.E.type;
                                                                            l = (yyvsp[(8) - (9)].attributedSymbol)._.ME.label;
                                                                            if(!CheckTypes(t, pBool))
                                                                            {

                                                                                printf("Erro, bool expected\n");
                                                                            }
                                                                            fprintf(f, "\tJMP_FW L%d\nL%d\n", l2, l1);
                                                                        ;}
    break;

  case 25:
#line 197 "parser.y"
    {

                                                                        t = (yyvsp[(4) - (7)].attributedSymbol)._.E.type;

                                                                        l1 = (yyvsp[(2) - (7)].attributedSymbol)._.MW.label;
                                                                        l2 = (yyvsp[(2) - (7)].attributedSymbol)._.MW.label;
                                                                        if(!CheckTypes(t, pBool))
                                                                        {

                                                                            printf("Erro, bool expected\n");
                                                                        }
                                                                        fprintf(f, "\tJMP_BW L%d\nL%d\n", l1, l2);
                                                                    ;}
    break;

  case 26:
#line 212 "parser.y"
    { 
			EndBlock();  
		;}
    break;

  case 27:
#line 217 "parser.y"
    {
                                                                    fprintf(f, "\tPOP\n");
                                                                ;}
    break;

  case 28:
#line 220 "parser.y"
    {
                                                                    fprintf(f, "\tTJMP_FW L\n");

                                                                ;}
    break;

  case 30:
#line 227 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pBool))
                                                            {

                                                               printf("Erro, bool expected\n");
                                                            }

                                                            if(!CheckTypes((yyvsp[(3) - (3)].attributedSymbol)._.F.type, pBool))
                                                            {

                                                                printf("Erro, bool expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = pBool;
                                                            fprintf(f, "\tAND\n" );
                                                        ;}
    break;

  case 31:
#line 242 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pBool))
                                                            {

                                                                printf("Erro, bool expected\n");
                                                            }

                                                            if(!CheckTypes((yyvsp[(3) - (3)].attributedSymbol)._.F.type, pBool))
                                                            {

                                                                printf("Erro, bool expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = pBool;
                                                            fprintf(f, "\tOR\n");
                                                        ;}
    break;

  case 32:
#line 257 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                                printf("Erro, int expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = pBool;
                                                            fprintf(f, "\tLT\n");
                                                        ;}
    break;

  case 33:
#line 271 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                                printf("Erro, int expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = pBool;
                                                            fprintf(f, "\tGT\n");
                                                        ;}
    break;

  case 34:
#line 285 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = pBool;
                                                            fprintf(f, "\tLE\n");
                                                        ;}
    break;

  case 35:
#line 299 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = pBool;
                                                            fprintf(f, "\tGE\n");
                                                        ;}
    break;

  case 36:
#line 313 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                               printf("Erro, int expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = pBool;
                                                            fprintf(f, "\tEQ\n");
                                                        ;}
    break;

  case 37:
#line 327 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                               printf("Erro, int expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = pBool;
                                                            fprintf(f, "\tNE\n");
                                                        ;}
    break;

  case 38:
#line 341 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                                printf("Erro, int expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = (yyvsp[(1) - (3)].attributedSymbol)._.F.type;
                                                            fprintf(f, "\tADD\n");
                                                        ;}
    break;

  case 39:
#line 355 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                               printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                               printf("Erro, int expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = (yyvsp[(1) - (3)].attributedSymbol)._.F.type;
                                                            fprintf(f, "\tSUB\n");
                                                        ;}
    break;

  case 40:
#line 369 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                                printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                               printf("Erro, int expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = (yyvsp[(1) - (3)].attributedSymbol)._.F.type;
                                                            fprintf(f, "\tMUL\n");
                                                        ;}
    break;

  case 41:
#line 383 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, (yyvsp[(3) - (3)].attributedSymbol)._.F.type))
                                                            {

                                                               printf("Erro, tipos nao compativeis\n");
                                                            }
                                                            if(!CheckTypes((yyvsp[(1) - (3)].attributedSymbol)._.E.type, pInt))
                                                            {

                                                                printf("Erro, int expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.E.type = (yyvsp[(1) - (3)].attributedSymbol)._.F.type;
                                                            fprintf(f, "\tDIV\n");

                                                        ;}
    break;

  case 42:
#line 398 "parser.y"
    {
                                                            (yyval.attributedSymbol)._.E.type = (yyvsp[(1) - (1)].attributedSymbol)._.F.type;
                                                        ;}
    break;

  case 43:
#line 403 "parser.y"
    {
                                                            if(!CheckTypes((yyvsp[(2) - (2)].attributedSymbol)._.F.type, pBool))
                                                            {
                                                               printf("Erro, boolean expected\n");
                                                            }
                                                            (yyval.attributedSymbol)._.F.type = (yyvsp[(2) - (2)].attributedSymbol)._.F.type;
                                                            fprintf(f, "\tNOT\n");
                                                        ;}
    break;

  case 44:
#line 411 "parser.y"
    {
                                                            (yyval.attributedSymbol)._.F.type = pBool;
                                                            n = (yyvsp[(1) - (1)].attributedSymbol)._.TRUE.val;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        ;}
    break;

  case 45:
#line 416 "parser.y"
    {
                                                            (yyval.attributedSymbol)._.F.type = pBool;
                                                            n = (yyvsp[(1) - (1)].attributedSymbol)._.FALSE.val;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        ;}
    break;

  case 46:
#line 421 "parser.y"
    {
                                                            (yyval.attributedSymbol)._.F.type = pChar;
                                                            n = (yyvsp[(1) - (1)].attributedSymbol)._.CHR.pos;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        ;}
    break;

  case 47:
#line 426 "parser.y"
    {
                                                            (yyval.attributedSymbol)._.F.type = pString;
                                                            n = (yyvsp[(1) - (1)].attributedSymbol)._.STR.pos;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        ;}
    break;

  case 48:
#line 431 "parser.y"
    {
                                                            (yyval.attributedSymbol)._.F.type = pInt;
                                                            n = (yyvsp[(1) - (1)].attributedSymbol)._.NUM.pos;
                                                            fprintf(f, "\tLOAD_CONST %d\n", n);
                                                        ;}
    break;

  case 49:
#line 436 "parser.y"
    {
                                                            p = (yyvsp[(1) - (1)].attributedSymbol)._.IDU.obj;
                                                            if(p->eKind != VAR_ )
                                                            {
                                                                if(p->eKind != UNIVERSAL_)
                                                                   printf("Erro, KIND NOT VAR\n");
                                                                (yyval.attributedSymbol)._.F.type = pUniversal;
                                                            }
                                                            else
                                                            {
                                                                (yyval.attributedSymbol)._.F.type = (yyvsp[(1) - (1)].attributedSymbol)._.IDU.obj->_.Var.pType;
                                                                n = (yyvsp[(1) - (1)].attributedSymbol)._.IDU.name;
                                                                fprintf(f, "\tLOAD_VAR %d\n", n);
                                                            }
                                                        ;}
    break;

  case 50:
#line 451 "parser.y"
    {
                                                            p = (yyvsp[(1) - (3)].attributedSymbol)._.IDU.obj;
                                                            if(p->eKind != VAR_)
                                                            {
                                                                printf("Erro KIND NOT VAR\n");
                                                                (yyval.attributedSymbol)._.F.type = pUniversal;
                                                            }
                                                            else
                                                            {
                                                                t1 = p->_.Var.pType;
                                                                t2 = (yyvsp[(3) - (3)].attributedSymbol)._.E.type;


                                                                if(!CheckTypes(t1, t2))
                                                                {
                                                                   printf("Erro de compatibilidade de tipos\n");
                                                                }
                                                                (yyval.attributedSymbol)._.F.type = t2;


                                                                fprintf(f, "\tDUP\n\tSTORE_VAR %d\n", (yyvsp[(1) - (3)].attributedSymbol)._.IDU.name);

                                                            }
                                                        ;}
    break;

  case 51:
#line 478 "parser.y"
    {
                (yyval.attributedSymbol)._.IDD.name = (yyvsp[(1) - (1)].tokenSecundario);
		object *p;
                        if( (p= SearchCurrentLevel((yyvsp[(1) - (1)].tokenSecundario))) != NULL)
				printf("Erro de redeclaracao");
			else
                                p = Define((yyvsp[(1) - (1)].tokenSecundario));
		p->eKind = NO_KIND_DEF_;
                (yyval.attributedSymbol)._.IDD.obj = p;
	;}
    break;

  case 52:
#line 493 "parser.y"
    {
                (yyval.attributedSymbol)._.IDD.name = (yyvsp[(1) - (1)].tokenSecundario);
		object *p;
                        if( (p= SearchAllSymbolTable((yyvsp[(1) - (1)].tokenSecundario))) == NULL)
			{
				printf("Erro de nao declaracao");
                                p = Define((yyvsp[(1) - (1)].tokenSecundario));
			}

                (yyval.attributedSymbol)._.IDD.obj = p;
	;}
    break;

  case 53:
#line 507 "parser.y"
    { (yyval.attributedSymbol)._.TRUE.type = pBool;
               (yyval.attributedSymbol)._.TRUE.val = 1;
             ;}
    break;

  case 54:
#line 512 "parser.y"
    { (yyval.attributedSymbol)._.FALSE.type = pBool;
                (yyval.attributedSymbol)._.FALSE.val = 0;
              ;}
    break;

  case 55:
#line 517 "parser.y"
    { (yyval.attributedSymbol)._.CHR.type = pChar;
                    (yyval.attributedSymbol)._.CHR.pos = (yyvsp[(1) - (1)].tokenSecundario);
                    (yyval.attributedSymbol)._.CHR.val = getCharConst((yyvsp[(1) - (1)].tokenSecundario));
                  ;}
    break;

  case 56:
#line 523 "parser.y"
    { (yyval.attributedSymbol)._.STR.type = pString;
                    (yyval.attributedSymbol)._.STR.pos = (yyvsp[(1) - (1)].tokenSecundario);
                    (yyval.attributedSymbol)._.STR.val = getStringConst((yyvsp[(1) - (1)].tokenSecundario));
                  ;}
    break;

  case 57:
#line 528 "parser.y"
    { (yyval.attributedSymbol)._.NUM.type = pInt;
                  (yyval.attributedSymbol)._.NUM.pos = (yyvsp[(1) - (1)].tokenSecundario);
                  (yyval.attributedSymbol)._.NUM.val = getIntConst((yyvsp[(1) - (1)].tokenSecundario));
                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2079 "parser.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 534 "parser.y"

/*int main( void )
{
	return yyparse();
}*/

