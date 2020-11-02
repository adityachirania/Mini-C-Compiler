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

	void yyerror(char* s);
	int yylex();

	extern FILE *yyin;
	extern int yylineno;
	extern char *yytext;

	// Temp generation
	char temp_var[10] = "t0";
	int temp_counter = 0;
	char *new_temp();

	// DS to hold generated code
	int line_ptr = 0;
	char code[1000][30];
	void gen(int n, const char*[]);

	// Back patch operation
	void backpatch(int backpatch_line, int goto_line);

#line 97 "y.tab.c"

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
# define YYERROR_VERBOSE 1
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
union YYSTYPE
{
#line 29 "parser.y"

	// Hack
	struct
	{
		char *Value;

		// line number for goto (for backpatch)
		int GotoLine;
		int BackPatchLine;

		// extra variable in times of needs
		int Extra;

		// string extra
		char *S_Extra;
	}

#line 318 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
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
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  277

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
       0,    92,    92,    95,    99,   100,   104,   105,   106,   107,
     108,   114,   122,   130,   131,   136,   141,   150,   157,   158,
     164,   165,   170,   175,   176,   180,   181,   186,   187,   191,
     192,   193,   197,   198,   202,   206,   211,   212,   216,   217,
     222,   225,   226,   227,   230,   231,   238,   240,   241,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   258,   259,
     260,   261,   264,   265,   266,   267,   270,   271,   274,   275,
     282,   289,   297,   305,   312,   316,   320,   324,   328,   332,
     336,   340,   344,   348,   352,   358,   367,   373,   382,   388,
     397,   403,   412,   418,   427,   433,   442,   448,   452,   456,
     457,   458,   462,   465,   466,   469,   473,   477,   481,   506,
     517,   523,   527,   531,   537,   550,   557,   564,   567,   571,
     575,   579,   588,   592,   598,   602,   606,   612,   616,   620,
     624,   628,   632,   641,   645,   646,   647,   648,   649,   650,
     651,   652,   656,   660,   661,   664,   668,   672,   673,   679,
     685,   696,   702,   707,   718,   722,   723,   727,   728,   732,
     733,   734,   738,   747,   753,   767,   777,   788,   795,   807,
     812,   823,   833,   839,   844
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "parameters_list", "param_identifier",
  "parameter_identifier_array_check", "variable_declaration",
  "variable_declaration_list", "variable_declaration_list_continuation",
  "single_element_declaration", "array_declaration", "first_dimension",
  "other_dimension", "array_dimension_without_integer",
  "array_dimension_with_integer", "initilization",
  "initilization_continuation", "array_initialization", "array_item_list",
  "array_item_list_continuation", "structure_definition",
  "struct_variable_declaration", "type_specifier", "unsigned", "signed",
  "short", "long", "expression", "assignment_type", "simple_expression",
  "and_expression", "unary_relational_expression", "relational_expression",
  "sum_of_factors", "factor", "factor_continuation", "size_of",
  "size_of_continuation", "address_of", "value_of", "assignable",
  "assignable_end", "fixed_value", "function_call", "arguments_list",
  "constant", "sum_operators", "multiplicative_operators",
  "relational_operators", "statement", "compound_statement",
  "statement_list", "expression_statement", "conditional_statements",
  "if_statement", "if_condition", "else_part", "empty_else",
  "switch_statement", "case_statements", "case_statements_continuation",
  "loop_statement", "for_statement", "for_statement_init",
  "for_statement_condition", "for_statement_update", "for_statement_body",
  "while_statement", "while_begin", "empty_while", "while_end",
  "do_while_statement", "empty_do_while", "return_statement", YY_NULLPTR
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

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -13

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     115,  -178,   -23,   -12,  -178,  -178,  -178,    67,    71,   -20,
    -178,  -178,  -178,    35,  -178,   115,  -178,  -178,  -178,   -10,
    -178,  -178,  -178,  -178,  -178,   -23,   -12,  -178,  -178,   -23,
     -12,  -178,    -8,  -178,  -178,  -178,    -6,    65,    -2,    15,
      46,  -178,  -178,  -178,  -178,   270,    50,    42,  -178,   -30,
      64,   288,   173,  -178,    -6,  -178,    36,   270,    63,    -6,
    -178,  -178,    81,  -178,    66,    66,     8,  -178,  -178,    87,
      62,    90,    70,    70,    91,  -178,   173,   196,    86,    99,
      96,    98,  -178,   100,   101,  -178,  -178,  -178,  -178,  -178,
    -178,   196,  -178,   109,   141,   142,  -178,  -178,   244,    40,
    -178,  -178,  -178,  -178,   252,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,   196,  -178,   173,  -178,
    -178,  -178,    -6,  -178,   112,  -178,    78,  -178,  -178,    38,
    -178,  -178,  -178,  -178,   108,   116,   196,   173,  -178,   -27,
     -27,   261,   173,   113,   114,  -178,   119,  -178,  -178,   196,
     173,   196,   196,  -178,   -27,  -178,   196,   196,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,   232,   232,  -178,  -178,
    -178,   232,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,   196,  -178,  -178,   106,   196,  -178,    16,
     196,  -178,  -178,  -178,    66,    38,   136,   140,   135,  -178,
     297,     2,   175,  -178,   139,   -27,  -178,  -178,  -178,  -178,
     196,   146,   124,    22,   148,   147,   142,  -178,    40,    69,
    -178,   144,  -178,  -178,  -178,   153,   173,  -178,   150,  -178,
      38,  -178,   108,  -178,  -178,  -178,  -178,  -178,    24,  -178,
     155,   158,   196,  -178,  -178,  -178,  -178,  -178,   140,  -178,
    -178,   173,  -178,   196,    59,  -178,  -178,  -178,    26,   196,
     161,   159,   165,    28,   173,  -178,  -178,   173,   143,    59,
     196,  -178,  -178,    34,   173,   143,  -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    49,    67,    69,    50,    52,    51,    65,    61,     0,
      57,     9,    10,     0,     2,     5,     6,     7,     8,     0,
      66,    55,    68,    56,    62,    67,    69,    54,    58,    67,
      69,    53,     0,     1,     4,     3,     0,    28,     0,     0,
      24,    63,    64,    59,    60,    48,    28,     0,    26,    31,
      37,     0,     0,    20,     0,    22,     0,    48,     0,     0,
      21,    34,     0,    27,    33,    33,     0,    25,    14,     0,
       0,     0,     0,     0,     0,   146,   144,     0,     0,     0,
       0,     0,   172,     0,   107,   118,   119,   120,   121,   140,
     141,     0,   138,     0,    73,    86,    88,    90,    92,    94,
      96,    99,   100,   101,    98,    97,   112,   113,    11,   135,
     133,   134,   147,   148,   136,   159,     0,   160,     0,   161,
     137,    23,     0,    47,     0,    35,     0,    30,    29,    43,
      36,    38,    39,    13,    19,    16,     0,     0,   107,   105,
     106,     0,   144,     0,     0,   173,     0,   139,   169,     0,
       0,     0,   117,    89,    98,   145,     0,     0,   132,   131,
     128,   129,   127,   130,   122,   123,     0,     0,   124,   125,
     126,     0,    80,    81,    84,    83,    82,    79,    78,    77,
      75,    76,    74,     0,    71,    72,     0,     0,   108,     0,
       0,   170,   167,    46,    33,    43,     0,    45,     0,    17,
       0,     0,   152,   104,     0,   103,   143,   142,   111,   174,
       0,     0,     0,     0,   116,     0,    85,    87,    93,    91,
      95,     0,   110,    70,   164,     0,     0,    32,     0,    40,
      43,    42,    19,    15,   150,   153,   149,   102,     0,   163,
       0,     0,   117,   114,   109,   165,   166,   162,    45,    44,
      18,     0,   168,     0,     0,   115,    41,   151,     0,     0,
       0,     0,     0,     0,     0,   154,   171,     0,   158,     0,
       0,   156,   155,     0,     0,   158,   157
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,   187,  -178,  -178,  -178,  -178,  -178,     4,  -178,
     -22,    11,   -29,  -178,   178,  -178,  -178,   -61,  -178,    83,
    -178,  -178,  -178,  -177,   -11,  -178,   182,     1,  -178,  -178,
       7,    14,   -58,  -178,  -114,    84,   -82,  -178,    51,    76,
      72,  -178,  -178,  -178,  -178,   -67,  -178,  -178,  -178,    18,
    -178,  -178,  -178,  -178,   -52,  -178,   111,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,   -19,    -4,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    35,    15,    16,    38,    52,    69,   135,
     199,    92,    39,    55,    40,    50,    63,   127,    64,    65,
      67,   130,   131,   196,   231,    18,    58,    59,    31,    27,
      21,    23,    93,   187,    94,    95,    96,    97,    98,    99,
     100,   101,   204,   102,   103,   104,   188,   105,   106,   215,
     107,   166,   171,   167,   142,   109,   143,   110,   111,   112,
     137,   236,   251,   113,   261,   271,   114,   115,   116,   190,
     226,   247,   117,   118,   210,   192,   119,   150,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,    19,   189,    47,   128,   139,   140,   156,   132,   153,
      36,    17,    36,    61,    36,   183,    19,    72,   228,   144,
     146,   156,   201,    20,   154,   121,    17,   156,    73,   156,
      45,   156,    41,   156,    22,    33,    43,   213,    51,   156,
      42,    62,    74,   234,    44,    32,   129,    72,    77,   154,
      53,   224,    70,   249,   186,    37,    57,    46,    73,    46,
     168,   169,   170,   241,   267,   252,   191,   262,    57,   154,
     274,   197,    74,    84,   205,   217,   195,    60,    77,    85,
      86,    87,    88,    54,   154,   202,    91,   164,   165,   154,
     154,   211,    49,    47,   214,    72,   238,    66,   212,   154,
     154,   122,   124,    84,   154,   -12,    73,    49,   126,    85,
      86,    87,    88,    24,    25,    26,    91,    28,    29,    30,
      74,   145,   259,   260,   125,   221,    77,   134,   133,   223,
     136,   141,   225,   227,   147,   138,   148,   197,   149,   258,
     151,   152,   203,   154,   155,   263,   156,   193,   157,    62,
     198,    84,   207,   200,   209,   208,   273,    85,    86,    87,
      88,     1,     2,     3,    91,     4,     5,     6,     7,     8,
       9,   222,   197,    10,   246,   229,    71,   230,   232,   235,
     237,   239,    72,   240,   214,   242,   154,   244,   243,   248,
      11,    12,   154,    73,   245,   253,   254,   264,   265,   257,
     266,    70,    34,   154,   233,    72,   270,    74,    75,   194,
     250,    76,   268,    77,    48,   269,    73,    78,   219,     1,
       2,     3,   275,     4,     5,     6,     7,     8,    56,    79,
      74,    10,    80,    81,    82,    83,    77,   256,    84,   123,
     216,    72,   218,   220,    85,    86,    87,    88,    89,    90,
     272,    91,    73,   206,   158,   159,   160,   161,   162,   163,
     255,    84,   164,   165,     0,     0,    74,    85,    86,    87,
      88,   276,    77,     0,    91,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     0,     0,     0,     0,
       0,     0,     0,     0,   183,     0,     0,    84,     0,     0,
       0,     0,     0,    85,    86,    87,    88,     1,     2,     3,
       0,     4,     5,     6,     7,     8,     1,     2,     3,    10,
       4,     5,     6,     7,     8,    56,   138,     0,    10,    68,
       0,   184,   185,   186,     1,     2,     3,     0,     4,     5,
       6,     7,     8,     1,     2,     3,    10,     4,     5,     6,
       7,     8,     0,     0,     0,    10
};

