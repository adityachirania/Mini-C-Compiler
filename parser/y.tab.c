/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include "stdlib.h"
	#include "string.h"
	#include "stdio.h"
	#include "ctype.h"
	//#include "malloc.h"

	void type_insert();
	void insert_symbol_type_proxy(char *,char *);
	void print_constant_table_proxy(void);
	void print_symbol_table_proxy(void);
	void insert_symbol_class_proxy(char *);
	void insert_symbol_array_dimension_proxy();
	void insert_arg_list_proxy(char *, char *);
	void append_star_proxy(char *);

	void push(char *);
	void start_pop(void);
	void pop(void);
	int check_present_proxy(void);	
	void insert_start_line(int, char *);
	void insert_end_line(int, char *);
	void nesting_insert(int);
	void class_insert(char* class);
	void array_dim_insert(int empty);

	void yyerror(char* s);
	int yylex();

	extern FILE *yyin;
	extern int yylineno;
	extern char *yytext;
	extern char cur_symbol[100];
	extern char cur_type[100];
	extern char cur_value[100];

	char symbol_stack[100][100];
	char cur_fun[100];
	char arglist[1000];
	int line_stack[100];
	int top=-1;
	int cur_line;
	int cur_open_line;
	int error_flag=0;
	int pointer_flag = 0;
	int nesting = 0;
	// extern struct_symbol_table_entry *identifiers_list;

