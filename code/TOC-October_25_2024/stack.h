#ifndef _STACK_
#define _STACK_

#include <stdlib.h>

struct stack_node
{
    void *data;
    struct stack_node *next;
};
typedef struct stack_node snode_t;

extern void push(snode_t **stack, void *data);
extern void *pop(snode_t **stack);
extern void *top(snode_t **stack);

#endif