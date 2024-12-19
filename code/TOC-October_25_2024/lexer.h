#ifndef _LEXER_
#define _LEXER_

#include <ctype.h>

#include <stdio.h>
#define LEX_LENGHT 100
enum lex_type{
    L_P,
    R_P,
    ADD,
    SUB,
    MULT,
    DIV,
    NUM,
    ERR,
    ENDL,
    ENDF,
    MOD,
    POW
};

struct token
{
    char lexeme[LEX_LENGHT];
    enum lex_type type;
    int lex_lenght;
};
typedef struct token token_t;

extern token_t get_token(FILE *input_file);
extern void unget_token(token_t token, FILE *input_file);

#endif