static const yytype_int16 yycheck[] =
{
      52,     0,   116,    32,    65,    72,    73,     5,    66,    91,
      20,     0,    20,    43,    20,    42,    15,     9,   195,    77,
      78,     5,   136,    46,    91,    54,    15,     5,    20,     5,
      38,     5,    25,     5,    46,     0,    29,   151,    40,     5,
      26,    71,    34,    41,    30,    65,    38,     9,    40,   116,
      35,    35,    51,   230,    81,    65,    45,    65,    20,    65,
      20,    21,    22,    41,    36,    41,   118,    41,    57,   136,
      36,   129,    34,    65,   141,   157,    38,    35,    40,    71,
      72,    73,    74,    37,   151,   137,    78,    18,    19,   156,
     157,   149,    42,   122,   152,     9,   210,    33,   150,   166,
     167,    65,    39,    65,   171,    40,    20,    42,    42,    71,
      72,    73,    74,    46,    47,    48,    78,    46,    47,    48,
      34,    35,    63,    64,    43,   183,    40,    65,    41,   187,
      40,    40,   190,   194,    35,    65,    40,   195,    40,   253,
      40,    40,   141,   210,    35,   259,     5,    35,     6,    71,
      42,    65,    39,    37,    35,    41,   270,    71,    72,    73,
      74,    46,    47,    48,    78,    50,    51,    52,    53,    54,
      55,    65,   230,    58,   226,    39,     3,    37,    43,     4,
      41,    35,     9,    59,   242,    37,   253,    43,    41,    39,
      75,    76,   259,    20,    41,    40,    38,    36,    39,   251,
      35,   200,    15,   270,   200,     9,    63,    34,    35,   126,
     232,    38,   264,    40,    36,   267,    20,    44,   167,    46,
      47,    48,   274,    50,    51,    52,    53,    54,    55,    56,
      34,    58,    59,    60,    61,    62,    40,   248,    65,    57,
     156,     9,   166,   171,    71,    72,    73,    74,    75,    76,
     269,    78,    20,   142,    10,    11,    12,    13,    14,    15,
     242,    65,    18,    19,    -1,    -1,    34,    71,    72,    73,
      74,   275,    40,    -1,    78,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    46,    47,    48,    58,
      50,    51,    52,    53,    54,    55,    65,    -1,    58,    41,
      -1,    79,    80,    81,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    46,    47,    48,    58,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,    48,    50,    51,    52,    53,    54,    55,
      58,    75,    76,    83,    84,    86,    87,    93,   107,   109,
      46,   112,    46,   113,    46,    47,    48,   111,    46,    47,
      48,   110,    65,     0,    84,    85,    20,    65,    88,    94,
      96,   112,   113,   112,   113,    38,    65,    94,    96,    42,
      97,    40,    89,    35,    37,    95,    55,    93,   108,   109,
      35,    43,    71,    98,   100,   101,    33,   102,    41,    90,
     109,     3,     9,    20,    34,    35,    38,    40,    44,    56,
      59,    60,    61,    62,    65,    71,    72,    73,    74,    75,
      76,    78,    93,   114,   116,   117,   118,   119,   120,   121,
     122,   123,   125,   126,   127,   129,   130,   132,   136,   137,
     139,   140,   141,   145,   148,   149,   150,   154,   155,   158,
     160,    94,    65,   108,    39,    43,    42,    99,    99,    38,
     103,   104,   114,    41,    65,    91,    40,   142,    65,   127,
     127,    40,   136,   138,   114,    35,   114,    35,    40,    40,
     159,    40,    40,   118,   127,    35,     5,     6,    10,    11,
      12,    13,    14,    15,    18,    19,   133,   135,    20,    21,
      22,   134,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    42,    79,    80,    81,   115,   128,   116,
     151,   136,   157,    35,   101,    38,   105,   114,    42,    92,
      37,   116,   136,   109,   124,   127,   138,    39,    41,    35,
     156,   114,   136,   116,   114,   131,   117,   118,   121,   120,
     122,   114,    65,   114,    35,   114,   152,    99,   105,    39,
      37,   106,    43,    90,    41,     4,   143,    41,   116,    35,
      59,    41,    37,    41,    43,    41,   136,   153,    39,   105,
      92,   144,    41,    40,    38,   131,   106,   136,   116,    63,
      64,   146,    41,   116,    36,    39,    35,    36,   136,   136,
      63,   147,   146,   116,    36,   136,   147
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    85,    85,    86,    86,    86,    86,
      86,    87,    88,    89,    89,    90,    90,    91,    92,    92,
      93,    93,    94,    95,    95,    96,    96,    97,    97,    98,
      98,    98,    99,    99,   100,   101,   102,   102,   103,   103,
     104,   105,   105,   105,   106,   106,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   123,   124,   124,   125,   126,   127,   127,   128,
     128,   129,   129,   129,   130,   131,   131,   131,   132,   132,
     132,   132,   133,   133,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   138,   138,   139,   139,   140,   140,   141,
     142,   143,   143,   144,   145,   146,   146,   147,   147,   148,
     148,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   160
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     1,     1,     1,
       1,     4,     1,     3,     2,     4,     2,     2,     3,     0,
       3,     4,     2,     2,     0,     3,     2,     2,     0,     2,
       2,     0,     3,     0,     1,     2,     2,     0,     1,     1,
       3,     4,     2,     0,     2,     0,     6,     2,     0,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     2,
       2,     0,     1,     2,     2,     0,     1,     0,     1,     0,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     2,     2,     1,     2,     3,
       2,     3,     1,     1,     4,     3,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     2,     0,     2,     1,     1,     1,     4,
       3,     3,     0,     0,     7,     5,     4,     5,     0,     1,
       1,     1,     4,     4,     2,     2,     1,     2,     5,     0,
       1,     8,     0,     2,     3
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
  case 11:
#line 115 "parser.y"
    {
				const char* line[] = {"end"};
				gen(1, line);
			}
#line 1679 "y.tab.c"
    break;

  case 12:
#line 123 "parser.y"
    {
				const char* line[] = {"begin", (yyval.Value)};
				gen(2, line);
			}
#line 1688 "y.tab.c"
    break;

  case 15:
#line 137 "parser.y"
    {
				const char *line[] = {"param", (yyvsp[-2].Value)};
				gen(2, line);
			}
#line 1697 "y.tab.c"
    break;

  case 16:
#line 142 "parser.y"
    {
				const char *line[] = {"param", (yyvsp[0].Value)};
				gen(2, line);
			}
#line 1706 "y.tab.c"
    break;

  case 17:
#line 151 "parser.y"
    {
				(yyval.Value) = (yyvsp[-1].Value);
			}
#line 1714 "y.tab.c"
    break;

  case 70:
#line 283 "parser.y"
    {
				const char *line[] = {(yyvsp[-2].Value), (yyvsp[-1].Value), (yyvsp[0].Value)};
				gen(3, line);

				(yyval.Value) = (yyvsp[-2].Value);
			}
#line 1725 "y.tab.c"
    break;

  case 71:
#line 290 "parser.y"
    {
				// TODO: Check if this is correct ICG generation
				const char *line[] = {(yyvsp[-1].Value), "=", (yyvsp[-1].Value), "+", "1"};
				gen(5, line);

				(yyval.Value) = (yyvsp[-1].Value);
			}
#line 1737 "y.tab.c"
    break;

  case 72:
#line 298 "parser.y"
    {
				// TODO: Check if this is correct ICG generation
				const char *line[] = {(yyvsp[-1].Value), "=", (yyvsp[-1].Value), "-", "1"};
				gen(5, line);

				(yyval.Value) = (yyvsp[-1].Value);
			}
#line 1749 "y.tab.c"
    break;

  case 73:
#line 306 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1757 "y.tab.c"
    break;

  case 74:
#line 313 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1765 "y.tab.c"
    break;

  case 75:
#line 317 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1773 "y.tab.c"
    break;

  case 76:
#line 321 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1781 "y.tab.c"
    break;

  case 77:
#line 325 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1789 "y.tab.c"
    break;

  case 78:
#line 329 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1797 "y.tab.c"
    break;

  case 79:
#line 333 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1805 "y.tab.c"
    break;

  case 80:
#line 337 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1813 "y.tab.c"
    break;

  case 81:
#line 341 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1821 "y.tab.c"
    break;

  case 82:
#line 345 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1829 "y.tab.c"
    break;

  case 83:
#line 349 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1837 "y.tab.c"
    break;

  case 84:
#line 353 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1845 "y.tab.c"
    break;

  case 85:
#line 359 "parser.y"
    {
				const char *temp = new_temp();

				const char *line[] = {temp, "=", (yyvsp[-2].Value), (yyvsp[-1].Value), (yyvsp[0].Value)};
				gen(5, line);

				(yyval.Value) = strdup(temp);
			}
#line 1858 "y.tab.c"
    break;

  case 86:
#line 368 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1866 "y.tab.c"
    break;

  case 87:
#line 374 "parser.y"
    {
				const char *temp = new_temp();

				const char *line[] = {temp, "=", (yyvsp[-2].Value), (yyvsp[-1].Value), (yyvsp[0].Value)};
				gen(5, line);

				(yyval.Value) = strdup(temp);
			}
#line 1879 "y.tab.c"
    break;

  case 88:
#line 383 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1887 "y.tab.c"
    break;

  case 89:
#line 389 "parser.y"
    {
				const char *temp = new_temp();

				const char *line[] = {temp, "=", (yyvsp[-1].Value), (yyvsp[0].Value)};
				gen(4, line);

				(yyval.Value) = strdup(temp);
			}
#line 1900 "y.tab.c"
    break;

  case 90:
#line 398 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1908 "y.tab.c"
    break;

  case 91:
#line 404 "parser.y"
    {
				const char *temp = new_temp();

				const char *line[] = {temp, "=", (yyvsp[-2].Value), (yyvsp[-1].Value), (yyvsp[0].Value)};
				gen(5, line);

				(yyval.Value) = strdup(temp);
			}
#line 1921 "y.tab.c"
    break;

  case 92:
#line 413 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1929 "y.tab.c"
    break;

  case 93:
#line 419 "parser.y"
    {
				const char *temp = new_temp();

				const char *line[] = {temp, "=", (yyvsp[-2].Value), (yyvsp[-1].Value), (yyvsp[0].Value)};
				gen(5, line);

				(yyval.Value) = strdup(temp);
			}
#line 1942 "y.tab.c"
    break;

  case 94:
#line 428 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1950 "y.tab.c"
    break;

  case 95:
#line 434 "parser.y"
    {
				const char *temp = new_temp();

				const char *line[] = {temp, "=", (yyvsp[-2].Value), (yyvsp[-1].Value), (yyvsp[0].Value)};
				gen(5, line);

				(yyval.Value) = strdup(temp);
			}
#line 1963 "y.tab.c"
    break;

  case 96:
#line 443 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1971 "y.tab.c"
    break;

  case 97:
#line 449 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1979 "y.tab.c"
    break;

  case 98:
#line 453 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1987 "y.tab.c"
    break;

  case 107:
#line 478 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 1995 "y.tab.c"
    break;

  case 108:
#line 482 "parser.y"
    {
				char id[20] = ""; // NOTE: Hard limit
				const char* t0 = strdup(new_temp());
				const char* line[] = {t0, "=", "&", (yyvsp[-1].Value)};
				gen(4, line);
				const char *t1 = strdup(new_temp());
				const char *line1[] = {t1, "=", "sizeof(int)"};
				gen(3, line1);
				const char *t2 = strdup(new_temp());
				const char *line2[] = {t2, "=", t1, "*", (yyvsp[0].S_Extra)};
				gen(5, line2);
				const char* t3 = strdup(new_temp());
				const char *line3[] = {t3, "=", t0, "+", t2};
				gen(5, line3);
				sprintf(id, "*%s", t3);
				

				// strcat(id, $<Value>1);
				// strcat(id, $<Value>2);
				(yyval.Value) = strdup(id);
			}
#line 2021 "y.tab.c"
    break;

  case 109:
#line 507 "parser.y"
    {
				// TODO: Arrays directly implmented for now
				char id[20] = ""; // NOTE: Hard limit
				strcat(id, (yyvsp[-2].Value));
				strcat(id, (yyvsp[-1].Value));
				strcat(id, (yyvsp[0].Value));

				(yyval.S_Extra) = strdup((yyvsp[-1].Value));
				(yyval.Value) = strdup(id);
			}
#line 2036 "y.tab.c"
    break;

  case 110:
#line 518 "parser.y"
    {
				// NOTE: Pointers not supported
			}
#line 2044 "y.tab.c"
    break;

  case 111:
#line 524 "parser.y"
    {
				(yyval.Value) = (yyvsp[-1].Value);
			}
#line 2052 "y.tab.c"
    break;

  case 112:
#line 528 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2060 "y.tab.c"
    break;

  case 113:
#line 532 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2068 "y.tab.c"
    break;

  case 114:
#line 538 "parser.y"
    {
				const char *temp = new_temp();

				const char* line[] = {"out", temp};
				gen(2, line);
				const char* line1[] = {"call", (yyvsp[-3].Value)};
				gen(2, line1);

				(yyval.Value) = strdup(temp);
			}
#line 2083 "y.tab.c"
    break;

  case 115:
#line 551 "parser.y"
    {
				(yyval.Value) = (yyvsp[-2].Value);

				const char *line[] = {"arg", (yyval.Value)};
				gen(2, line);
			}
#line 2094 "y.tab.c"
    break;

  case 116:
#line 558 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);

				const char *line[] = {"arg", (yyval.Value)};
				gen(2, line);
			}
