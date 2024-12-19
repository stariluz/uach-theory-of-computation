#include "stack.h"

void push(snode_t **stack, void *data){
    snode_t *new = malloc(sizeof(snode_t));
    new->data = data;
    new->next = *stack;
    *stack = new;
}

void *pop(snode_t **stack){
    if(!*stack) return NULL;
    snode_t *q = *stack;
    *stack = q->next;
    void *data = q->data;
    free(q);
    return data;
}

void *top(snode_t **stack){
    if(!*stack) return NULL;
    return (*stack)->data;
}