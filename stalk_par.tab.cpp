
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "stalk_par.y"


#include "includes.hpp"
#define NG(x) (nget(prim_table,x))



#define primchek(f,c,m) {size_t n,t=(size_t)(m);\
	if(t<num_prims && (n=(size_t)(nget(prim_table,t)))){\
				\
				t_add(f,svm_p##c);\
				t_add(f,n);\
			}\
			else{\
				t_add(f,svm_##c);\
				t_add(f,t);\
			}\
}



struct listliststring {
		t_list l;
        t_list ll;
        char* s;
};

struct numandstring {
    unsigned int n;
    char* s;
};

struct justlist {
  t_list jl;
};


/* Line 189 of yacc.c  */
#line 111 "stalk_par.tab.cpp"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LOW = 258,
     PERIOD = 259,
     ARGHOLDER = 260,
     WORDFROM_K_Q = 261,
     WORDFROM_K = 262,
     WORDSET_K_Q = 263,
     WORDSET_K = 264,
     WORDFROM_Q = 265,
     WORDFROM = 266,
     WORDSET_Q = 267,
     WORDSET = 268,
     COMBIN = 269,
     INITIAL_KEYWORD = 270,
     INITIAL_KEYWORD2 = 271,
     INITIAL_SYMBOL = 272,
     INITIAL_WORD = 273,
     KEYWORD = 274,
     KEYWORD2 = 275,
     SYMBOL = 276,
     LITERAL_HEX = 277,
     LITERAL_BIN = 278,
     LITERAL_DEC_NEG = 279,
     LITERAL_FLOAT_NEG = 280,
     LITERAL_DEC = 281,
     LITERAL_STRING = 282,
     LITERAL_FLOAT = 283,
     SYMBOL_Q = 284,
     KEYWORD_Q = 285,
     AWORD_Q_D = 286,
     AWORD_Q = 287,
     AWORD_D = 288,
     AWORD = 289,
     RB = 290,
     LB = 291,
     RCB = 292,
     LCB = 293,
     RSB = 294,
     LSB = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 40 "stalk_par.y"

unsigned int uint4;
struct listliststring* lls;
struct numandstring* ns;
struct justlist* jl;



/* Line 214 of yacc.c  */
#line 196 "stalk_par.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 208 "stalk_par.tab.cpp"

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
# if YYENABLE_NLS
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  81

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    19,
      22,    24,    26,    28,    31,    34,    38,    40,    44,    48,
      51,    54,    59,    63,    66,    69,    71,    73,    76,    79,
      81,    83,    86,    88,    91,    93,    95,    97,   101,   105,
     109,   111,   113,   115,   117,   119,   121,   123,   126,   129,
     131,   133,   135,   137,   139,   141,   143,   145,   147,   149,
     151,   153,   155,   157,   159,   161
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    44,    -1,    44,    -1,    45,    47,    -1,
      45,    -1,    47,    -1,    46,    -1,    45,    46,    -1,    47,
       4,    -1,     5,    -1,    48,    -1,    50,    -1,    48,    50,
      -1,    62,    50,    -1,    49,    62,    50,    -1,    51,    -1,
      50,    60,    50,    -1,    61,    50,    49,    -1,    61,    50,
      -1,    60,    50,    -1,    50,    61,    50,    49,    -1,    50,
      61,    50,    -1,    59,    50,    -1,    58,    50,    -1,    56,
      -1,    57,    -1,    56,    53,    -1,    57,    53,    -1,    52,
      -1,    55,    -1,    55,    53,    -1,    54,    -1,    53,    54,
      -1,    56,    -1,    57,    -1,    55,    -1,    36,    48,    35,
      -1,    38,    43,    37,    -1,    40,    43,    39,    -1,    27,
      -1,    28,    -1,    26,    -1,    23,    -1,    22,    -1,    25,
      -1,    24,    -1,    40,    39,    -1,    38,    37,    -1,    34,
      -1,    33,    -1,    32,    -1,    31,    -1,    30,    -1,    29,
      -1,    11,    -1,    10,    -1,     7,    -1,     6,    -1,    13,
      -1,    12,    -1,     9,    -1,     8,    -1,    21,    -1,    19,
      -1,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    91,   120,   125,   129,   143,   147,   156,
     160,   171,   200,   204,   212,   223,   239,   241,   249,   262,
     268,   275,   288,   296,   318,   338,   344,   358,   365,   378,
     384,   388,   395,   399,   405,   409,   421,   430,   434,   440,
     446,   454,   460,   467,   473,   479,   485,   491,   496,   503,
     505,   507,   508,   509,   512,   517,   518,   519,   520,   523,
     524,   525,   526,   534,   537,   543
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOW", "PERIOD", "ARGHOLDER",
  "WORDFROM_K_Q", "WORDFROM_K", "WORDSET_K_Q", "WORDSET_K", "WORDFROM_Q",
  "WORDFROM", "WORDSET_Q", "WORDSET", "COMBIN", "INITIAL_KEYWORD",
  "INITIAL_KEYWORD2", "INITIAL_SYMBOL", "INITIAL_WORD", "KEYWORD",
  "KEYWORD2", "SYMBOL", "LITERAL_HEX", "LITERAL_BIN", "LITERAL_DEC_NEG",
  "LITERAL_FLOAT_NEG", "LITERAL_DEC", "LITERAL_STRING", "LITERAL_FLOAT",
  "SYMBOL_Q", "KEYWORD_Q", "AWORD_Q_D", "AWORD_Q", "AWORD_D", "AWORD",
  "RB", "LB", "RCB", "LCB", "RSB", "LSB", "$accept", "endresult",
  "object_core", "object_core2", "statements", "statement", "items",
  "items2", "keyword2list", "item", "wordlist", "wl_not_word_at_start",
  "wl", "wl_item", "literal", "word", "word_q", "wordfrom", "wordset",
  "symbol", "keyword", "keyword2", 0
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
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    44,    45,    45,    46,
      46,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    57,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    59,    59,    60,    61,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     3,     1,     3,     3,     2,
       2,     4,     3,     2,     2,     1,     1,     2,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    58,    57,    62,    61,    56,    55,    60,    59,
      64,    63,    44,    43,    46,    45,    42,    40,    41,    54,
      53,    52,    51,    50,    49,     0,     0,     0,     0,     2,
       5,     7,     6,    11,    12,    16,    29,    30,    25,    26,
       0,     0,     0,     0,     0,    48,     0,     3,    47,     0,
       1,     8,     4,     9,    13,     0,     0,    31,    32,    36,
      34,    35,    27,    28,    24,    23,    20,    19,    37,    38,
      39,    17,    22,    33,    65,    18,     0,    21,     0,    14,
      15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    28,    46,    47,    30,    31,    32,    33,    75,    34,
      35,    36,    57,    58,    37,    38,    39,    40,    41,    42,
      43,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
     156,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   226,    84,   120,    25,   -51,
     156,   -51,    24,   226,   -13,   -51,   -51,   245,   245,   245,
     226,   226,   226,   226,   191,   -51,     6,   -51,   -51,     1,
     -51,   -51,    24,   -51,   -13,   226,   226,   245,   -51,   -51,
     -51,   -51,   245,   245,   -13,   -13,   -13,     3,   -51,   -51,
     -51,   -51,   -16,   -51,   -51,    27,   226,    27,   226,    23,
      23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,    21,    54,   -51,    28,    30,    36,   -10,    26,
     -51,   -51,   -24,   -50,   -36,   -28,   -21,   -51,   -51,   -34,
     -15,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      55,    59,    59,    59,    74,    11,    10,    73,    11,    60,
      60,    60,    73,    73,    62,    63,    61,    61,    61,    56,
      55,    59,    10,    74,    11,    50,    59,    59,    53,    60,
      55,    55,    55,    55,    60,    60,    61,    55,    55,    56,
      70,    61,    61,    69,    11,    55,    55,    74,    49,    56,
      56,    56,    56,    78,    29,    78,    56,    56,    51,    54,
      52,    44,    77,     0,    56,    56,    64,    65,    66,    67,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    72,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,     0,    79,    10,    80,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    45,    26,     0,    27,     1,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,    10,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,     0,    26,    48,
      27,     1,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     0,    26,     0,    27,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    68,    25,     0,    26,
       0,    27,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,    10,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     0,    26,     0,    27,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,     0,    26,     0,    27
};

