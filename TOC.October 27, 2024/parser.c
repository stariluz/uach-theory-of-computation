#include <stdio.h>
#include "stack.h"
#include <ctype.h>
#include "lexer.h"
#include <math.h>

//S -> E '\n'
//E -> M + E | M - E | M
//M -> P * M | P / M | P % M | P
//P -> F ^ P | F
//F -> N | -F | ( E )
//N -> 0...9
FILE *entrada;

snode_t *pila = NULL;

int S();
int E();
int M();
int P();
int F();
int N();

int main(int argc, char **args){
    if(argc == 2) entrada = fopen(args[1], "r");
    else entrada = stdin;
    while(!feof(entrada)){
        if(S()){
            double *resultado = pop(&pila);
            printf("%.2lf\n", *resultado);  
            printf("OK");  
        } 
        else while(!feof(entrada) && (getc(entrada))!='\n');
        putc('\n', stdout);
    }
    return 0;
}

//S -> E '\n'
int S(){
    if(E()){
        token_t t = get_token(entrada);
        if(t.type == ENDL){
            return 1;
        }
        
    }
    return 0;
}

//E -> M + E | M - E | M
int E(){
    if(M()){
        token_t t = get_token(entrada);
        if(t.type == ADD){
            if(E()){
                double *b = pop(&pila);
                double *a = pop(&pila);
                double *c = malloc(sizeof(double));
                *c = *a + *b;
                push(&pila, c);
                free(a); free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despúes de \'*\'\n");
            return 0;
        }
        if(t.type == SUB){
            if(E()){
                double *b = pop(&pila);
                double *a = pop(&pila);
                double *c = malloc(sizeof(double));
                *c = *a - *b;
                push(&pila, c);
                free(a); free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despúes de \'/\'\n");
            return 0;
        }
        
        unget_token(t,entrada);
        return 1;
    }
    return 0;
}

//M -> P * M | P / M | P % M | P
int M(){
    if(P()){
        token_t t = get_token(entrada);
        if(t.type == MULT){
            if(M()){
                double *b = pop(&pila);
                double *a = pop(&pila);
                double *c = malloc(sizeof(double));
                *c = *a * *b;
                push(&pila, c);
                free(a); free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despúes de \'*\'\n");
            return 0;
        }
        if(t.type == DIV ){
            if(M()){
                double *b = pop(&pila);
                double *a = pop(&pila);
                double *c = malloc(sizeof(double));
                *c = *a / *b;
                push(&pila, c);
                free(a); free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despúes de \'/\'\n");
            return 0;
        }
        if(t.type == MOD){
            if(M()){
                double *b = pop(&pila);
                double *a = pop(&pila);
                double *c = malloc(sizeof(int));
                *c = fmod(*a, *b);
                push(&pila, c);
                free(a); free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despúes de \'%\'\n");
            return 0;
        }
        unget_token(t,entrada);
        return 1;
    }
    return 0;
}

//P -> F ^ P | F
int P(){
    if(F()){
        token_t t = get_token(entrada);
        if(t.type == POT){
            if(P()){
                double *b = pop(&pila);
                double *a = pop(&pila);
                double *c = malloc(sizeof(double));
                *c = pow(*a, *b);
                push(&pila, c);
                free(a); free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despúes de \'^\'\n");
            return 0;
        }
        unget_token(t,entrada);
        return 1;
    }
    return 0;
}

//F -> N | -F | ( E )
int F(){
    if(N()) return 1;
    token_t t = get_token(entrada);
    if(t.type == SUB){
        if(F()){
            double *valor = top(&pila);
            *valor *= -1;
            return 1;
        }
        fprintf(stderr, "Se esperaba un factor despúes de \'-\'\n");
        return 0;
    }
    if(t.type == L_P){
        if(E()){
            token_t t = get_token(entrada);
            if(t.type == R_P){
                return 1;
            } 
            unget_token(t,entrada);
            fprintf(stderr, "Se esperaba un  \')\'\n");
            return 0;
        }
    }
    unget_token(t,entrada);
    return 0;
}

//N -> 0 - 9
int N(){
    token_t t = get_token(entrada);
    if(t.type == NUM){
        double *valor = malloc(sizeof(double));
        *valor = atof(t.lexeme);
        push(&pila, valor);
        return 1;  

    }
    unget_token(t,entrada);
    return 0;
}