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

LInt parteAmeio(LInt *a)
{
    int tam, i;
    LInt pt, r, ant, top;
    top = *a;
    ant = NULL;
    pt = *a;
    tam = 0;
    while (pt != NULL)
    {
        tam++;
        pt = pt->prox;
    }
    for (i = 0; i < tam / 2; i++)
    {
        r = malloc(sizeof(struct lligada));
        r = *a;
        ant = r;
        r = r->prox;
        *a = (*a)->prox;
    }
    if (ant != NULL)
    {
        ant->prox = NULL;
    }
    else
        top = NULL;
    return top;
}

int removeAll(LInt *l, int x)
{
    int r;
    LInt pt, ant;
    ant = NULL;
    pt = *l;
    r = 0;
    while (pt != NULL)
    {
        if (ant == NULL && pt->valor == x)
        {
            *l = (*l)->prox;
            free(pt);
            pt = *l;
            ++r;
        }
        else if (pt->valor == x)
        {
            ant->prox = pt->prox;
            free(pt);
            pt = pt->prox;
            ++r;
        }
        else
        {
            ant = pt;
            pt = pt->prox;
        }
    }
    return r;
}

int removeDups(LInt *l)
{
    int r;
    r = 0;
    LInt pt, ant, p;
    pt = *l;
    while (pt != NULL)
    {
        for (ant = pt, p = pt->prox; p != NULL; ant = p, p = p->prox)
            if (pt->valor == p->valor)
            {
                ant->prox = p->prox;
                free(p);
                p = ant;
                ++r;
            }
        pt = pt->prox;
    }
    return r;
}

int removeMaiorL(LInt *l)
{
    LInt pt, ant;
    int maior;
    pt = *l;
    maior = pt->valor;
    pt = pt->prox;
    for (; pt != NULL; pt = pt->prox)
        if (pt->valor > maior)
            maior = pt->valor;
    for (pt = *l, ant = NULL; pt != NULL && pt->valor != maior; ant = pt, pt = pt->prox)
        ;
    if (pt == NULL)
        ;
    else if (ant == NULL)
    {
        *l = (*l)->prox;
        free(pt);
    }
    else if (pt->valor == maior)
    {
        ant->prox = pt->prox;
        free(pt);
    }
    return maior;
}

void init(LInt *l)
{
    LInt pt, ant;
    pt = *l;
    ant = NULL;
    while (pt->prox != NULL)
    {
        ant = pt;
        pt = pt->prox;
    }
    free(pt);
    if (ant == NULL)
        *l = NULL;
    else
        ant->prox = NULL;
}

void appendL(LInt *l, int x)
{
    LInt new;
    new = malloc(sizeof(LInt));
    new->valor = x;
    new->prox = NULL;
    if (*l == NULL)
        *l = new;
    else
    {
        LInt pt;
        for (pt = *l; pt->prox != NULL; pt = pt->prox)
            ;
        pt->prox = new;
    }
}

void concatL(LInt *a, LInt b)
{
    LInt pt;
    if (*a == NULL)
        *a = b;
    else
    {
        for (pt = *a; pt->prox != NULL; pt = pt->prox)
            ;
        pt->prox = b;
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
    printLInt(parteAmeio(&r));
    printLInt(r);
    printf("%d\n", length(r));
    return 0;
}
