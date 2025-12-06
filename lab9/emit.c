//Emitter file for compilers with mips

//functions to create proper mips code from my AST!!!
//places mips code in designated file "test.al"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "emit.h"
#include "symtable.h"



int labelCount = 0;

//prototypes used
void EMIT_AST(ASTnode *p, FILE *fp);
void EMIT_FUNDEC(ASTnode *p, FILE *fp);
void EMIT_WRITE(ASTnode *p, FILE *fp);
void EMIT_EXPR(ASTnode *p, FILE * fp);
void EMIT_VAR(ASTnode *p, FILE *fp);
void EMIT_READ(ASTnode *p, FILE *fp);
void EMIT_ASSIGN(ASTnode *p, FILE *fp);
void EMIT_IF(ASTnode *p, FILE *fp);
void EMIT_ITERATION(ASTnode *p, FILE *fp);
void EMIT_RETURN(ASTnode *p, FILE *fp);
void EMIT_CALL(ASTnode *p, FILE *fp);
void EMIT_ARGS(ASTnode *p, FILE *fp);







//PRE: PTR to astnode and NULL

// POST: all mips code directly and through helper functions print into file 'fp'

void EMIT(ASTnode * p, FILE* fp)
{
    fprintf(fp, " # Compilers MIPS code - 2025 FALL\n\n");
    
    
    fprintf(fp, ".data    \n\n");
    EMIT_STRINGS(p,fp );
    
    //print all global variables
    fprintf(fp, "\n.align 2    \n\n");
    EMIT_GLOBALS(p, fp);

    fprintf(fp, "\n.text    \n\n");
    
    fprintf(fp, ".globl main   \n\n");
    //emit functions
    EMIT_FUNDEC(p, fp);
}



/*  
######################################[EMIT GLOBAL VARIABLES FUNCTION]#############################################
                                   
pre: ast and input .al code file and NULL node/null file 
post: mips code for global variables at level 0

*/

void EMIT_GLOBALS(ASTnode *p, FILE *fp)
{
    while (p != NULL && fp != NULL)
    {
        ASTnode *declaration = p->s1;  

        if ((declaration->nodetype == A_VARDEC) && (declaration->symbol->level == 0))
        {
            fprintf(fp, "%s:\t.space\t%d  # GLOBAL VARIABLE\n",
                    declaration->symbol->name,
                    declaration->symbol->mysize * WSIZE);
        }

        p = p->s2;  // next declaration
    }


}
/*#################################[emit HELPER FUCNTION]##########################################################
pre: label, command, or comment
post: formatted output to file



*/
void emit(FILE *fp, char * label, char * command, char * comment)
{
    if(strcmp("", comment) == 0 ){
        if(strcmp("", label) == 0) {fprintf(fp, "\t%s \t\t\n", command);}
        else {fprintf(fp, "%s:\t%s\t\t\n", label, command);}
   }else{
        if (strcmp("", label) == 0) {fprintf(fp, "\t%s\t\t# %s\n", command, comment);}
        else {(fprintf(fp, "%s:\t%s\t\t# %s\n", label, command, comment));}
   }

}
        


/*#################################[CREATE LABEL FUCNTION]##########################################################

pre: none
post: create node label

*/
char * CreateLabel()
{    char hold[100];
     char *s;
     sprintf(hold,"_L%d", labelCount++);
     s=strdup(hold);
     return (s);
}

/* 
######################################[EMIT STRING VARIABLES FUNCTION]#############################################
                                   
pre: entire tree and null nodes or null files
post: mips code for all string variables

*/


void EMIT_STRINGS(ASTnode *p, FILE *fp)
{
    
    if (p == NULL || fp == NULL){ return;}


    if (p->nodetype == A_WRITE && p->s1->name != NULL && p->s1->symbol == NULL) // makes sure its not a variable/number
    {
        if (p->label == NULL)
            p->label = CreateLabel();

        fprintf(fp, "%s: .asciiz\t%s\n", p->label, p->s1->name);
    }

    EMIT_STRINGS(p->s1, fp);
    EMIT_STRINGS(p->s2, fp);
}


