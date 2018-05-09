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
    LInt ant, new, at;
    at = (*l);
    ant = NULL;
    if ((*l) == NULL)
    {
        new = malloc(sizeof(struct lligada));
        new->valor = x;
        new->prox = NULL;
        *l = new;
    }
    else
    {
        while (at != NULL && at->valor < x)
        {
            ant = at;
            at = at->prox;
        }
        new = malloc(sizeof(struct lligada));
        new->valor = x;
        new->prox = at;
        ant->prox = new;
    }
}

int removeOneOrd(LInt *l, int x)
{
    LInt pt, ant;
    pt = *l;
    ant = NULL;
    int r;
    r = 0;
    if (*l == NULL)
        r = 1;
    else
    {
        while (pt != NULL && pt->valor != x)
        {
            ant = pt;
            pt = pt->prox;
        }
        if (ant == NULL && pt->valor == x)
            (*l) = (*l)->prox;
        else if (ant == NULL)
        {
            r = 1;
        }
        else
        {
            ant->prox = pt->prox;
            free(pt);
        }
    }
    return r;
}

int main()
{
    LInt l;
    l = NULL;
    l = newLInt(2, l);
    l = newLInt(1, l);
    // l = newLInt(1, l);
    printLInt(l);
    printf("%d\n", length(l));
    insertOrd(&l, 10);
    // freeL(l);
    // l = reverseL(l);
    removeOneOrd(&l, 2);
    printLInt(l);
    printf("%d\n", length(l));
    return 0;
}
