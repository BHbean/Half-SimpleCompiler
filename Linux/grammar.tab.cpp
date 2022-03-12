/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./grammar.y"

#include "stdio.h"
#include <iostream>
#include "../tree/nodes.h"
#include "../symbol/symbol.h"
// #include "./tree/gtree.h"

// 为每个树节点编号
static int idx;
// 定义一颗语法树
ASTNode* root;
//定义根符号表
SymbolTable* Base = new SymbolTable();

//在lex.yy.c里定义，会被yyparse()调用。在此声明消除编译和链接错误。
extern int yylex(void); 

// 在此声明，消除yacc生成代码时的告警
extern int yyparse(void);

void yyerror(const char *s) 
{ 
    printf("[error] %s\n", s); 
}


#line 97 "./Linux/grammar.tab.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_LINUX_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_LINUX_GRAMMAR_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    CONSTANT = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    FOR = 263,
    RETURN = 264,
    LE_OP = 265,
    GE_OP = 266,
    EQ_OP = 267,
    NE_OP = 268,
    LT_OP = 269,
    GT_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    NOT_OP = 273,
    INT = 274,
    VOID = 275,
    MAIN = 276,
    PRINTF = 277,
    SCANF = 278,
    UMINUS = 279,
    IFX = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "./grammar.y"
 
    int iValue; /* integer value */ 
    //  char sIndex; /* symbol table index */ 
    char* str;
    ASTNode *ast; /* node pointer */ 

#line 182 "./Linux/grammar.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LINUX_GRAMMAR_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

