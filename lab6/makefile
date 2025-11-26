#
#
#
#
# Brittany Benedict
# Makefile for lab 6
# October 6, 2025
# Compilers class - CS3730
#algol_c with enif and prototypes
# Add abstract syntax tree to lab 5
#
#

all:	lab6

lab6:	lab6.l lab6.y ast.c ast.h
		bison -d lab6.y 
		flex lab6.l
		gcc lex.yy.c lab6.tab.c ast.c -o lab6

clean: #remove compiled files
	 rm -f lab6 lex.yy.c lab6.tab.c lab6.tab.h 
	