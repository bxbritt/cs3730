#
#
#
#
# Brittany Benedict
# Makefile for lab 5
# Compilers class - CS3730
#
#
#

all:	lab5

lab5:	lab5.l lab5.y #things I might edit
		bison -d lab5.y 
		flex lab5.l
		gcc -o lab5 lab5.tab.c lex.yy.c

clean: #remove compiled files
	 rm -f lab5 lab5.tab.c lab5.tab.h lex.yy.c
	