//###########################[EMIT_AST FUNCTION]################################################
//pre: pointer to astnode and NULL ASTnodes
//post: main driver for walking out AST tree to produce MIPS code in the file

void EMIT_AST(ASTnode *p, FILE *fp)
{
    if(p == NULL) return;

    switch(p->nodetype)
    {
        case A_DECLARATION_LIST: 
            EMIT_AST(p->s1,fp);
            EMIT_AST(p->s2,fp);
            break;
            
        case A_STMT_LIST:
            EMIT_AST(p->s1,fp);
            EMIT_AST(p->s2,fp);
            break;
            
        case A_VARDEC: 
            EMIT_AST(p->s1,fp);
            EMIT_AST(p->s2,fp);
            break;
            
        case A_FUNDEC: 
            EMIT_FUNDEC(p,fp);
            break;
            
        case A_COMPOUNDSTMT:
            EMIT_AST(p->s1,fp);
            EMIT_AST(p->s2,fp);
            break;
            
        case A_READ:
            EMIT_READ(p,fp);
            break;
            
        case A_WRITE:
            EMIT_WRITE(p,fp);
            break;
            
        case A_EXPR_STMT:
            EMIT_EXPR(p->s1,fp);
            break;
            
        case A_ASSIGNSTMT:
            EMIT_ASSIGN(p,fp);
            break;
            
        case A_SELECT:
            EMIT_IF(p,fp);
            break;
            
        case A_ITERATION:
            EMIT_ITERATION(p,fp);
            break;
            
        case A_RETURN:
            EMIT_RETURN(p, fp);
            break;

        default: 
            printf ("EMIT_AST: Unknown NODETYPE %d \n", p->nodetype);
            printf ("exiting FIX FIX FIX");
            exit(1);
    }
}//end of emit ast

//##########################################################
// pre: pointer to argument list and NULL nodes 
// post: mips code to evaluate and push arguments

void EMIT_ARGS(ASTnode *p, FILE *fp)
{
    if (p == NULL) return;
    
   
    if (p->nodetype == A_ARG_LIST) {

        //process first arg
        EMIT_EXPR(p->s1, fp);
        emit(fp, "", "subu $sp, $sp, 4", "push argument");
        emit(fp, "", "sw $a0, ($sp)", "store argument");
        
        //process args list
        if (p->s2 != NULL) {
            EMIT_ARGS(p->s2, fp);
        }
    } else {
        // if there's only one argument
        EMIT_EXPR(p, fp);
        emit(fp, "", "subu $sp, $sp, 4", "push argument");
        emit(fp, "", "sw $a0, ($sp)", "store argument");
    }
    
} //end of emit args




//##########################################################
// pre: pointer to a function call node and NULL nodes 
// post: mips code to perform function call

void EMIT_CALL(ASTnode *p, FILE *fp)
{
    if (p == NULL) return;
    
    char s[100];
    int argCount = 0;
    
    // keep track of number of arguments if more than one
    ASTnode *arg = p->s1;
    if (arg != NULL) {
        if (arg->nodetype == A_ARG_LIST) {
            // count number of args
            while (arg != NULL) {
                argCount++;
                arg = arg->s2; 
            }
        } else {
            argCount = 1;
        }
    }
    
    // evaluate args and push them onto stack
    if (p->s1 != NULL) {
        EMIT_ARGS(p->s1, fp);
    }

    sprintf(s, "jal %s", p->name);
    emit(fp, "", s, "call function");
    
    // remove args from stack
    if (argCount > 0) {
        sprintf(s, "addu $sp, $sp, %d", argCount * WSIZE);
        emit(fp, "", s, "remove aruments from stack");
    }
    
    // result is in $v0, move back to $a0 
    emit(fp, "", "move $a0, $v0", "get return value");
    fprintf(fp, "\n");
    
} //end of emit call