#line 2105 "y.tab.c"
    break;

  case 118:
#line 568 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2113 "y.tab.c"
    break;

  case 119:
#line 572 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2121 "y.tab.c"
    break;

  case 120:
#line 576 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2129 "y.tab.c"
    break;

  case 121:
#line 580 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2137 "y.tab.c"
    break;

  case 122:
#line 589 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2145 "y.tab.c"
    break;

  case 123:
#line 593 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2153 "y.tab.c"
    break;

  case 124:
#line 599 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2161 "y.tab.c"
    break;

  case 125:
#line 603 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2169 "y.tab.c"
    break;

  case 126:
#line 607 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2177 "y.tab.c"
    break;

  case 127:
#line 613 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2185 "y.tab.c"
    break;

  case 128:
#line 617 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2193 "y.tab.c"
    break;

  case 129:
#line 621 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2201 "y.tab.c"
    break;

  case 130:
#line 625 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2209 "y.tab.c"
    break;

  case 131:
#line 629 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2217 "y.tab.c"
    break;

  case 132:
#line 633 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2225 "y.tab.c"
    break;

  case 133:
#line 642 "parser.y"
    {
				(yyval.Value) = (yyvsp[0].Value);
			}
#line 2233 "y.tab.c"
    break;

  case 145:
#line 665 "parser.y"
    {
				(yyval.Value) = (yyvsp[-1].Value);
			}
