/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         raptor_parsedate_parse
#define yylex           raptor_parsedate_lex
#define yyerror         raptor_parsedate_error
#define yydebug         raptor_parsedate_debug
#define yynerrs         raptor_parsedate_nerrs


/* Copy the first part of user declarations.  */
#line 1 "./parsedate.y" /* yacc.c:339  */

/*
 * Imported from the public domain source in PHP 4.4
 *   Fri May 20 07:14:01 2005
 *   https://github.com/php/php-src/blob/379c4af44aa6456fbdbc69dba3ead166ba7ff67d/ext/standard/parsedate.y
 *
 * and patched from there
 *
 * Later versions removed this from PHP and replaced it with entirely
 * new code written under the PHP license. That code is not used here
 * and cannot be used.
 *
 */


/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990.
**
**  This code is in the public domain and has no copyright.
*/


#ifdef HAVE_CONFIG_H
#include <raptor_config.h>
#endif

#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <ctype.h>

#ifdef HAVE_SYS_TIME_H
# include <sys/time.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#if defined(_HPUX_SOURCE)
#include <alloca.h>
#endif

#include "raptor2.h"
#include "raptor_internal.h"

#if defined (STDC_HEADERS) || (!defined (isascii) && !defined (HAVE_ISASCII))
# define IN_CTYPE_DOMAIN(c) 1
#else
# define IN_CTYPE_DOMAIN(c) isascii(c)
#endif

#define ISSPACE(c) (IN_CTYPE_DOMAIN (c) && isspace (c))
#define ISALPHA(c) (IN_CTYPE_DOMAIN (c) && isalpha (c))
#define ISUPPER(c) (IN_CTYPE_DOMAIN (c) && isupper (c))
#define ISDIGIT_LOCALE(c) (IN_CTYPE_DOMAIN (c) && isdigit (c))

/* ISDIGIT differs from ISDIGIT_LOCALE, as follows:
   - Its arg may be any int or unsigned int; it need not be an unsigned char.
   - It's guaranteed to evaluate its argument exactly once.
   - It's typically faster.
   Posix 1003.2-1992 section 2.5.2.1 page 50 lines 1556-1558 says that
   only '0' through '9' are digits.  Prefer ISDIGIT to ISDIGIT_LOCALE unless
   it's important to use the locale's definition of `digit' even when the
   host does not conform to Posix.  */
#define ISDIGIT(c) ((unsigned) (c) - '0' <= 9)

#ifdef HAVE_STRING_H
# include <string.h>
#endif

#if !defined(__GNUC__) || __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 7)
# define __attribute__(x)
#endif

#ifndef ATTRIBUTE_UNUSED
# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif

/* Some old versions of bison generate parsers that use bcopy.
   That loses on systems that don't provide the function, so we have
   to redefine it here.  */
#if !defined (HAVE_BCOPY) && defined (HAVE_MEMCPY) && !defined (bcopy)
# define bcopy(from, to, len) memcpy ((to), (from), (len))
#endif

/* Prototypes */ 
static int raptor_parsedate_error(void* parm, const char *msg);


#define EPOCH		1970
#define HOUR(x)		((x) * 60)

#define MAX_BUFF_LEN    128   /* size of buffer to read the date into */

/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    const char	*name;
    int		type;
    int		value;
} TABLE;


/*
**  Meridian:  am, pm, or 24-hour style.
*/
typedef enum _MERIDIAN {
    MERam, MERpm, MER24
} MERIDIAN;

struct date_yy {
	const char	*yyInput;
	int	yyDayOrdinal;
	int	yyDayNumber;
	int	yyHaveDate;
	int	yyHaveDay;
	int	yyHaveRel;
	int	yyHaveTime;
	int	yyHaveZone;
	int	yyTimezone;
	int	yyDay;
	int	yyHour;
	int	yyMinutes;
	int	yyMonth;
	int	yySeconds;
	int	yyYear;
	MERIDIAN	yyMeridian;
	int	yyRelDay;
	int	yyRelHour;
	int	yyRelMinutes;
	int	yyRelMonth;
	int	yyRelSeconds;
	int	yyRelYear;
};

typedef union _date_ll {
    int			Number;
    enum _MERIDIAN	Meridian;
} date_ll;

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm
#define YYSTYPE date_ll
#define YYLTYPE void

static int yylex (YYSTYPE *lvalp, void *parm);

static int ToHour (int Hours, MERIDIAN Meridian);
static int ToYear (int Year);
static int LookupWord (YYSTYPE *lvalp, char *buff);


#line 230 "parsedate.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "parsedate.tab.h".  */
#ifndef YY_RAPTOR_PARSEDATE_PARSEDATE_TAB_H_INCLUDED
# define YY_RAPTOR_PARSEDATE_PARSEDATE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int raptor_parsedate_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tAGO = 258,
    tDAY = 259,
    tDAY_UNIT = 260,
    tDAYZONE = 261,
    tDST = 262,
    tHOUR_UNIT = 263,
    tID = 264,
    tTZONE = 265,
    tWZONE = 266,
    tZZONE = 267,
    tMERIDIAN = 268,
    tMINUTE_UNIT = 269,
    tMONTH = 270,
    tMONTH_UNIT = 271,
    tSEC_UNIT = 272,
    tSNUMBER = 273,
    tUNUMBER = 274,
    tYEAR_UNIT = 275,
    tZONE = 276
  };
#endif

/* Value type.  */



int raptor_parsedate_parse (struct date_yy *parm);