#line 119 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    OR_OPERATOR = 260,
    AND_OPERATOR = 261,
    BITWISE_OR_OPERATOR = 262,
    CARET_OPERATOR = 263,
    BITWISE_AND_OPERATOR = 264,
    EQUAL_COMPARATOR = 265,
    NOT_EQUAL_COMPARATOR = 266,
    LESSER_THAN_OR_EQUAL_TO = 267,
    LESSER_THAN = 268,
    GREATER_THAN_OR_EQUAL_TO = 269,
    GREATER_THAN = 270,
    LEFT_SHIFT_OPERATOR = 271,
    RIGHT_SHIFT_OPERATOR = 272,
    ADD = 273,
    SUBTRACT = 274,
    MULTIPLICATION_OPERATOR = 275,
    DIVISION = 276,
    MODULO = 277,
    LEFT_SHIFT_ASSIGNMENT_OPERATOR = 278,
    RIGHT_SHIFT_ASSIGNMENT_OPERATOR = 279,
    XOR_ASSIGNMENT_OPERATOR = 280,
    OR_ASSIGNMENT_OPERATOR = 281,
    AND_ASSIGNMENT_OPERATOR = 282,
    MODULO_ASSIGNMENT_OPERATOR = 283,
    MULTIPLICATION_ASSIGNMENT_OPERATOR = 284,
    DIVISION_ASSIGNMENT_OPERATOR = 285,
    ADD_ASSIGNMENT_OPERATOR = 286,
    SUBTRACTION_ASSIGNMENT_OPERATOR = 287,
    ASSIGNMENT_OPERATOR = 288,
    SIZEOF = 289,
    SEMICOLON_DELIMITER = 290,
    COLON = 291,
    COMMA_DELIMITER = 292,
    OPEN_BRACES = 293,
    CLOSE_BRACES = 294,
    OPEN_BRACKET = 295,
    CLOSE_BRACKET = 296,
    OPEN_SQUARE = 297,
    CLOSE_SQUARE = 298,
    RETURN = 299,
    MAIN_FUNCTION = 300,
    INT = 301,
    SHORT = 302,
    LONG = 303,
    LONG_LONG = 304,
    FLOAT = 305,
    CHAR = 306,
    DOUBLE = 307,
    SIGNED = 308,
    UNSIGNED = 309,
    STRUCT = 310,
    BREAK = 311,
    CONTINUE = 312,
    VOID = 313,
    WHILE = 314,
    FOR = 315,
    DO = 316,
    SWITCH = 317,
    CASE = 318,
    DEFAULT = 319,
    IDENTIFIER = 320,
    INVALID_INTEGER = 321,
    INVALID_FLOAT = 322,
    INVALID_CHARACTER = 323,
    INVALID_STRING = 324,
    ILLEGAL_TOKEN = 325,
    INTEGER_CONSTANT = 326,
    STRING_CONSTANT = 327,
    FLOAT_CONSTANT = 328,
    CHARACTER_CONSTANT = 329,
    PREPROCESSOR_DIRECTIVE = 330,
    MACRO = 331,
    BITWISE_COMPLEMENT_OPERATOR = 332,
    EXCLAMATION_OPERATOR = 333,
    INCREMENT_OPERATOR = 334,
    DECREMENT_OPERATOR = 335
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define OR_OPERATOR 260
#define AND_OPERATOR 261
#define BITWISE_OR_OPERATOR 262
#define CARET_OPERATOR 263
#define BITWISE_AND_OPERATOR 264
#define EQUAL_COMPARATOR 265
#define NOT_EQUAL_COMPARATOR 266
#define LESSER_THAN_OR_EQUAL_TO 267
#define LESSER_THAN 268
#define GREATER_THAN_OR_EQUAL_TO 269
#define GREATER_THAN 270
#define LEFT_SHIFT_OPERATOR 271
#define RIGHT_SHIFT_OPERATOR 272
#define ADD 273
#define SUBTRACT 274
#define MULTIPLICATION_OPERATOR 275
#define DIVISION 276
#define MODULO 277
#define LEFT_SHIFT_ASSIGNMENT_OPERATOR 278
#define RIGHT_SHIFT_ASSIGNMENT_OPERATOR 279
#define XOR_ASSIGNMENT_OPERATOR 280
#define OR_ASSIGNMENT_OPERATOR 281
#define AND_ASSIGNMENT_OPERATOR 282
#define MODULO_ASSIGNMENT_OPERATOR 283
#define MULTIPLICATION_ASSIGNMENT_OPERATOR 284
#define DIVISION_ASSIGNMENT_OPERATOR 285
#define ADD_ASSIGNMENT_OPERATOR 286
#define SUBTRACTION_ASSIGNMENT_OPERATOR 287
#define ASSIGNMENT_OPERATOR 288
#define SIZEOF 289
#define SEMICOLON_DELIMITER 290
#define COLON 291
#define COMMA_DELIMITER 292
#define OPEN_BRACES 293
#define CLOSE_BRACES 294
#define OPEN_BRACKET 295
#define CLOSE_BRACKET 296
#define OPEN_SQUARE 297
#define CLOSE_SQUARE 298
#define RETURN 299
#define MAIN_FUNCTION 300
#define INT 301
#define SHORT 302
#define LONG 303
#define LONG_LONG 304
#define FLOAT 305
#define CHAR 306
#define DOUBLE 307
#define SIGNED 308
#define UNSIGNED 309
#define STRUCT 310
#define BREAK 311
#define CONTINUE 312
#define VOID 313
#define WHILE 314
#define FOR 315
#define DO 316
#define SWITCH 317
#define CASE 318
#define DEFAULT 319
#define IDENTIFIER 320
#define INVALID_INTEGER 321
#define INVALID_FLOAT 322
#define INVALID_CHARACTER 323
#define INVALID_STRING 324
#define ILLEGAL_TOKEN 325
#define INTEGER_CONSTANT 326
#define STRING_CONSTANT 327
#define FLOAT_CONSTANT 328
#define CHARACTER_CONSTANT 329
#define PREPROCESSOR_DIRECTIVE 330
#define MACRO 331
#define BITWISE_COMPLEMENT_OPERATOR 332
#define EXCLAMATION_OPERATOR 333
#define INCREMENT_OPERATOR 334
#define DECREMENT_OPERATOR 335

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  175
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