#define YYUNDEFTOK  2
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    28,    37,     2,
      33,    34,    26,    24,    38,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    32,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,    29,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    30,
      31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    96,   100,   108,   117,   123,   128,   135,
     139,   150,   154,   171,   176,   181,   186,   192,   201,   205,
     236,   240,   268,   296,   327,   331,   359,   390,   394,   422,
     450,   478,   509,   513,   541,   572,   576,   607,   611,   642,
     646,   655,   659,   667,   674,   679,   698,   734,   743,   976,
     984,   988,   995,   999,  1008,  1016,  1026,  1030,  1038,  1042,
    1051,  1059,  1063,  1082,  1088,  1095,  1102,  1106,  1111,  1115,
    1119,  1126,  1133,  1137,  1144,  1148,  1152,  1156,  1163,  1169,
    1178,  1193,  1201,  1208,  1216,  1225,  1236,  1248,  1255,  1267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "LT_OP",
  "GT_OP", "AND_OP", "OR_OP", "NOT_OP", "INT", "VOID", "MAIN", "PRINTF",
  "SCANF", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMINUS", "IFX",
  "'='", "'('", "')'", "'['", "']'", "'&'", "','", "'{'", "'}'", "';'",
  "$accept", "program", "element", "assign_op", "primary_expr",
  "postfix_expr", "unary_expr", "unary_operator", "pow_expr",
  "multiplicative_expr", "additive_expr", "relational_expr",
  "equality_expr", "logical_and_expr", "logical_or_expr", "assign_expr",
  "expression", "constant_expr", "type_specifier", "function_definition",
  "main_declaration", "compound_k", "sentences", "statement", "pointer",
  "var_declaration", "init_declaration_list", "init_declarator",
  "declarator", "direct_declarator", "initializer", "comma_expr",
  "comma_termination", "semicolon_sentence", "sentence", "repeat_k",
  "for_head", "for_statement", "while_head", "while_statement", "write_k",
  "read_k", "condition_statement", "return_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    42,    47,    37,    94,
     279,   280,    61,    40,    41,    91,    93,    38,    44,   123,
     125,    59
};
# endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   -67,   -67,    10,   -67,     5,    18,    -5,   -67,    33,
     -67,    87,   -67,     6,   -67,   -67,    42,    52,    64,    36,
     -67,    68,    70,   -67,   -67,   -67,   168,   -67,   -67,    67,
     -67,    76,   168,    85,    30,    44,     1,    58,    99,   108,
     -67,    78,     2,   -67,   -67,   114,    88,   -14,   -67,   -67,
     -67,   -67,   141,   -67,   141,   -67,   -67,   -67,   -67,   -67,
     -67,    56,    56,   165,   -67,    69,   125,   -17,   168,   -67,
     168,   -67,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   -67,   -67,     3,
       3,    92,   -67,    76,    96,   -67,   -67,   -67,    56,   -67,
     -67,   -67,   -16,   -15,    56,   101,   107,   109,   -67,    29,
     -67,   -67,   -67,    85,    85,    85,    30,    30,    44,    44,
      44,    44,     1,     1,    58,    99,   -67,   118,   -67,     2,
     168,   168,   104,   141,   -67,    56,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   108,   119,   150,    -9,   -67,   141,
     -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    44,    45,     0,     2,     0,     3,     0,     1,     0,
       4,    68,    46,     0,     6,     7,     0,     0,     0,     0,
      15,     0,     0,    13,    14,    17,     0,    16,    49,     9,
      11,    18,     0,    20,    24,    27,    32,    35,    37,    39,
      41,    66,     0,    51,    52,    68,     0,     0,    72,    74,
      50,    75,    68,    78,    68,    79,    69,    70,    76,    77,
      47,    68,    68,    68,    89,     0,     0,     0,     0,     5,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    54,     0,
       0,    55,    56,    58,    61,    48,    53,    73,    68,    71,
      81,    83,     0,     0,    68,     0,     0,     0,     8,     0,
      40,    19,    18,    21,    22,    23,    25,    26,    30,    31,
      28,    29,    33,    34,    36,    38,    42,     0,    60,     0,
       0,     0,    67,    68,    82,    68,    84,    85,    86,    10,
      64,    57,    65,    59,    43,     0,    87,     0,    62,    68,
      80,    88
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   151,    65,   -67,   -67,   -31,   -67,   -12,     7,
     -48,     4,    86,    77,    45,   -66,   -13,   -67,     8,   -67,
     -67,   166,   -45,   -67,   -67,   -67,   -67,    46,   -67,     9,
     -67,   -59,    73,   116,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    70,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   145,    42,     6,
       7,    43,    44,    45,    90,    46,    91,    92,    93,    94,
     143,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      96,    71,   102,   103,   110,    87,    87,   100,     5,   101,
       8,    78,    79,    67,     5,    80,    81,   108,   133,   134,
     126,    86,    98,    98,    98,   150,     9,    99,    88,    98,
     118,   119,   120,   121,    11,    89,    89,     1,     2,   132,
      60,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   109,    73,    74,    75,    14,
      15,   113,   114,   115,   142,   139,    13,    86,    76,    77,
      82,    83,   105,   106,    20,    61,   147,    64,    21,    22,
      23,    24,    25,   116,   117,    62,   122,   123,   146,    26,
      14,    15,    16,    27,    17,    18,    19,    63,   127,   128,
     112,    65,    68,    66,   151,    20,     1,     2,    69,    21,
      22,    23,    24,    25,    72,    84,    86,    14,    15,    16,
      26,    17,    18,    19,    27,    85,    11,    28,   107,    97,
     129,   131,    20,     1,     2,   136,    21,    22,    23,    24,
      25,   137,    98,   138,    14,    15,    16,    26,    17,    18,
      19,    27,   140,    11,    95,   148,   149,    10,   130,    20,
       1,     2,   125,    21,    22,    23,    24,    25,    14,    15,
     124,    14,    15,    12,    26,   141,   144,   135,    27,   104,
      11,     0,     0,    20,     1,     2,    20,    21,    22,    23,
      24,    25,    23,    24,    25,     0,     0,     0,    26,     0,
       0,    26,    27,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      45,    32,    61,    62,    70,     3,     3,    52,     0,    54,
       0,    10,    11,    26,     6,    14,    15,    34,    34,    34,
      86,    38,    38,    38,    38,    34,    21,    41,    26,    38,
      78,    79,    80,    81,    39,    33,    33,    19,    20,    98,
      34,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    68,    26,    27,    28,     3,
       4,    73,    74,    75,   130,    36,    33,    38,    24,    25,
      12,    13,     3,     4,    18,    33,   135,    41,    22,    23,
      24,    25,    26,    76,    77,    33,    82,    83,   133,    33,
       3,     4,     5,    37,     7,     8,     9,    33,    89,    90,
     131,    33,    35,    33,   149,    18,    19,    20,    32,    22,
      23,    24,    25,    26,    29,    16,    38,     3,     4,     5,
      33,     7,     8,     9,    37,    17,    39,    40,     3,    41,
      38,    35,    18,    19,    20,    34,    22,    23,    24,    25,
      26,    34,    38,    34,     3,     4,     5,    33,     7,     8,
       9,    37,    34,    39,    40,    36,     6,     6,    93,    18,
      19,    20,    85,    22,    23,    24,    25,    26,     3,     4,
      84,     3,     4,     7,    33,   129,   131,   104,    37,    63,
      39,    -1,    -1,    18,    19,    20,    18,    22,    23,    24,
      25,    26,    24,    25,    26,    -1,    -1,    -1,    33,    -1,
      -1,    33,    37,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    20,    43,    44,    60,    61,    62,     0,    21,
      44,    39,    63,    33,     3,     4,     5,     7,     8,     9,
      18,    22,    23,    24,    25,    26,    33,    37,    40,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    60,    63,    64,    65,    67,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      34,    33,    33,    33,    41,    33,    33,    58,    35,    32,
      45,    48,    29,    26,    27,    28,    24,    25,    10,    11,
      14,    15,    12,    13,    16,    17,    38,     3,    26,    33,
      66,    68,    69,    70,    71,    40,    64,    41,    38,    41,
      64,    64,    73,    73,    75,     3,     4,     3,    34,    58,
      57,    48,    48,    50,    50,    50,    51,    51,    52,    52,
      52,    52,    53,    53,    54,    55,    57,    71,    71,    38,
      45,    35,    73,    34,    34,    74,    34,    34,    34,    36,
      34,    69,    57,    72,    56,    59,    64,    73,    36,     6,
      34,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    46,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    50,    50,
      51,    51,    51,    51,    52,    52,    52,    53,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    60,    60,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    67,    68,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    73,    73,    73,    73,
      73,    74,    75,    75,    76,    76,    76,    76,    77,    77,
      78,    79,    80,    81,    82,    82,    83,    84,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     1,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     4,     3,     2,
       1,     1,     1,     2,     1,     2,     1,     3,     1,     3,
       2,     1,     4,     1,     3,     1,     1,     3,     0,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       6,     2,     4,     2,     4,     4,     4,     5,     7,     2
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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
  case 2:
#line 85 "./grammar.y"
           {
        std::cout << "program : element" << std::endl;
        root = new ASTNode(ASTNodeType::program, idx);
        
        root->addChildNode((yyvsp[0].ast));
        // std::cout << root->getChildNum() << std::endl;
        idx++;
    }
#line 1489 "./Linux/grammar.tab.cpp"
    break;

  case 3:
#line 96 "./grammar.y"
                       {
        std::cout << "element : function_definition" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1498 "./Linux/grammar.tab.cpp"
    break;

  case 4:
#line 100 "./grammar.y"
                                 {
        std::cout << "element : function_definition element" << std::endl;
        (yyvsp[-1].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 1508 "./Linux/grammar.tab.cpp"
    break;

  case 5:
#line 108 "./grammar.y"
       {
        std::cout << "assign_op : '='" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "=");
        idx++;
    }
#line 1518 "./Linux/grammar.tab.cpp"
    break;

  case 6:
#line 117 "./grammar.y"
              {
        std::cout << "primary_expr : IDENTIFIER" << std::endl;
        std::string identifier = (yyvsp[0].str);
        (yyval.ast) = new IdDeclarationNode(idx, identifier);
        idx++;
    }
#line 1529 "./Linux/grammar.tab.cpp"
    break;

  case 7:
#line 123 "./grammar.y"
                  {
        std::cout << "primary_expr : CONSTANT" << std::endl;
        (yyval.ast) = new ConstNode(idx, (yyvsp[0].iValue));
        idx++;
    }
#line 1539 "./Linux/grammar.tab.cpp"
    break;

  case 8:
#line 128 "./grammar.y"
                            {
        std::cout << "primary_expr : '(' expression ')'" << std::endl;
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 1548 "./Linux/grammar.tab.cpp"
    break;

  case 9:
#line 135 "./grammar.y"
                {
        std::cout << "postfix_expr : primary_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1557 "./Linux/grammar.tab.cpp"
    break;

  case 10:
#line 139 "./grammar.y"
                                     {
        // 一维数组产生式
        std::cout << "postfix_expr : primary_expr '[' expression ']'" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "[]");
        idx++;
        (yyvsp[-3].ast)->getRightestPeer()->setRightSibling((yyvsp[-1].ast));
        (yyval.ast)->addChildNode((yyvsp[-3].ast));
    }
#line 1570 "./Linux/grammar.tab.cpp"
    break;

  case 11:
#line 150 "./grammar.y"
                {
        std::cout << "unary_expr : postfix_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1579 "./Linux/grammar.tab.cpp"
    break;

  case 12:
#line 154 "./grammar.y"
                                   {
        std::cout << "unary_expr : unary_operator unary_expr" << std::endl;
        if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
            ((OperatorNode*)(yyvsp[-1].ast))->setFlag(true);
        }
        else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
            if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                ((OperatorNode*)(yyvsp[-1].ast))->setFlag(true);
            }
        }
        (yyvsp[-1].ast)->addChildNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 1597 "./Linux/grammar.tab.cpp"
    break;

  case 13:
#line 171 "./grammar.y"
                        {
        std::cout << "unary_operator : '+'" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "+");
        idx++;
    }
#line 1607 "./Linux/grammar.tab.cpp"
    break;

  case 14:
#line 176 "./grammar.y"
                          {
        std::cout << "unary_operator : '-'" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "-");
        idx++;
    }
#line 1617 "./Linux/grammar.tab.cpp"
    break;

  case 15:
#line 181 "./grammar.y"
            {
        std::cout << "unary_operator : NOT_OP" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "!");
        idx++;
    }
#line 1627 "./Linux/grammar.tab.cpp"
    break;

  case 16:
#line 186 "./grammar.y"
         {
        // 取地址运算符
        std::cout << "unary_operator : '&'" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "&");
        idx++;
    }
#line 1638 "./Linux/grammar.tab.cpp"
    break;

  case 17:
#line 192 "./grammar.y"
         {
        // 取值运算符
        std::cout << "unary_operator : '*'" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "*");
        idx++;
    }
#line 1649 "./Linux/grammar.tab.cpp"
    break;

  case 18:
#line 201 "./grammar.y"
              {
        std::cout << "pow_expr : unary_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1658 "./Linux/grammar.tab.cpp"
    break;

  case 19:
#line 205 "./grammar.y"
                             {
        std::cout << "pow_expr : pow_expr '^' unary_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "^");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1691 "./Linux/grammar.tab.cpp"
    break;

  case 20:
#line 236 "./grammar.y"
            {
        std::cout << "multiplicative_expr : pow_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1700 "./Linux/grammar.tab.cpp"
    break;

  case 21:
#line 240 "./grammar.y"
                                          {
        std::cout << "multiplicative_expr : multiplicative_expr '*' pow_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "*");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op  && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1733 "./Linux/grammar.tab.cpp"
    break;

  case 22:
#line 268 "./grammar.y"
                                          {
        std::cout << "multiplicative_expr : multiplicative_expr '/' pow_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "/");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1766 "./Linux/grammar.tab.cpp"
    break;

  case 23:
#line 296 "./grammar.y"
                                          {
        std::cout << "multiplicative_expr : multiplicative_expr '%' pow_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "%");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1799 "./Linux/grammar.tab.cpp"
    break;

  case 24:
#line 327 "./grammar.y"
                       {
        std::cout << "additive_expr : multiplicative_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1808 "./Linux/grammar.tab.cpp"
    break;

  case 25:
#line 331 "./grammar.y"
                                               {
        std::cout << "additive_expr : additive_expr '+' multiplicative_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "+");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1841 "./Linux/grammar.tab.cpp"
    break;

  case 26:
#line 359 "./grammar.y"
                                               {
        std::cout << "multiplicative_expr : additive_expr '-' multiplicative_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "-");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1874 "./Linux/grammar.tab.cpp"
    break;

  case 27:
#line 390 "./grammar.y"
                 {
        std::cout << "relational_expr : additive_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1883 "./Linux/grammar.tab.cpp"
    break;

  case 28:
#line 394 "./grammar.y"
                                             {
        std::cout << "relational_expr : relational_expr LT_OP additive_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "<");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1916 "./Linux/grammar.tab.cpp"
    break;

  case 29:
#line 422 "./grammar.y"
                                             {
        std::cout << "relational_expr : relational_expr GT_OP additive_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, ">");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1949 "./Linux/grammar.tab.cpp"
    break;

  case 30:
#line 450 "./grammar.y"
                                             {
        std::cout << "relational_expr : relational_expr LE_OP additive_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "<=");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 1982 "./Linux/grammar.tab.cpp"
    break;

  case 31:
#line 478 "./grammar.y"
                                             {
        std::cout << "relational_expr : relational_expr GE_OP additive_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, ">=");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 2015 "./Linux/grammar.tab.cpp"
    break;

  case 32:
#line 509 "./grammar.y"
                   {
        std::cout << "equality_expr : relational_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2024 "./Linux/grammar.tab.cpp"
    break;

  case 33:
#line 513 "./grammar.y"
                                             {
        std::cout << "equality_expr : equality_expr EQ_OP relational_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "==");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 2057 "./Linux/grammar.tab.cpp"
    break;

  case 34:
#line 541 "./grammar.y"
                                             {
        std::cout << "equality_expr : equality_expr NE_OP relational_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "!=");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 2090 "./Linux/grammar.tab.cpp"
    break;

  case 35:
#line 572 "./grammar.y"
                 {
        std::cout << "logical_and_expr : equality_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2099 "./Linux/grammar.tab.cpp"
    break;

  case 36:
#line 576 "./grammar.y"
                                               {
        std::cout << "logical_and_expr : logical_and_expr AND_OP equality_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "&&");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 2132 "./Linux/grammar.tab.cpp"
    break;

  case 37:
#line 607 "./grammar.y"
                    {
        std::cout << "logical_or_expr : logical_and_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2141 "./Linux/grammar.tab.cpp"
    break;

  case 38:
#line 611 "./grammar.y"
                                                {
        std::cout << "logical_or_expr : logical_or_expr OR_OP logical_and_expr" << std::endl;
        (yyval.ast) = new OperatorNode(idx, "||");
        idx++;
        if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::constDcl){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
            ((OperatorNode*)(yyval.ast))->setFlag(true);
        }
        else if((yyvsp[-2].ast)->getNodeType() == ASTNodeType::op && ((OperatorNode*)(yyvsp[-2].ast))->getFlag()){
            if((yyvsp[0].ast)->getNodeType() == ASTNodeType::constDcl){
                ((OperatorNode*)(yyval.ast))->setFlag(true);
            }
            else if((yyvsp[0].ast)->getNodeType() == ASTNodeType::op){
                if(((OperatorNode*)(yyvsp[0].ast))->getFlag()){
                    ((OperatorNode*)(yyval.ast))->setFlag(true);
                }
            }
        }
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 2174 "./Linux/grammar.tab.cpp"
    break;

  case 39:
#line 642 "./grammar.y"
                   {
        std::cout << "assign_expr : logical_or_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2183 "./Linux/grammar.tab.cpp"
    break;

  case 40:
#line 646 "./grammar.y"
                                          {
        std::cout << "logical_or_expr : logical_or_expr OR_OP logical_and_expr" << std::endl;
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyvsp[-1].ast)->addChildNode((yyvsp[-2].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2194 "./Linux/grammar.tab.cpp"
    break;

  case 41:
#line 655 "./grammar.y"
               {
        std::cout << "expression : assign_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2203 "./Linux/grammar.tab.cpp"
    break;

  case 42:
#line 659 "./grammar.y"
                                    {
        std::cout << "expression : expression ',' assign_expr" << std::endl;
        (yyvsp[-2].ast)->getRightestPeer()->setRightSibling((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 2213 "./Linux/grammar.tab.cpp"
    break;

  case 43:
#line 667 "./grammar.y"
                   {
        std::cout << "constant_expr : logical_or_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2222 "./Linux/grammar.tab.cpp"
    break;

  case 44:
#line 674 "./grammar.y"
       {
        std::cout << "type_specifier: INT" << std::endl;
        (yyval.ast) = new TypeSpcfNode(idx, "int");
        idx++;
    }
#line 2232 "./Linux/grammar.tab.cpp"
    break;

  case 45:
#line 679 "./grammar.y"
          {
        std::cout << "type_specifier: VOID" << std::endl;
        (yyval.ast) = new TypeSpcfNode(idx, "void");
        idx++;
    }
#line 2242 "./Linux/grammar.tab.cpp"
    break;

  case 46:
#line 698 "./grammar.y"
                               {
        std::cout << "function_definition: main_declaration compound_k" << std::endl;
        // if(NULL != $1){
        //     std::cout << "main_declaration construction successed!" << std::endl;
        // }
        (yyvsp[-1].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast) = new ASTNode(ASTNodeType::defFunc, idx);
        idx++;
        (yyval.ast)->addChildNode((yyvsp[-1].ast));
        CompoundNode* current_node = dynamic_cast<CompoundNode*>((yyvsp[0].ast));
        current_node->getTable()->setBase(Base);
        Base->addChild(current_node->getTable());
        std::vector<SymbolTable*>* test_vec = Base->getChild();
        for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
            std::cout<<"                                                 child "<<std::endl;
        }
        //std::cout<<"                                                              ha"<<std::endl;
        // CompoundNode* current_node = dynamic_cast<CompoundNode*>($2);
        // Base = current_node->getTable();
        // if(!Base->getChild()->empty()){
        //     std::vector<SymbolTable*>* test_vec = Base->getChild();
        //     for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
        //         /*设置根符号表*/
        //         (*test_iter)->setBase(Base);
        //     }
            
        // }


        // if(NULL != $$){
        //     std::cout << "function_definition construction successed!" << std::endl;
        // }
    }
#line 2280 "./Linux/grammar.tab.cpp"
    break;

  case 47:
#line 734 "./grammar.y"
                               {
        std::cout << "main_declaration: type_specifier MAIN '(' ')'" << std::endl;
        (yyval.ast) = new ASTNode(ASTNodeType::mainFunc, idx);
        idx++;
        (yyval.ast)->addChildNode((yyvsp[-3].ast));
    }
#line 2291 "./Linux/grammar.tab.cpp"
    break;

  case 48:
#line 743 "./grammar.y"
                     { //如何找到作用域的子作用域，然后通过父子结点连接起来   每当遇到{}便会遍历该节点向下的id然后插入符号表，如何遍历
        std::cout << "compound_k : '{' statement '}'" << std::endl;
        (yyval.ast) = new CompoundNode(idx);
        idx++;
        (yyval.ast)->addChildNode((yyvsp[-1].ast));
        CompoundNode* current_node = dynamic_cast<CompoundNode*>((yyval.ast));
        if((yyval.ast)->getChild()->empty()){
            //current_node->getTable()->setBase(Base);
            //std::cout<<"                                                              ha"<<std::endl;
        } //如果没有子结点
        else{ //如果存在子结点           
	        std::vector<ASTNode*>* tmp = (yyval.ast)->getChild();
            for(auto it = (*tmp).begin();it != (*tmp).end();it++){ //遍历子结点
                if((*it)->getNodeType()==ASTNodeType::compoudStmt){ //enum中定义的compoudStmt而不是compoundStmt
                //Derived *pD = dynamic_cast<Derived*>(pB);
                    CompoundNode * compound_it = dynamic_cast<CompoundNode*>(*it);
                    
                    //*it = CompoundNode* (*it);                  
                    compound_it->getTable()->setParent(current_node->getTable());
                    compound_it->getTable()->setBase(Base);
                    Base->addChild(compound_it->getTable());
                    
                    // std::vector<SymbolTable*>* test_vec = Base->getChild();
                    // for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
                    //     std::cout<<"                                                 child "<<std::endl;
                    // }
                    current_node->getTable()->addChild(compound_it->getTable());
                    //std::cout<<"YesYYYYYYYY"<<std::endl;
                    //std::cout<<"AAAAAAAAAAAA"<<std::endl; 
                }else if((*it)->getNodeType()==ASTNodeType::reapeatStmt){ 
                    /*循环语句需寻找子结点的compoundStmt
                     -- 循环语句的()和{}都是子作用域，需要进行进一步判断
                     -- 根据当前产生式不需要考虑这一点*/
                    if((*it)->getChild()->empty()){}
                    else{

                        std::vector<ASTNode*>* child_tmp = (*it)->getChild();
                        for(auto iter =(*child_tmp).begin();iter != (*child_tmp).end();iter++){
                            if((*iter)->getNodeType()==ASTNodeType::compoudStmt){ //如果是{}
                                
                                CompoundNode * compound_it_re = dynamic_cast<CompoundNode*>(*iter);
                                compound_it_re->getTable()->setParent(current_node->getTable());
                                compound_it_re->getTable()->setBase(Base);
                                Base->addChild(compound_it_re->getTable());
                                // std::vector<SymbolTable*>* test_vec = Base->getChild();
                                // for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
                                //     std::cout<<"                                                 child "<<std::endl;
                                // }
                                current_node->getTable()->addChild(compound_it_re->getTable());
                            }//else if((*iter)->getNodeType()==ASTNodeType::compoudStmt){} //如果是()
                        }
                    }

                }else if((*it)->getNodeType()==ASTNodeType::conditionStmt){ //条件判断语句
                    if((*it)->getChild()->empty()){}
                    else{
                        std::vector<ASTNode*>* child_tmp_1 = (*it)->getChild();
                        for(auto iter_1 =(*child_tmp_1).begin();iter_1 != (*child_tmp_1).end();iter_1++){
                            if((*iter_1)->getNodeType()==ASTNodeType::compoudStmt){
                                CompoundNode * compound_it_con = dynamic_cast<CompoundNode*>(*iter_1);
                                compound_it_con->getTable()->setParent(current_node->getTable());
                                Base->addChild(compound_it_con->getTable());
                                compound_it_con->getTable()->setBase(Base);
                                // std::vector<SymbolTable*>* test_vec = Base->getChild();
                                // for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
                                //     std::cout<<"                                                 child "<<std::endl;
                                // }
                                current_node->getTable()->addChild(compound_it_con->getTable());
                            }
                        }
                    }

                }else if((*it)->getNodeType()==ASTNodeType::varDcl){ //声明变量语句
                    if(!(*it)->getChild()->empty()){ //如果子结点不为空
                        std::vector<ASTNode*>* child_tmp_2 = (*it)->getChild();
                        // for(auto iter_2 = (*child_tmp_2).begin;iter_2 != (*child_tmp_2).end();iter_2++){
                        // }
                        ASTNode * init_del_list = (*child_tmp_2)[0]->getRightSibling();
                        
                        
                        while(init_del_list->getRightSibling() != NULL){
                            ASTNode * init_del = init_del_list;
                            if(init_del->getChild()->empty()){ //int b 的形式
                                
                                IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(init_del);
                                if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                    std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                }else{
                                    current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                }
                                
                        
                            }
                            else{
                                //数组
                                if(init_del->getNodeType() == ASTNodeType::arrayDcl){
                                    std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                                    ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                                    IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                                    OperatorNode * array_del_1 = dynamic_cast<OperatorNode*>(init_del);
                                    //bool tmpflag = array_del_1->getFlag();
                                    //if(tmpflag==true){}
                                    //else{}
                                    if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                        std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                    }else{
                                        //向符号表中插入标识符
                                        //current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                    
                                    }
                                }
                                else{ //id或指针
                                std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                                ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                                if (del_it_var_tmp->getChild()->empty()){ //子结点为空，是一个iddecl
                                IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                                if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                    std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                }else{
                                    //向符号表中插入标识符
                                    current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                    
                                }
                                }
                                else{
                                    //是一个指针
                                    std::vector<ASTNode*>* child_tmp_4 = del_it_var_tmp->getChild();
                                    ASTNode * pointer_del_1 = (*child_tmp_4)[0];
                                    IdDeclarationNode * del_it_pointer = dynamic_cast<IdDeclarationNode*>(pointer_del_1);
                                    if(current_node->getTable()-> IfInThisTable(del_it_pointer->getSymbol()->getname())==1){
                                        std::cout<<"重定义错误！"<<del_it_pointer->getSymbol()->getname()<<std::endl;
                                    }else{
                                    //向符号表中插入标识符
                                    current_node->getTable()->addSymbol(del_it_pointer->getSymbol());
                                    }
                                }
                                }
                                
                            }
                            init_del_list = init_del_list->getRightSibling();
                        }
                        if(init_del_list->getRightSibling()==NULL){ //右结点为空，两种情况，即原本就没有右结点或遍历到最后一个结点
                            ASTNode * init_del = init_del_list;
                            
                            if(init_del->getChild()->empty()){
                                IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(init_del);
                                if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                    std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                }else{

                                    current_node->getTable()->addSymbol(del_it_var->getSymbol());

                                }
                                //std::cout<<"                                                       this is decloator1"<<del_it_var->getSymbol()->getname()<<std::endl;
                            }
                            // else{
                            //     std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                            //     ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                            //     IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                            //     if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                            //         std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                            //     }
                            else{
                                //数组
                                if(init_del->getNodeType() == ASTNodeType::arrayDcl){
                                    std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                                    ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                                    IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                                    OperatorNode * array_del_1 = dynamic_cast<OperatorNode*>(init_del);
                                    //bool tmpflag = array_del_1->getFlag();
                                    //if(tmpflag==true){}
                                    //else{}
                                    if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                        std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                    }else{
                                        //向符号表中插入标识符
                                        //current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                    
                                    }
                                }
                                else{ //id或指针
                                std::vector<ASTNode*>* child_tmp_3 = init_del->getChild();
                                ASTNode * del_it_var_tmp = (*child_tmp_3)[0];
                                if (del_it_var_tmp->getChild()->empty()){ //子结点为空，是一个iddecl
                                IdDeclarationNode * del_it_var = dynamic_cast<IdDeclarationNode*>(del_it_var_tmp);
                                if(current_node->getTable()-> IfInThisTable(del_it_var->getSymbol()->getname())==1){
                                    std::cout<<"重定义错误！"<<del_it_var->getSymbol()->getname()<<std::endl;
                                }else{
                                    //向符号表中插入标识符
                                    current_node->getTable()->addSymbol(del_it_var->getSymbol());
                                    
                                }
                                }
                                else{
                                    //是一个指针
                                    std::vector<ASTNode*>* child_tmp_4 = del_it_var_tmp->getChild();
                                    ASTNode * pointer_del_1 = (*child_tmp_4)[0];
                                    IdDeclarationNode * del_it_pointer = dynamic_cast<IdDeclarationNode*>(pointer_del_1);
                                    if(current_node->getTable()-> IfInThisTable(del_it_pointer->getSymbol()->getname())==1){
                                        std::cout<<"重定义错误！"<<del_it_pointer->getSymbol()->getname()<<std::endl;
                                    }else{
                                    //向符号表中插入标识符
                                    current_node->getTable()->addSymbol(del_it_pointer->getSymbol());
                                    }
                                }
                                }
                                
                            
                            
                            }
                        }
                        

                    }

                }
            }
        }
        /*测试符号表是否连接
        int test = 1;
        SymbolTable *test_table = new SymbolTable(); 
        test_table = current_node->getTable();
        
        if(!test_table->getChild()->empty()){
            std::vector<SymbolTable*>* test_vec = test_table->getChild();
            for(auto test_iter = (*test_vec).begin();test_iter != (*test_vec).end();test_iter++){
                std::cout<<test<<"                                                    jjjjjjjjjjjjjjjjjjj"<<std::endl;
                test++;
                //test_table = test_table->getChild(); 
            }
            
        }*/
    }
#line 2529 "./Linux/grammar.tab.cpp"
    break;

  case 49:
#line 976 "./grammar.y"
             {
        std::cout << "compound_k : '{' '}'" << std::endl;
        (yyval.ast) = new CompoundNode(idx);
        idx++;
    }
#line 2539 "./Linux/grammar.tab.cpp"
    break;

  case 50:
#line 984 "./grammar.y"
            {
        std::cout << "sentences : sentence" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2548 "./Linux/grammar.tab.cpp"
    break;

  case 51:
#line 988 "./grammar.y"
                {
        std::cout << "sentences : compound_k" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2557 "./Linux/grammar.tab.cpp"
    break;

  case 52:
#line 995 "./grammar.y"
             {
        std::cout << "statement : sentences" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2566 "./Linux/grammar.tab.cpp"
    break;

  case 53:
#line 999 "./grammar.y"
                         {
        std::cout << "statement : statement sentences" << std::endl;
        (yyvsp[-1].ast)->getRightestPeer()->setRightSibling((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2576 "./Linux/grammar.tab.cpp"
    break;

  case 54:
#line 1008 "./grammar.y"
       {
        std::cout << "pointer : '*'" << std::endl;
        (yyval.ast) = new ASTNode(ASTNodeType::ptrDcl, idx);
        idx++;
    }
#line 2586 "./Linux/grammar.tab.cpp"
    break;

  case 55:
#line 1016 "./grammar.y"
                                        {
        std::cout << "var_declaration: type_specifier init_declaration_list" << std::endl;
        (yyval.ast) = new ASTNode(ASTNodeType::varDcl, idx);
        idx++;
        (yyvsp[-1].ast)->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-1].ast));
    }
#line 2598 "./Linux/grammar.tab.cpp"
    break;

  case 56:
#line 1026 "./grammar.y"
                   {
        std::cout << "init_declaration_list: init_declarator" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2607 "./Linux/grammar.tab.cpp"
    break;

  case 57:
#line 1030 "./grammar.y"
                                               {
        std::cout << "init_declaration_list: init_declarator_list ',' init_declarator" << std::endl;
        (yyvsp[-2].ast)->getRightestPeer()->setRightSibling((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 2617 "./Linux/grammar.tab.cpp"
    break;

  case 58:
#line 1038 "./grammar.y"
              {
        std::cout << "init_declarator: declarator" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2626 "./Linux/grammar.tab.cpp"
    break;

  case 59:
#line 1042 "./grammar.y"
                                      {
        std::cout << "init_declarator: declarator assign_op initializer" << std::endl;
        (yyvsp[-2].ast)->setRightSibling((yyvsp[0].ast));
        (yyvsp[-1].ast)->addChildNode((yyvsp[-2].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2637 "./Linux/grammar.tab.cpp"
    break;

  case 60:
#line 1051 "./grammar.y"
                             {
        std::cout << "declarator : pointer direct_declarator" << std::endl;
        IdDeclarationNode * idNode = dynamic_cast<IdDeclarationNode*>((yyvsp[0].ast));
        Symbol * tmp_symbol1 = idNode->getSymbol();
        tmp_symbol1->change(idNode->getIdentifier(),SymbolType::pointer);
        (yyval.ast) = (yyvsp[-1].ast);
        (yyvsp[-1].ast)->addChildNode((yyvsp[0].ast));
    }
#line 2650 "./Linux/grammar.tab.cpp"
    break;

  case 61:
#line 1059 "./grammar.y"
                       {
        std::cout << "declarator : direct_declarator" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2659 "./Linux/grammar.tab.cpp"
    break;

  case 62:
#line 1063 "./grammar.y"
                                             {
        (yyval.ast) = new ASTNode(ASTNodeType::arrayDcl, idx);
        IdDeclarationNode * idNode_2 = dynamic_cast<IdDeclarationNode*>((yyvsp[-3].ast));
        Symbol * tmp_symbol2 = idNode_2->getSymbol();
        tmp_symbol2->change(idNode_2->getIdentifier(),SymbolType::array);
        idx ++;
        if((yyvsp[-1].ast)->getNodeType() == ASTNodeType::op){
            // std::cout << "********************in**************************" << std::endl;
            if(((OperatorNode*)(yyvsp[-1].ast))->getFlag() == false){
                std::cout << "In array declaration, the expression in '['']' has to be constant expression!" << std::endl;
                exit(0);
            }
        }
        (yyvsp[-3].ast)->setRightSibling((yyvsp[-1].ast));
        (yyval.ast)->addChildNode((yyvsp[-3].ast));
    }
#line 2680 "./Linux/grammar.tab.cpp"
    break;

  case 63:
#line 1082 "./grammar.y"
              {
        std::cout << "direct_declarator: IDENTIFIER" << std::endl;
        std::string str = (yyvsp[0].str);
        (yyval.ast) = new IdDeclarationNode(idx, str);
        idx++;
    }
#line 2691 "./Linux/grammar.tab.cpp"
    break;

  case 64:
#line 1088 "./grammar.y"
                               {
        std::cout << "direct_declarator: '(' direct_declarator ')'" << std::endl;
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2700 "./Linux/grammar.tab.cpp"
    break;

  case 65:
#line 1095 "./grammar.y"
               {
        std::cout << "initializer: assign_expr" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2709 "./Linux/grammar.tab.cpp"
    break;

  case 66:
#line 1102 "./grammar.y"
              {
        std::cout << "comma_expr: expression" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2718 "./Linux/grammar.tab.cpp"
    break;

  case 67:
#line 1106 "./grammar.y"
                               {
        std::cout << "comma_expr: comma_expr ',' comma_expr" << std::endl;
        (yyvsp[-2].ast)->getRightestPeer()->setRightSibling((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 2728 "./Linux/grammar.tab.cpp"
    break;

  case 68:
#line 1111 "./grammar.y"
                        {
        std::cout << "comma_expr: ε" << std::endl;
        (yyval.ast) = NULL;
    }
#line 2737 "./Linux/grammar.tab.cpp"
    break;

  case 69:
#line 1115 "./grammar.y"
             {
        std::cout << "comma_expr: write_k" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2746 "./Linux/grammar.tab.cpp"
    break;

  case 70:
#line 1119 "./grammar.y"
            {
        std::cout << "comma_expr: read_k" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2755 "./Linux/grammar.tab.cpp"
    break;

  case 71:
#line 1126 "./grammar.y"
                  {
        std::cout << "comma_termination: comma_expr ';'" << std::endl;
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2764 "./Linux/grammar.tab.cpp"
    break;

  case 72:
#line 1133 "./grammar.y"
                     {
        std::cout << "semicolon_sentence: comma_termination ';'" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2773 "./Linux/grammar.tab.cpp"
    break;

  case 73:
#line 1137 "./grammar.y"
                         {
        std::cout << "semicolon_sentence: var_declaration ';'" << std::endl;
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2782 "./Linux/grammar.tab.cpp"
    break;

  case 74:
#line 1144 "./grammar.y"
                      {
        std::cout << "sentence: semicolon_sentence" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2791 "./Linux/grammar.tab.cpp"
    break;

  case 75:
#line 1148 "./grammar.y"
              {
        std::cout << "sentence: repeat_k" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2800 "./Linux/grammar.tab.cpp"
    break;

  case 76:
#line 1152 "./grammar.y"
                         {
        std::cout << "sentence: condition_statement" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2809 "./Linux/grammar.tab.cpp"
    break;

  case 77:
#line 1156 "./grammar.y"
                 {
        std::cout << "sentence: return_stmt" << std::endl;
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2818 "./Linux/grammar.tab.cpp"
    break;

  case 78:
#line 1163 "./grammar.y"
                 {
        std::cout << "repeat_k: for_statement" << std::endl;
        (yyval.ast) = new RepeatNode(idx, "for");
        idx++;
        (yyval.ast)->addChildNode((yyvsp[0].ast));
    }
#line 2829 "./Linux/grammar.tab.cpp"
    break;

  case 79:
#line 1169 "./grammar.y"
                     {
        std::cout << "repeat_k: for_statement" << std::endl;
        (yyval.ast) = new RepeatNode(idx, "while");
        idx++;
        (yyval.ast)->addChildNode((yyvsp[0].ast));
    }
#line 2840 "./Linux/grammar.tab.cpp"
    break;

  case 80:
#line 1178 "./grammar.y"
                                                               {
        std::cout << "for_head: FOR '(' semicolon_sentence comma_termination comma_expr ')'" 
                  << std::endl;
        if((yyvsp[-3].ast) != NULL){
            (yyvsp[-3].ast)->getRightestPeer()->setRightSibling((yyvsp[-2].ast));
            (yyval.ast) = (yyvsp[-3].ast);
        }
        (yyvsp[-2].ast)->getRightestPeer()->setRightSibling((yyvsp[-1].ast));
        if((yyvsp[-3].ast) == NULL){
            (yyval.ast) = (yyvsp[-2].ast);
        }
    }
#line 2857 "./Linux/grammar.tab.cpp"
    break;

  case 81:
#line 1193 "./grammar.y"
                      {
        std::cout << "for_statement: for_head sentences" << std::endl;
        (yyvsp[-1].ast)->getRightestPeer()->setRightSibling((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2867 "./Linux/grammar.tab.cpp"
    break;

  case 82:
#line 1201 "./grammar.y"
                            {
        std::cout << "while_head: WHILE '(' comma_expr ')'" << std::endl;
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2876 "./Linux/grammar.tab.cpp"
    break;

  case 83:
#line 1208 "./grammar.y"
                        {
        std::cout << "while_statement: while_head sentences" << std::endl;
        (yyvsp[-1].ast)->getRightestPeer()->setRightSibling((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2886 "./Linux/grammar.tab.cpp"
    break;

  case 84:
#line 1216 "./grammar.y"
                             {
        std::cout << "write_k: PRINTF '(' IDENTIFIER ')'" << std::endl;
        std::string str = (yyvsp[-1].str);
        ASTNode* tmp = new IdDeclarationNode(idx, str);
        idx++;
        (yyval.ast) = new ASTNode(ASTNodeType::writeFunc, idx);
        idx++;
        (yyval.ast)->addChildNode(tmp);
    }
#line 2900 "./Linux/grammar.tab.cpp"
    break;

  case 85:
#line 1225 "./grammar.y"
                             {
        std::cout << "write_k: PRINTF '(' CONSTANT ')'" << std::endl;
        ASTNode* tmp = new ConstNode(idx, (yyvsp[-1].iValue));
        idx++;
        (yyval.ast) = new ASTNode(ASTNodeType::writeFunc, idx);
        idx++;
        (yyval.ast)->addChildNode(tmp);
    }
#line 2913 "./Linux/grammar.tab.cpp"
    break;

  case 86:
#line 1236 "./grammar.y"
                            {
        std::cout << "read_k: SCANF '(' IDENTIFIER ')'" << std::endl;
        std::string str = (yyvsp[-1].str);
        ASTNode* tmp = new IdDeclarationNode(idx, str);
        idx++;
        (yyval.ast) = new ASTNode(ASTNodeType::readFunc, idx);
        idx++;
        (yyval.ast)->addChildNode(tmp);
    }
#line 2927 "./Linux/grammar.tab.cpp"
    break;

  case 87:
#line 1248 "./grammar.y"
                                             {
        std::cout << "condition_statement: IF '(' comma_expr ')' sentences" << std::endl;
        (yyval.ast) = new ASTNode(ASTNodeType::conditionStmt, idx);
        idx++;
        (yyvsp[-2].ast)->getRightestPeer()->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
    }
#line 2939 "./Linux/grammar.tab.cpp"
    break;

  case 88:
#line 1255 "./grammar.y"
                                                    {
        std::cout << "condition_statement: IF '(' comma_expr ')' sentences ELSE sentences" 
                  << std::endl;
        (yyval.ast) = new ASTNode(ASTNodeType::conditionStmt, idx);
        idx++;
        (yyvsp[-4].ast)->getRightestPeer()->setRightSibling((yyvsp[-2].ast));
        (yyvsp[-2].ast)->getRightestPeer()->setRightSibling((yyvsp[0].ast));
        (yyval.ast)->addChildNode((yyvsp[-4].ast));
    }
#line 2953 "./Linux/grammar.tab.cpp"
    break;

  case 89:
#line 1267 "./grammar.y"
              {
        std::cout << "return_stmt: RETURN ';'" << std::endl;
        (yyval.ast) = new ASTNode(ASTNodeType::returnStmt, idx);
        idx++;
    }
#line 2963 "./Linux/grammar.tab.cpp"
    break;


#line 2967 "./Linux/grammar.tab.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 1273 "./grammar.y"


// #include "lex.yy.c"
int main()
{
    //Base = new SymbolTable();
    Base->settotalOffset(4);
    Base->setsymbolItemCount(0);
    Base->setBase(Base);
    yyparse();
    // if(NULL != root){
    //     std::cout << "root exists!" << std::endl;
    // }

    ASTNode::printTree(root);
    return 0;
}