#line 2241 "y.tab.c"
    break;

  case 149:
#line 680 "parser.y"
    {
				backpatch((yyvsp[-2].BackPatchLine), (yyvsp[0].GotoLine));
			}
#line 2249 "y.tab.c"
    break;

  case 150:
#line 686 "parser.y"
    {
				// False condition
				const char* line[] = {"if", (yyvsp[-1].Value), "= 0", "goto"};			
				gen(4, line);
			
				(yyval.BackPatchLine) = line_ptr-1;
			}
#line 2261 "y.tab.c"
    break;

  case 151:
#line 697 "parser.y"
    {
				backpatch((yyvsp[-1].BackPatchLine), line_ptr);
				(yyval.GotoLine) = (yyvsp[-1].GotoLine);
			}
#line 2270 "y.tab.c"
    break;

  case 152:
#line 702 "parser.y"
    {
				(yyval.GotoLine) = line_ptr;
			}
#line 2278 "y.tab.c"
    break;

  case 153:
#line 707 "parser.y"
    {
				const char *line[] = {"goto"};
				gen(1, line);

				(yyval.BackPatchLine) = line_ptr-1;
				(yyval.GotoLine) = line_ptr;
			}
#line 2290 "y.tab.c"
    break;

  case 162:
#line 739 "parser.y"
    {
				backpatch((yyvsp[-1].BackPatchLine), (yyvsp[-3].GotoLine));
				backpatch((yyvsp[0].BackPatchLine), (yyvsp[-2].GotoLine));
				backpatch((yyvsp[-2].BackPatchLine), (yyvsp[-1].GotoLine));
				backpatch((yyvsp[-2].Extra), (yyvsp[0].GotoLine));
			}
