/* 
lab21
  Brittany B
  This lex program removes comments from a source program.
  
  Changes made:
    - Added 'line' variable to keep track of the number of lines (line 12)
    - Changed 'comment' and 'debug' variable to 1 instead of 0 to since the lines start at 1 (lines 13-14)
    - Added 'line' variable to the fprintf (%d) statement (line 26)
    - Added int return type to main function. (line 44)
*/
        int line = 1; /* <-----added line varaibale to keep track of the number of lines */
        int comment = 1; /* <-----changed comment variable to 1 instead of 0 */
        int debug=1;  /* prints out debug statements if desired */
%%

"\n"  {
        if(!comment) printf("%s",yytext);
          line++;
        }



"/*"	{
	if (comment && debug) fprintf(stderr,
		" >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n", line); /* <----  Added 'line' at the end of 
                                                                        statement so the %d prints out varibale 'line'*/
	comment = 1;
	}


"*/"	{
          if (!comment) printf("%s",yytext); /*print out if it is not in a comment */
  	  comment = 0;
	}
.       { if (!comment) printf("%s",yytext);}

%%

int yywrap(void)
{ return 1;
}
              
int main()    /* <------ int return type added to main*/
{
  yylex();
  
}

