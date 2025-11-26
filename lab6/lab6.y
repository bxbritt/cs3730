/*
Brittany Benedict
October 6,2025
Lab 6 - CS3730

Major edits to lab5 code: 
        Added AST nodes for all node types
        Assigned $$ values to all grammar rules
        Added semantic actions to production rules to build the AST
        Gave meaning to tokens 

*/

%{

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>


extern int yylex();
extern int mydebug;
extern int linecount;


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
        ASTnode * node;
        enum DataTypes datatype;
        enum OPERATORS operator;
}
/*  defines the type of the values returned from LEX and used in the grammar  */

%token <string> T_ID T_STRING
%token <value> T_NUM

%token  T_BOOLEAN T_INT T_READ T_RETURN  T_VOID T_WRITE
%token  T_BEGIN T_END T_AND T_OR T_TRUE T_FALSE T_NOT
%token  T_EQ T_GE T_GT T_LE T_LT T_NE
%token  T_IF T_ELSE T_WHILE T_ENDIF T_DO T_THEN


%type <node> Declaration Declaration_List Var_Declaration Var_List Fun_Declaration VARIABLE        
%type <node> Compound_Stmt Local_Declarations Statement_List Statement
%type <node> Expression_Stmt Selection_Stmt Iteration_Stmt Assignment_Stmt Return_Stmt Read_Stmt Write_Stmt
%type <node> Factor Term Additive_Expression Simple_Expression
%type <node> Expr Params Param_List Param 
%type <node> CALL Args Arg_list


%type <datatype> Type_Specifier
%type <operator> Rel_Op

%type <operator> Add_Op Mult_Op


%%	/* end specs, begin rules */

/*  the grammar rules  */

Program : Declaration_List
        { program = $1;
        }
	;

/*  create nodes for declaration and declaration_list  */
Declaration_List    : Declaration
                        {$$ = ASTCreateNode(A_DECLARATION_LIST);
                         $$->s1 = $1;
                        }
                    | Declaration Declaration_List
                        {$$ = ASTCreateNode(A_DECLARATION_LIST);
                         $$->s1 = $1;
                         $$->s2 = $2;
                        }
                    ;

Declaration : Var_Declaration 
                {$$ = $1;}
            | Fun_Declaration 
                {$$ = $1;}
            ;

Var_Declaration : Type_Specifier Var_List ';' //variable declaration
                {ASTnode* p = $2;
                 while(p != NULL){
                     p -> datatype = $1; //set datatype for each variable in the list
                     p = p -> s1; //move to next variable in the list
                 }
                 $$ = $2;} //return the list of variables
                ;

Var_List    : T_ID 
                {$$ = ASTCreateNode(A_VARDEC);
                $$-> name = $1;
                }
            | T_ID '['T_NUM']' 
            { $$ = ASTCreateNode(A_VARDEC);
              $$ -> name = $1;
              $$-> value = $3;} //points to a value (t_num)

            | T_ID ',' Var_List  
            { $$ = ASTCreateNode(A_VARDEC);
              $$ -> name = $1;
              $$->s1 = $3;} 

            | T_ID '['T_NUM']' ',' Var_List 
            {$$ = ASTCreateNode(A_VARDEC);
             $$ -> name = $1;
             $$ -> value = $3; 
             $$ -> s1 = $6;} //points to next variable in the list (recursion)
            ;

Type_Specifier  : T_INT { $$ = A_INTTYPE;}
                | T_BOOLEAN { $$ = A_BOOLEANTYPE;}
                | T_VOID     { $$ = A_VOIDTYPE;}
                ;

Fun_Declaration : Type_Specifier T_ID '(' Params ')' Compound_Stmt
                {$$ = ASTCreateNode(A_FUNDEC);
                 $$-> name = $2;
                 $$-> datatype = $1;
                 $$ -> s1 = $4; //  params
                 $$ -> s2 = $6;} //compound stmt
                ;

