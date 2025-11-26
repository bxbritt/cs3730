#
#
#
#
# Brittany Benedict
# Makefile for lab 4
# Compilers class - CS3730
#
#
#

all:	lab4

lab4:	lab4.l lab4.y symtable.c symtable.h #things I might edit
		yacc -d lab4.y 
		lex lab4.l
		gcc y.tab.c lex.yy.c symtable.c -o lab4  

clean: #remove compiled files
	rm -f y.tab.c y.tab.h lex.yy.c lab4
	