#endif /* !YY_RAPTOR_PARSEDATE_PARSEDATE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 297 "parsedate.c" /* yacc.c:358  */

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
# elif ! defined YYSIZE_T
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    24,     2,    22,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   193,   193,   194,   197,   200,   203,   206,   209,   212,
     213,   216,   222,   226,   229,   233,   236,   242,   245,   248,
     251,   254,   256,   259,   269,   275,   281,   297,   300,   303,
     306,   309,   312,   317,   321,   325,   331,   335,   346,   364,
     365,   368,   374,   379,   387,   392,   400,   407,   408,   427,
     433,   439,   451,   454,   460,   461,   486,   500,   503,   506,
     509,   512,   515,   518,   521,   524,   527,   530,   533,   536,
     539,   542,   545,   548,   551,   554,   559,   594
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tAGO", "tDAY", "tDAY_UNIT", "tDAYZONE",
  "tDST", "tHOUR_UNIT", "tID", "tTZONE", "tWZONE", "tZZONE", "tMERIDIAN",
  "tMINUTE_UNIT", "tMONTH", "tMONTH_UNIT", "tSEC_UNIT", "tSNUMBER",
  "tUNUMBER", "tYEAR_UNIT", "tZONE", "'.'", "':'", "','", "'/'", "$accept",
  "spec", "item", "time", "iso8601time_colon", "iso8601zonepart",
  "sec_fraction_part", "zonepart_numeric_without_colon",
  "zonepart_numeric_with_colon", "HMStime_with_colon", "HMtime_with_colon",
  "zone", "day", "date", "iso8601datetime", "iso8601date",
  "iso8601weekspec", "iso8601time", "rel", "relunit", "number", "o_merid", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    46,    58,    44,    47
};
# endif

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -60,     2,   -60,   -13,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,    13,   -60,   -60,    69,    20,   -60,    32,   -60,
     -60,   -60,    29,     4,   -60,   -60,   -60,   -60,    44,   -60,
      58,   -60,   -60,   -60,   -15,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,    46,    48,   -60,   -60,    28,   -60,
     -60,    37,   -60,    56,    57,   -60,   -60,    59,    52,    61,
      52,    46,   -60,    64,    62,    26,   -60,   -60,    66,   -60,
     -60,   -60,   -60,    68,   -60,    36,    74,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,    76,   -60,    86,   -60,
      80,    81,    78,    79,   -60,   -60,   -60,    84,    87,   -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    33,    66,    31,    69,    27,    28,    29,
      77,    72,     0,    63,    75,     0,    76,    60,    30,     3,
       4,    12,    22,    22,     5,     7,     6,    40,    39,     8,
      57,     9,    10,    34,    43,    65,    68,    71,    62,    74,
      59,    35,    64,    67,     0,     0,    11,    70,    45,    61,
      73,    50,    58,     0,     0,    51,    32,     0,    20,     0,
      20,     0,    56,    42,     0,    22,    54,    48,    52,    41,
      46,    49,    26,    36,    21,    23,     0,    15,    17,    18,
      19,    13,    25,    16,    14,    47,     0,    44,    20,    53,
       0,     0,     0,    23,    55,    38,    24,     0,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -60,   104,   -59,   -23,   -60,   -60,   -60,
     -60,   107,   -60,   -60,   -60,   -60,   -60,    49,   -55,   -60,
     -60,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    19,    20,    66,    77,    58,    78,    79,    22,
      23,    80,    25,    26,    27,    28,    55,    67,    29,    30,
      31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      60,    83,     2,    81,    63,    84,     3,     4,     5,    64,
       6,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    41,    42,    57,    59,    43,    94,
      44,    45,    34,    46,    47,    48,    49,    50,    51,    56,
      52,    35,    88,    53,    36,    54,    69,    70,    57,    53,
      37,    57,    38,    39,    61,    71,    40,     4,     5,    91,
       6,    62,     7,     8,     9,    65,    11,    68,    13,    14,
      75,    76,    17,    18,    35,    72,    73,    36,    74,    42,
      82,    87,    43,    37,    89,    38,    39,    86,    47,    40,
      49,    50,     5,    90,    52,    92,     7,     8,     9,    95,
      96,    97,    91,    98,    93,    21,    99,    18,    24,     0,
      85
};

static const yytype_int8 yycheck[] =
{
      23,    60,     0,    58,    19,    60,     4,     5,     6,    24,
       8,    24,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     4,     5,    22,    23,     8,    88,
      10,    11,    19,    13,    14,    15,    16,    17,    18,     7,
      20,     5,    65,    23,     8,    25,    18,    19,    22,    23,
      14,    22,    16,    17,    10,    18,    20,     5,     6,    23,
       8,     3,    10,    11,    12,    19,    14,    19,    16,    17,
      18,    19,    20,    21,     5,    19,    19,     8,    19,     5,
      19,    19,     8,    14,    18,    16,    17,    23,    14,    20,
      16,    17,     6,    25,    20,    19,    10,    11,    12,    19,
      19,    23,    23,    19,    18,     1,    19,    21,     1,    -1,
      61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,     0,     4,     5,     6,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    28,
      29,    30,    35,    36,    37,    38,    39,    40,    41,    44,
      45,    46,    47,    24,    19,     5,     8,    14,    16,    17,
      20,     4,     5,     8,    10,    11,    13,    14,    15,    16,
      17,    18,    20,    23,    25,    42,     7,    22,    32,    23,
      32,    10,     3,    19,    24,    19,    30,    43,    19,    18,
      19,    18,    19,    19,    19,    18,    19,    31,    33,    34,
      37,    44,    19,    31,    44,    43,    23,    19,    32,    18,
      25,    23,    19,    18,    31,    19,    19,    23,    19,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    27,    27,    28,    28,    28,    28,    28,    28,
      28,    29,    29,    30,    30,    30,    30,    31,    31,    31,
      31,    32,    32,    33,    34,    35,    36,    37,    37,    37,
      37,    37,    37,    38,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    40,    40,    41,
      41,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    46,    47
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     3,     3,     3,     1,     1,     1,
       0,     2,     0,     1,     3,     3,     3,     1,     1,     1,
       1,     1,     2,     1,     2,     2,     3,     8,     5,     1,
       1,     3,     3,     2,     4,     2,     3,     3,     3,     3,
       2,     2,     2,     3,     1,     3,     2,     1,     2,     2,
       1,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      yyerror (parm, YY_("syntax error: cannot back up")); \
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
                  Type, Value, parm); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct date_yy *parm)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (parm);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct date_yy *parm)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parm);
  YYFPRINTF (yyoutput, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, struct date_yy *parm)
{
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , parm);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parm); \
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
      default: yyformat = YY_("syntax error");
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct date_yy *parm)
{
  YYUSE (yyvaluep);
  YYUSE (parm);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct date_yy *parm)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval, parm);
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
        case 4:
#line 197 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyHaveTime++;
	}
#line 1452 "parsedate.c" /* yacc.c:1646  */
    break;

  case 5:
#line 200 "./parsedate.y" /* yacc.c:1646  */
    {
	        ((struct date_yy *)parm)->yyHaveZone++;
	}
#line 1460 "parsedate.c" /* yacc.c:1646  */
    break;

  case 6:
#line 203 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyHaveDate++;
	}
#line 1468 "parsedate.c" /* yacc.c:1646  */
    break;

  case 7:
#line 206 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyHaveDay++;
	}
#line 1476 "parsedate.c" /* yacc.c:1646  */
    break;

  case 8:
#line 209 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyHaveRel++;
	}
#line 1484 "parsedate.c" /* yacc.c:1646  */
    break;

  case 11:
#line 216 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyHour = (yyvsp[-1].Number);
	    ((struct date_yy *)parm)->yyMinutes = 0;
	    ((struct date_yy *)parm)->yySeconds = 0;
	    ((struct date_yy *)parm)->yyMeridian = (yyvsp[0].Meridian);
	}
#line 1495 "parsedate.c" /* yacc.c:1646  */
    break;

  case 13:
#line 226 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMeridian = MER24;
	}
#line 1503 "parsedate.c" /* yacc.c:1646  */
    break;

  case 14:
#line 229 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMeridian = MER24;
	    ((struct date_yy *)parm)->yySeconds = 0;
	}
#line 1512 "parsedate.c" /* yacc.c:1646  */
    break;

  case 15:
#line 233 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMeridian = MER24;
	}
#line 1520 "parsedate.c" /* yacc.c:1646  */
    break;

  case 16:
#line 236 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMeridian = MER24;
	    ((struct date_yy *)parm)->yySeconds = 0;
	}
#line 1529 "parsedate.c" /* yacc.c:1646  */
    break;

  case 17:
#line 242 "./parsedate.y" /* yacc.c:1646  */
    {
		((struct date_yy *)parm)->yyHaveZone++;
	}
#line 1537 "parsedate.c" /* yacc.c:1646  */
    break;

  case 18:
#line 245 "./parsedate.y" /* yacc.c:1646  */
    {
		((struct date_yy *)parm)->yyHaveZone++;
	}
#line 1545 "parsedate.c" /* yacc.c:1646  */
    break;

  case 19:
#line 248 "./parsedate.y" /* yacc.c:1646  */
    {
		((struct date_yy *)parm)->yyHaveZone++;
	}
#line 1553 "parsedate.c" /* yacc.c:1646  */
    break;

  case 21:
#line 254 "./parsedate.y" /* yacc.c:1646  */
    {
	}
#line 1560 "parsedate.c" /* yacc.c:1646  */
    break;

  case 23:
#line 259 "./parsedate.y" /* yacc.c:1646  */
    {
		/* format: [+-]hhmm */
		if((yyvsp[0].Number) <= -100 || (yyvsp[0].Number) >= 100) {
			((struct date_yy *)parm)->yyTimezone = (-(yyvsp[0].Number) / 100) * 60 + (-(yyvsp[0].Number) % 100);
		} else if((yyvsp[0].Number) >= -99 && (yyvsp[0].Number) <= 99) {
			((struct date_yy *)parm)->yyTimezone = -(yyvsp[0].Number) * 60;
		}
	}
#line 1573 "parsedate.c" /* yacc.c:1646  */
    break;

  case 24:
#line 269 "./parsedate.y" /* yacc.c:1646  */
    {
		/* format: [+-]hh:mm */
		((struct date_yy *)parm)->yyTimezone = -(yyvsp[-2].Number) * 60 + ((yyvsp[-2].Number) > 0 ? -(yyvsp[0].Number): (yyvsp[0].Number));
	}
#line 1582 "parsedate.c" /* yacc.c:1646  */
    break;

  case 25:
#line 275 "./parsedate.y" /* yacc.c:1646  */
    {
		/* format: hh:mm:ss */
	    ((struct date_yy *)parm)->yySeconds = (yyvsp[0].Number);
	}
#line 1591 "parsedate.c" /* yacc.c:1646  */
    break;

  case 26:
#line 281 "./parsedate.y" /* yacc.c:1646  */
    {
		/* format: hh:mm */
	    ((struct date_yy *)parm)->yyHour = (yyvsp[-2].Number);
	    ((struct date_yy *)parm)->yyMinutes = (yyvsp[0].Number);
	}
#line 1601 "parsedate.c" /* yacc.c:1646  */
    break;

  case 27:
#line 297 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyTimezone = (yyvsp[0].Number);
	}
#line 1609 "parsedate.c" /* yacc.c:1646  */
    break;

  case 28:
#line 300 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyTimezone = (yyvsp[0].Number);
	}
#line 1617 "parsedate.c" /* yacc.c:1646  */
    break;

  case 29:
#line 303 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyTimezone = (yyvsp[0].Number);
	}
#line 1625 "parsedate.c" /* yacc.c:1646  */
    break;

  case 30:
#line 306 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyTimezone = (yyvsp[0].Number);
	}
#line 1633 "parsedate.c" /* yacc.c:1646  */
    break;

  case 31:
#line 309 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyTimezone = (yyvsp[0].Number) - 60;
	}
#line 1641 "parsedate.c" /* yacc.c:1646  */
    break;

  case 32:
#line 312 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyTimezone = (yyvsp[-1].Number) - 60;
	}
#line 1649 "parsedate.c" /* yacc.c:1646  */
    break;

  case 33:
#line 317 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyDayOrdinal = 1;
	    ((struct date_yy *)parm)->yyDayNumber = (yyvsp[0].Number);
	}
#line 1658 "parsedate.c" /* yacc.c:1646  */
    break;

  case 34:
#line 321 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyDayOrdinal = 1;
	    ((struct date_yy *)parm)->yyDayNumber = (yyvsp[-1].Number);
	}
#line 1667 "parsedate.c" /* yacc.c:1646  */
    break;

  case 35:
#line 325 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyDayOrdinal = (yyvsp[-1].Number);
	    ((struct date_yy *)parm)->yyDayNumber = (yyvsp[0].Number);
	}
#line 1676 "parsedate.c" /* yacc.c:1646  */
    break;

  case 36:
#line 331 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMonth = (yyvsp[-2].Number);
	    ((struct date_yy *)parm)->yyDay = (yyvsp[0].Number);
	}
#line 1685 "parsedate.c" /* yacc.c:1646  */
    break;

  case 37:
#line 335 "./parsedate.y" /* yacc.c:1646  */
    {
		((struct date_yy *)parm)->yyYear = (yyvsp[0].Number);
		((struct date_yy *)parm)->yyMonth = (yyvsp[-7].Number);
		((struct date_yy *)parm)->yyDay = (yyvsp[-6].Number);

		((struct date_yy *)parm)->yyHour = (yyvsp[-5].Number);
		((struct date_yy *)parm)->yyMinutes = (yyvsp[-3].Number);
		((struct date_yy *)parm)->yySeconds = (yyvsp[-1].Number);

		((struct date_yy *)parm)->yyHaveTime = 1;
	}
#line 1701 "parsedate.c" /* yacc.c:1646  */
    break;

  case 38:
#line 346 "./parsedate.y" /* yacc.c:1646  */
    {
	  /* Interpret as YYYY/MM/DD if $1 >= 1000, otherwise as MM/DD/YY.
	     The goal in recognizing YYYY/MM/DD is solely to support legacy
	     machine-generated dates like those in an RCS log listing.  If
	     you want portability, use the ISO 8601 format.  */
	  if((yyvsp[-4].Number) >= 1000)
	    {
	      ((struct date_yy *)parm)->yyYear = (yyvsp[-4].Number);
	      ((struct date_yy *)parm)->yyMonth = (yyvsp[-2].Number);
	      ((struct date_yy *)parm)->yyDay = (yyvsp[0].Number);
	    }
	  else
	    {
	      ((struct date_yy *)parm)->yyMonth = (yyvsp[-4].Number);
	      ((struct date_yy *)parm)->yyDay = (yyvsp[-2].Number);
	      ((struct date_yy *)parm)->yyYear = (yyvsp[0].Number);
	    }
	}
#line 1724 "parsedate.c" /* yacc.c:1646  */
    break;

  case 40:
#line 365 "./parsedate.y" /* yacc.c:1646  */
    {
			((struct date_yy *)parm)->yyHaveTime++;
    }
#line 1732 "parsedate.c" /* yacc.c:1646  */
    break;

  case 41:
#line 368 "./parsedate.y" /* yacc.c:1646  */
    {
	    /* e.g. 17-JUN-1992.  */
	    ((struct date_yy *)parm)->yyDay = (yyvsp[-2].Number);
	    ((struct date_yy *)parm)->yyMonth = (yyvsp[-1].Number);
	    ((struct date_yy *)parm)->yyYear = -(yyvsp[0].Number);
	}
#line 1743 "parsedate.c" /* yacc.c:1646  */
    break;

  case 42:
#line 374 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMonth = (yyvsp[-2].Number);
	    ((struct date_yy *)parm)->yyDay = (yyvsp[-1].Number);
		((struct date_yy *)parm)->yyYear = (yyvsp[0].Number);
	}
#line 1753 "parsedate.c" /* yacc.c:1646  */
    break;

  case 43:
#line 379 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMonth = (yyvsp[-1].Number);
	    if((yyvsp[0].Number) > 1000) {
		((struct date_yy *)parm)->yyYear = (yyvsp[0].Number);
	    } else {
		((struct date_yy *)parm)->yyDay = (yyvsp[0].Number);
	    }
	}
#line 1766 "parsedate.c" /* yacc.c:1646  */
    break;

  case 44:
#line 387 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMonth = (yyvsp[-3].Number);
	    ((struct date_yy *)parm)->yyDay = (yyvsp[-2].Number);
	    ((struct date_yy *)parm)->yyYear = (yyvsp[0].Number);
	}
#line 1776 "parsedate.c" /* yacc.c:1646  */
    break;

  case 45:
#line 392 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMonth = (yyvsp[0].Number);
	    if((yyvsp[-1].Number) > 1000) {
		((struct date_yy *)parm)->yyYear = (yyvsp[-1].Number);
	    } else {
		((struct date_yy *)parm)->yyDay = (yyvsp[-1].Number);
	    }
	}
#line 1789 "parsedate.c" /* yacc.c:1646  */
    break;

  case 46:
#line 400 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyMonth = (yyvsp[-1].Number);
	    ((struct date_yy *)parm)->yyDay = (yyvsp[-2].Number);
	    ((struct date_yy *)parm)->yyYear = (yyvsp[0].Number);
	}
#line 1799 "parsedate.c" /* yacc.c:1646  */
    break;

  case 48:
#line 408 "./parsedate.y" /* yacc.c:1646  */
    {
		int i = (yyvsp[-2].Number);

		if(i >= 10000) {
			/* format: yyyymmdd */
			((struct date_yy *)parm)->yyYear = i / 10000;
			i %= 10000;
			((struct date_yy *)parm)->yyMonth = i / 100;
			i %= 100;
			((struct date_yy *)parm)->yyDay = i;
		} else if(i >= 1000 && i <= 9999) {
			/* format: yyyy */
			((struct date_yy *)parm)->yyYear = i;
			((struct date_yy *)parm)->yyDay= 1;
			((struct date_yy *)parm)->yyMonth = 1;
		}
	}
#line 1821 "parsedate.c" /* yacc.c:1646  */
    break;

  case 49:
#line 427 "./parsedate.y" /* yacc.c:1646  */
    {
	    /* ISO 8601 format.  yyyy-mm-dd.  */
	    ((struct date_yy *)parm)->yyYear = (yyvsp[-2].Number);
	    ((struct date_yy *)parm)->yyMonth = -(yyvsp[-1].Number);
	    ((struct date_yy *)parm)->yyDay = -(yyvsp[0].Number);
	}
#line 1832 "parsedate.c" /* yacc.c:1646  */
    break;

  case 50:
#line 433 "./parsedate.y" /* yacc.c:1646  */
    {
		/* ISO 8601 format   yyyy-mm */
	    ((struct date_yy *)parm)->yyYear = (yyvsp[-1].Number);
	    ((struct date_yy *)parm)->yyMonth = -(yyvsp[0].Number);
	    ((struct date_yy *)parm)->yyDay = 1;
	}
#line 1843 "parsedate.c" /* yacc.c:1646  */
    break;

  case 51:
#line 439 "./parsedate.y" /* yacc.c:1646  */
    {
		const int om = (1 + 9) % 12; /* offset month */
		const int oy = (yyvsp[-1].Number) - 1; /* offset year */

		((struct date_yy *)parm)->yyYear = (yyvsp[-1].Number);
		((struct date_yy *)parm)->yyMonth = 1;
		/* Zeller's formula */
		((struct date_yy *)parm)->yyDay -= ((13 * om + 12) / 5 +
					oy + oy / 4 + oy / 400 - oy / 100) % 7 - 1;
	}
#line 1858 "parsedate.c" /* yacc.c:1646  */
    break;

  case 52:
#line 451 "./parsedate.y" /* yacc.c:1646  */
    {
		((struct date_yy *)parm)->yyDay = ((yyvsp[0].Number) / 10) * 7 + ((yyvsp[0].Number) % 10) - 8;
	}
#line 1866 "parsedate.c" /* yacc.c:1646  */
    break;

  case 53:
#line 454 "./parsedate.y" /* yacc.c:1646  */
    {
		((struct date_yy *)parm)->yyDay = (yyvsp[-1].Number) * 7 - (yyvsp[0].Number) - 8;
	}
#line 1874 "parsedate.c" /* yacc.c:1646  */
    break;

  case 55:
