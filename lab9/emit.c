//Emitter file for compilers with mips

//functions to create proper mips code
//places mips code in designated file

#include "emit.h"
//PRE: PTR to astnode
// POST: all mips code directly and through helper functions print into file 'fp'
void EMIT(ASTnode * p, FILE* fp)
{
    fprintf(fp, " #Compilers MIPS code - 2025 FALL\n");
    fprintf(fp, ".data    \n");
    fprintf(fp, ".align 2    \n");
    fprintf(fp, ".text    \n");
    fprintf(fp, ".global    \n");
}
