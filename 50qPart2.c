#include <stdio.h>
#include <stdlib.h>
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLInt(int v, LInt t)
{
    LInt new = (LInt) malloc(sizeof(LInt));
    if (new != NULL)
    {
        new -> valor = v;
        new -> prox  = t;
    }
    return new;
}

void printLInt(LInt l)
{
    if(l == NULL)
    {
        printf("NULL");
        return;
    }
    while(l != NULL)
    {
        printf("%d ", l -> valor);
        l = l -> prox;
    }
    putchar('\n');
    return;
}

int length(LInt a)
{
    int length;
    length = 0;
    for(length = 0; a != NULL; ++length, a = a -> prox);
    return length;
}

void freeL(LInt a)
{
    LInt *ant;
    while(a -> prox != NULL)
    {
        ant = &(a -> prox);
        free(a);
        a = *ant;
    }
    free(a);
    return;
}
    
void printL(LInt l)
{
    while(l != NULL)
    {
        printf("%d\n", l -> valor);
        l = l -> prox;
    }
    return;
}

LInt reverseL(LInt l)
{
    LInt ant, prox;
    ant = NULL;
    while(l != NULL)
    {
        prox = l -> prox;
        l -> prox = ant;
        ant = l;
        l = prox;
    }
    return ant;
}
/*
void insertOrd(LInt *l, int x)
{
    LInt ant, new;
    ant = NULL;
    if((*l) == NULL)
    {
        *
}
*/

int main()
{
    LInt l;
    l = NULL;
    l = newLInt(1, l);
    l = newLInt(2, l);
    printLInt(l);
    printf("%d\n", length(l));
    freeL(l);
    printLInt(l);
    printf("%d\n", length(l));
    return 0;
}