#line 461 "./parsedate.y" /* yacc.c:1646  */
    {
		int i = (yyvsp[-2].Number);

		if(i <= -100000 || i >= 100000) {
			((struct date_yy *)parm)->yyHour = i / 10000;
			i %= 10000;
			((struct date_yy *)parm)->yyMinutes = i / 100;
			i %= 100;
	    	((struct date_yy *)parm)->yySeconds = i;
		} else if(i <= -1000 || i >= 1000) {
			((struct date_yy *)parm)->yyHour = i / 100;
			i %= 100;
			((struct date_yy *)parm)->yyMinutes = i;
	    	((struct date_yy *)parm)->yySeconds = 0;
		} else if(i >= -99 && i <= 99) {
			((struct date_yy *)parm)->yyHour = i;
			((struct date_yy *)parm)->yyMinutes = 0;
	    	((struct date_yy *)parm)->yySeconds = 0;
		} else {
			((struct date_yy *)parm)->yyHaveTime = 0;
		}
	    ((struct date_yy *)parm)->yyMeridian = MER24;
	}
#line 1902 "parsedate.c" /* yacc.c:1646  */
    break;

  case 56:
#line 486 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelSeconds =
			-((struct date_yy *)parm)->yyRelSeconds;
	    ((struct date_yy *)parm)->yyRelMinutes =
			-((struct date_yy *)parm)->yyRelMinutes;
	    ((struct date_yy *)parm)->yyRelHour =
			-((struct date_yy *)parm)->yyRelHour;
	    ((struct date_yy *)parm)->yyRelDay =
			-((struct date_yy *)parm)->yyRelDay;
	    ((struct date_yy *)parm)->yyRelMonth =
			-((struct date_yy *)parm)->yyRelMonth;
	    ((struct date_yy *)parm)->yyRelYear =
			-((struct date_yy *)parm)->yyRelYear;
	}
#line 1921 "parsedate.c" /* yacc.c:1646  */
    break;

  case 58:
#line 503 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelYear += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1929 "parsedate.c" /* yacc.c:1646  */
    break;

  case 59:
#line 506 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelYear += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1937 "parsedate.c" /* yacc.c:1646  */
    break;

  case 60:
#line 509 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelYear += (yyvsp[0].Number);
	}
#line 1945 "parsedate.c" /* yacc.c:1646  */
    break;

  case 61:
#line 512 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelMonth += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1953 "parsedate.c" /* yacc.c:1646  */
    break;

  case 62:
#line 515 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelMonth += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1961 "parsedate.c" /* yacc.c:1646  */
    break;

  case 63:
#line 518 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelMonth += (yyvsp[0].Number);
	}
#line 1969 "parsedate.c" /* yacc.c:1646  */
    break;

  case 64:
#line 521 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelDay += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1977 "parsedate.c" /* yacc.c:1646  */
    break;

  case 65:
#line 524 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelDay += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1985 "parsedate.c" /* yacc.c:1646  */
    break;

  case 66:
#line 527 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelDay += (yyvsp[0].Number);
	}
#line 1993 "parsedate.c" /* yacc.c:1646  */
    break;

  case 67:
#line 530 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelHour += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 2001 "parsedate.c" /* yacc.c:1646  */
    break;

  case 68:
#line 533 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelHour += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 2009 "parsedate.c" /* yacc.c:1646  */
    break;

  case 69:
#line 536 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelHour += (yyvsp[0].Number);
	}
#line 2017 "parsedate.c" /* yacc.c:1646  */
    break;

  case 70:
#line 539 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelMinutes += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 2025 "parsedate.c" /* yacc.c:1646  */
    break;

  case 71:
#line 542 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelMinutes += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 2033 "parsedate.c" /* yacc.c:1646  */
    break;

  case 72:
#line 545 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelMinutes += (yyvsp[0].Number);
	}
#line 2041 "parsedate.c" /* yacc.c:1646  */
    break;

  case 73:
#line 548 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelSeconds += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 2049 "parsedate.c" /* yacc.c:1646  */
    break;

  case 74:
#line 551 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelSeconds += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 2057 "parsedate.c" /* yacc.c:1646  */
    break;

  case 75:
#line 554 "./parsedate.y" /* yacc.c:1646  */
    {
	    ((struct date_yy *)parm)->yyRelSeconds += (yyvsp[0].Number);
	}
#line 2065 "parsedate.c" /* yacc.c:1646  */
    break;

  case 76:
#line 560 "./parsedate.y" /* yacc.c:1646  */
    {
	    if(((struct date_yy *)parm)->yyHaveTime && 
			((struct date_yy *)parm)->yyHaveDate && 
			!((struct date_yy *)parm)->yyHaveRel)
	      ((struct date_yy *)parm)->yyYear = (yyvsp[0].Number);
	    else
	      {
		if((yyvsp[0].Number) > 10000)
		  {
		    ((struct date_yy *)parm)->yyHaveDate++;
		    ((struct date_yy *)parm)->yyDay= ((yyvsp[0].Number))%100;
		    ((struct date_yy *)parm)->yyMonth= ((yyvsp[0].Number)/100)%100;
		    ((struct date_yy *)parm)->yyYear = (yyvsp[0].Number)/10000;
		  }
		else
		  {
		    ((struct date_yy *)parm)->yyHaveTime++;
		    if((yyvsp[0].Number) < 100)
		      {
			((struct date_yy *)parm)->yyHour = (yyvsp[0].Number);
			((struct date_yy *)parm)->yyMinutes = 0;
		      }
		    else
		      {
		    	((struct date_yy *)parm)->yyHour = (yyvsp[0].Number) / 100;
		    	((struct date_yy *)parm)->yyMinutes = (yyvsp[0].Number) % 100;
		      }
		    ((struct date_yy *)parm)->yySeconds = 0;
		    ((struct date_yy *)parm)->yyMeridian = MER24;
		  }
	      }
	  }
#line 2102 "parsedate.c" /* yacc.c:1646  */
    break;

  case 77:
#line 595 "./parsedate.y" /* yacc.c:1646  */
    {
			 ((struct date_yy *)parm)->yyMeridian = (yyvsp[0].Meridian);
		  }
#line 2110 "parsedate.c" /* yacc.c:1646  */
    break;


#line 2114 "parsedate.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
      yyerror (parm, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
if(yytoken < 0) yytoken = YYUNDEFTOK;
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
if(yytoken < 0) yytoken = YYUNDEFTOK;
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (parm, yymsgp);
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
                      yytoken, &yylval, parm);
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
                  yystos[yystate], yyvsp, parm);
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
  yyerror (parm, YY_("memory exhausted"));
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
                  yytoken, &yylval, parm);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, parm);
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
#line 600 "./parsedate.y" /* yacc.c:1906  */


time_t get_date (char *p, time_t *now);

