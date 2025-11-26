#
#
#
#
# Brittany Benedict
# Makefile for lab 9
# November 26, 2025
# Compilers class - CS3730
#
#
#

all:	lab9

lab9:	lab9.l lab9.y ast.c ast.h symtable.c symtable.h emit.c emit.h
		bison -dv lab9.y 
		flex lab9.l
		gcc lex.yy.c lab9.tab.c ast.c symtable.c emit.c -o lab9





clean: #remove compiled files
	    rm -f lab9 lex.yy.c lab9.tab.c lab9.tab.h  

auto:	
		rm -f lab9 lex.yy.c lab9.tab.c lab9.tab.h 
		bison -d lab9.y 
		flex lab9.l
		gcc lex.yy.c lab9.tab.c ast.c symtable.c -o lab9
		./lab9 
	