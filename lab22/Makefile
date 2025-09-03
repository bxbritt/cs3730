#
#
#
#
# Brittany Benedict
# Makefile for lab 21
# Compilers class - CS3730
#
#
#

all:	lab22

lab22:	lab22.l lab22.y
		yacc -d lab22.y  
		lex lab22.l
		gcc y.tab.c lex.yy.c -o lab22

clean: 
	rm -f lab22