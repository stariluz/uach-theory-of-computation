#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int S();
int A();
int N();
int N1();
int C();
int L();
int D();
char w[100];
int i = 0;
int main(void)
{
    while (!feof(stdin))
    {
        i=0;
        if (S() && getc(stdin) == '\n')
        {
            w[i] = '\0';
            printf("%s\n", w);
        }
        else
        {
            while (getc(stdin) != '\n' && !feof(stdin))
                ;
        }
        // char c=getc(stdin);
        // putc(c, stdout);
    }
    return 0;
}

// S -> NAD
int S()
{
    if (N())
    {
        if (A())
        {
            if (D())
            {
                return 1;
            }
        }
    }
    return 0;
}

// N -> LN'
int N()
{
    if (L())
    {
        return N1();
    }
    return 0;
}

// N' -> LN' | _N' | null
int N1()
{
    if (L())
    {
        return N1();
    }

    char c = getc(stdin);
    if (c == '_')
    {
        w[i++] = c;
        return N1();
    }

    ungetc(c, stdin);

    return 1;
}

// L -> a,....,z
int L()
{
    char c = getc(stdin);
    if (isalpha(c))
    {
        w[i++] = c;
        return 1;
    }
    ungetc(c, stdin);
    return 0;
}

// A -> @
int A()
{
    char c = getc(stdin);
    if (c == '@')
    {
        w[i++] = c;
        return 1;
    }
    ungetc(c, stdin);
    return 0;
}

// A -> NC
int D()
{
    if (N())
    {
        return C();
    }
    return 0;
}

// C -> .LLL
int C()
{
    char c = getc(stdin);
    if (c == '.')
    {
        w[i++] = c;
        if (L())
        {
            if (L())
            {
                return L();
            }
        }
    }

    ungetc(c, stdin);
    return 0;
}