// gcc stack.c TOC.September_24_2024.c -o TOC.September_24_2024 && ./TOC.September_24_2024

#include <stdio.h>
#include <ctype.h>
#include "TOC-October_25_2024/stack.h"

//S -> E '\n'
//E -> M + E | M - E | M
//M -> F * M | F / M | F
//F -> N | -F | ( E )
// N -> 0...9

FILE *input_file;
snode_t *stack = NULL;

int S(), E(), M(), F(), N();

int main(int argc, char **args){
    if(argc == 2) input_file = fopen(args[1], "r");
    else input_file = stdin;
    while(!feof(input_file)){
        if(S()){
            int *result=pop(&stack);
            printf("%d\n", *result);
            printf("OK");
        }
        else while(!feof(input_file) && (getc(input_file))!='\n');
        putc('\n', stdout);
    }
}

// S -> E '\n'
int S(){
    if(E()){
        char c = getc(input_file);
        if(c == '\n') return 1;
    }
    return 0;
}


// E -> M + E | M - E | M
int E(){
    if(M()){
        char c = getc(input_file);
        if(c=='+'){
            if(E()){
                int *b = pop(&stack);
                int *a = pop(&stack);
                int *c = malloc(sizeof(int));
                *c = *a + *b;
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'+\'");
            return 0;
        }
        if(c=='-'){
            if(E()){
                int *b = pop(&stack);
                int *a = pop(&stack);
                int *c = malloc(sizeof(int));
                *c = *a - *b;
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'-\'");
            return 0;
        }
        ungetc(c, input_file);
        return 1;
    }
    return 0;
}

// M -> F * M | F / M | F
int M(){
    if(F()){
        char c = getc(input_file);
        if(c=='*'){
            if(M()){
                int *b = pop(&stack);
                int *a = pop(&stack);
                int *c = malloc(sizeof(int));
                *c = *a * *b;
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'*\'");
            return 0;
        }
        if(c=='/'){
            if(M()){
                int *b = pop(&stack);
                int *a = pop(&stack);
                int *c = malloc(sizeof(int));
                *c = *a / *b;
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'/\'");
            return 0;
        }
        ungetc(c, input_file);
        return 1;
    }
    return 0;
}
// F -> N | -F | ( E )
int F(){
    if(N()) return 1;
    char c = getc(input_file);
    if(c=='-'){
        if(F()){
            int *value = top(&stack);
            *value *= -1;
            return 1;
        }
        fprintf(stderr, "Se esperaba un factor despues de -");
        return 0;
    }
    if(c=='('){
        if(E()){
            char c = getc(input_file);
            if(c==')'){
                return 1;
            }
            fprintf(stderr, "Se esperaba un \')\'");
            ungetc(c, input_file);
            return 0;
        }
    }
    ungetc(c, input_file);
    return 0;
}
// N -> 0...9
int N(){
    char c = getc(input_file);
    if(isdigit(c)){
        int *value=malloc(sizeof(int));
        *value = c-48;
        push(&stack, value);
        return 1;
    }
    ungetc(c, input_file);
    return 0;
}