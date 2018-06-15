#include <stdio.h>

#define MAX 100
typedef struct stack
{
    int sp;
    int valores[MAX];
} STACK;

void initStack(STACK *s)
{
    s->sp = 0;
}

int isEmptyS(STACK *s)
{
    return s->sp;
}

int push(STACK *s, int x)
{
    int r;
    r = 0;
    if(s->sp == MAX)
        r = 1;
    else
        s->valores[s->sp++] = x;
    return r;
}

int pop(STACK *s, int *x)
{
    int r;
    r = 0;
    if(!s->sp)
        r = 1;
    else
        *x = s->valores[--s->sp];
    return r;
}

int top(STACK *s, int *x)
{
    int r; 
    r = 0;
    if(!s->sp)
        r = 1;
    else
        *x = s->valores[s->sp - 1];
    return r;
}

typedef struct queue
{
    int inicio, tamanho;
    int valores[MAX];
} QUEUE;

void initQueue(QUEUE *q)
{
    q->inicio = q->tamanho = 0;
}

int isEmptyQ(QUEUE *q)
{
    return q->tamanho;
}