#line 2301 "y.tab.c"
    break;

  case 163:
#line 748 "parser.y"
    {
				(yyval.GotoLine) = line_ptr;
			}
#line 2309 "y.tab.c"
    break;

  case 164:
#line 754 "parser.y"
    {
				const char* line[] = {"if", (yyvsp[0].Value), "!= 0", "goto"};			
				gen(4, line);

				const char* line1[] = {"goto"};
				gen(1, line1);

				(yyval.BackPatchLine) = line_ptr-2;
				(yyval.Extra) = line_ptr-1;
				(yyval.GotoLine) = line_ptr;
			}
#line 2325 "y.tab.c"
    break;

  case 165:
#line 768 "parser.y"
    {
				const char* line[] = {"goto"};
				gen(1, line);
				
				(yyval.BackPatchLine) = line_ptr-1;
				(yyval.GotoLine) = line_ptr;
			}
#line 2337 "y.tab.c"
    break;

  case 166:
#line 778 "parser.y"
    {
				const char* line[] = {"goto"};
				gen(1, line);
				
				(yyval.BackPatchLine) = line_ptr-1;
				(yyval.GotoLine) = line_ptr;
			}
#line 2349 "y.tab.c"
    break;

  case 167:
#line 789 "parser.y"
    {
				backpatch((yyvsp[-1].BackPatchLine), (yyvsp[0].GotoLine));
				backpatch((yyvsp[0].BackPatchLine), (yyvsp[-1].GotoLine));
			}