#define YYUNDEFTOK  2
#define YYMAXUTOK   335

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    81,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    98,   102,   103,   107,   108,   109,   110,
     111,   117,   121,   130,   131,   136,   136,   142,   152,   152,
     159,   160,   166,   167,   172,   177,   178,   182,   182,   183,
     183,   188,   189,   193,   194,   195,   199,   200,   204,   204,
     208,   208,   213,   214,   218,   219,   224,   227,   228,   229,
     232,   233,   240,   240,   245,   246,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   263,   264,   265,   266,   269,
     270,   271,   272,   275,   276,   279,   280,   286,   287,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   307,   310,   311,   314,   317,   318,   321,   322,
     325,   326,   329,   330,   333,   334,   337,   338,   339,   340,
     341,   344,   347,   348,   351,   355,   359,   360,   364,   365,
     368,   369,   370,   373,   376,   377,   378,   381,   382,   383,
     384,   390,   391,   394,   395,   396,   399,   400,   401,   402,
     403,   404,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   422,   423,   427,   427,   431,   432,   436,   437,   442,
     446,   447,   451,   451,   455,   456,   460,   461,   465,   466,
     467,   471,   475,   479,   483,   484
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "OR_OPERATOR",
  "AND_OPERATOR", "BITWISE_OR_OPERATOR", "CARET_OPERATOR",
  "BITWISE_AND_OPERATOR", "EQUAL_COMPARATOR", "NOT_EQUAL_COMPARATOR",
  "LESSER_THAN_OR_EQUAL_TO", "LESSER_THAN", "GREATER_THAN_OR_EQUAL_TO",
  "GREATER_THAN", "LEFT_SHIFT_OPERATOR", "RIGHT_SHIFT_OPERATOR", "ADD",
  "SUBTRACT", "MULTIPLICATION_OPERATOR", "DIVISION", "MODULO",
  "LEFT_SHIFT_ASSIGNMENT_OPERATOR", "RIGHT_SHIFT_ASSIGNMENT_OPERATOR",
  "XOR_ASSIGNMENT_OPERATOR", "OR_ASSIGNMENT_OPERATOR",
  "AND_ASSIGNMENT_OPERATOR", "MODULO_ASSIGNMENT_OPERATOR",
  "MULTIPLICATION_ASSIGNMENT_OPERATOR", "DIVISION_ASSIGNMENT_OPERATOR",
  "ADD_ASSIGNMENT_OPERATOR", "SUBTRACTION_ASSIGNMENT_OPERATOR",
  "ASSIGNMENT_OPERATOR", "SIZEOF", "SEMICOLON_DELIMITER", "COLON",
  "COMMA_DELIMITER", "OPEN_BRACES", "CLOSE_BRACES", "OPEN_BRACKET",
  "CLOSE_BRACKET", "OPEN_SQUARE", "CLOSE_SQUARE", "RETURN",
  "MAIN_FUNCTION", "INT", "SHORT", "LONG", "LONG_LONG", "FLOAT", "CHAR",
  "DOUBLE", "SIGNED", "UNSIGNED", "STRUCT", "BREAK", "CONTINUE", "VOID",
  "WHILE", "FOR", "DO", "SWITCH", "CASE", "DEFAULT", "IDENTIFIER",
  "INVALID_INTEGER", "INVALID_FLOAT", "INVALID_CHARACTER",
  "INVALID_STRING", "ILLEGAL_TOKEN", "INTEGER_CONSTANT", "STRING_CONSTANT",
  "FLOAT_CONSTANT", "CHARACTER_CONSTANT", "PREPROCESSOR_DIRECTIVE",
  "MACRO", "BITWISE_COMPLEMENT_OPERATOR", "EXCLAMATION_OPERATOR",
  "INCREMENT_OPERATOR", "DECREMENT_OPERATOR", "'.'", "$accept", "source",
  "declaration_list", "declaration_list_continuation", "declaration",
  "function_declaration", "function_name", "function_parameters",
  "parameters_list", "$@1", "param_identifier", "@2",
  "parameter_identifier_array_check", "variable_declaration",
  "variable_declaration_list", "variable_declaration_list_continuation",
  "single_element_declaration", "$@3", "$@4", "array_declaration",
  "first_dimension", "other_dimension", "array_dimension_without_integer",
  "$@5", "array_dimension_with_integer", "$@6", "initilization",
  "initilization_continuation", "array_initialization", "array_item_list",
  "array_item_list_continuation", "structure_definition", "$@7",
  "struct_variable_declaration", "type_specifier", "unsigned", "signed",
  "short", "long", "expression", "assignment_type", "simple_expression",
  "simple_expression_end", "and_expression", "and_expression_end",
  "unary_relational_expression", "relational_expression", "sum_of_factors",
  "factor", "factor_continuation", "size_of", "size_of_continuation",
  "address_of", "value_of", "assignable", "assignable_end", "fixed_value",
  "function_call", "arguments_list", "constant", "sum_operators",
  "multiplicative_operators", "relational_operators", "statement",
  "statement_list", "compound_statement", "$@8", "expression_statement",
  "conditional_statements", "if_statement", "else_part",
  "switch_statement", "$@9", "case_statements",
  "case_statements_continuation", "loop_statement", "for_statement",
  "while_statement", "do_while_statement", "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,    46
};
# endif