//##########################################################
// pre: pointer to a return statement node and NULL return nodes 
// post: mips code to perform return

void EMIT_RETURN(ASTnode *p, FILE *fp)
{
    if (p == NULL) return;
    
    if (p->s1 != NULL) {
        // eval the return expression
        EMIT_EXPR(p->s1, fp);
        
        // move result to $v0 
        emit(fp, "", "move $v0, $a0", "set return value");
    }
    // if s1 is NULL, it's a void return
    
    emit(fp, "", "lw $ra, ($sp)", "restore return address");
    emit(fp, "", "lw $sp, 4($sp)", "restore SP");
    
    
    emit(fp, "", "jr $ra", "return");
    fprintf(fp, "\n");
    
} //end of emit return

//#####################################################
//pre: pointer to a functioin node and NULL nodes 
//post: mips code for the function using EMIT_AST as a helper

void EMIT_FUNDEC(ASTnode *p, FILE *fp)
{
    if (p == NULL) return;
    
    if (p->nodetype == A_FUNDEC)
    {
        char s[100];
        emit(fp, p->name, "", "START OF FUNCTION");
        fprintf(fp, "\n");
        sprintf(s, "subu $a0, $sp, %d", p->symbol->offset*WSIZE);
        emit(fp, "" , s, "set up $a0 to be the new spot for the SP");
        emit(fp, "" , "sw $sp, 4($a0)", "remember old SP");
        emit(fp, "" , "sw $ra, ($a0)" , "remember current return address");
        emit(fp, "" , "move $sp, $a0", "set the SP to the new value");
        
       
        emit(fp, "", "move $fp, $sp", "copy SP into $fp");
        fprintf(fp, "\n");
        
        // handle parameters using $t0 
        if (p->s1 != NULL) {
            emit(fp, "", "lw $t0, 4($fp)", "save old SP in $t0 for parameter handling");
            
            ASTnode *param = p->s1;
            int argOffset = 8;
            
            while (param != NULL) {
                ASTnode *currentParam;
                
                if (param->nodetype == A_PARAM_LIST) {
                    currentParam = param->s1;
                    param = param->s2;
                } else {
                    currentParam = param;
                    param = NULL;
                }
                
                if (currentParam->nodetype == A_PARAM) {
                    sprintf(s, "lw $a0, %d($t0)", argOffset);
                    emit(fp, "", s, "load argument from caller");
                    
                    sprintf(s, "sw $a0, %d($fp)", currentParam->symbol->offset * WSIZE);
                    emit(fp, "", s, "store into parameter");
                    
                    argOffset += WSIZE;
                }
            }
            fprintf(fp, "\n");
        }
        
        fprintf(fp, "\n");

        EMIT_AST(p->s2, fp);

        emit(fp, "" , "lw $ra, ($fp)" , "reset return address");
        emit(fp, "" , "lw $sp, 4($fp)" , "reset SP");

        if(strcmp(p->name, "main") == 0)
        {
            emit(fp, "" , "li $v0, 10" , "leave main function");
            emit(fp, "" , "syscall" , "only for ending main");
        }
        else 
        {
            emit(fp, "" , "jr $ra" , "return to caller");
        }
    }
    
    EMIT_FUNDEC(p->s1, fp);
    EMIT_FUNDEC(p->s2, fp);
 
} //end of emit function


//##########################################################
//pre: pointer to a Write node and NULL nodes 
//post: mips code to perform write