Params  : T_VOID
        {$$ = NULL;} //no parameters
        | Param_List
        {$$ = $1;}   //list of parameters
        ;

Param_List  : Param
            {$$ = $1;}
            | Param ',' Param_List
                { $$ = ASTCreateNode(A_PARAM_LIST); // create a node to hold the param list
                  $$ -> s1 = $1;
                  $$ -> s2 = $3;}
            ;
Param   : Type_Specifier T_ID
        { $$ = ASTCreateNode(A_PARAM);
          $$ -> datatype = $1;
          $$ -> name = $2;}

        | Type_Specifier T_ID '['']'
        { $$ = ASTCreateNode(A_PARAM);
          $$ -> datatype = $1;
          $$ -> name = $2;
          $$ -> value = 1;} //to signify it's an array
        ;

Compound_Stmt   : T_BEGIN Local_Declarations Statement_List T_END
                {$$ = ASTCreateNode(A_COMPOUNDSTMT);
                 $$ ->s1 = $2;
                  $$ -> s2 = $3;}
                ;

Local_Declarations  : Var_Declaration Local_Declarations
                        {$$ = ASTCreateNode(A_DECLARATION_LIST);
                         $$ -> s1 = $1;
                         $$ -> s2 = $2;}
                    | /*empty*/
                    {$$ = NULL;} //tree is done when NULL
                    ;

Statement_List  :  /*empty by default */
                {$$ = NULL;}
                |Statement Statement_List
                {$$ = ASTCreateNode(A_STMT_LIST);
                 $$ -> s1 = $1;
                 $$ -> s2 = $2;}
                ;

Statement   : Expression_Stmt
            {$$ = $1;} 
            | Compound_Stmt
            {$$ = $1;} 
            | Selection_Stmt
            {$$ = $1;} 
            | Iteration_Stmt
            {$$ = $1;}
            | Assignment_Stmt
            {$$ = $1;}
            | Return_Stmt
            {$$ = $1;}
            | Read_Stmt
            {$$ = $1;}
            | Write_Stmt
            {$$ = $1;}
            ;

Expression_Stmt : Expr ';'
                {$$ = ASTCreateNode(A_EXPR_STMT);
                 $$ -> s1 = $1;}
                | ';'
                {$$ = NULL;} //empty statement
                ;

Selection_Stmt  : T_IF  Expr T_THEN Statement T_ENDIF // if-then
                {  $$ = ASTCreateNode(A_SELECT); //node to hold if and then statements
                   $$ -> s1 = $2;    
                   $$ -> s2 = $4;    
                   $$ -> value = 0;  // to signify there is no 'else' 
                }
                | T_IF  Expr T_THEN Statement T_ELSE Statement T_ENDIF  // if-then/else
                {  $$ = ASTCreateNode(A_SELECT);
                   $$ -> s1 = $2;    // condition
                   ASTnode * p = ASTCreateNode(A_STMT_LIST);   // node to hold if and then/else statements (because we're only using s1 and s2)
                   p -> s1 = $4;  
                   p -> s2 = $6;   
                   $$ -> s2 = p; 
                   $$ -> value = 1; // to signify there is an 'else' part
                }
                ;

Iteration_Stmt  : T_WHILE Expr T_DO Statement
                { $$ = ASTCreateNode(A_ITERATION);
                  $$ -> s1 = $2; //condition
                  $$ -> s2 = $4; //statement 
                }
                ;

Assignment_Stmt : VARIABLE '=' Expr ';'
                { $$ = ASTCreateNode(A_ASSIGNSTMT);
                  $$ -> s1 = $1;
                  $$ -> s2 = $3;
                  $$ -> operator = A_ASSIGN;}
                ;

Return_Stmt : T_RETURN Expr ';' //return with value
                { $$ = ASTCreateNode(A_RETURN);
                  $$-> s1 = $2;  
                }
            | T_RETURN ';' // no return value
                { $$ = ASTCreateNode(A_RETURN);
                  $$-> s1 = NULL; 
                }
            ;

