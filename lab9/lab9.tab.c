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
#line 19 "lab9.y"

#include "symtable.h"
#include "ast.h"
#include "emit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



extern int yylex();
extern int mydebug;
extern int linecount;
 
int LEVEL = 0; //how may compound statements deep we are in 
int maxoffset; //total number of words a function has
int OFFSET = 0; //how many words weve seen at a GLOBAL score or INSIDE a function
int GOFFSET = 0; //holder for global offset when we enter and exit a funtion def


void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s at line %d\n", s, linecount);
}



#line 100 "lab9.tab.c"

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

#include "lab9.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_ID = 3,                       /* T_ID  */
  YYSYMBOL_T_STRING = 4,                   /* T_STRING  */
  YYSYMBOL_T_NUM = 5,                      /* T_NUM  */
  YYSYMBOL_T_BOOLEAN = 6,                  /* T_BOOLEAN  */
  YYSYMBOL_T_INT = 7,                      /* T_INT  */
  YYSYMBOL_T_READ = 8,                     /* T_READ  */
  YYSYMBOL_T_RETURN = 9,                   /* T_RETURN  */
  YYSYMBOL_T_VOID = 10,                    /* T_VOID  */
  YYSYMBOL_T_WRITE = 11,                   /* T_WRITE  */
  YYSYMBOL_T_BEGIN = 12,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 13,                     /* T_END  */
  YYSYMBOL_T_AND = 14,                     /* T_AND  */
  YYSYMBOL_T_OR = 15,                      /* T_OR  */
  YYSYMBOL_T_TRUE = 16,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 17,                   /* T_FALSE  */
  YYSYMBOL_T_NOT = 18,                     /* T_NOT  */
  YYSYMBOL_T_EQ = 19,                      /* T_EQ  */
  YYSYMBOL_T_GE = 20,                      /* T_GE  */
  YYSYMBOL_T_GT = 21,                      /* T_GT  */
  YYSYMBOL_T_LE = 22,                      /* T_LE  */
  YYSYMBOL_T_LT = 23,                      /* T_LT  */
  YYSYMBOL_T_NE = 24,                      /* T_NE  */
  YYSYMBOL_T_IF = 25,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 26,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 27,                   /* T_WHILE  */
  YYSYMBOL_T_ENDIF = 28,                   /* T_ENDIF  */
  YYSYMBOL_T_DO = 29,                      /* T_DO  */
  YYSYMBOL_T_THEN = 30,                    /* T_THEN  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '['  */
  YYSYMBOL_33_ = 33,                       /* ']'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_Declaration_List = 44,          /* Declaration_List  */
  YYSYMBOL_Declaration = 45,               /* Declaration  */
  YYSYMBOL_Var_Declaration = 46,           /* Var_Declaration  */
  YYSYMBOL_Var_List = 47,                  /* Var_List  */
  YYSYMBOL_Type_Specifier = 48,            /* Type_Specifier  */
  YYSYMBOL_Fun_Declaration = 49,           /* Fun_Declaration  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_Params = 52,                    /* Params  */
  YYSYMBOL_Param_List = 53,                /* Param_List  */
  YYSYMBOL_Param = 54,                     /* Param  */
  YYSYMBOL_Compound_Stmt = 55,             /* Compound_Stmt  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_Local_Declarations = 57,        /* Local_Declarations  */
  YYSYMBOL_Statement_List = 58,            /* Statement_List  */
  YYSYMBOL_Statement = 59,                 /* Statement  */
  YYSYMBOL_Expression_Stmt = 60,           /* Expression_Stmt  */
  YYSYMBOL_Selection_Stmt = 61,            /* Selection_Stmt  */
  YYSYMBOL_Iteration_Stmt = 62,            /* Iteration_Stmt  */
  YYSYMBOL_Assignment_Stmt = 63,           /* Assignment_Stmt  */
  YYSYMBOL_Return_Stmt = 64,               /* Return_Stmt  */
  YYSYMBOL_Write_Stmt = 65,                /* Write_Stmt  */
  YYSYMBOL_Read_Stmt = 66,                 /* Read_Stmt  */
  YYSYMBOL_VARIABLE = 67,                  /* VARIABLE  */
  YYSYMBOL_Expr = 68,                      /* Expr  */
  YYSYMBOL_Simple_Expression = 69,         /* Simple_Expression  */
  YYSYMBOL_Rel_Op = 70,                    /* Rel_Op  */
  YYSYMBOL_Additive_Expression = 71,       /* Additive_Expression  */
  YYSYMBOL_Add_Op = 72,                    /* Add_Op  */
  YYSYMBOL_Term = 73,                      /* Term  */
  YYSYMBOL_Mult_Op = 74,                   /* Mult_Op  */
  YYSYMBOL_Factor = 75,                    /* Factor  */
  YYSYMBOL_CALL = 76,                      /* CALL  */
  YYSYMBOL_Args = 77,                      /* Args  */
  YYSYMBOL_Arg_list = 78                   /* Arg_list  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      35,    36,    40,    38,    34,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    96,   100,   107,   109,   113,   126,   143,
     158,   173,   189,   190,   191,   195,   211,   194,   227,   229,
     233,   235,   240,   256,   272,   272,   286,   291,   295,   296,
     302,   304,   306,   308,   310,   312,   314,   316,   320,   323,
     327,   333,   344,   351,   367,   371,   377,   382,   387,   411,
     442,   446,   448,   464,   465,   466,   467,   468,   469,   472,
     474,   492,   493,   496,   498,   513,   514,   515,   516,   519,
     521,   526,   529,   531,   533,   547,   551,   557,   588,   591,
     594,   602
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
  "\"end of file\"", "error", "\"invalid token\"", "T_ID", "T_STRING",
  "T_NUM", "T_BOOLEAN", "T_INT", "T_READ", "T_RETURN", "T_VOID", "T_WRITE",
  "T_BEGIN", "T_END", "T_AND", "T_OR", "T_TRUE", "T_FALSE", "T_NOT",
  "T_EQ", "T_GE", "T_GT", "T_LE", "T_LT", "T_NE", "T_IF", "T_ELSE",
  "T_WHILE", "T_ENDIF", "T_DO", "T_THEN", "';'", "'['", "']'", "','",
  "'('", "')'", "'='", "'+'", "'-'", "'*'", "'/'", "$accept", "Program",
  "Declaration_List", "Declaration", "Var_Declaration", "Var_List",
  "Type_Specifier", "Fun_Declaration", "$@1", "$@2", "Params",
  "Param_List", "Param", "Compound_Stmt", "$@3", "Local_Declarations",
  "Statement_List", "Statement", "Expression_Stmt", "Selection_Stmt",
  "Iteration_Stmt", "Assignment_Stmt", "Return_Stmt", "Write_Stmt",
  "Read_Stmt", "VARIABLE", "Expr", "Simple_Expression", "Rel_Op",
  "Additive_Expression", "Add_Op", "Term", "Mult_Op", "Factor", "CALL",
  "Args", "Arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      23,   -67,   -67,   -67,     4,   -67,    23,   -67,    28,   -67,
     -67,   -67,    19,    -5,    47,    61,   -67,   -67,    33,   -12,
     -67,    55,    34,    56,    88,    57,   -67,    60,    61,    63,
     -67,    23,   -67,    64,    84,   -67,   -67,   -67,   -67,    23,
      23,    61,     7,   -67,    44,   -67,   -67,    95,    32,    40,
     -67,   -67,    40,    40,    40,   -67,    40,   -67,    86,     7,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,    65,    69,    66,
      42,    -1,   -67,   -67,    40,    40,    71,    70,   -67,   -67,
      73,    74,   -67,    76,    78,    72,   -67,   -67,    40,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,    40,   -67,   -67,    40,
     -67,   -67,   -67,   -67,    40,    77,    75,    79,   -67,   -67,
     -67,   -67,     7,     7,   -67,    80,    42,    -1,   -67,   -67,
      40,   -67,    46,   -67,   -67,   -67,     7,   -67,    85,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    13,    12,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,    15,     7,     0,     8,
      10,     0,     9,    14,     0,     0,    19,    20,     0,    22,
      16,     0,    11,     0,     0,    21,    23,    24,    17,    27,
      27,     0,    28,    26,    48,    71,    70,     0,     0,     0,
      76,    75,     0,     0,     0,    39,     0,    31,     0,    28,
      30,    32,    33,    34,    35,    37,    36,    72,     0,    50,
      51,    59,    63,    73,     0,    79,    48,     0,    45,    72,
       0,     0,    74,     0,     0,     0,    25,    29,     0,    38,
      57,    56,    55,    53,    54,    58,     0,    61,    62,     0,
      67,    68,    65,    66,     0,     0,    81,     0,    78,    47,
      44,    46,     0,     0,    69,     0,    52,    60,    64,    49,
       0,    77,     0,    42,    43,    80,     0,    40,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   106,   -67,    43,    -7,    38,   -67,   -67,   -67,
     -67,    83,   -67,    82,   -67,    81,    58,   -66,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -42,   -47,   -67,   -67,    22,
     -67,    20,   -67,   -49,   -67,   -67,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    13,     8,     9,    21,    34,
      25,    26,    27,    57,    39,    42,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    79,    68,    69,    96,    70,
      99,    71,   104,    72,    73,   107,   108
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    80,    81,    82,    10,    77,    83,    84,    20,    85,
      44,    45,    46,   100,   101,    47,    48,    67,    49,    37,
      14,    32,    15,    50,    51,    52,    17,   105,   106,     1,
       2,    12,    53,     3,    54,    44,    45,    46,    55,   102,
     103,   115,    56,    44,    45,    46,   122,   123,    50,    51,
      52,    14,    18,    15,    16,   118,    50,    51,    52,    24,
     128,     1,     2,    78,    19,    23,    22,    56,    28,    24,
      67,    67,   126,   106,   127,    56,    74,    41,    41,    75,
      97,    98,    40,    40,    67,    90,    91,    92,    93,    94,
      95,    29,   -18,    30,    31,    33,    37,    36,    76,    86,
      89,   109,    88,    74,   110,   111,   112,   113,   114,   120,
     119,   124,    11,   129,    35,   121,    38,    87,   116,   117,
     125,    43
};

static const yytype_int8 yycheck[] =
{
      42,    48,    49,    52,     0,    47,    53,    54,    15,    56,
       3,     4,     5,    14,    15,     8,     9,    59,    11,    12,
      32,    28,    34,    16,    17,    18,    31,    74,    75,     6,
       7,     3,    25,    10,    27,     3,     4,     5,    31,    40,
      41,    88,    35,     3,     4,     5,   112,   113,    16,    17,
      18,    32,     5,    34,    35,   104,    16,    17,    18,    21,
     126,     6,     7,    31,     3,    10,    33,    35,    34,    31,
     112,   113,    26,   120,    28,    35,    32,    39,    40,    35,
      38,    39,    39,    40,   126,    19,    20,    21,    22,    23,
      24,     3,    36,    36,    34,    32,    12,    33,     3,    13,
      31,    31,    37,    32,    31,    31,    30,    29,    36,    34,
      33,    31,     6,    28,    31,    36,    34,    59,    96,    99,
     120,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    10,    43,    44,    45,    46,    48,    49,
       0,    44,     3,    47,    32,    34,    35,    31,     5,     3,
      47,    50,    33,    10,    48,    52,    53,    54,    34,     3,
      36,    34,    47,    32,    51,    53,    33,    12,    55,    56,
      46,    48,    57,    57,     3,     4,     5,     8,     9,    11,
      16,    17,    18,    25,    27,    31,    35,    55,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      71,    73,    75,    76,    32,    35,     3,    67,    31,    67,
      68,    68,    75,    68,    68,    68,    13,    58,    37,    31,
      19,    20,    21,    22,    23,    24,    70,    38,    39,    72,
      14,    15,    40,    41,    74,    68,    68,    77,    78,    31,
      31,    31,    30,    29,    36,    68,    71,    73,    75,    33,
      34,    36,    59,    59,    31,    78,    26,    28,    59,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      47,    47,    48,    48,    48,    50,    51,    49,    52,    52,
      53,    53,    54,    54,    56,    55,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    63,    64,    64,    65,    66,    67,    67,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    77,    77,
      78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     0,     8,     1,     1,
       1,     3,     2,     4,     0,     5,     2,     0,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     4,     4,     3,     2,     3,     3,     1,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     4,     1,     0,
       3,     1
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
  case 2: /* Program: Declaration_List  */
