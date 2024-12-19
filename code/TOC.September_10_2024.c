// gcc TOC.September_10_2024.c -o TOC.September_10_2024 && ./TOC.September_10_2024

#include <stdio.h>

int automaton(void);
int choose_column(int alphabet_length, char alpabeth[], char c);
int is_final(int finals_length, int finals[], int state);

char result[100];
int result_index;
FILE *input_file;

int main(void)
{
    input_file = stdin;
    while (!feof(input_file))
    {
        result_index = 0;
        if (automaton())
        {
            result[result_index] = '\0';
            printf("Cadena valida %s\n", result);
        }
        else
        {
            printf("Cadena invalida\n");
        }
    }
    return 0;
}

int automaton(void)
{
    int states[][3] = {
        {2, 1, 4}, // 0
        {1, 1, 4}, // 1
        {2, 3, 4}, // 2
        {2, 3, 4}, // 3
        {4, 4, 4}, // 4
    };
    int finals[] = {1,3};
    int finals_length = 2;
    // int states[][3] = {
    //     {0, 1, 3}, // 0
    //     {0, 2, 3}, // 1
    //     {2, 2, 3}, // 2
    //     {3, 3, 3}, // 3
    // };
    // int finals[] = {2};
    // int finals_length = 1;
    char alphabet[] = {'a', 'b'};
    int alphabet_length = 2;
    int state = 0;
    char c;
    while (
        !feof(input_file) &&
        (c = getc(input_file)) != '\n')
    {
        result[result_index++] = c;
        int column = choose_column(alphabet_length, alphabet, c);
        state = states[state][column];
    }

    return is_final(finals_length, finals, state);
}

int choose_column(int alphabet_length, char alphabet[], char c)
{
    int i = 0;
    while (i < alphabet_length)
    {
        if (alphabet[i] == c)
            return i;
        i++;
    }
    return i;
}

int is_final(int finals_length, int finals[], int state)
{
    int i = 0;
    while (i < finals_length)
    {
        if (finals[i] == state)
            return 1;
        i++;
    }
    return 0;
}