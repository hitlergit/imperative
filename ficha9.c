#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct abin
{
    char *pal;
    int ocorr;
    struct abin *esq, *dir;
} * Dicionario;

typedef struct lista
{
    int valor;
    struct lista *prox;
} * LInt;

typedef struct abin *ABin;

void initDic(Dicionario *d)
{
    *d = malloc(sizeof(struct abin));
    *d = NULL;
}

int acrescenta(Dicionario *d, char *pal)
{
    int r;
    Dicionario pt, ant;
    r = 1;
    pt = *d;
    ant = NULL;
    while (pt != NULL && r == 1)
    {
        ant = pt;
        if (strcmp(pt->pal, pal) == 0)
            r = ++pt->ocorr;
        else if (strcmp(pt->pal, pal) > 0)
            pt = pt->dir;
        else
            pt = pt->esq;
    }
    if (*d == NULL)
    {
        *d = malloc(sizeof(struct abin));
        (*d)->pal = malloc(sizeof(pal) + 1);
        strcpy((*d)->pal, pal);
        (*d)->ocorr = 1;
        (*d)->dir = (*d)->esq = NULL;
    }
    else if (r == 1)
    {
        pt = malloc(sizeof(struct abin));
        pt->pal = malloc(sizeof(pal) + 1);
        strcpy(pt->pal, pal);
        pt->ocorr = 1;
        pt->dir = pt->esq = NULL;
        if (strcmp(ant->pal, pal) > 0)
            ant->dir = pt;
        else
            ant->esq = pt;
    }
    return r;
}

char *maisFreq(Dicionario d, int *c)
{
    char *at, *dirc, *esqc;
    int dir, esq;
    if (d == NULL)
    {
        *c = 0;
        at = NULL;
    }
    else
    {
        dirc = maisFreq(d->dir, &dir);
        esqc = maisFreq(d->esq, &esq);
        if (dirc == NULL && esqc == NULL)
        {
            at = d->pal;
            *c = d->ocorr;
        }
        else if (dirc != NULL && dir >= esq && dir >= d->ocorr)
        {
            at = dirc;
            *c = dir;
        }
        else if (esqc != NULL && esq > dir && esq > d->ocorr)
        {
            at = esqc;
            *c = esq;
        }
        else
        {
            *c = d->ocorr;
            at = d->pal;
        }
    }
    return at;
}

void imprimeL(Dicionario d)
{
    if (d == NULL)
        return;
    imprimeL(d->dir);
    printf("(%s %d)", d->pal, d->ocorr);
    imprimeL(d->esq);
    printf("\n");
    return;
}

int main()
{
    int x;
    char *z;
    Dicionario d;
    initDic(&d);
    acrescenta(&d, "aaaa");
    acrescenta(&d, "bbbb");
    acrescenta(&d, "aaaa");
    z = maisFreq(d, &x);
    printf("%s %d\n", z, x);
    imprimeL(d);
    return 0;
}