#line 91 "lab9.y"
        { program = (yyvsp[0].node);
        }
#line 1257 "lab9.tab.c"
    break;

  case 3: /* Declaration_List: Declaration  */
#line 97 "lab9.y"
                        {(yyval.node) = ASTCreateNode(A_DECLARATION_LIST);
                         (yyval.node)->s1 = (yyvsp[0].node);
                        }
#line 1265 "lab9.tab.c"
    break;

  case 4: /* Declaration_List: Declaration Declaration_List  */
#line 101 "lab9.y"
                        {(yyval.node) = ASTCreateNode(A_DECLARATION_LIST);
                         (yyval.node)->s1 = (yyvsp[-1].node);
                         (yyval.node)->s2 = (yyvsp[0].node);
                        }
#line 1274 "lab9.tab.c"
    break;

  case 5: /* Declaration: Var_Declaration  */
#line 108 "lab9.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1280 "lab9.tab.c"
    break;

  case 6: /* Declaration: Fun_Declaration  */
#line 110 "lab9.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1286 "lab9.tab.c"
    break;

  case 7: /* Var_Declaration: Type_Specifier Var_List ';'  */
#line 114 "lab9.y"
                {
                  (yyval.node) = (yyvsp[-1].node);
                  ASTnode* p;
                  p = (yyvsp[-1].node);
                 while(p != NULL){
                    p -> symbol -> Declared_Type = (yyvsp[-2].datatype);
                    p = p -> s1; //move to next variable in the list
                 }
                 (yyval.node) = (yyvsp[-1].node);}