#define YYPACT_NINF -215

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-215)))

#define YYTABLE_NINF -39

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,  -215,   -14,   -12,  -215,  -215,  -215,   -17,    -4,   -30,
    -215,  -215,  -215,    37,  -215,    94,  -215,  -215,  -215,   -10,
    -215,  -215,  -215,  -215,  -215,   -14,   -12,  -215,  -215,   -14,
     -12,  -215,    -9,  -215,  -215,  -215,  -215,    -2,     9,    15,
      20,  -215,  -215,  -215,  -215,  -215,    23,    24,    -9,    21,
     302,   193,  -215,    -9,  -215,  -215,   311,  -215,   -26,    32,
    -215,    25,     2,    30,     6,     6,    33,  -215,  -215,   253,
      19,     7,    39,    36,    41,   193,    42,    46,  -215,  -215,
    -215,  -215,  -215,  -215,   253,  -215,    -9,    44,  -215,    82,
      83,  -215,   204,    26,  -215,  -215,  -215,  -215,   309,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,   311,    49,  -215,  -215,    52,    55,
      52,   119,  -215,  -215,  -215,    58,   253,  -215,   -29,   -29,
     238,   193,    60,  -215,    81,    -9,  -215,   253,   253,    61,
     253,   253,  -215,   -29,  -215,   253,  -215,   253,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,   134,   134,  -215,
    -215,  -215,   134,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,  -215,  -215,    56,  -215,  -215,
    -215,    87,    80,    53,  -215,  -215,  -215,   241,  -215,  -215,
    -215,    85,    88,    89,  -215,    91,   -29,   193,    90,  -215,
    -215,    92,    99,    95,    96,   101,   110,    82,    83,    26,
       8,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,    93,  -215,  -215,  -215,    52,   241,   116,
     121,   113,  -215,   324,   193,  -215,  -215,  -215,   193,   253,
     253,   122,   253,  -215,  -215,  -215,  -215,  -215,   123,  -215,
     241,  -215,    85,  -215,   159,  -215,   129,   124,  -215,  -215,
     121,  -215,  -215,   193,  -215,   253,   131,   -23,  -215,  -215,
     130,  -215,   253,   136,   137,   193,   139,   193,  -215,  -215,
     193,   117,   -23,   253,  -215,  -215,   143,   193,   117,  -215
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    56,    74,    76,    57,    59,    58,    72,    68,     0,
      64,     9,    10,     0,     2,     5,     6,     7,     8,     0,
      73,    62,    75,    63,    69,    74,    76,    61,    65,    74,
      76,    60,    52,     1,     4,     3,    29,    27,     0,     0,
      26,    70,    71,    66,    67,    27,     0,     0,     0,    32,
       0,     0,    22,     0,    24,    23,    55,    30,    35,    43,
      14,     0,     0,     0,     0,     0,     0,   156,   153,     0,
       0,     0,     0,     0,     0,     0,     0,   116,   127,   128,
     129,   130,   149,   150,     0,   147,     0,     0,    78,    94,
      97,    99,   101,   103,   105,   108,   109,   110,   107,   106,
     121,   122,    11,   144,   142,   143,   157,   158,   145,   168,
     169,   170,   146,    25,    55,     0,    40,    31,    37,     0,
      37,     0,    28,    13,    18,    15,     0,   116,   114,   115,
       0,   152,     0,   174,     0,     0,   148,     0,     0,     0,
       0,   126,    98,   107,   155,     0,    92,     0,    95,   141,
     140,   137,   138,   136,   139,   131,   132,     0,     0,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,     0,    77,   117,
      54,     0,     0,     0,    34,    39,    33,    49,    42,    44,
      45,    21,     0,     0,   113,     0,   112,   152,     0,   120,
     175,     0,     0,     0,     0,   125,     0,    94,    97,   102,
     100,   104,    85,    86,    89,    88,    87,    84,    83,    82,
      80,    81,    79,     0,   119,    53,    41,    37,    49,     0,
      51,     0,    19,     0,     0,   111,   151,   154,     0,     0,
       0,     0,   126,   123,    93,    96,   118,    36,     0,    46,
      49,    48,    21,    16,   161,   172,     0,     0,   162,   124,
      51,    50,    20,     0,   159,     0,     0,     0,    47,   160,
       0,   173,     0,     0,     0,     0,     0,     0,   163,   171,
       0,   167,     0,     0,   165,   164,     0,     0,   167,   166
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,   158,  -215,  -215,  -215,  -215,  -215,   -48,  -215,
    -215,  -215,   -70,     5,   -20,  -215,   138,  -215,  -215,  -215,
    -215,  -113,  -215,  -215,    11,  -215,  -215,  -215,  -215,  -214,
     -72,  -215,  -215,    84,     1,  -215,  -215,    -6,    -5,   -61,
    -215,  -122,    -7,    50,     3,   -78,  -215,    43,    63,    47,
    -215,  -215,  -215,  -215,   -62,  -215,  -215,  -215,   -39,  -215,
    -215,  -215,  -215,   -51,    28,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,   -52,   -56,  -215,  -215,  -215,  -215,  -215
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    35,    15,    16,    38,    51,    61,   192,
     125,   191,   232,    85,    39,    54,    40,    49,    48,    59,
     117,   184,   118,   119,   120,   182,   122,   188,   189,   229,
     251,    18,    47,   115,    86,    31,    27,    21,    23,    87,
     178,    88,   146,    89,   148,    90,    91,    92,    93,    94,
      95,   195,    96,    97,    98,   179,    99,   100,   206,   101,
     157,   162,   158,   197,   198,   103,   131,   104,   105,   106,
     264,   107,   267,   274,   284,   108,   109,   110,   111,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     102,    19,   128,   129,   193,    17,   142,   186,   132,   134,
      36,    36,    46,   174,   248,   201,    19,   -38,   204,    41,
      17,    42,   143,    43,   139,    44,   155,   156,    64,    24,
      25,    26,    20,   113,    22,    32,   261,    33,   -12,    65,
     272,   273,    28,    29,    30,   116,   159,   160,   161,    50,
      52,    62,   177,    66,   133,    37,    45,    53,    55,    69,
     190,   114,    56,    58,   143,   121,   123,   124,   196,   208,
     126,   127,   135,   130,   136,   143,   137,   202,   143,   144,
     205,   138,   140,   143,    77,   143,   141,   145,   181,   147,
      78,    79,    80,    81,   183,   143,   143,    84,   185,   -17,
     143,   199,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   247,    46,   200,   256,   257,   114,
     203,   224,   225,   226,   116,   233,   230,   231,    64,   237,
     234,   194,   235,   238,   239,   240,   246,   241,   242,    65,
       1,     2,     3,    64,     4,     5,     6,     7,     8,     9,
     276,   243,    10,    66,    65,   249,   252,   187,   250,    69,
     258,   286,   260,   263,   265,   266,   271,   230,    66,    11,
      12,   275,   277,    34,    69,   280,   278,   143,   143,   287,
     283,   205,   262,   254,    77,   253,    57,   255,   268,   230,
      78,    79,    80,    81,   227,   207,    63,    84,   180,    77,
     244,   210,    64,   259,   270,    78,    79,    80,    81,   211,
     143,   245,   269,    65,   149,   150,   151,   152,   153,   154,
     209,   143,   155,   156,   279,   236,   281,    66,    67,   282,
     285,    68,   289,    69,    62,     0,   288,    70,     0,     1,
       2,     3,     0,     4,     5,     6,     7,     8,    71,    72,
      64,    10,    73,    74,    75,    76,     0,     0,    77,     0,
       0,    65,    64,     0,    78,    79,    80,    81,    82,    83,
       0,    84,     0,    65,     0,    66,     0,     0,     0,   228,
       0,    69,     0,     0,     1,     2,     3,    66,     4,     5,
       6,     7,     8,    69,     0,     0,    10,     0,     0,     0,
       0,     0,     0,   127,     0,     0,    77,     0,     0,     0,
       0,     0,    78,    79,    80,    81,     0,     0,    77,    84,
       0,     0,     0,     0,    78,    79,    80,    81,     0,     0,
       0,    84,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    60,     0,     0,     0,     0,     1,     2,
       3,   174,     4,     5,     6,     7,     8,     1,     2,     3,
      10,     4,     5,     6,     7,     8,    71,     0,     0,    10,
       1,     2,     3,     0,     4,     5,     6,     7,     8,     0,
       0,     0,    10,     0,     0,     0,     0,     0,   175,   176,
     177
};