Write_Stmt  : T_WRITE Expr ';'
                { $$ = ASTCreateNode(A_WRITE);
                  $$-> s1 = $2;  
                }

Read_Stmt   : T_READ VARIABLE ';'
                { $$ = ASTCreateNode(A_READ);
                  $$-> s1 = $2;}    // variable
                ;

VARIABLE    : T_ID  
            {$$ = ASTCreateNode(A_VARIABLE);
             $$->name = $1;} 

            | T_ID '[' Expr ']' // array with index
            {$$ = ASTCreateNode(A_VARIABLE);
             $$->name = $1;
             $$->s1 = $3;}     
            ;

Expr    : Simple_Expression
        {$$ = $1;}
        ;

Simple_Expression   : Additive_Expression
                        {$$ = $1;}
                    | Simple_Expression Rel_Op Additive_Expression
                    {$$ = ASTCreateNode(A_EXPR);
                     $$ -> s1 = $1;
                     $$ -> s2 = $3;
                     $$ -> operator = $2;}
                    ;

Rel_Op  : T_LE { $$ = A_LE; } 
        | T_LT { $$ = A_LT; } 
        | T_GT { $$ = A_GT; } 
        | T_GE { $$ = A_GE; }
        | T_EQ { $$ = A_EQ; }
        | T_NE { $$ = A_NE; }
        ;

Additive_Expression : Term
                    {$$ = $1;}
                    | Additive_Expression Add_Op Term
                    {$$ = ASTCreateNode(A_EXPR);
                     $$ -> s1 = $1;
                     $$ -> s2 = $3;
                     $$ -> operator = $2;} 
                    ;

Add_Op  : '+' {$$ = A_PLUS;}
        | '-' {$$ = A_MINUS;}
        ;

Term    : Factor
        {$$ = $1;}
        | Term Mult_Op Factor
        {$$ = ASTCreateNode(A_EXPR);
         $$ -> s1 = $1;
         $$ -> s2 = $3;
         $$ -> operator = $2;}
        ;

Mult_Op : '*' {$$ = A_TIMES;}
        | '/' {$$ = A_DIVIDE;}
        |T_AND {$$ = A_AND;}
        |T_OR {$$ = A_OR;}
        ;

Factor  : '(' Expr ')' 
        {$$ = $2;} 
        | T_NUM
        {$$ = ASTCreateNode(A_NUM);
         $$-> value = $1;
        } 
        | T_STRING
        {$$ = ASTCreateNode(A_STRING);
         $$-> name = $1;}
        | VARIABLE
        {$$ = $1;} 
        | CALL
        {$$ = $1;} 
        | T_FALSE
        {$$ = ASTCreateNode(A_BOOLEAN);
         $$-> value = 0;}
        | T_TRUE
        {$$ = ASTCreateNode(A_BOOLEAN);
         $$-> value = 1;}
        | T_NOT Factor  
        {$$ = ASTCreateNode(A_NOT);
         $$-> s1 = $2;
         $$-> operator = A_NOT;}
        ;

CALL    : T_ID '(' Args ')'
        { $$ = ASTCreateNode(A_CALL);
          $$-> name = $1;
          $$-> s1 = $3;} 
        ;

Args    : Arg_list
        {$$ = $1;}
        | 
        {$$ = NULL;} /*empty*/
        ;

Arg_list        : Expr ',' Arg_list
                { $$ = ASTCreateNode(A_ARG_LIST);
                  $$ -> s1 = $1;
                  $$ -> s2 = $3;}
                | Expr
                {$$ = $1;}
                ;
                
%%	
//--------------END OF GRAMMAR RULES------------------------------------------------------//




//-------------START OF MAIN PROGRAM------------------------------------------------------//
int main()
{ yyparse();
  //fprintf(stderr, "The input is syntactically correct\n");

  //we know that var program has to be set to an AST!
  ASTprint(0,program);
  exit(0);
}
