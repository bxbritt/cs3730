#ifndef EMIT_H
#define EMIT_H
#include "ast.h"

#define WSIZE 4
#define LOG_WSIZE 2


void EMIT(ASTnode * p, FILE* fp);

void EMIT_GLOBALS(ASTnode *p, FILE *fp);

void EMIT_STRINGS(ASTnode *p, FILE *fp);


#endif



