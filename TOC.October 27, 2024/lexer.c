
#include "lexer.h"

int edos[][13]= {
//(  )  +  -  *  /  %  ^  .  \n DI BL OT      STATE
{ 1, 2, 3, 4, 5, 6, 13,14,8, 12,7, 0, 11}, // 0 (return LP)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 1 (return LP)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 2 (return RP)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 3 (return ADD)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 4 (return SUB)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 5 (return MULT)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 6 (return DIV)
{ 10,10,10,10,10,10,10,10,8, 10,7, 10,10}, // 7 (digit loop, decimal, anything other than decimal is sent to 10)
{ 11,11,11,11,11,11,11,11,11,11,9, 11,11}, // 8 (post-decimal first digit, other is sent to 11)
{ 10,10,10,10,10,10,10,10,10,10,9, 10,10}, // 9 (post-decimal digit loop, other is sent to 10)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 10 (unget, return NUM)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 11 (ERROR state)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 12 (End of line)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}, // 13 (return MOD)
{ 11,11,11,11,11,11,11,11,11,11,11,11,11}  // 14 (return POT)
};

char alfabeto[]={'(',')','+','-','*','/','%','^','.','\n'};
const int c_alfabeto = 10;

token_t get_token(FILE *entrada);
void unget_token(token_t t, FILE *entrada) ;
int elegir_columna( char c);


token_t get_token(FILE *entrada){
    int edo = 0;
    char c;
    token_t t;
    t.lex_len = 0;

    while(!feof(entrada)){
        c = getc(entrada);
        t.lexeme[t.lex_len++] = c;
        t.lexeme[t.lex_len] = '\0';
        int columna = elegir_columna(c);
        edo = edos[edo][columna];
        switch (edo)
        {
        case 1:
            t.type = L_P;
            return t;
        case 2:
            t.type = R_P;
            return t;
        case 3:
            t.type = ADD;
            return t;
        case 4:
            t.type = SUB;
            return t;
        case 5:
            t.type = MULT;
            return t;
        case 6:
            t.type = DIV;
            return t;
        case 10:
            ungetc(c,entrada);
            t.lexeme[--t.lex_len] = '\0';
            t.type = NUM;
            return t;
        case 11:
            t.type = ERR;
            return t;
        case 12:
            t.type = ENDL;
            return t;
        case 13:
            t.type = MOD;
            return t;
        case 14:
            t.type = POT;
            return t;
        }
    }
   
    t.lexeme[0]= '\0' ;
    t.lex_len = 0;
    t.type = ENDF;
    return t;
    
}

void unget_token(token_t t, FILE *entrada){
    for (int i=t.lex_len-1;i>=0;i--){
        ungetc(t.lexeme[i],entrada);
    }
}


int elegir_columna( char c){
    int i=0;
    while(i<c_alfabeto){
        if(alfabeto[i] == c) return i;
        i++;
    }
    if(isdigit(c)) return i;
    i++;
    if(isblank(c)) return i;
    i++;
    return i;
}