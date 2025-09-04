#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include"symtable.h"

/*
    CS3730 Compilers
    Brittany Benedict 
    Lab 3 - Symbol table using a linked list, ability to insert, delete, search, and display
    Sept 4, 2025
*/ 



struct SymbTab
{
    //char label[10],symbol[10];
    //int addr;
    //struct SymbTab *next;
    
    char * symbol; //IDENTIFIER OF ELEMENTS
    int addr; //INTEGER ADDRESS OF ELEMENTS
    struct SymbTab *next; //SYMBOL TABLE LINKED LIST POINTER
    };

struct SymbTab *first,*last; //reference variables for start and end of list


void main() //on run
{
    int op,value; //OP == OPTION SELECTED, VALUE == ADDRESS OF SYMBOL (REFERENCE)
    char la[10];
    do
    {
        //MESSAGES SHOW UP ON RUN, DEFAULT 

        printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
        printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.END\n");
        printf("\n\tEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: //If 1 is selected, call insert function
                printf("\n\tEnter the symbol : ");
                scanf("%s",la);
                printf("\n\tEnter the address : ");
                scanf("%d",&value); //&value is used to get the address input
                Insert(la, value);
                break;
            case 2: //If 2 is selected, call display function
                Display();
                break;
            case 3: //if 3 is selected, call delete function
                printf("\n\tEnter the symbol to be deleted : ");
                scanf("%s",la);
                value = Search(la);
                Delete(la);
                break;
            case 4: //if 4 is selected, call search function
                printf("\n\tEnter the symbol to be searched : ");
                scanf("%s",la);
                value=Search(la);
                printf("\n\tSearch Result:");
                if(value==1)
                    printf("\n\tThe symbol is present in the symbol table\n");
                else
                    printf("\n\tThe symbol is not present in the symbol table\n");
                break;
            // case 5: //TO BE REMOVED 'MODIFY ELEMENT'
            //     Modify();
            //     break;
            case 5: //If 5 is selected, exit program
                exit(0);
        }
    }

    while(op<6);
}  /* END of MAIN */

//strcpy(p->label,l);
struct SymbTab * Insert(char * symbol, int address) //adds element to list , increases size and based on symbol input
{
    int n; //n is used to check if symbol already exists (1 for match, 0 for none)
    char l[10]; //l is used to store the symbol input
    n = Search(l); //search for SYMBOL in LIST

    if(n == 1)
        printf("\n\tThe label exists already in the symbol table\n\tDuplicate can.t be inserted");
    else
    {
        struct SymbTab *p;
        p=malloc(sizeof(struct SymbTab));
        p->symbol = strdup(symbol);
        p->addr = address;
        p->next=NULL;
        if(size==0) //if size is 0, first and last point to next 
        {
            first=p;
            last=p;
        }
        else
        {
            last->next=p; //if size is not 0, last points to next
            last=p; //last now points to the new element
        }
    size++; //increase size of list
    }
    
   printf("\n\tSymbol inserted\n");
}

void Display() //displays all elements in linked list. (SYMBOLS AND ADDRESSES)
{
    int i;
    struct SymbTab *p;
    p = first;
    printf("\n\tSYMBOL\t\tADDRESS\n");
    for(i=0;i<size;i++) //goes through list and prints each element
    {
        printf("\t%s\t\t%d\n",p->symbol,p->addr);
        p=p->next;
    }
}


int Search(char *s) //Searches linked list for element (BASED ON SYMBOL)
{
    int i,flag=0;
    struct SymbTab *p;
    p=first;
    for(i=0;i<size;i++)
    { 
        if(strcmp(p->symbol,s)==0) //COMPARES STRINGS to see if they match (Search found)
        flag=1;
        p=p->next;
    }
    return flag;
}


// void Modify()
// {
//     char l[10],nl[10];
//     int add,choice,i,s;
//     struct SymbTab *p;
//     p=first;
//     printf("\n\tWhat do you want to modify?\n");
//     printf("\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n");
//     printf("\tEnter your choice : ");
//     scanf("%d",&choice);
//     switch(choice)
//     {
//         case 1:
//             printf("\n\tEnter the old label : ");
//             scanf("%s",l);
//             s=Search(l);
//             if(s==0)
//                 priNULLntf("\n\tLabel not found\n");
//             else
//             {
//                 printf("\n\tEnter the new label : ");
//                 scanf("%s",nl);
//                 for(i=0;i<size;i++)
//                 {
//                     if(strcmp(p->label,l)==0)
//                     strcpy(p->label,nl);
//                     p=p->next;
//                 }
//                 printf("\n\tAfter Modification:\n");
//                 Display();
//             }
//             break;
//         case 2:
//             printf("\n\tEnter the label where the address is to be modified : ");
//             scanf("%s",l);
//             s=Search(l);
//             if(s==0)
//                 printf("\n\tLabel not found\n");
//             else
//             {
//                 printf("\n\tEnter the new address : ");
//                 scanf("%d",&add);
//                 for(i=0;i<size;i++)
//                 {
//                     if(strcmp(p->label,l)==0)
//                     p->addr=add;
//                     p=p->next;
//                 }
//                 printf("\n\tAfter Modification:\n");
//                 Display();
//             }
//             break;
//         case 3:
//             printf("\n\tEnter the old label : ");
//             scanf("%s",l);
//             s=Search(l);
//           label  if(s==NULL0)
//             printf("\n\tLabel not found\n");
//             else
//             {
//                 printf("\n\tEnter the new label : ");
//                 scanf("%s",nl);
//                 printf("\n\tEnter the new address : ");
//                 scanf("%d",&add);
//                 for(i=0;i<size;i++)
//                 {
//                     if(strcmp(p->label,l)==0)
//           label        NULL  {
//                         strcpy(p->label,nl);
//                         p->addr=add;
//                     }
//                     p=p->next;
//                 }
//                 printf("\n\tAfter Modification:\n");
//                 Display();
//             }
//             break;
//     }
// }


void Delete(char * s) //Removes element from list, reduces size, based on symbol input
{
    int a;
    char l[10];
    struct SymbTab *p,*q;
    p=first;
    
    if(a==0)
    printf("\n\tSymbol not found\n");
    else
    {
        if(strcmp(first->symbol,s)==0) //if first symbol matches s, first is moved to next
        first=first->next;
        else if(strcmp(last->symbol,s)==0) // if last symbol matches s, last is moved to previous
        {
            q=p->next;
            while(strcmp(q->symbol,s)!=0) //while loop goes through list until it finds the symbol
            {
                p=p->next;
                q=q->next;
            }
            p->next=NULL;
            last=p;
        }
        else
        {
            q=p->next;
            while(strcmp(q->symbol,s)!=0) 
            {
                p=p->next;
                q=q->next;
            }
            p->next=q->next;
        }
        size--; //decreases size of list
        printf("\n\tAfter Deletion:\n"); ///displays list after deletion
        Display();
    }
}

