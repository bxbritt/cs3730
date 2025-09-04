#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

int size = 0; //size will change on insertion or delete
struct SymbTab * Insert(char * sym, int address); //adds to list, increases size
void Display(); //prints element
void Delete(); //removes element from list, reduces size
int Search(char lab[]);   //void Modify(); // TO BE REMOVED 'MODIFY ELEMENT'