void EMIT_WRITE(ASTnode *p, FILE *fp)
{
    if (p == NULL) return;

    char s[100];
    //two types of write -> string and expression

    if(p->label != NULL) //then its a string
    {
        emit(fp, "" , "li $v0, 4" , "print a string");
        sprintf(s, "la $a0, %s", p->label);
        emit(fp, "" , s , "print string  location");
        emit(fp, "" , "syscall" , "perform write string");
        fprintf(fp, "\n\n");
    }

    else //its an expression
    {
        EMIT_EXPR(p->s1, fp);
        emit(fp, "" ,"li $v0, 1","print NUMBER location");
        emit(fp, "" , "syscall" , "perform write NUMBER");
        fprintf(fp, "\n\n");
    }

} //end of emit write


//##########################################
//pre: pointer to a selection statement and NULL nodes 
// post: mips code to perform if-then-else

void EMIT_IF(ASTnode *p, FILE *fp)
{
    if (p == NULL) return;

    char *elseLabel = CreateLabel();
    char *endLabel = CreateLabel();
    char s[100];

    // eval condition $a0
    EMIT_EXPR(p->s1, fp);
    
    if (p->value == 0) {
        // if-then
        sprintf(s, "beq $a0, 0, %s", endLabel);
        emit(fp, "", s, "IF: branch to END if condition is false");
        fprintf(fp, "\n");
        
        // then
        EMIT_AST(p->s2, fp);
        
        // endif
        sprintf(s, "%s:", endLabel);
        fprintf(fp, "%s\t\t\t# ENDIF, if-then\n", s);
        fprintf(fp, "\n");
    }
    else {
        // if-then-else
        sprintf(s, "beq $a0, 0, %s", elseLabel);
        emit(fp, "", s, "IF: branch to ELSE if condition is false");
        fprintf(fp, "\n");
        
        // then
        EMIT_AST(p->s2->s1, fp);
        
        sprintf(s, "j %s", endLabel);
        emit(fp, "", s, "IF: jump to END after THEN");
        fprintf(fp, "\n");
        
        // else 
        sprintf(s, "%s:", elseLabel);
        fprintf(fp, "%s\t\t\t# ELSE part\n", s);
        
        if (p->s2 != NULL && p->s2->s2 != NULL) {
            EMIT_AST(p->s2->s2, fp);
        }
        
        // endif
        sprintf(s, "%s:", endLabel);
        fprintf(fp, "%s\t\t\t# ENDIF, if-then-else\n", s);
        fprintf(fp, "\n");
    }
    
} //end of emit if






//##########################################################
// pre: pointer to an iteration (while) statement node and NULL nodes 
// post: mips code to perform while loop

void EMIT_ITERATION(ASTnode *p, FILE *fp)
{
    if (p == NULL) return;
    
    char *startLabel = CreateLabel();  // label for start
    char *endLabel = CreateLabel();    // label for end
    char s[100];
    
    // create start label
    sprintf(s, "%s:", startLabel);
    fprintf(fp, "%s\t\t\t# WHILE loop start\n", s);
    fprintf(fp, "\n");
    
    // eval the condition first
    EMIT_EXPR(p->s1, fp);
    
    // branch to end if condition equals false
    sprintf(s, "beq $a0, 0, %s", endLabel);
    emit(fp, "", s, "exit loop if condition is false");
    fprintf(fp, "\n");
    
    // while statement
    EMIT_AST(p->s2, fp);
    
    //loop finsihed, restart
    sprintf(s, "j %s", startLabel);
    emit(fp, "", s, "jump back to loop start");
    fprintf(fp, "\n");
    
    // create the end label
    sprintf(s, "%s:", endLabel);
    fprintf(fp, "%s\t\t\t# WHILE loop end\n", s);
    fprintf(fp, "\n");
    
} //end of emit iteration


//####################################################
//pre: pointer to expression OR NULL node 
//post: mips code to set $a0 to the evaluated expression

