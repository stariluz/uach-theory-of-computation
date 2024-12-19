// gcc lexer.c -o lexer && ./lexer

#include "lexer.h"

int states[][13] = {
    //(  )  +  -  *  /  %  ^  .  \n DI BL OT      STATE
    {1, 2, 3, 4, 5, 6, 13, 14, 8, 12, 7, 0, 11},          // 0 (return LP)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 1 (return LP)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 2 (return RP)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 3 (return ADD)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 4 (return SUB)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 5 (return MULT)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 6 (return DIV)
    {10, 10, 10, 10, 10, 10, 10, 10, 8, 10, 7, 10, 10},   // 7 (digit loop, decimal, anything other than decimal is sent to 10)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 9, 11, 11},  // 8 (post-decimal first digit, other is sent to 11)
    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10},  // 9 (post-decimal digit loop, other is sent to 10)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 10 (unget, return NUM)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 11 (ERROR state)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 12 (End of line)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}, // 13 (return MOD)
    {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11}  // 14 (return POT)
};

char alphabet[] = {'(', ')', '+', '-', '*', '/', '%', '^', '.', '\n'};
int alphabet_length = 10;

token_t get_token(FILE *input_file);
void unget_token(token_t token, FILE *input_file);
int choose_symbol_index(char c);

token_t get_token(FILE *input_file)
{
    int state = 0;
    char c;
    token_t token;
    token.lex_lenght = 0;
    while (!feof(input_file))
    {
        c = getc(input_file);
        token.lexeme[token.lex_lenght++] = c;
        token.lexeme[token.lex_lenght] = '\r';
        int column = choose_symbol_index(c);
        state = states[state][column];
        switch (state)
        {
        case 1:
            token.type = L_P;
            return token;

        case 2:
            token.type = R_P;
            return token;

        case 3:
            token.type = ADD;
            return token;

        case 4:
            token.type = SUB;
            return token;

        case 5:
            token.type = MULT;
            return token;

        case 6:
            token.type = DIV;
            return token;

        case 10:
            ungetc(c, input_file);
            token.lexeme[--token.lex_lenght] = '\r';
            token.type = NUM;
            return token;

        case 11:
            token.type = ERR;
            return token;

        case 12:
            token.type = ENDL;
            return token;
            
        case 13:
            token.type = MOD;
            return token;

        case 14:
            token.type = POW;
            return token;
        }
    }
    token.lexeme[0] = '\r';
    token.lex_lenght = 0;
    token.type = ENDF;
    return token;
}

void unget_token(token_t token, FILE *input_file)
{
    for (int i = token.lex_lenght - 1; i >= 0; i--)
    {
        ungetc(token.lexeme[i], input_file);
    }
}

int choose_symbol_index(char c)
{
    int i = 0;
    while (i < alphabet_length)
    {
        if (alphabet[i] == c)
            return i;
        i++;
    }
    if (isdigit(c))
        return i;
    i++;
    if (isblank(c))
        return i;
    i++;
    return i;
}