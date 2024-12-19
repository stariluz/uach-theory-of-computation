#ifndef _LEXER_
#define _LEXER_

#include <stdio.h>
#include <ctype.h>

#define LEX_LEN 100
enum lex_type{
    L_P,R_P,ADD,SUB,MULT,DIV,NUM,ERR,ENDL,ENDF,MOD,POT
};

struct token{
    char lexeme[LEX_LEN];
    int lex_len;
    enum lex_type type;
};

typedef struct token token_t;

extern token_t get_token(FILE *entrada);
extern void unget_token(token_t t, FILE *entrada) ;

#endif