/* Month and day table. */
static TABLE const MonthDayTable[] = {
    { "january",	tMONTH,  1 },
    { "february",	tMONTH,  2 },
    { "march",		tMONTH,  3 },
    { "april",		tMONTH,  4 },
    { "may",		tMONTH,  5 },
    { "june",		tMONTH,  6 },
    { "july",		tMONTH,  7 },
    { "august",		tMONTH,  8 },
    { "september",	tMONTH,  9 },
    { "sept",		tMONTH,  9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL, 0, 0 }
};

/* Time units table. */
static TABLE const UnitsTable[] = {
    { "year",		tYEAR_UNIT,	1 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tDAY_UNIT,	14 },
    { "week",		tDAY_UNIT,	7 },
    { "day",		tDAY_UNIT,	1 },
    { "hour",		tHOUR_UNIT,	1 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL, 0, 0 }
};

/* Assorted relative-time words. */
static TABLE const OtherTable[] = {
    { "tomorrow",	tDAY_UNIT,	1 },
    { "yesterday",	tDAY_UNIT,	-1 },
    { "today",		tDAY_UNIT,	0 },
    { "now",		tDAY_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tUNUMBER,	0 },
    { "next",		tUNUMBER,	1 },
    { "first",		tUNUMBER,	1 },
/*  { "second",		tUNUMBER,	2 }, */
    { "third",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
    { "ago",		tAGO,	1 },
    { NULL, 0, 0 }
};

/* The timezone table. */
static TABLE const TimezoneTable[] = {
    { "gmt",	tZONE,     HOUR ( 0) },	/* Greenwich Mean */
    { "ut",	tZONE,     HOUR ( 0) },	/* Universal (Coordinated) */
    { "utc",	tZONE,     HOUR ( 0) },
    { "wet",	tZONE,     HOUR ( 0) },	/* Western European */
    { "bst",	tDAYZONE,  HOUR ( 0) },	/* British Summer */
    { "wat",	tZONE,     HOUR ( 1) },	/* West Africa */
    { "at",	tZONE,     HOUR ( 2) },	/* Azores */
#if	0
    /* For completeness.  BST is also British Summer, and GST is
     * also Guam Standard. */
    { "bst",	tZONE,     HOUR ( 3) },	/* Brazil Standard */
    { "gst",	tZONE,     HOUR ( 3) },	/* Greenland Standard */
#endif
#if 0
    { "nft",	tZONE,     HOUR (3.5) },	/* Newfoundland */
    { "nst",	tZONE,     HOUR (3.5) },	/* Newfoundland Standard */
    { "ndt",	tDAYZONE,  HOUR (3.5) },	/* Newfoundland Daylight */
#endif
    { "ast",	tZONE,     HOUR ( 4) },	/* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR ( 4) },	/* Atlantic Daylight */
    { "est",	tZONE,     HOUR ( 5) },	/* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR ( 5) },	/* Eastern Daylight */
    { "cst",	tZONE,     HOUR ( 6) },	/* Central Standard */
    { "cdt",	tDAYZONE,  HOUR ( 6) },	/* Central Daylight */
    { "mst",	tZONE,     HOUR ( 7) },	/* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR ( 7) },	/* Mountain Daylight */
    { "pst",	tZONE,     HOUR ( 8) },	/* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR ( 8) },	/* Pacific Daylight */
    { "yst",	tZONE,     HOUR ( 9) },	/* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR ( 9) },	/* Yukon Daylight */
    { "hst",	tZONE,     HOUR (10) },	/* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR (10) },	/* Hawaii Daylight */
    { "cat",	tZONE,     HOUR (10) },	/* Central Alaska */
    { "akst",	tZONE,     HOUR (10) }, /* Alaska Standard */
    { "akdt",	tZONE,     HOUR (10) }, /* Alaska Daylight */
    { "ahst",	tZONE,     HOUR (10) },	/* Alaska-Hawaii Standard */
    { "nt",	tZONE,     HOUR (11) },	/* Nome */
    { "idlw",	tZONE,     HOUR (12) },	/* International Date Line West */
    { "cet",	tZONE,     -HOUR (1) },	/* Central European */
    { "cest",	tDAYZONE,  -HOUR (1) },	/* Central European Summer */
    { "met",	tZONE,     -HOUR (1) },	/* Middle European */
    { "mewt",	tZONE,     -HOUR (1) },	/* Middle European Winter */
    { "mest",	tDAYZONE,  -HOUR (1) },	/* Middle European Summer */
    { "mesz",	tDAYZONE,  -HOUR (1) },	/* Middle European Summer */
    { "swt",	tZONE,     -HOUR (1) },	/* Swedish Winter */
    { "sst",	tDAYZONE,  -HOUR (1) },	/* Swedish Summer */
    { "fwt",	tZONE,     -HOUR (1) },	/* French Winter */
    { "fst",	tDAYZONE,  -HOUR (1) },	/* French Summer */
    { "eet",	tZONE,     -HOUR (2) },	/* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,     -HOUR (3) },	/* Baghdad, USSR Zone 2 */
#if 0
    { "it",	tZONE,     -HOUR (3.5) },/* Iran */
#endif
    { "zp4",	tZONE,     -HOUR (4) },	/* USSR Zone 3 */
    { "zp5",	tZONE,     -HOUR (5) },	/* USSR Zone 4 */
#if 0
    { "ist",	tZONE,     -HOUR (5.5) },/* Indian Standard */
#endif
    { "zp6",	tZONE,     -HOUR (6) },	/* USSR Zone 5 */
#if	0
    /* For completeness.  NST is also Newfoundland Standard, and SST is
     * also Swedish Summer. */
    { "nst",	tZONE,     -HOUR (6.5) },/* North Sumatra */
    { "sst",	tZONE,     -HOUR (7) },	/* South Sumatra, USSR Zone 6 */
#endif	/* 0 */
    { "wast",	tZONE,     -HOUR (7) },	/* West Australian Standard */
    { "wadt",	tDAYZONE,  -HOUR (7) },	/* West Australian Daylight */
#if 0
    { "jt",	tZONE,     -HOUR (7.5) },/* Java (3pm in Cronusland!) */
#endif
    { "cct",	tZONE,     -HOUR (8) },	/* China Coast, USSR Zone 7 */
    { "jst",	tZONE,     -HOUR (9) },	/* Japan Standard, USSR Zone 8 */
#if 0
    { "cast",	tZONE,     -HOUR (9.5) },/* Central Australian Standard */
    { "cadt",	tDAYZONE,  -HOUR (9.5) },/* Central Australian Daylight */
#endif
    { "east",	tZONE,     -HOUR (10) },	/* Eastern Australian Standard */
    { "eadt",	tDAYZONE,  -HOUR (10) },	/* Eastern Australian Daylight */
    { "gst",	tZONE,     -HOUR (10) },	/* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,     -HOUR (12) },	/* New Zealand */
    { "nzst",	tZONE,     -HOUR (12) },	/* New Zealand Standard */
    { "nzdt",	tDAYZONE,  -HOUR (12) },	/* New Zealand Daylight */
    { "idle",	tZONE,     -HOUR (12) },	/* International Date Line East */
    {  NULL, 0, 0  }
};

/* Military timezone table. */
static TABLE const MilitaryTable[] = {
    { "a",	tZONE,	HOUR (- 1) },
    { "b",	tZONE,	HOUR (- 2) },
    { "c",	tZONE,	HOUR (- 3) },
    { "d",	tZONE,	HOUR (- 4) },
    { "e",	tZONE,	HOUR (- 5) },
    { "f",	tZONE,	HOUR (- 6) },
    { "g",	tZONE,	HOUR (- 7) },
    { "h",	tZONE,	HOUR (- 8) },
    { "i",	tZONE,	HOUR (- 9) },
    { "k",	tZONE,	HOUR (-10) },
    { "l",	tZONE,	HOUR (-11) },
    { "m",	tZONE,	HOUR (-12) },
    { "n",	tZONE,	HOUR (  1) },
    { "o",	tZONE,	HOUR (  2) },
    { "p",	tZONE,	HOUR (  3) },
    { "q",	tZONE,	HOUR (  4) },
    { "r",	tZONE,	HOUR (  5) },
    { "s",	tZONE,	HOUR (  6) },
    { "t",	tTZONE,	HOUR (  7) },
    { "u",	tZONE,	HOUR (  8) },
    { "v",	tZONE,	HOUR (  9) },
    { "w",	tWZONE,	HOUR ( 10) },
    { "x",	tZONE,	HOUR ( 11) },
    { "y",	tZONE,	HOUR ( 12) },
    { "z",	tZZONE,	HOUR (  0) },
    { NULL, 0, 0 }
};




/* ARGSUSED */
static int
yyerror(void* parm, const char *s)
{
  return 0;
}

static int
ToHour(int Hours, MERIDIAN Meridian)
{
  switch (Meridian)
    {
    case MER24:
      if(Hours < 0 || Hours > 23)
	return -1;
      return Hours;
    case MERam:
      if(Hours < 1 || Hours > 12)
	return -1;
      if(Hours == 12)
	Hours = 0;
      return Hours;
    case MERpm:
      if(Hours < 1 || Hours > 12)
	return -1;
      if(Hours == 12)
	Hours = 0;
      return Hours + 12;
    default:
#ifdef RAPTOR_DEBUG
      fprintf(stderr, "%s:%d:%s: UNKNOWN Meridian %d - add a new case", 
              __FILE__, __LINE__, __FUNCTION__, (int)Meridian);
#endif
      return -1;
    }
  /* NOTREACHED */
}

static int
ToYear(int Year)
{
  if(Year < 0)
    Year = -Year;

  /* XPG4 suggests that years 00-68 map to 2000-2068, and
     years 69-99 map to 1969-1999.  */
  if(Year < 69)
    Year += 2000;
  else if(Year < 100)
    Year += 1900;

  return Year;
}

static int
LookupWord (YYSTYPE *lvalp, char *buff)
{
  char *p;
  char *q;
  const TABLE *tp;
  int i;
  int abbrev;

  /* Make it lowercase. */
  for(p = buff; *p; p++)
    if(ISUPPER ((unsigned char) *p))
      *p = tolower (*p);

  if(strcmp (buff, "am") == 0 || strcmp (buff, "a.m.") == 0)
    {
      lvalp->Meridian = MERam;
      return tMERIDIAN;
    }
  if(strcmp (buff, "pm") == 0 || strcmp (buff, "p.m.") == 0)
    {
      lvalp->Meridian = MERpm;
      return tMERIDIAN;
    }

  /* See if we have an abbreviation for a month. */
  if(strlen (buff) == 3)
    abbrev = 1;
  else if(strlen (buff) == 4 && buff[3] == '.')
    {
      abbrev = 1;
      buff[3] = '\0';
    }
  else
    abbrev = 0;

  for(tp = MonthDayTable; tp->name; tp++)
    {
      if(abbrev)
	{
	  if(strncmp (buff, tp->name, 3) == 0)
	    {
	      lvalp->Number = tp->value;
	      return tp->type;
	    }
	}
      else if(strcmp (buff, tp->name) == 0)
	{
	  lvalp->Number = tp->value;
	  return tp->type;
	}
    }

  for(tp = TimezoneTable; tp->name; tp++)
    if(strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  if(strcmp (buff, "dst") == 0)
    return tDST;

  for(tp = UnitsTable; tp->name; tp++)
    if(strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  /* Strip off any plural and try the units table again. */
  i = RAPTOR_BAD_CAST(int, strlen(buff)) - 1;
  if(buff[i] == 's')
    {
      buff[i] = '\0';
      for(tp = UnitsTable; tp->name; tp++)
	if(strcmp (buff, tp->name) == 0)
	  {
	    lvalp->Number = tp->value;
	    return tp->type;
	  }
      buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

  for(tp = OtherTable; tp->name; tp++)
    if(strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  /* Military timezones. */
  if(buff[1] == '\0' && ISALPHA ((unsigned char) *buff))
    {
      for(tp = MilitaryTable; tp->name; tp++)
	if(strcmp (buff, tp->name) == 0)
	  {
	    lvalp->Number = tp->value;
	    return tp->type;
	  }
    }

  /* Drop out any periods and try the timezone table again. */
  for(i = 0, p = q = buff; *q; q++)
    if(*q != '.')
      *p++ = *q;
    else
      i++;
  *p = '\0';
  if(i)
    for(tp = TimezoneTable; tp->name; tp++)
      if(strcmp (buff, tp->name) == 0)
	{
	  lvalp->Number = tp->value;
	  return tp->type;
	}

  return tID;
}

int yylex(YYSTYPE *lvalp, void *parm)
{
  unsigned char c;
  char *p;
  char buff[20];
  int Count;
  int sign;
  struct date_yy * date = (struct date_yy *)parm;

  for(;;)
    {
      while(ISSPACE ((unsigned char) *date->yyInput))
	date->yyInput++;

      if(ISDIGIT (c = *date->yyInput) || c == '-' || c == '+')
	{
	  if(c == '-' || c == '+')
	    {
	      sign = c == '-' ? -1 : 1;
	      if(!ISDIGIT (*++date->yyInput))
		/* skip the '-' sign */
		continue;
	    }
	  else
	    sign = 0;
	  for(lvalp->Number = 0; ISDIGIT (c = *date->yyInput++);)
	    lvalp->Number = 10 * lvalp->Number + c - '0';
	  date->yyInput--;
	  if(sign < 0)
	    lvalp->Number = -lvalp->Number;
	  /* Ignore ordinal suffixes on numbers */
	  c = *date->yyInput;
	  if(c == 's' || c == 'n' || c == 'r' || c == 't') {
	    c = *++date->yyInput;
	    if(c == 't' || c == 'd' || c == 'h') {
	      date->yyInput++;
	    } else {
	      date->yyInput--;
	    }
	  }
	  return sign ? tSNUMBER : tUNUMBER;
	}
      if(ISALPHA (c))
	{
	  for(p = buff; (c = *date->yyInput++, ISALPHA (c)) || c == '.';)
	    if(p < &buff[sizeof buff - 1])
	      *p++ = c;
	  *p = '\0';
	  date->yyInput--;
	  return LookupWord (lvalp, buff);
	}
      if(c != '(')
	return *date->yyInput++;
      Count = 0;
      do
	{
	  c = *date->yyInput++;
	  if(c == '\0')
	    return c;
	  if(c == '(')
	    Count++;
	  else if(c == ')')
	    Count--;
	}
      while(Count > 0);
    }
}

#define TM_YEAR_ORIGIN 1900

/* Yield A - B, measured in seconds.  */
static long
difftm (struct tm *a, struct tm *b)
{
  int ay = a->tm_year + (TM_YEAR_ORIGIN - 1);
  int by = b->tm_year + (TM_YEAR_ORIGIN - 1);
  long days = (
  /* difference in day of year */
		a->tm_yday - b->tm_yday
  /* + intervening leap days */
		+ ((ay >> 2) - (by >> 2))
		- (ay / 100 - by / 100)
		+ ((ay / 100 >> 2) - (by / 100 >> 2))
  /* + difference in years * 365 */
		+ (long) (ay - by) * 365
  );
  return (60 * (60 * (24 * days + (a->tm_hour - b->tm_hour))
		+ (a->tm_min - b->tm_min))
	  + (a->tm_sec - b->tm_sec));
}

time_t raptor_parse_date(const char *p, time_t *now)
{
  struct tm tm, tm0, *tmp;
  time_t Start;
  struct date_yy date;

  date.yyInput = p;
  Start = now ? *now : time ((time_t *) NULL);
  tmp = localtime (&Start);
  if(!tmp)
    return -1;
  date.yyYear = tmp->tm_year + TM_YEAR_ORIGIN;
  date.yyMonth = tmp->tm_mon + 1;
  date.yyDay = tmp->tm_mday;
  date.yyHour = tmp->tm_hour;
  date.yyMinutes = tmp->tm_min;
  date.yySeconds = tmp->tm_sec;
  tm.tm_isdst = tmp->tm_isdst;
  date.yyMeridian = MER24;
  date.yyRelSeconds = 0;
  date.yyRelMinutes = 0;
  date.yyRelHour = 0;
  date.yyRelDay = 0;
  date.yyRelMonth = 0;
  date.yyRelYear = 0;
  date.yyHaveDate = 0;
  date.yyHaveDay = 0;
  date.yyHaveRel = 0;
  date.yyHaveTime = 0;
  date.yyHaveZone = 0;

  if(yyparse (&date)
      || date.yyHaveTime > 1 || date.yyHaveZone > 1 
	  || date.yyHaveDate > 1 || date.yyHaveDay > 1) {
    return -1;
  }
  tm.tm_year = ToYear (date.yyYear) - TM_YEAR_ORIGIN + date.yyRelYear;
  tm.tm_mon = date.yyMonth - 1 + date.yyRelMonth;
  tm.tm_mday = date.yyDay + date.yyRelDay;
  if(date.yyHaveTime || (date.yyHaveRel && !date.yyHaveDate && !date.yyHaveDay))
    {
      tm.tm_hour = ToHour (date.yyHour, date.yyMeridian);
      if(tm.tm_hour < 0)
	return -1;
      tm.tm_min = date.yyMinutes;
      tm.tm_sec = date.yySeconds;
    }
  else
    {
      tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
    }
  tm.tm_hour += date.yyRelHour;
  tm.tm_min += date.yyRelMinutes;
  tm.tm_sec += date.yyRelSeconds;

  /* Let mktime deduce tm_isdst if we have an absolute timestamp,
     or if the relative timestamp mentions days, months, or years.  */
  if(date.yyHaveDate | date.yyHaveDay | date.yyHaveTime | date.yyRelDay | date.yyRelMonth | date.yyRelYear)
    tm.tm_isdst = -1;

  tm0 = tm;

  Start = mktime (&tm);

  if(Start == (time_t) -1)
    {

      /* Guard against falsely reporting errors near the time_t boundaries
         when parsing times in other time zones.  For example, if the min
         time_t value is 1970-01-01 00:00:00 UTC and we are 8 hours ahead
         of UTC, then the min localtime value is 1970-01-01 08:00:00; if
         we apply mktime to 1970-01-01 00:00:00 we will get an error, so
         we apply mktime to 1970-01-02 08:00:00 instead and adjust the time
         zone by 24 hours to compensate.  This algorithm assumes that
         there is no DST transition within a day of the time_t boundaries.  */
      if(date.yyHaveZone)
	{
	  tm = tm0;
	  if(tm.tm_year <= EPOCH - TM_YEAR_ORIGIN)
	    {
	      tm.tm_mday++;
	      date.yyTimezone -= 24 * 60;
	    }
	  else
	    {
	      tm.tm_mday--;
	      date.yyTimezone += 24 * 60;
	    }
	  Start = mktime (&tm);
	}

      if(Start == (time_t) -1)
	return Start;
    }

  if(date.yyHaveDay && !date.yyHaveDate)
    {
      tm.tm_mday += ((date.yyDayNumber - tm.tm_wday + 7) % 7
		     + 7 * (date.yyDayOrdinal - (0 < date.yyDayOrdinal)));
      Start = mktime (&tm);
      if(Start == (time_t) -1)
	return Start;
    }

  if(date.yyHaveZone)
    {
      long delta;
      struct tm *gmt = gmtime (&Start);
      if(!gmt)
	return -1;
      delta = date.yyTimezone * 60L + difftm (&tm, gmt);

      if((Start + delta < Start) != (delta < 0))
	return -1;		/* time_t overflow */
      Start += delta;
    }

  return Start;
}
