/*
Brittany Benedict
September 24, 2025
Lab 5 - CS3730
*/

%{


#include <stdio.h>

extern int yylex();
extern int mydebug;
extern int linecount;

int regs[26];
int base, dlex, lab5,debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s at line %d\n", s, linecount);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */



%start Program

/*  defines the precedence and associativity of operators  */
%union{
	int value;
	char* string;

}
/*  defines the type of the values returned from LEX and used in the grammar  */

%token <string> T_ID T_STRING
%token <value> T_NUM

%token  T_BOOLEAN T_INT T_READ T_RETURN  T_VOID T_WRITE
%token  T_BEGIN T_END T_AND T_OR T_TRUE T_FALSE T_NOT
%token  T_EQ T_GE T_GT T_LE T_LT T_NE
%token  T_IF T_ELSE T_WHILE T_ENDIF T_DO T_THEN





%%	/* end specs, begin rules */

/*  the grammar rules  */

Program : Declaration_List
	;


Declaration_List    : Declaration
                    | Declaration Declaration_List
                    ;

Declaration : Var_Declaration
            | Fun_Declaration
            ;

Var_Declaration : Type_Specifier Var_List ';'
                ;

Var_List    : T_ID {printf("Found ID in Var_List -> T_ID %s %d\n", $1, linecount);}
            | T_ID '['T_NUM']' {printf("Found ID in Var_List -> T_ID %s %d\n", $1, linecount);}
            | T_ID ',' Var_List {printf("Found ID in Var_List -> T_ID %s %d\n", $1, linecount);}
            | T_ID '['T_NUM']' ',' Var_List
            ;

Type_Specifier  : T_INT
                | T_BOOLEAN
                | T_VOID
                ;

Fun_Declaration : Type_Specifier T_ID '(' Params ')' Compound_Stmt
                ;

Params  : T_VOID
        | Param_List
        ;

Param_List  : Param
            | Param ',' Param_List
            ;
Param   : Type_Specifier T_ID 
        | Type_Specifier T_ID '['']'
        ;

Compound_Stmt   : T_BEGIN Local_Declarations Statement_List T_END
                ;

Local_Declarations  : Var_Declaration Local_Declarations
                    | /*empty*/
                    ;

Statement_List  : Statement Statement_List
                | /*empty*/
                ;

Statement   : Expression_Stmt
            | Compound_Stmt
            | Selection_Stmt
            | Iteration_Stmt
            | Assignment_Stmt
            | Return_Stmt
            | Read_Stmt
            | Write_Stmt
            ;

Expression_Stmt : Expr ';'
                | ';'
                ;

Selection_Stmt  : T_IF  Expr T_THEN Statement T_ENDIF
                | T_IF  Expr T_THEN Statement T_ELSE Statement T_ENDIF
                ;

Iteration_Stmt  : T_WHILE Expr T_DO Statement
                ;

Assignment_Stmt : VARIABLE '=' Expr ';'
                ;

Return_Stmt : T_RETURN Expr ';'
            | T_RETURN ';'
            ;

Write_Stmt  : T_WRITE Expr ';'
            | T_WRITE T_STRING ';'
            ;

Read_Stmt   : T_READ VARIABLE ';'
            ;

VARIABLE    : T_ID 
            | T_ID '[' Expr ']'
            ;

Expr    : Simple_Expression
        ;

Simple_Expression   : Additive_Expression
                    | Additive_Expression Rel_Op Additive_Expression
                    ;

Rel_Op  : T_LE
        | T_LT
        | T_GT
        | T_GE
        | T_EQ
        | T_NE
        ;

Additive_Expression : Additive_Expression Add_Op Term
                    | Term
                    ;

Add_Op  : '+'
        | '-'
        ;

Term    : Term Mult_Op Factor
        | Factor 
        ;

Mult_Op : '*'
        | '/'
        |T_AND
        |T_OR
        ;

Factor  : '(' Expr ')'
        | T_NUM
        | VARIABLE
        | Call
        | T_FALSE
        | T_TRUE
        | T_NOT Factor
        ;

Call    : T_ID '(' Args ')'
        ;

Args    : Arg_list
        | /*empty*/
        ;

Arg_list        : Expr ',' Arg_list
                | Expr
                ;


/* //7. factor → ( expression ) | NUM | var | call | true | false | not factor
28. call → ID ( args )
29. args → arg-list | empty
30. arg-list → expression { , expression }
*/



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
