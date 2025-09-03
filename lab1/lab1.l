     /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015
   */

   /*
     Brittany Benedict
     Compilers class - CS3730 LAB
   */


   	int lgths[100];
     int countnum;
%%
[a-zA-Z]+	lgths[yyleng]++;
[0-9]+ countnum++;
.	|
\n	
;
%%


int yywrap() /*
               the loop is looking through a list of 'words' 
               and counting the amount of LETTERS found and 
               how many words also have those amount of letters
               */
{
	int i;
	printf("Length  No. words\n");
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}


     /*counts how many NUMBERS there are present*/

     printf("Number of numbers %d \n", countnum );
          
	return(1);



}

int main() 

/*
   this is the method called to analyze the 
    list of 'words' given
*/

{  yylex();

}