void EMIT_EXPR(ASTnode *p, FILE * fp)
{
    char s[100];
    if(p == NULL)
    {
        printf("Illegal use of EMIT_EXPR with NULL pointer\n");
        exit(1);
    }
    
    //base cases
    switch(p->nodetype)
    {
        case A_BOOLEAN:
        case A_NUM: 
            sprintf(s,"li $a0, %d", p->value); 
            emit(fp, "", s, "is a constant");
            return;
            break;

        case A_TRUE:
            emit(fp, "", "li $a0, 1", " is TRUE");  
            return;
            break;
            
        case A_FALSE:
            emit(fp, "", "li $a0, 0", " is FALSE"); 
            return;
            break;
            
        case A_VARIABLE:
            EMIT_VAR(p,fp);     
            emit(fp, "", "lw $a0, ($a0)", " is a VARIABLE, get value");
            return;
            break;
        case A_CALL:
            EMIT_CALL(p, fp);
            return;
            break;
        case A_EXPR: 
            if (p->operator == A_NOT) {
                EMIT_EXPR(p->s1, fp);  
                emit(fp, "", "seq $a0, $a0, 0", "NOT operation"); //set equal to 0 if they $a0 is 1, vise versa
                return;
    }
    

            //now its time to set up to easily evaluate expr
            
            // eval LHS
            EMIT_EXPR(p->s1, fp);  // result in $a0
            
            // Save left result to stack
            emit(fp, "", "subu $sp, $sp, 4", "push left side on stack");
            emit(fp, "", "sw $a0, ($sp)", "store left side on stack");
            
            // eval RHS
            EMIT_EXPR(p->s2, fp);  // result in $a0
            
            // Pop left LHS into $a1
            emit(fp, "", "lw $a1, ($sp)", "load left side from stack");
            emit(fp, "", "addu $sp, $sp, 4", "pop stack");

            // Add operators here
            switch(p->operator)
            {
                case A_PLUS:
                    emit(fp, "", "add $a0, $a1, $a0", "EXPR: ADD operation");
                    break;
               
                case A_MINUS:
                    emit(fp, "", "sub $a0, $a1, $a0", "EXPR: SUBTRACT operation");
                    break;
                    
                case A_TIMES:
                    emit(fp, "", "mult $a1, $a0", "MULTIPLY operation");
                    emit(fp, "", "mflo $a0", "get result from LO register");
                    break;
                    
                case A_DIVIDE:
                    emit(fp, "", "div $a1, $a0", "EXPR: DIVIDE operation");
                    emit(fp, "", "mflo $a0", "get quotient from LO register");
                    break;
                case A_AND:
                    emit(fp, "", "and $a0, $a1, $a0", "EXPR: AND operation");
                    break;
                case A_OR:
                    emit(fp, "", "or $a0, $a1, $a0", "EXPR: OR operation");
                    break;
                
                
                // Relational operators (return 0 or 1)
                case A_LT:  // <
                    emit(fp, "", "slt $a0, $a1, $a0", "EXPR:LESS THAN operation");
                    break;
                    
                case A_LE:  // <=
                    emit(fp, "", "sle $a0, $a1, $a0", "EXPR: LESS THAN OR EQUAL operation");
                    break;
                    
                case A_GT:  // >
                    emit(fp, "", "sgt $a0, $a1, $a0", "EXPR: GREATER THAN operation");
                    break;
                    
                case A_GE:  // >=
                    emit(fp, "", "sge $a0, $a1, $a0", "EXPR: GREATER THAN OR EQUAL operation");
                    break;
                    
                case A_EQ:  // ==
                    emit(fp, "", "seq $a0, $a1, $a0", "EXPR: EQUAL operation");
                    break;
                    
                case A_NE:  // !=
                    emit(fp, "", "sne $a0, $a1, $a0", "EXPR: NOT EQUAL operation");
                    break;
                    
                default:
                    printf("EMIT_EXPR: Operator not recognzied: %d\n", p->operator);
                    exit(1);

            } //end of switch for operators

            return;
            break;  
            
        default: 
            printf("EMIT_EXPR: Base case not known, nodetype: %d\n", p->nodetype);
            exit(1);
            
    } //end of switch for expr base cases

}//end of emit expr


