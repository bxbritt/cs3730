/*
Brittany Benedict
September 17, 2025
Lab 5 - CS3730
*/

%{


/*

  					Brittany Benedict
                    CS3730

*/


extern int mydebug;
extern int linecount;

int regs[26];
int base, dlex, lab5,lebugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */



%start Program


%union{
	int value;
	char* string;

}

//check this


%token  T_BOOLEAN T_ID T_INT T_NUM T_READ T_RETURN T_STRING T_VOID T_WRITE
%token  T_BEGIN T_END T_AND T_OR T_TRUE T_FALSE T_NOT
%token  T_EQ T_GE T_GT T_LE T_LT T_NE



%left '|'
%left '&'
%left '+' '-''(' ')'
%left '*' '/' '%'
%left UMINUS



%%	/* end specs, begin rules */

Program : Declaration_List
		;



Declaration_List    : Declaration
                    | Declaration Declaration_List'[' Expr ']'
                    ;

Declaration : Var_Declaration
            | Fun_Declaration
            ;

Var_Declaration : Type_Specifier Var_List ';'
                ;

Var_List    : T_ID
            | T_ID '['T_NUM']'
            | T_ID ',' Var_List
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
                |
                ;

Local_Declarations  : Var_Declaration Local_Declarations
                    | /*empty*/
                    ;

Statement_List  : Statement Statement_List
                | /*empty*/
                ;

Statement   : Write_Stmt
            | Read_Stmt
            ;

Write_Stmt  : T_WRITE T_STRING
            | /**/
            ;

Read_Stmt   : T_READ VARIABLE
            ;
            ;
VARIABLE    : T_ID 
            | T_ID Expr
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
        |Factor
        ;

Mult_Op : '*'
        | '\\'
        |T_AND
        |T_OR
        ;

Factor  : '('Expr')'
        | T_NUM
        | VARIABLE
        | T_TRUE
        | T_NOT Factor
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
