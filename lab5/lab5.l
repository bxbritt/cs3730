%{
int mydebug=1;

%}


%%
int         {return(T_INT);}
void        {return(T_VOID);}
boolean     {return(T_BOOLEAN);}
return      {return(T_RETURN);}
write       {return(T_WRITE);}
begin       {return(T_BEGIN);}
end         {return(T_END);}
read        {return(T_READ);}
"<="        {return(T_LE);}
\".*\"      yylval.string=strdup(yytext) {return(T_STRING);} //????
not         {return(T_NOT);}
true        {return(T_TRUE);}
false       {return(T_FALSE);}




[a-zA-Z][a-zA-Z0-9_]*		{if (mydebug) fprintf(stderr,"Letter found\n"); 
                       yylval.string = strdup(yytext); return(VARIABLE);}
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                       yylval.value = atoi((const char *)yytext); return(INTEGER);}
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=\-+*/%&|();,[\](\)] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                       return (*yytext);}
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                       yylineno++;
                       return (*yytext);}

%%

int yywrap(void)
{ return 1;}


