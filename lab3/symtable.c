#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

/*
    CS3730 Compilers
    Brittany Benedict 
    Lab 3 - Symbol table using a linked list, ability to insert, delete, search, and display
    Sept 3, 2025
*/ 

int size = 0; //size will change on insertion or delete
struct SymbTab * Insert(char * sym, int address); //adds to list, increases size
void Display(); //prints element
void Delete(); //removes element from list, reduces size
int Search(char lab[]);   //void Modify(); // TO BE REMOVED 'MODIFY ELEMENT'


struct SymbTab
{
    //char label[10],symbol[10]; //10 CHARACTERS MAX
    //int addr;
    //struct SymbTab *next;
    
    char * symbol;
    int addr;
    struct SymbTab *next;
    };

struct SymbTab *first,*last; //reference variables for start and end of list


void main() //on run
{
    int op,value;
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
                scanf("%d",value);
                Insert(la, value);
                break;
            case 2: //If 2 is selected, call display function
                Display();
                break;
            case 3: //if 3 is selected, call delete function
                printf("\n\tEnter the symbol to be deleted : ");
                scanf("%s",la);
                value =Search(la);
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
struct SymbTab * Insert(char * symbol, int address) //IMPLEMENTATION OF ADDING ELEMENT TO LINKED LIST (INSERT FUNCTION)
{
    int n;
    char l[10];
    n = Search(l);

    if(n == 1)
        printf("\n\tThe label exists already in the symbol table\n\tDuplicate can.t be inserted");
    else
    {
        struct SymbTab *p;
        p=malloc(sizeof(struct SymbTab));
        p->symbol = strdup(symbol);
        p->addr = address;
        p->next=NULL;
        if(size==0)
        {
            first=p;
            last=p;
        }
        else
        {
            last->next=p;
            last=p;
        }
    size++;
    }
    
    printf("\n\tLabel inserted\n");
}

void Display()
{
    int i;
    struct SymbTab *p;
    p=first;
    printf("\n\tSYMBOL\t\tADDRESS\n");
    for(i=0;i<size;i++)
    {
        printf("\t%s\t\t%s\t\t%d\n",p->symbol,p->addr);
        p=p->next;
    }
}


int Search(char *s) 
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


void Delete(char * s)
{
    int a;
    char l[10];
    struct SymbTab *p,*q;
    p=first;
    
    if(a==0)
    printf("\n\tSymbol not found\n");
    else
    {
        if(strcmp(first->symbol,s)==0)
        first=first->next;
        else if(strcmp(last->symbol,s)==0)
        {
            q=p->next;
            while(strcmp(q->symbol,s)!=0)
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
        size--;
        printf("\n\tAfter Deletion:\n");
        Display();
    }
}