#line 2358 "y.tab.c"
    break;

  case 168:
#line 796 "parser.y"
    {
				// False condition
				const char* line[] = {"if", (yyvsp[-3].Value), "= 0", "goto"};			
				gen(4, line);

				(yyval.BackPatchLine) = line_ptr-1;
				(yyval.GotoLine) = (yyvsp[-2].GotoLine);
			}
#line 2371 "y.tab.c"
    break;

  case 169:
#line 807 "parser.y"
    {
				(yyval.GotoLine) = line_ptr;
			}
#line 2379 "y.tab.c"
    break;

  case 170:
#line 813 "parser.y"
    {
				const char* line[] = {"goto"};
				gen(1, line);

				(yyval.BackPatchLine) = line_ptr-1;
				(yyval.GotoLine) = line_ptr;
			}
#line 2391 "y.tab.c"
    break;

  case 171:
#line 824 "parser.y"
    {
				const char *line[] = {"if", (yyvsp[-2].Value), "= 0", "goto"};
				gen(4, line);

				backpatch(line_ptr-1, (yyvsp[-6].GotoLine));
			}
#line 2402 "y.tab.c"
    break;

  case 172:
#line 833 "parser.y"
    {
				(yyval.GotoLine) = line_ptr;	
			}
#line 2410 "y.tab.c"
    break;

  case 173:
