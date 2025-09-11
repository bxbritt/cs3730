#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>


struct SymbTab * Insert(char * sym, int address); //adds to list, increases size
void Display(); //prints element
void Delete(); //removes element from list, reduces size
struct SymbTab * Search(char lab[]);   //void Modify(); // TO BE REMOVED 'MODIFY ELEMENT'
int fetchAddress(char * symbol); //returns address of symbol