#line 1300 "lab9.tab.c"
    break;

  case 8: /* Var_List: T_ID  */
#line 127 "lab9.y"
              {if(Search((yyvsp[0].string), LEVEL, 0) == NULL){
                //if symbol is not present, insert it into the table!
                 
              {(yyval.node) = ASTCreateNode(A_VARDEC);
                (yyval.node)-> name = (yyvsp[0].string);
                (yyval.node) -> value = 0;
                (yyval.node) -> symbol = Insert((yyvsp[0].string), A_UNKNOWN, SYM_SCALAR, LEVEL, 1, OFFSET);
                OFFSET += 1;
              }}
              else{
                yyerror((yyvsp[0].string));
                yyerror("Error: Already defined variable");
                exit(1);
              }
                
                }
#line 1321 "lab9.tab.c"
    break;

  case 9: /* Var_List: T_ID '[' T_NUM ']'  */
#line 144 "lab9.y"
            {if(Search((yyvsp[-3].string), LEVEL, 0) == NULL){
                //if symbol is not present, insert it into the table!

              (yyval.node) = ASTCreateNode(A_VARDEC);
              (yyval.node) -> name = (yyvsp[-3].string);
              (yyval.node)-> value = (yyvsp[-1].value); //points to a value (t_num)
              (yyval.node) -> symbol = Insert((yyvsp[-3].string), A_UNKNOWN, SYM_ARRAY, LEVEL, (yyvsp[-1].value), OFFSET);
              OFFSET += (yyvsp[-1].value);
            }
              else{
                yyerror((yyvsp[-3].string));
                yyerror("Error: Already defined variable");
                exit(1);}}
#line 1339 "lab9.tab.c"
    break;

  case 10: /* Var_List: T_ID ',' Var_List  */
