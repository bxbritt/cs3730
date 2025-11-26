%{

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */



/*

  					Brittany Benedict
                    CS3730
                    lab22
                    Purpose of this lab is to get the operations of a simple calculator to work

   problems:  fix unary minus, fix parenthesis, add multiplication

	CHANGES MADE: (LINE 88) original line read "expr '-' expr". I delted the first expr so the UMINUS
					will act as a negative instead of a binary minus.
					(LINE 84-85) added the line so the calulator has a multiplication function)
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "symtable.h"
#include "y.tab.h"

extern int yylex();
extern int yylineno();

#define MAXVAR 26

int regs[MAXVAR];
int base, dlex, lab22,lebugsw;
int oneup = 0;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */



%start program


%union{
	int value;
	char* string;

}


%token <value> INTEGER
%token  <string> VARIABLE
%token T_INT

%type <value> expr


%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS



%%	/* end specs, begin rules */

program	: decls list
		| list
		;


decls	: T_INT VARIABLE ';' '\n' 
			{
				//check if symbool is present
				//if present...barf, 
				//else...insert($2, oneup);
				//			oneup++;
				//

				if(Search($2)!= NULL){
					fprintf(stderr, "Varible '%s' is already present.\n", $2);
				}
				else if(oneup >= MAXVAR){
					fprintf(stderr, "Error: Too many variables (MAX 26)\n", $2);
				}
				else{
					Insert($2,oneup);
					fprintf(stderr, "Inserted %s\n", $2);
					oneup++;
				}


			}
		|	/* empty */
		;

list	:	/* empty */
		|	list stat '\n'
		|	list error '\n'
			{ yyerrok; }	
		;

stat	:	expr
			{ fprintf(stderr,"the answser is %d\n", $1); }

		|	VARIABLE '=' expr
			{ regs[fetchAddress($1)] = $3; }
		;

expr	:	'(' expr ')'
			{ $$ = $2; }

		|	expr '-' expr
				{ $$ = $1 - $3; }
		|	expr '+' expr
				{ $$ = $1 + $3; }
		|	expr '/' expr
				{ $$ = $1 / $3; }
		|	expr '%' expr
				{ $$ = $1 % $3; }
		|	expr '*' expr
				{ $$ = $1 * $3; }
		|	expr '&' expr
				{ $$ = $1 & $3; }
		|	expr '|' expr
				{ $$ = $1 | $3; }
		|	'-' expr	%prec UMINUS
				{ $$ = -$2; }
		|	VARIABLE{
				//if search ($1) is not there, barf
					//else do next line below

					if(Search($1)==NULL){
						fprintf(stderr, "Varible '%s' is not found.\n", $1);
					}
					else{
					$$ = regs[fetchAddress($1)]; fprintf(stderr,"found a variable value =%d\n",$1); }}
		|	INTEGER {$$=$1; fprintf(stderr,"found an integer\n");}
		;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