static const yytype_int16 yycheck[] =
{
      51,     0,    64,    65,   126,     0,    84,   120,    69,    70,
      20,    20,    32,    42,   228,   137,    15,    43,   140,    25,
      15,    26,    84,    29,    75,    30,    18,    19,     9,    46,
      47,    48,    46,    53,    46,    65,   250,     0,    40,    20,
      63,    64,    46,    47,    48,    71,    20,    21,    22,    40,
      35,    50,    81,    34,    35,    65,    65,    37,    35,    40,
     121,    56,    38,    42,   126,    33,    41,    65,   130,   147,
      40,    65,    65,    40,    35,   137,    40,   138,   140,    35,
     141,    40,    40,   145,    65,   147,    40,     5,    39,     6,
      71,    72,    73,    74,    42,   157,   158,    78,    43,    41,
     162,    41,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   227,   135,    35,   239,   240,   114,
      59,    65,    35,    43,    71,    37,   187,    42,     9,    39,
      41,   130,    41,    41,    35,    40,    43,    41,    37,    20,
      46,    47,    48,     9,    50,    51,    52,    53,    54,    55,
     272,    41,    58,    34,    20,    39,    43,    38,    37,    40,
      38,   283,    39,     4,    35,    41,    35,   228,    34,    75,
      76,    41,    36,    15,    40,    36,    39,   239,   240,    36,
      63,   242,   252,   234,    65,   233,    48,   238,   260,   250,
      71,    72,    73,    74,   183,   145,     3,    78,   114,    65,
     207,   158,     9,   242,   265,    71,    72,    73,    74,   162,
     272,   208,   263,    20,    10,    11,    12,    13,    14,    15,
     157,   283,    18,    19,   275,   197,   277,    34,    35,   280,
     282,    38,   288,    40,   233,    -1,   287,    44,    -1,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
       9,    58,    59,    60,    61,    62,    -1,    -1,    65,    -1,
      -1,    20,     9,    -1,    71,    72,    73,    74,    75,    76,
      -1,    78,    -1,    20,    -1,    34,    -1,    -1,    -1,    38,
      -1,    40,    -1,    -1,    46,    47,    48,    34,    50,    51,
      52,    53,    54,    40,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    65,    78,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    41,    -1,    -1,    -1,    -1,    46,    47,
      48,    42,    50,    51,    52,    53,    54,    46,    47,    48,
      58,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,    48,    50,    51,    52,    53,    54,    55,
      58,    75,    76,    83,    84,    86,    87,    95,   113,   116,
      46,   119,    46,   120,    46,    47,    48,   118,    46,    47,
      48,   117,    65,     0,    84,    85,    20,    65,    88,    96,
      98,   119,   120,   119,   120,    65,    96,   114,   100,    99,
      40,    89,    35,    37,    97,    35,    38,    98,    42,   101,
      41,    90,   116,     3,     9,    20,    34,    35,    38,    40,
      44,    55,    56,    59,    60,    61,    62,    65,    71,    72,
      73,    74,    75,    76,    78,    95,   116,   121,   123,   125,
     127,   128,   129,   130,   131,   132,   134,   135,   136,   138,
     139,   141,   145,   147,   149,   150,   151,   153,   157,   158,
     159,   160,   161,    96,    95,   115,    71,   102,   104,   105,
     106,    33,   108,    41,    65,    92,    40,    65,   136,   136,
      40,   148,   121,    35,   121,    65,    35,    40,    40,   145,
      40,    40,   127,   136,    35,     5,   124,     6,   126,    10,
      11,    12,    13,    14,    15,    18,    19,   142,   144,    20,
      21,    22,   143,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    42,    79,    80,    81,   122,   137,
     115,    39,   107,    42,   103,    43,   103,    38,   109,   110,
     121,    93,    91,   123,   116,   133,   136,   145,   146,    41,
      35,   123,   121,    59,   123,   121,   140,   125,   127,   130,
     129,   131,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,    65,    35,    43,   106,    38,   111,
     121,    42,    94,    37,    41,    41,   146,    39,    41,    35,
      40,    41,    37,    41,   124,   126,    43,   103,   111,    39,
      37,   112,    43,    90,   145,   145,   123,   123,    38,   140,
      39,   111,    94,     4,   152,    35,    41,   154,   112,   145,
     121,    35,    63,    64,   155,    41,   123,    36,    39,   145,
      36,   145,   145,    63,   156,   155,   123,    36,   145,   156
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    85,    85,    86,    86,    86,    86,
      86,    87,    88,    89,    89,    91,    90,    90,    93,    92,
      94,    94,    95,    95,    96,    97,    97,    99,    98,   100,
      98,   101,   101,   102,   102,   102,   103,   103,   105,   104,
     107,   106,   108,   108,   109,   109,   110,   111,   111,   111,
     112,   112,   114,   113,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   118,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   124,   124,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   131,   131,
     131,   132,   133,   133,   134,   135,   136,   136,   137,   137,
     138,   138,   138,   139,   140,   140,   140,   141,   141,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   144,   144,
     144,   144,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   146,   146,   148,   147,   149,   149,   150,   150,   151,
     152,   152,   154,   153,   155,   155,   156,   156,   157,   157,
     157,   158,   159,   160,   161,   161
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     1,     1,     1,
       1,     4,     1,     3,     2,     0,     5,     2,     0,     3,
       3,     0,     3,     4,     2,     2,     0,     0,     4,     0,
       3,     2,     0,     2,     2,     0,     3,     0,     0,     2,
       0,     3,     2,     0,     1,     1,     3,     4,     2,     0,
       2,     0,     0,     7,     2,     0,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     2,     2,     0,     1,
       2,     2,     0,     1,     0,     1,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     2,     3,     0,     2,     3,     0,     2,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     2,     2,     1,     2,     3,     2,
       3,     1,     1,     4,     3,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     2,     0,     0,     4,     2,     1,     1,     1,     6,
       2,     0,     0,     8,     5,     4,     5,     0,     1,     1,
       1,     9,     5,     7,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 12:
#line 121 "parser.y"
    {
				type_insert();
				class_insert("Function");
				strcpy(cur_fun, cur_symbol);
				// nesting_insert(nesting);
			}
#line 1689 "y.tab.c"
    break;

  case 15:
#line 136 "parser.y"
    {
				char cpy[100];
				strcpy(cpy, cur_symbol);
				strcat(cpy, ",");
				strcat(arglist, cpy);
			}
#line 1700 "y.tab.c"
    break;

  case 17:
#line 142 "parser.y"
    {
				char cpy[100];
				strcpy(cpy, cur_symbol);
				strcat(arglist, cpy);
				insert_arg_list_proxy(cur_fun, arglist);
				arglist[0] = '\0';
			}
#line 1712 "y.tab.c"
    break;

  case 18:
#line 152 "parser.y"
    { 
				yyval = 1;
				type_insert(); 
			}
#line 1721 "y.tab.c"
    break;

  case 27:
#line 182 "parser.y"
    { type_insert(); push(cur_symbol); pointer_flag = 0;  nesting_insert(nesting);}
#line 1727 "y.tab.c"
    break;

  case 29:
#line 183 "parser.y"
    {pointer_flag++;}
#line 1733 "y.tab.c"
    break;

  case 38:
#line 204 "parser.y"
    {array_dim_insert(1);}
#line 1739 "y.tab.c"
    break;

  case 40:
#line 208 "parser.y"
    {array_dim_insert(0);}
#line 1745 "y.tab.c"
    break;

  case 52:
#line 240 "parser.y"
    { 
				type_insert(); 
				class_insert("Structure");
			}
#line 1754 "y.tab.c"
    break;

  case 153:
#line 427 "parser.y"
    {push("{"); nesting++; ;}
#line 1760 "y.tab.c"
    break;

  case 154:
#line 427 "parser.y"
    {push("}"); nesting--; ;}
#line 1766 "y.tab.c"
    break;

  case 162:
#line 451 "parser.y"
    {nesting++; ;}
#line 1772 "y.tab.c"
    break;

  case 163:
#line 451 "parser.y"
    {nesting--; ;}
#line 1778 "y.tab.c"
    break;


#line 1782 "y.tab.c"

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
  return yyresult;
}
#line 487 "parser.y"