#line 159 "lab9.y"
            {if(Search((yyvsp[-2].string), LEVEL, 0) == NULL){
                //if symbol is not present, insert it into the table!
                (yyval.node) = ASTCreateNode(A_VARDEC);
              (yyval.node) -> name = (yyvsp[-2].string);
              (yyval.node) -> s1 = (yyvsp[0].node);
              (yyval.node) -> symbol = Insert((yyvsp[-2].string), A_UNKNOWN, SYM_SCALAR, LEVEL, 1, OFFSET);
              OFFSET += 1;} 
              else{
                yyerror((yyvsp[-2].string));
                yyerror("Error: Already defined variable");
                exit(1);}}
#line 1355 "lab9.tab.c"
    break;

  case 11: /* Var_List: T_ID '[' T_NUM ']' ',' Var_List  */
#line 174 "lab9.y"
            {
              if(Search((yyvsp[-5].string), LEVEL, 0) == NULL){
                //if symbol is not present, insert it into the table!
              (yyval.node) = ASTCreateNode(A_VARDEC);
              (yyval.node) -> name = (yyvsp[-5].string);
              (yyval.node) -> value = (yyvsp[-3].value); 
              (yyval.node) -> s1 = (yyvsp[0].node); //points to next variable in the list (recursion)
              (yyval.node) -> symbol = Insert((yyvsp[-5].string), A_UNKNOWN, SYM_ARRAY, LEVEL, (yyvsp[-3].value), OFFSET);
              OFFSET += (yyvsp[-3].value);}
            else{
              yyerror((yyvsp[-5].string));
              yyerror("Error: Already defined variable");
              exit(1);}}
#line 1373 "lab9.tab.c"
    break;

  case 12: /* Type_Specifier: T_INT  */
#line 189 "lab9.y"
                        { (yyval.datatype) = A_INTTYPE;}
#line 1379 "lab9.tab.c"
    break;

  case 13: /* Type_Specifier: T_BOOLEAN  */
#line 190 "lab9.y"
                            { (yyval.datatype) = A_BOOLEANTYPE;}
#line 1385 "lab9.tab.c"
    break;

  case 14: /* Type_Specifier: T_VOID  */
#line 191 "lab9.y"
                             { (yyval.datatype) = A_VOIDTYPE;}
#line 1391 "lab9.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 195 "lab9.y"
          { //check to see if function name is known, if it is, bard
            //else, insert in smbol table
            //manage offset of value
             if(Search((yyvsp[-1].string), LEVEL, 0) == NULL){
               Insert((yyvsp[-1].string), (yyvsp[-2].datatype), SYM_FUNCTION, LEVEL, 0, 0);
               GOFFSET = OFFSET;
               OFFSET = 2;  // Start at 2 for function
               maxoffset = OFFSET;

             }else{
              yyerror((yyvsp[-1].string));
              yyerror("Error: Function name already defined");
              exit(1);
             }
            
          }
#line 1412 "lab9.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 211 "lab9.y"
          {
            //update symble table with param
            //allows us to have recursive functions
            Search((yyvsp[-4].string), LEVEL, 1) -> fparms = (yyvsp[-1].node);
          }
#line 1422 "lab9.tab.c"
    break;

  case 17: /* Fun_Declaration: Type_Specifier T_ID '(' $@1 Params ')' $@2 Compound_Stmt  */
#line 217 "lab9.y"
           {(yyval.node) = ASTCreateNode(A_FUNDEC);
            (yyval.node)-> name = (yyvsp[-6].string);
            (yyval.node)-> datatype = (yyvsp[-7].datatype); 
            (yyval.node) -> s1 = (yyvsp[-3].node); //  params 
            (yyval.node) -> s2 = (yyvsp[0].node);
            (yyval.node) -> symbol = Search((yyvsp[-6].string),LEVEL,0);
            (yyval.node) -> symbol -> offset = maxoffset;
            }
#line 1435 "lab9.tab.c"
    break;

  case 18: /* Params: T_VOID  */
#line 228 "lab9.y"
        {(yyval.node) = NULL;}
#line 1441 "lab9.tab.c"
    break;

  case 19: /* Params: Param_List  */
#line 230 "lab9.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 1447 "lab9.tab.c"
    break;

  case 20: /* Param_List: Param  */
#line 234 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1453 "lab9.tab.c"
    break;

  case 21: /* Param_List: Param ',' Param_List  */
#line 236 "lab9.y"
                { (yyval.node) = ASTCreateNode(A_PARAM_LIST); // create a node to hold the param list
                  (yyval.node) -> s1 = (yyvsp[-2].node);
                  (yyval.node) -> s2 = (yyvsp[0].node);}
#line 1461 "lab9.tab.c"
    break;

  case 22: /* Param: Type_Specifier T_ID  */
#line 241 "lab9.y"
        { 
          (yyval.node) = ASTCreateNode(A_PARAM);
          (yyval.node) -> datatype = (yyvsp[-1].datatype);
          (yyval.node) -> name = (yyvsp[0].string);


          if(Search((yyvsp[0].string), 1, 0) == NULL){
          (yyval.node) -> symbol = Insert((yyvsp[0].string), (yyvsp[-1].datatype), SYM_SCALAR, 1, 1, OFFSET);
          OFFSET += 1;
          }else{
            yyerror((yyvsp[0].string));
            yyerror("Error: Parameter name already used");
            exit(1);
          }}
#line 1480 "lab9.tab.c"
    break;

  case 23: /* Param: Type_Specifier T_ID '[' ']'  */
