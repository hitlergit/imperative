#include <stdio.h>
#include <stdlib.h>
typedef struct lligada
{
    int valor;
    struct lligada *prox;
} * LInt;

LInt newLInt(int v, LInt t)
{
    LInt new = (LInt)malloc(sizeof(LInt));
    if (new != NULL)
    {
        new->valor = v;
        new->prox = t;
    }
    return new;
}

void printLInt(LInt l)
{
    if (l == NULL)
    {
        printf("NULL");
        return;
    }
    while (l != NULL)
    {
        printf("%d ", l->valor);
        l = l->prox;
    }
    putchar('\n');
    return;
}

int length(LInt a)
{
    int length;
    length = 0;
    for (length = 0; a != NULL; ++length, a = a->prox)
        ;
    return length;
}

// void freeL(LInt a)
// {
//     LInt prox, *ant;
//     ant = &a;
//     prox = a->prox;
//     while (*ant != NULL)
//     {
//         prox = (*ant)->prox;
//         free(*ant);
//         *ant = NULL;
//         ant = &prox;
//     }
//     a = NULL;
//     return;
// }

void printL(LInt l)
{
    while (l != NULL)
    {
        printf("%d\n", l->valor);
        l = l->prox;
    }
    return;
}

LInt reverseL(LInt l)
{
    LInt ant, prox;
    ant = NULL;
    if (l == NULL)
        ;
    else if (l->prox == NULL)
        ;
    else
    {
        while (l->prox != NULL)
        {
            prox = l->prox;
            l->prox = ant;
            ant = l;
            l = prox;
        }
        l->prox = ant;
    }
    return l;
}

void insertOrd(LInt *l, int x)
{
    LInt ant, prox, new;
    ant = NULL;
    if (*l == NULL)
    {
        *l = malloc(sizeof(LInt));
        (*l)->valor = x;
        (*l)->prox = NULL;
    }
    else
    {
        for (prox = *l; prox != NULL && prox->valor < x; ant = prox, prox = prox->prox)
            ;
        new = malloc(sizeof(LInt));
        new->valor = x;
        new->prox = prox;
        if (ant == NULL)
            *l = new;
        else
            ant->prox = new;
    }
}

int removeOneOrd(LInt *l, int x)
{
    int r;
    LInt pt, ant;
    ant = NULL;
    r = 0;
    if (*l == NULL)
        r = 1;
    else
    {
        for (pt = *l; pt != NULL && pt->valor < x; ant = pt, pt = pt->prox)
            ;
        if (pt == NULL)
            r = 1;
        else if (x == pt->valor)
        {
            if (ant != NULL && pt != NULL)
                ant->prox = pt->prox;
            else if (ant == NULL)
                *l = (*l)->prox;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

void merge(LInt *r, LInt a, LInt b)
{

    if (a == NULL)
        *r = b;
    else if (b == NULL)
        *r = a;
    else if (a->valor > b->valor)
    {
        *r = malloc(sizeof(LInt));
        (*r)->valor = b->valor;
        merge(&(*r)->prox, a, b->prox);
    }
    else
    {
        *r = malloc(sizeof(LInt));
        (*r)->valor = a->valor;
        merge(&(*r)->prox, a->prox, b);
    }
}

int main()
{
    LInt l, x, r;
    x = l = NULL;
    r = malloc(sizeof(struct lligada));
    l = newLInt(2, l);
    l = newLInt(1, l);
    // l = newLInt(1, l);
    printLInt(l);
    printf("%d\n", length(l));
    insertOrd(&l, 10);
    x = newLInt(45, x);
    x = newLInt(32, x);
    printLInt(x);
    // freeL(l);
    // l = reverseL(l);
    // removeOneOrd(&l, 2);
    merge(&r, x, l);
    printLInt(r);
    printf("%d\n", length(r));
    return 0;
}