int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");

	yyparse();

	if(error_flag == 0)
	{
		printf("Parsing Complete: Result - Valid" "\n");
		printf("%50s \n", "Symbol table");
		print_symbol_table_proxy();

		printf("Constant table\n");
		print_constant_table_proxy();
	}

	return 0;
}

void class_insert(char* class)
{
	insert_symbol_class_proxy(class);
}

void type_insert()
{
	if(pointer_flag)
	{
		char pointer_type[100] = "";
		int i = 0;
		for(i = 0; i < pointer_flag; i++)
		{
			strcat(pointer_type, "*");
		}
		strcat(pointer_type, cur_type);
		insert_symbol_type_proxy(cur_symbol, pointer_type);
		return;
	}
	insert_symbol_type_proxy(cur_symbol, cur_type);
}

void append_star()
{
	append_star_proxy(cur_symbol);
}

void array_dim_insert(int empty)
{

	insert_symbol_array_dimension_proxy(empty);
}


void push(char symbol[])
{
	if(top == -1 && strcmp(symbol, "{") != 0) 
	{
		return;
	}
	if(strcmp(symbol, "}") == 0)
	{
		start_pop();
		return;
	}
	top++;
	if(strcmp(symbol, "{") == 0)
	{
		cur_open_line = yylineno;
	}
	strcpy(symbol_stack[top], symbol);
	line_stack[top] = cur_open_line;
}

void start_pop()
{
	char cur[100];
	cur_line = yylineno;
	while(strcmp(symbol_stack[top], "{") != 0)
	{
		insert_start_line(line_stack[top], symbol_stack[top]);
		insert_end_line(cur_line, symbol_stack[top]);
		pop();

	}
	pop();
}

void pop()
{
	top--;
}

int yywrap()
{
	return 1;
}


void yyerror(char *error)
{
	error_flag=1;
	printf("%d %s %s\n", yylineno, error, yytext);
	printf("Parsing Failed: Result- Invalid\n");
}
