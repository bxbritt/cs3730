#
#
#
#
# Brittany Benedict
# Makefile for lab 7
# October 27, 2025
# Compilers class - CS3730
#
#
#

all:	lab7

lab7:	lab7.l lab7.y ast.c ast.h symtable.c symtable.h
		bison -d lab7.y 
		flex lab7.l
		gcc lex.yy.c lab7.tab.c ast.c symtable.c -o lab7

clean: #remove compiled files
	    rm -f lab7 lex.yy.c lab7.tab.c lab7.tab.h  

auto:	
		rm -f lab7 lex.yy.c lab7.tab.c lab7.tab.h 
		bison -d lab7.y 
		flex lab7.l
		gcc lex.yy.c lab7.tab.c ast.c symtable.c -o lab7
		./lab7 < test.al
	