//##########################################################
// pre: pointer to assignment statement node and NULL nodes 
// post: mips code to perform assignment

void EMIT_ASSIGN(ASTnode *p, FILE *fp)
{
    if (p == NULL) return;
    
    // get LHS variable address 
    EMIT_VAR(p->s1, fp);

    
    // save variable address to stack
    emit(fp, "", "subu $sp, $sp, 4", "push variable address");
    emit(fp, "", "sw $a0, ($sp)", "store variable address");
    
    // evaluate the RHS expression
    EMIT_EXPR(p->s2, fp);
    
    // move result to $a1
    emit(fp, "", "move $a1, $a0", "save expression result");
    
    // pop variable address into $a0
    emit(fp, "", "lw $a0, ($sp)", "load variable address");
    emit(fp, "", "addu $sp, $sp, 4", "pop stack");
    
    // store the value at the variable address
    emit(fp, "", "sw $a1, ($a0)", "store value to variable");
    fprintf(fp, "\n");

} //end of emit assign


/*##########################################
pre: pointer to VARIABLE 
post: $a0 will be the memory location of the variable 

    variables are: global or local
                : array or not
    for GLOBALs, the start point is where the label is located
    for LOCALs, it is SP + OFFSET
    for ARRAYS, we have to add on the internal OFFSET to these values i++ */

void EMIT_VAR(ASTnode *p, FILE *fp)
{ 
    char s[100];

    if (p->symbol->level == 0) { 
        // GLOBAL variable
        sprintf(s, "la $a0, %s", p->symbol->name);
        emit(fp, "", s, " GLOBAL variable");
        
        // check if its an array
        if (p->s1 != NULL) {

            // calculate offset
            EMIT_EXPR(p->s1, fp);
            
            sprintf(s, "li $a1, %d", WSIZE);
            emit(fp, "", s, "load word size");
            emit(fp, "", "mult $a0, $a1", "multiply index by word size");
            emit(fp, "", "mflo $a0", "get offset");
            
            sprintf(s, "la $a1, %s", p->symbol->name);
            emit(fp, "", s, "load origin address of array");
            emit(fp, "", "add $a0, $a1, $a0", "add offset to origin");
        }
    }   
    else {
        // LOCAL variable - use SP + offset
        sprintf(s, "addu $a0, $fp, %d", p->symbol->offset * WSIZE);  // use $fp + offset, fp = saved stack pointer
        emit(fp, "", s, " LOCAL variable");

 
        // check if its an ARRAY
        if (p->s1 != NULL) {
            // save SP
            emit(fp, "", "subu $sp, $sp, 4", "push SP address");
            emit(fp, "", "sw $a0, ($sp)", "store SP address");
            
            // evaluate [index expression]
            EMIT_EXPR(p->s1, fp);
            
            sprintf(s, "li $a1, %d", WSIZE);
            emit(fp, "", s, "load word size");
            emit(fp, "", "mult $a0, $a1", "multiply index by word size");
            emit(fp, "", "mflo $a0", "get offset");
            
            // pop SP + offset into $a1
            emit(fp, "", "lw $a1, ($sp)", "load SP address");
            emit(fp, "", "addu $sp, $sp, 4", "pop stack");
            emit(fp, "", "add $a0, $a1, $a0", "add offset to SP");
        }
    } 

} //of emit var

//pre: pointer to a read var
//post: mips code to generate a location of variable and read it in
void EMIT_READ(ASTnode *p, FILE *fp)
{
    EMIT_VAR(p->s1, fp); //a0 is the memory location
    emit(fp, "", "li $v0, 5", "read a VAR from input");
    emit(fp, "", "syscall", "perform read VAR");
    emit(fp, "", "sw $v0, ($a0)", "store the read into the memory address");
    fprintf(fp, "\n");

    
} //of emit read