#line 257 "lab9.y"
        { (yyval.node) = ASTCreateNode(A_PARAM);
          (yyval.node) -> datatype = (yyvsp[-3].datatype);
          (yyval.node) -> name = (yyvsp[-2].string);
          (yyval.node) -> value = 1;
          if(Search((yyvsp[-2].string), 1, 0) == NULL){
          // insert parameters at level 1 
          (yyval.node) -> symbol = Insert((yyvsp[-2].string), (yyvsp[-3].datatype), SYM_ARRAY, 1, 1, OFFSET);
          OFFSET += 1;
          }else{
            yyerror((yyvsp[-2].string));
            yyerror("Error: Parameter name already used");
            exit(1);
          }}
#line 1498 "lab9.tab.c"
    break;

  case 24: /* $@3: %empty  */
#line 272 "lab9.y"
                          {LEVEL++;}
#line 1504 "lab9.tab.c"
    break;

  case 25: /* Compound_Stmt: T_BEGIN $@3 Local_Declarations Statement_List T_END  */
#line 274 "lab9.y"
                {(yyval.node) = ASTCreateNode(A_COMPOUNDSTMT);
                 (yyval.node) ->s1 = (yyvsp[-2].node);
                 (yyval.node) -> s2 = (yyvsp[-1].node);
                 if(OFFSET > maxoffset){
                  maxoffset = OFFSET;
                 }
                 Display();
                 OFFSET -= Delete(LEVEL);
                 LEVEL--;
                 }
#line 1519 "lab9.tab.c"
    break;

  case 26: /* Local_Declarations: Var_Declaration Local_Declarations  */
#line 287 "lab9.y"
                        {(yyval.node) = ASTCreateNode(A_DECLARATION_LIST);
                         (yyval.node) -> s1 = (yyvsp[-1].node);
                         (yyval.node) -> s2 = (yyvsp[0].node);}
#line 1527 "lab9.tab.c"
    break;

  case 27: /* Local_Declarations: %empty  */
#line 291 "lab9.y"
                    {(yyval.node) = NULL;}
#line 1533 "lab9.tab.c"
    break;

  case 28: /* Statement_List: %empty  */
#line 295 "lab9.y"
                {(yyval.node) = NULL;}
#line 1539 "lab9.tab.c"
    break;

  case 29: /* Statement_List: Statement Statement_List  */
#line 297 "lab9.y"
                {(yyval.node) = ASTCreateNode(A_STMT_LIST);
                 (yyval.node) -> s1 = (yyvsp[-1].node);
                 (yyval.node) -> s2 = (yyvsp[0].node);}
#line 1547 "lab9.tab.c"
    break;

  case 30: /* Statement: Expression_Stmt  */
#line 303 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1553 "lab9.tab.c"
    break;

  case 31: /* Statement: Compound_Stmt  */
#line 305 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1559 "lab9.tab.c"
    break;

  case 32: /* Statement: Selection_Stmt  */
#line 307 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1565 "lab9.tab.c"
    break;

  case 33: /* Statement: Iteration_Stmt  */
#line 309 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1571 "lab9.tab.c"
    break;

  case 34: /* Statement: Assignment_Stmt  */
#line 311 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1577 "lab9.tab.c"
    break;

  case 35: /* Statement: Return_Stmt  */
#line 313 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1583 "lab9.tab.c"
    break;

  case 36: /* Statement: Read_Stmt  */
#line 315 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1589 "lab9.tab.c"
    break;

  case 37: /* Statement: Write_Stmt  */
#line 317 "lab9.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1595 "lab9.tab.c"
    break;

  case 38: /* Expression_Stmt: Expr ';'  */