static const yytype_int8 yycheck[] =
{
      34,    37,    38,    39,    20,    21,    19,    57,    21,    37,
      38,    39,    62,    63,    38,    39,    37,    38,    39,    34,
      54,    57,    19,    20,    21,     0,    62,    63,     4,    57,
      64,    65,    66,    67,    62,    63,    57,    71,    72,    54,
      39,    62,    63,    37,    21,    79,    80,    20,    27,    64,
      65,    66,    67,    75,     0,    77,    71,    72,    30,    33,
      30,    25,    72,    -1,    79,    80,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    76,    19,    78,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    -1,    40,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    38,    39,
      40,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    38,    -1,    40,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      -1,    40,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    38,    -1,    40,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    -1,    38,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      19,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    36,    38,    40,    42,    44,
      45,    46,    47,    48,    50,    51,    52,    55,    56,    57,
      58,    59,    60,    61,    48,    37,    43,    44,    39,    43,
       0,    46,    47,     4,    50,    60,    61,    53,    54,    55,
      56,    57,    53,    53,    50,    50,    50,    50,    35,    37,
      39,    50,    50,    54,    20,    49,    62,    49,    62,    50,
      50
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
# if YYLTYPE_IS_TRIVIAL
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 77 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
	t_addlist((yyval.jl)->jl,(yyvsp[(1) - (1)].jl)->jl);
	if((yyvsp[(1) - (1)].jl)->jl->taintlist!=0){
		t_addlist((yyval.jl)->jl,(yyvsp[(1) - (1)].jl)->jl->taintlist);
		t_add((yyval.jl)->jl,svm_ctos);
	}
	return((int)((yyval.jl)->jl));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 91 "stalk_par.y"
    {
			(yyval.jl)=newnew (justlist);
			(yyval.jl)->jl=newtlist;
			if((yyvsp[(1) - (1)].jl)->jl->taintlist!=0){
				t_add((yyval.jl)->jl,svm_seteval);
				//t_add($$->jl,reinterpret_cast<void*>(&($1->jl->taintlist)));//was & not cast
				(yyval.jl)->jl->additem((yyvsp[(1) - (1)].jl)->jl->taintlist);
				//printf("DEBUG %d %d\n",$1->jl->taintlist->numberin,&($1->jl->taintlist));
				//size_t f;
				//iterate($1->jl->taintlist,size_t,f)
				//	printf(":%d:",f);
				//enditerate
				//printf("\n");
				
				if ((yyvsp[(1) - (1)].jl)->jl->args!=0){
					(yyvsp[(1) - (1)].jl)->jl->taintlist->args=(yyvsp[(1) - (1)].jl)->jl->args;//DODGEEE INDEED
				}
            //if($1->taintlist->args!=0)svmprint("YO!");
			}
			t_addlist((yyval.jl)->jl,(yyvsp[(1) - (1)].jl)->jl);
			(yyval.jl)->jl->taintlist=0;
			(yyval.jl)->jl->taintflag=0;
			(yyval.jl)->jl->isanobjectcore=1;
         //if($$->args!=0)svmprint("[%d] ",$$);
;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 120 "stalk_par.y"
    {
		(yyval.jl)=newnew (justlist);
		(yyval.jl)->jl=(yyvsp[(1) - (2)].jl)->jl;
		t_addlist((yyval.jl)->jl,(yyvsp[(2) - (2)].jl)->jl);
	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 125 "stalk_par.y"
    {
		(yyval.jl)=newnew (justlist);
		(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 129 "stalk_par.y"
    {
		(yyval.jl)=newnew (justlist);
		(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 143 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 147 "stalk_par.y"
    {
		(yyval.jl)=newnew (justlist);
		(yyval.jl)->jl=(yyvsp[(1) - (2)].jl)->jl;
		t_addlist((yyval.jl)->jl,(yyvsp[(2) - (2)].jl)->jl);
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 156 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (2)].jl)->jl;
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 160 "stalk_par.y"
    {
			char* temp;
			(yyval.jl)=newnew (justlist);
			(yyval.jl)->jl=newtlist;
			(yyval.jl)->jl->args=newlist;
			makestring_strip_last(temp,yytext);
			add((yyval.jl)->jl->args,lookup(temp)+2);
		
		   ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 171 "stalk_par.y"
    {


if((yyvsp[(1) - (1)].jl)->jl->taintflag==1){
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
	t_add((yyval.jl)->jl,svm_ctos);
	if((yyval.jl)->jl->extractos==1 && (yyval.jl)->jl->wordset==0){
            t_add((yyval.jl)->jl,svm_ctos);//if there was an evals in the statement and the statement was assignment- extra clear stack
            //NEW! (unless wordset was the first item, in which case no extractos. this is for x->void. etc.)
			//$$->extractos==0; //might have to unrem this!
	}
}//only double ctos if evals....
else {
			(yyval.jl)=newnew (justlist);
			(yyval.jl)->jl=newtlist;

                        //if($1->taintflag2==1 && $1->wordset==1){svmprint("FSCKYOU");}

                        if(((yyvsp[(1) - (1)].jl)->jl->taintflag2==1) && ((yyvsp[(1) - (1)].jl)->jl->extractos==1 && (yyvsp[(1) - (1)].jl)->jl->wordset==0))
                            {t_add((yyvsp[(1) - (1)].jl)->jl,svm_ctos);}//NEW LINE- if evals/nevals in statement and stmt was <- extra clear stack in order
			(yyval.jl)->jl->taintlist=(yyvsp[(1) - (1)].jl)->jl;
   //                     if($1->extractos==1)add($$->taintlist,svm_ctos);
}

;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 200 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 204 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (2)].jl)->jl;
	t_addlist((yyval.jl)->jl,(yyvsp[(2) - (2)].jl)->jl);
;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 213 "stalk_par.y"
    {   (yyval.lls)=newnew (listliststring);
        
		//$$->l=newtlist;

		(yyval.lls)->l=(yyvsp[(2) - (2)].jl)->jl;
        (yyval.lls)->ll=newtlist;
		t_add((yyval.lls)->ll,((yyvsp[(1) - (2)].ns)->n)+1);
        makestring((yyval.lls)->s,(yyvsp[(1) - (2)].ns)->s);
        //svmprint("1%s",$$->s);
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 224 "stalk_par.y"
    {   (yyval.lls)=newnew (listliststring);//svmprint("TAIL");
    
	//$$->l=newtlist;
	
	(yyval.lls)->l=(yyvsp[(1) - (3)].lls)->l;
	t_addlist((yyval.lls)->l,(yyvsp[(3) - (3)].jl)->jl);
    (yyval.lls)->ll=newtlist;
	t_add((yyval.lls)->ll,((yyvsp[(2) - (3)].ns)->n)+1);
	t_addlist((yyval.lls)->ll,(yyvsp[(1) - (3)].lls)->ll);
    makestring_plus((yyval.lls)->s,(yyvsp[(1) - (3)].lls)->s,(yyvsp[(2) - (3)].ns)->s);
    //svmprint("2%s",$$->s);
;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 239 "stalk_par.y"
    {(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 241 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(3) - (3)].jl)->jl;
	t_addlist((yyval.jl)->jl,(yyvsp[(1) - (3)].jl)->jl);
	primchek((yyval.jl)->jl,evalx,(yyvsp[(2) - (3)].uint4))
	t_add((yyval.jl)->jl,1);
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 250 "stalk_par.y"
    {
    char* ts;
	(yyval.jl)=newnew (justlist);
    (yyval.jl)->jl=(yyvsp[(2) - (3)].jl)->jl;
	t_addlist((yyval.jl)->jl,(yyvsp[(3) - (3)].lls)->l);//t_addlist($$,$1);
    //t_add($$,svm_evalxs);
    makestring_plus(ts,(yyvsp[(1) - (3)].ns)->s,(yyvsp[(3) - (3)].lls)->s);primchek((yyval.jl)->jl,evalxs,lookup(ts)+2)//t_add($$,lookup(ts)+2);
    t_add((yyval.jl)->jl,((yyvsp[(3) - (3)].lls)->ll->numberin)+1);
	//t_addlist($$,$3->ll);t_add($$,($1->n)+1); THIS WAS ARG #S IN REVERSE ORDER- NO LONGER USED

;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 262 "stalk_par.y"
    {
		(yyval.jl)=newnew (justlist);
		(yyval.jl)->jl=(yyvsp[(2) - (2)].jl)->jl;primchek((yyval.jl)->jl,evalxs,(yyvsp[(1) - (2)].ns)->n)
		t_add((yyval.jl)->jl,1);
	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 268 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(2) - (2)].jl)->jl;
	primchek((yyval.jl)->jl,evalxs,(yyvsp[(1) - (2)].uint4))
	t_add((yyval.jl)->jl,1);
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 276 "stalk_par.y"
    {   char* ts;
	(yyval.jl)=newnew (justlist);
    (yyval.jl)->jl=(yyvsp[(3) - (4)].jl)->jl;
	t_addlist((yyval.jl)->jl,(yyvsp[(4) - (4)].lls)->l);
	t_addlist((yyval.jl)->jl,(yyvsp[(1) - (4)].jl)->jl);//t_add($$,svm_evalx);
    makestring_plus(ts,(yyvsp[(2) - (4)].ns)->s,(yyvsp[(4) - (4)].lls)->s);
	primchek((yyval.jl)->jl,evalx,lookup(ts)+2)//t_add($$,lookup(ts)+2);
    t_add((yyval.jl)->jl,((yyvsp[(4) - (4)].lls)->ll->numberin)+1);
	//t_addlist($$,$4->ll);t_add($$,($2->n)+1); THIS WAS ARG #S IN REVERSE ORDER- NO LONGER USED
    // svmprint("3%s",ts);
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 288 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(3) - (3)].jl)->jl;
	t_addlist((yyval.jl)->jl,(yyvsp[(1) - (3)].jl)->jl);
	primchek((yyval.jl)->jl,evalx,(yyvsp[(2) - (3)].ns)->n)
	t_add((yyval.jl)->jl,1);
;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 297 "stalk_par.y"
    {
  //cope with 'parent->...'
  if((yyvsp[(1) - (2)].uint4)==6){
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(2) - (2)].jl)->jl;
	t_add((yyval.jl)->jl,svm_setp);
	(yyval.jl)->jl->taint();
	(yyval.jl)->jl->wordset=1; 
  }
    else

    {
		(yyval.jl)=newnew (justlist);
		(yyval.jl)->jl=(yyvsp[(2) - (2)].jl)->jl;
		t_add((yyval.jl)->jl,svm_sets);
		t_add((yyval.jl)->jl,(yyvsp[(1) - (2)].uint4));
		(yyval.jl)->jl->taint();
		(yyval.jl)->jl->wordset=1;
	}

;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 319 "stalk_par.y"
    {   //cope with parent<-...
    if((yyvsp[(1) - (2)].uint4)==6){
		(yyval.jl)=newnew (justlist);
		(yyval.jl)->jl=(yyvsp[(2) - (2)].jl)->jl;
		t_add((yyval.jl)->jl,svm_setp);
		(yyval.jl)->jl->taint2();
		(yyval.jl)->jl->wordset==1;
	}
    else {
		(yyval.jl)=newnew (justlist);
		(yyval.jl)->jl=(yyvsp[(2) - (2)].jl)->jl;
		t_add((yyval.jl)->jl,svm_setl);
		t_add((yyval.jl)->jl,(yyvsp[(1) - (2)].uint4));
		(yyval.jl)->jl->taint2();
		(yyval.jl)->jl->wordset=1;
	}//was setf
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 338 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
	primchek((yyval.jl)->jl,evals,(yyvsp[(1) - (1)].uint4))//t_add($$,svm_evals);t_add($$,$1);
	(yyval.jl)->jl->extractos=1;
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 344 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    if((yyvsp[(1) - (1)].uint4)==3||(yyvsp[(1) - (1)].uint4)==6){
	    t_add((yyval.jl)->jl,svm_pevals);
        t_add((yyval.jl)->jl,NG((yyvsp[(1) - (1)].uint4)+6));
	}
    else {
        t_add((yyval.jl)->jl,svm_nevals);
        t_add((yyval.jl)->jl,(yyvsp[(1) - (1)].uint4));
    }
    (yyval.jl)->jl->extractos=1;
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 358 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
    (yyval.jl)->jl=newtlist;
    primchek((yyval.jl)->jl,evals,(yyvsp[(1) - (2)].uint4))//t_add($$,svm_evals);t_add($$,$1);
    t_addlist((yyval.jl)->jl,(yyvsp[(2) - (2)].jl)->jl);
    (yyval.jl)->jl->extractos=1;
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 365 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    if((yyvsp[(1) - (2)].uint4)==3||(yyvsp[(1) - (2)].uint4)==6){
	    t_add((yyval.jl)->jl,svm_pevals);
        t_add((yyval.jl)->jl,NG((yyvsp[(1) - (2)].uint4)+6));
    }
	else {
        t_add((yyval.jl)->jl,svm_nevals);t_add((yyval.jl)->jl,(yyvsp[(1) - (2)].uint4));
    }
	t_addlist((yyval.jl)->jl,(yyvsp[(2) - (2)].jl)->jl);
	(yyval.jl)->jl->extractos=1;
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 378 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 384 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 388 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (2)].jl)->jl;
	t_addlist((yyval.jl)->jl,(yyvsp[(2) - (2)].jl)->jl);
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 395 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 399 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (2)].jl)->jl;
	t_addlist((yyval.jl)->jl,(yyvsp[(2) - (2)].jl)->jl);
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 405 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    primchek((yyval.jl)->jl,eval,(yyvsp[(1) - (1)].uint4));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 409 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    if((yyvsp[(1) - (1)].uint4)==3||(yyvsp[(1) - (1)].uint4)==6){
	    t_add((yyval.jl)->jl,svm_peval);
		t_add((yyval.jl)->jl,NG((yyvsp[(1) - (1)].uint4)+6));
	}
    else {
		t_add((yyval.jl)->jl,svm_neval);
		t_add((yyval.jl)->jl,(yyvsp[(1) - (1)].uint4));
	}
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 421 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(1) - (1)].jl)->jl;
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 430 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=(yyvsp[(2) - (3)].jl)->jl;
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 434 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    t_add((yyval.jl)->jl,svm_obj);
	t_addlist((yyval.jl)->jl,(yyvsp[(2) - (3)].jl)->jl);
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 440 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    t_add((yyval.jl)->jl,svm_block);
	t_addlist((yyval.jl)->jl,(yyvsp[(2) - (3)].jl)->jl);
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 446 "stalk_par.y"
    {
	char* temp;
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    t_add((yyval.jl)->jl,svm_str);
	makestring(temp,string_buf);
    t_add((yyval.jl)->jl,temp);
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 454 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    t_add((yyval.jl)->jl,svm_float);
	t_addf((yyval.jl)->jl,(float)(STRTOD(yytext,0)));
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 460 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
 	(yyval.jl)->jl=newtlist;
    t_addst((yyval.jl)->jl,svm_int);
	t_addst((yyval.jl)->jl,(size_t)STRTOUL(yytext,0,10));
	//$$->jl->print();
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 467 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
	t_addst((yyval.jl)->jl,svm_int);
	t_addst((yyval.jl)->jl,strtoul(yytext+2,0,2));
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 473 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
	t_addst((yyval.jl)->jl,svm_int);
	t_addst((yyval.jl)->jl,strtoul(yytext+2,0,16));
;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 479 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    t_add((yyval.jl)->jl,svm_float);
    t_addf((yyval.jl)->jl,(float)(STRTOD(yytext,0)));
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 485 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
    t_add((yyval.jl)->jl,svm_int);
	t_add((yyval.jl)->jl,(size_t)STRTOL(yytext,0,10));
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 491 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
	t_add((yyval.jl)->jl,svm_block);
;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 496 "stalk_par.y"
    {
	(yyval.jl)=newnew (justlist);
	(yyval.jl)->jl=newtlist;
	t_add((yyval.jl)->jl,svm_obj);
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 503 "stalk_par.y"
    {(yyval.uint4)=lookup(yytext)+2;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 505 "stalk_par.y"
    {(yyval.uint4)=lookup(yytext+1)+1;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 507 "stalk_par.y"
    {(yyval.uint4)=lookup(yytext+1)+2;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 508 "stalk_par.y"
    {(yyval.uint4)=lookup(yytext+2)+1;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 509 "stalk_par.y"
    {char* temp;
               makestring_strip_ends(temp,yytext);
               (yyval.uint4)=lookup(temp);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 512 "stalk_par.y"
    {(yyval.uint4)=lookup(yytext+1)+2;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 517 "stalk_par.y"
    {(yyval.uint4)=makestring_from();;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 518 "stalk_par.y"
    {(yyval.uint4)=makestring_from_q();;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 519 "stalk_par.y"
    {(yyval.uint4)=makestring_from_k();;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 520 "stalk_par.y"
    {(yyval.uint4)=makestring_from_k_q();;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 523 "stalk_par.y"
    {(yyval.uint4)=makestring_set();;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 524 "stalk_par.y"
    {(yyval.uint4)=makestring_set_q();;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 525 "stalk_par.y"
    {(yyval.uint4)=makestring_set_k();;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 526 "stalk_par.y"
    {(yyval.uint4)=makestring_set_k_q();;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 534 "stalk_par.y"
    {(yyval.uint4)=lookup(yytext)+2;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 537 "stalk_par.y"
    {char* temp;
    (yyval.ns)=newnew (numandstring);
    makestring_strip_last(temp,yytext);

    (yyval.ns)->n=lookup(temp);makestring((yyval.ns)->s,yytext);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 543 "stalk_par.y"
    {
    char* temp;
    makestring_strip_last(temp,yytext);
    //temp[strlen(temp)-1]=':';
    (yyval.ns)=newnew (numandstring);
    (yyval.ns)->n=lookup(temp);makestring((yyval.ns)->s,yytext);;}
    break;



/* Line 1455 of yacc.c  */
#line 2303 "stalk_par.tab.cpp"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 555 "stalk_par.y"




int yyerror(char* s){
    pen_red
    svmprint("%s. All input discarded!\n",s);
    pen_nor
	return 0;
}

main(int argc,char**argv){

//++argv;--argc;

yyin=fopen("r7","r");


//yydebug=1;

initruntime();
execute_interp();
//yyparse();

};