#line 840 "parser.y"
    {
				const char *line[] = {"ret"};
				gen(1, line);
			}
#line 2419 "y.tab.c"
    break;

  case 174:
#line 845 "parser.y"
    {
				const char *line[] = {"ret", (yyvsp[-1].Value)};
				gen(2, line);	
			}
#line 2428 "y.tab.c"
    break;


#line 2432 "y.tab.c"

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
#line 851 "parser.y"


int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");

	yyparse();

	// Print ICG output
	for(int i = 0; i <= line_ptr; i++)
	{
		printf("%02d: %s;\n", i, code[i]);
	}

	return 0;
}

int yywrap()
{
	return 1;
}

void yyerror(char *error)
{
	printf("%d %s %s\n", yylineno, error, yytext);
	printf("Parsing Failed: Result- Invalid\n");
}

// Implement ICG helper functions

char *new_temp()
{
	snprintf(temp_var, 10, "t%d", temp_counter);
	temp_counter++;
	return temp_var;
}

void gen(int n, const char *line[]) 
{
	char code_line[20] = "";
	for(int i = 0; i < n; i++)
	{
		strcat(code_line, line[i]);
		if(i != n-1)
		{
			strcat(code_line, " ");
		}
	}

	strcpy(code[line_ptr], code_line);
	line_ptr++;
}

void backpatch(int backpatch_line, int goto_line)
{
	char str_line[10];
	snprintf(str_line, 10, " %02d", goto_line);

	strcat(code[backpatch_line], str_line);
}