#line 321 "lab9.y"
                {(yyval.node) = ASTCreateNode(A_EXPR_STMT);
                 (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1602 "lab9.tab.c"
    break;

  case 39: /* Expression_Stmt: ';'  */
#line 324 "lab9.y"
                {(yyval.node) = NULL;}
#line 1608 "lab9.tab.c"
    break;

  case 40: /* Selection_Stmt: T_IF Expr T_THEN Statement T_ENDIF  */
#line 328 "lab9.y"
                {  (yyval.node) = ASTCreateNode(A_SELECT); //node to hold if and then statements
                   (yyval.node) -> s1 = (yyvsp[-3].node);    
                   (yyval.node) -> s2 = (yyvsp[-1].node);    
                   (yyval.node) -> value = 0;  // to signify there is no 'else' 
                }
#line 1618 "lab9.tab.c"
    break;

  case 41: /* Selection_Stmt: T_IF Expr T_THEN Statement T_ELSE Statement T_ENDIF  */
#line 334 "lab9.y"
                {  (yyval.node) = ASTCreateNode(A_SELECT);
                   (yyval.node) -> s1 = (yyvsp[-5].node);    // condition
                   ASTnode * p = ASTCreateNode(A_STMT_LIST);   // node to hold if and then/else statements (because we're only using s1 and s2)
                   p -> s1 = (yyvsp[-3].node);  
                   p -> s2 = (yyvsp[-1].node);   
                   (yyval.node) -> s2 = p; 
                   (yyval.node) -> value = 1; // to signify there is an 'else' part
                }
#line 1631 "lab9.tab.c"
    break;

  case 42: /* Iteration_Stmt: T_WHILE Expr T_DO Statement  */
#line 345 "lab9.y"
                { (yyval.node) = ASTCreateNode(A_ITERATION);
                  (yyval.node) -> s1 = (yyvsp[-2].node); //condition
                  (yyval.node) -> s2 = (yyvsp[0].node); //statement 
                }
#line 1640 "lab9.tab.c"
    break;

  case 43: /* Assignment_Stmt: VARIABLE '=' Expr ';'  */
#line 352 "lab9.y"
                { 
                   (yyval.node) = ASTCreateNode(A_ASSIGNSTMT);
                  (yyval.node) -> s1 = (yyvsp[-3].node);
                  (yyval.node) -> s2 = (yyvsp[-1].node);
                  (yyval.node) -> operator = A_ASSIGN;

                  if((yyvsp[-3].node) -> datatype != (yyvsp[-1].node) -> datatype){
                  yyerror("Error: Must be the same datatype");
                  exit(1);
                  }
                  (yyval.node) ->datatype = (yyvsp[-3].node)->datatype;
                  (yyval.node) -> symbol = Insert(CreateTemp(), (yyval.node) -> datatype, SYM_SCALAR, LEVEL, 1, OFFSET);
                  OFFSET += 1;}
#line 1658 "lab9.tab.c"
    break;

  case 44: /* Return_Stmt: T_RETURN Expr ';'  */
#line 368 "lab9.y"
                { (yyval.node) = ASTCreateNode(A_RETURN);
                  (yyval.node)-> s1 = (yyvsp[-1].node);  
                }
#line 1666 "lab9.tab.c"
    break;

  case 45: /* Return_Stmt: T_RETURN ';'  */
#line 372 "lab9.y"
                { (yyval.node) = ASTCreateNode(A_RETURN);
                  (yyval.node)-> s1 = NULL; 
                }
#line 1674 "lab9.tab.c"
    break;

  case 46: /* Write_Stmt: T_WRITE Expr ';'  */
#line 378 "lab9.y"
                { (yyval.node) = ASTCreateNode(A_WRITE);
                  (yyval.node)-> s1 = (yyvsp[-1].node);  
                }
#line 1682 "lab9.tab.c"
    break;

  case 47: /* Read_Stmt: T_READ VARIABLE ';'  */
#line 383 "lab9.y"
                { (yyval.node) = ASTCreateNode(A_READ);
                  (yyval.node)-> s1 = (yyvsp[-1].node);}
#line 1689 "lab9.tab.c"
    break;

  case 48: /* VARIABLE: T_ID  */
#line 388 "lab9.y"
              {
                struct SymbTab *p;
                p = Search((yyvsp[0].string), LEVEL, 1); //variable to make searching more efficient
                if(p == NULL)
                {
                  yyerror((yyvsp[0].string));
                  yyerror("Error: Variable doesn't exist");
                  exit(1);
                }
                // if it's the wrong subtype, barf 
                if(p->SubType != SYM_SCALAR)
                {
                  yyerror((yyvsp[0].string));
                  yyerror("Error: Variable has wrong subtype");
                  exit(1);
                }
                // proceed if no errors 
                (yyval.node) = ASTCreateNode(A_VARIABLE);
                (yyval.node) -> name = (yyvsp[0].string);
                (yyval.node) -> symbol = p;
                (yyval.node) -> datatype = p -> Declared_Type;
              }
#line 1716 "lab9.tab.c"
    break;

  case 49: /* VARIABLE: T_ID '[' Expr ']'  */
#line 412 "lab9.y"
              {
                struct SymbTab *p;
                p = Search((yyvsp[-3].string), LEVEL, 1);
                if(p == NULL)
                {
                  yyerror((yyvsp[-3].string));
                  yyerror("Error: Variable doesn't exist in symbol table");
                  exit(1);
                }
                // make sure it's an array 
                if(p->SubType != SYM_ARRAY)
                {
                  yyerror((yyvsp[-3].string));
                  yyerror("Error: Variable has wrong subtype, should be an array");
                  exit(1);
                }
                if ((yyvsp[-1].node)-> datatype != A_INTTYPE){
                  yyerror((yyvsp[-3].string));
                  yyerror("Error: Array index should be an integer");
                  exit(1);
                }
                (yyval.node) = ASTCreateNode(A_VARIABLE);
                (yyval.node)->name = (yyvsp[-3].string);
                (yyval.node)->s1 = (yyvsp[-1].node); //index expression
                (yyval.node)->symbol = p;
                (yyval.node) -> symbol = p;
                (yyval.node) -> datatype = p -> Declared_Type;
              }
#line 1749 "lab9.tab.c"
    break;

  case 50: /* Expr: Simple_Expression  */
#line 443 "lab9.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 1755 "lab9.tab.c"
    break;

  case 51: /* Simple_Expression: Additive_Expression  */
#line 447 "lab9.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1761 "lab9.tab.c"
    break;

  case 52: /* Simple_Expression: Simple_Expression Rel_Op Additive_Expression  */
#line 449 "lab9.y"
                    {
                      if((yyvsp[-2].node)->datatype != (yyvsp[0].node)->datatype)
                      {
                        yyerror("Mismatching types on expression");
                        exit(1);
                      }
                     (yyval.node) = ASTCreateNode(A_EXPR);
                     (yyval.node) -> s1 = (yyvsp[-2].node);
                     (yyval.node) -> s2 = (yyvsp[0].node);
                     (yyval.node) -> operator = (yyvsp[-1].operator);
                     (yyval.node) -> datatype = A_BOOLEAN;
                     (yyval.node) -> symbol = Insert(CreateTemp(), (yyval.node) -> datatype, SYM_SCALAR, LEVEL, 1, OFFSET);
                     OFFSET += 1;}
#line 1779 "lab9.tab.c"
    break;

  case 53: /* Rel_Op: T_LE  */
#line 464 "lab9.y"
               { (yyval.operator) = A_LE; }
#line 1785 "lab9.tab.c"
    break;

  case 54: /* Rel_Op: T_LT  */
#line 465 "lab9.y"
               { (yyval.operator) = A_LT; }
#line 1791 "lab9.tab.c"
    break;

  case 55: /* Rel_Op: T_GT  */
#line 466 "lab9.y"
               { (yyval.operator) = A_GT; }
#line 1797 "lab9.tab.c"
    break;

  case 56: /* Rel_Op: T_GE  */
#line 467 "lab9.y"
               { (yyval.operator) = A_GE; }
#line 1803 "lab9.tab.c"
    break;

  case 57: /* Rel_Op: T_EQ  */
#line 468 "lab9.y"
               { (yyval.operator) = A_EQ; }
#line 1809 "lab9.tab.c"
    break;

  case 58: /* Rel_Op: T_NE  */
#line 469 "lab9.y"
               { (yyval.operator) = A_NE; }
#line 1815 "lab9.tab.c"
    break;

  case 59: /* Additive_Expression: Term  */
#line 473 "lab9.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1821 "lab9.tab.c"
    break;

  case 60: /* Additive_Expression: Additive_Expression Add_Op Term  */
#line 475 "lab9.y"
                    {
                      if((yyvsp[-2].node)->datatype != (yyvsp[0].node)->datatype)
                      {
                        yyerror("Mismatching types on expression");
                        exit(1);
                      }

                     (yyval.node) = ASTCreateNode(A_EXPR);
                     (yyval.node) -> s1 = (yyvsp[-2].node);
                     (yyval.node) -> s2 = (yyvsp[0].node);
                     (yyval.node) -> operator = (yyvsp[-1].operator);
                     (yyval.node) -> datatype = (yyvsp[-2].node)->datatype;
                     (yyval.node) -> symbol = Insert(CreateTemp(), (yyvsp[-2].node)->datatype, SYM_SCALAR, LEVEL, 1,OFFSET); 
                     OFFSET += 1;}
#line 1840 "lab9.tab.c"
    break;

  case 61: /* Add_Op: '+'  */
#line 492 "lab9.y"
              {(yyval.operator) = A_PLUS;}
#line 1846 "lab9.tab.c"
    break;

  case 62: /* Add_Op: '-'  */
#line 493 "lab9.y"
              {(yyval.operator) = A_MINUS;}
#line 1852 "lab9.tab.c"
    break;

  case 63: /* Term: Factor  */
#line 497 "lab9.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 1858 "lab9.tab.c"
    break;

  case 64: /* Term: Term Mult_Op Factor  */
#line 499 "lab9.y"
        {
          if((yyvsp[-2].node)->datatype != (yyvsp[0].node)->datatype){
            yyerror("Mismatching types on expression");
            exit(1);
          }
          (yyval.node) = ASTCreateNode(A_EXPR);
          (yyval.node) -> s1 = (yyvsp[-2].node);
          (yyval.node) -> s2 = (yyvsp[0].node);
          (yyval.node) -> operator = (yyvsp[-1].operator);
          (yyval.node)->datatype = (yyvsp[-2].node)->datatype;
          (yyval.node)->symbol = Insert(CreateTemp(), (yyvsp[-2].node)->datatype, SYM_SCALAR, LEVEL, 1,OFFSET);
          OFFSET = OFFSET + 1;}
#line 1875 "lab9.tab.c"
    break;

  case 65: /* Mult_Op: '*'  */
#line 513 "lab9.y"
              {(yyval.operator) = A_TIMES;}
#line 1881 "lab9.tab.c"
    break;

  case 66: /* Mult_Op: '/'  */
#line 514 "lab9.y"
              {(yyval.operator) = A_DIVIDE;}
#line 1887 "lab9.tab.c"
    break;

  case 67: /* Mult_Op: T_AND  */
#line 515 "lab9.y"
               {(yyval.operator) = A_AND;}
#line 1893 "lab9.tab.c"
    break;

  case 68: /* Mult_Op: T_OR  */
#line 516 "lab9.y"
              {(yyval.operator) = A_OR;}
#line 1899 "lab9.tab.c"
    break;

  case 69: /* Factor: '(' Expr ')'  */
#line 520 "lab9.y"
        {(yyval.node) = (yyvsp[-1].node);}
#line 1905 "lab9.tab.c"
    break;

  case 70: /* Factor: T_NUM  */
#line 522 "lab9.y"
        {(yyval.node) = ASTCreateNode(A_NUM);
         (yyval.node)-> value = (yyvsp[0].value);
         (yyval.node)->datatype = A_INTTYPE;
        }
#line 1914 "lab9.tab.c"
    break;

  case 71: /* Factor: T_STRING  */
#line 527 "lab9.y"
        {(yyval.node) = ASTCreateNode(A_STRING);
         (yyval.node)-> name = (yyvsp[0].string);}
#line 1921 "lab9.tab.c"
    break;

  case 72: /* Factor: VARIABLE  */
#line 530 "lab9.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 1927 "lab9.tab.c"
    break;

  case 73: /* Factor: CALL  */
#line 532 "lab9.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 1933 "lab9.tab.c"
    break;

  case 74: /* Factor: T_NOT Factor  */
#line 534 "lab9.y"
        {
          if((yyvsp[0].node)->datatype != A_BOOLEANTYPE)
          {
            yyerror((yyvsp[0].node));
            yyerror("Error: NOT operator expects boolean");
            exit(1);

          }
          (yyval.node) = ASTCreateNode(A_EXPR); 
          (yyval.node) -> operator = A_NOT;
          (yyval.node) -> s1 = (yyvsp[0].node);
          (yyval.node) -> datatype = (yyvsp[0].node) -> datatype;
        }
#line 1951 "lab9.tab.c"
    break;

  case 75: /* Factor: T_FALSE  */
#line 548 "lab9.y"
        {(yyval.node) = ASTCreateNode(A_BOOLEAN);
         (yyval.node)-> value = 0;
         (yyval.node)->datatype = A_BOOLEANTYPE;}
#line 1959 "lab9.tab.c"
    break;

  case 76: /* Factor: T_TRUE  */
#line 552 "lab9.y"
        {(yyval.node) = ASTCreateNode(A_BOOLEAN);
         (yyval.node)-> value = 1;
         (yyval.node)->datatype = A_BOOLEANTYPE;}
#line 1967 "lab9.tab.c"
    break;

  case 77: /* CALL: T_ID '(' Args ')'  */
#line 558 "lab9.y"
        { //check if its in the symtabble
          struct SymbTab *p;
          p = Search((yyvsp[-3].string), 0, 0);
          if(p == NULL)
          {
            yyerror((yyvsp[-3].string));
            yyerror("Error: Function doesn't exist in symbol table");
            exit(1);
          }
          if(p-> SubType != SYM_FUNCTION)
          {
            yyerror((yyvsp[-3].string));
            yyerror("Error: This is not a function");
            exit(1);
          }
          //check to see if actual and formals match in length and type
          if(check_params(p->fparms,(yyvsp[-1].node)) == 0)
          {
            yyerror((yyvsp[-3].string));
            yyerror("Error: Parameter usage is incorrect");
            exit(1);
          }
          (yyval.node) = ASTCreateNode(A_CALL);
          (yyval.node)-> name = (yyvsp[-3].string);
          (yyval.node)-> s1 = (yyvsp[-1].node);
          (yyval.node) -> symbol = p;
          (yyval.node) -> datatype = (yyval.node) -> symbol -> Declared_Type;
          }
#line 2000 "lab9.tab.c"
    break;

  case 78: /* Args: Arg_list  */
#line 589 "lab9.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 2006 "lab9.tab.c"
    break;

  case 79: /* Args: %empty  */
#line 591 "lab9.y"
        {(yyval.node) = NULL;}
#line 2012 "lab9.tab.c"
    break;

  case 80: /* Arg_list: Expr ',' Arg_list  */
#line 595 "lab9.y"
                { (yyval.node) = ASTCreateNode(A_ARG_LIST);
                  (yyval.node) -> s1 = (yyvsp[-2].node);
                  (yyval.node) -> s2 = (yyvsp[0].node);
                  (yyval.node)->name = CreateTemp();
                  (yyval.node)->datatype = (yyvsp[-2].node)->datatype;
                  (yyval.node)->symbol = Insert((yyval.node)-> name, (yyvsp[-2].node) -> datatype, SYM_SCALAR, LEVEL, 1, OFFSET);
                  OFFSET += 1;}
#line 2024 "lab9.tab.c"
    break;

  case 81: /* Arg_list: Expr  */
#line 603 "lab9.y"
                {(yyval.node) = ASTCreateNode(A_ARG_LIST);
                 (yyval.node) = (yyvsp[0].node);
                 (yyval.node) -> s2 = NULL;
                 (yyval.node)->name = CreateTemp();
                 (yyval.node)->datatype = (yyvsp[0].node)->datatype;
                 (yyval.node)->symbol = Insert((yyval.node)-> name, (yyvsp[0].node) -> datatype, SYM_SCALAR, LEVEL, 1, OFFSET);
                 OFFSET += 1;}
#line 2036 "lab9.tab.c"
    break;


#line 2040 "lab9.tab.c"

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

#line 612 "lab9.y"
	
//--------------END OF GRAMMAR RULES------------------------------------------------------//




//-------------START OF MAIN PROGRAM------------------------------------------------------//
int main(int argc, char * argv[])
{ 
  FILE *fp = NULL;
  char s[100];


  for(int i = 1; i < argc; i++) 
  {
    if(strcmp("-d",argv[i]) == 0) mydebug = 1;

    if(strcmp("-o",argv[i]) == 0)
    {
       strcpy(s,argv[i+1]);
       strcat(s, ".asm");

       if(mydebug) printf("Opening file %s\n",s);
       fp = fopen(s,"w");

       if(fp == NULL)
       {
          printf("Unable to open %s\n", s);
          exit(1);
       } //end of if fopen

    } //end of strcmp
   
  } //end of loop 

  if(fp ==NULL){
    printf("No Filename provided, must use -o option\n");
    exit(1);}
    
    
    
  
  
  yyparse();
  
  if (mydebug) fprintf(stderr, "The input is syntactically correct\n");

  //we know that var program has to be set to an AST!
  if (mydebug) Display();
  
  EMIT(program,fp);

  //ASTprint(0,program);
  exit(0);
}


  

