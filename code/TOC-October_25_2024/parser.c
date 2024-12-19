// gcc stack.c lexer.c parser.c -o parser && ./parser

// S -> E '\n'
// E -> M + E | M - E | M
// M -> P * M | P / M | P % M | P
// P -> F ^  P | F
// F -> N | -F | ( E )
//  N -> 0...9
#include <math.h>
#include "stack.h"
#include "lexer.h"

FILE *input_file;
snode_t *stack = NULL;

int S(), E(), M(), P(), F(), N();

int main(int argc, char **args)
{
    if (argc == 2)
        input_file = fopen(args[1], "r");
    else
        input_file = stdin;
    while (!feof(input_file))
    {
        if (S())
        {
            double *result = pop(&stack);
            printf("%.2lf\n", *result);
            printf("OK");
        }
        else
        {
            fprintf(stderr, "Operacion no reconocible");
            while (
                !feof(input_file) &&
                (getc(input_file)) != '\n')
                ;
        }
        putc('\n', stdout);
    }
}

// S -> E '\n'
int S()
{
    if (E())
    {
        token_t token = get_token(input_file);

        if (token.type == ENDL)
            return 1;
    }
    return 0;
}

// E -> M + E | M - E | M
int E()
{
    if (M())
    {
        token_t token = get_token(input_file);

        if (token.type == ADD)
        {
            if (E())
            {
                double *b = pop(&stack);
                double *a = pop(&stack);
                double *c = malloc(sizeof(double));
                *c = *a + *b;
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'+\'");
            return 0;
        }
        if (token.type == SUB)
        {
            if (E())
            {
                double *b = pop(&stack);
                double *a = pop(&stack);
                double *c = malloc(sizeof(double));
                *c = *a - *b;
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'-\'");
            return 0;
        }
        unget_token(token, input_file);

        return 1;
    }
    return 0;
}

// P * M | P / M | P % M | P
int M()
{
    if (P())
    {
        token_t token = get_token(input_file);

        if (token.type == MULT)
        {
            if (M())
            {
                double *b = pop(&stack);
                double *a = pop(&stack);
                double *c = malloc(sizeof(double));
                *c = *a * *b;
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'*\'");
            return 0;
        }
        if (token.type == DIV)
        {
            if (M())
            {
                double *b = pop(&stack);
                double *a = pop(&stack);
                double *c = malloc(sizeof(double));
                *c = *a / *b;
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'/\'");
            return 0;
        }
        if (token.type == MOD)
        {
            if (M())
            {
                double *b = pop(&stack);
                double *a = pop(&stack);
                double *c = malloc(sizeof(double));
                *c = fmod(*a, *b);
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'\%\'");
            return 0;
        }
        unget_token(token, input_file);

        return 1;
    }
    return 0;
}
// P -> F ^ P | F
int P()
{
    if (F())
    {
        token_t token = get_token(input_file);

        if (token.type == POW)
        {
            if (P())
            {
                double *b = pop(&stack);
                double *a = pop(&stack);
                double *c = malloc(sizeof(double));
                *c = pow(*a, *b);
                push(&stack, c);
                free(a);
                free(b);
                return 1;
            }
            fprintf(stderr, "Se esperaba algo despues de \'^\'");
            return 0;
        }
        unget_token(token, input_file);
        return 1;
    }
    return 0;
}

// F -> N | -F | ( E )
int F()
{
    if (N())
        return 1;
    token_t token = get_token(input_file);

    if (token.type == SUB)
    {
        if (F())
        {
            double *value = top(&stack);
            *value *= -1;
            return 1;
        }
        fprintf(stderr, "Se esperaba un factor despues de -");
        return 0;
    }
    if (token.type == L_P)
    {
        if (E())
        {
            token_t token = get_token(input_file);
            if (token.type == ERR)
            {
                fprintf(stderr, "Caracter no reconocible o sobrante.");
                unget_token(token, input_file);
                return 0;
            }
            if (token.type == R_P)
            {
                return 1;
            }
            unget_token(token, input_file);
            fprintf(stderr, "Se esperaba un \')\'");
            return 0;
        }
    }

    unget_token(token, input_file);
    return 0;
}
// N -> 0...9
int N()
{
    token_t token = get_token(input_file);

    if (token.type == NUM)
    {
        double *value = malloc(sizeof(double));
        *value = atof(token.lexeme);
        push(&stack, value);
        return 1;
    }
    unget_token(token, input_file);
    return 0;
}