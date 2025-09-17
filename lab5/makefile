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

lab4:	lab5.l lab5.y #things I might edit
		yacc -d lab5.y 
		lex lab5.l
		gcc lab5.c -o lab5

clean: #remove compiled files
	rm -f lab5.c lab5
	