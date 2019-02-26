#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entrada {
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Dicionario;

#define HSIZE 1000
typedef Dicionario DicionarioH[HSIZE];
int hash (char *pal, int s)
{
    int r;
    for (r=0; *pal != '\0'; pal++)
        r += *pal;
    return (r%s);
}

void initDic(Dicionario *d)
{
    (*d) = NULL;
    return;
}

int acrescenta(Dicionario *d, char *pal)
{
    int r;
    r = 1;
    Dicionario z, x;
    if(*d == NULL)
    {
        *d = malloc(sizeof(struct entrada));
        (*d)->palavra = malloc(sizeof(pal) + 1);
        strcpy((*d)->palavra, pal);
        (*d)->ocorr = 1;
        (*d)->prox = NULL;
    }
    else
    {
        for(z = *d; z->prox != NULL && strcmp(z->palavra, pal); z = z->prox);
        if(!strcmp(z->palavra, pal))
            r = ++z->ocorr;
        else
        {
            x = malloc(sizeof(struct entrada));
            x->palavra = malloc(sizeof(pal)+1);
            strcpy(x->palavra, pal);
            x->ocorr = 1;
            x->prox = NULL;
         
            z->prox = x;
        }
    }
    return r;
}

char *maisFreq(Dicionario d, int *c)
{
    char *maisF;
    maisF = NULL;
    int x;
    x = 0;
    for(; d != NULL; d = d->prox)
        if(x < d->ocorr)
        {
            x = d->ocorr;
            maisF = d->palavra;
        }
    *c = x;
    return maisF;
}

int acrescentaH(DicionarioH *h, char *pal)
{
    int x;
    x = hash(pal, HSIZE);
    acrescenta((*h)+x, pal);
    return x;
}

void printD(Dicionario d)
{
    for(; d != NULL; d = d->prox)
        printf("%s %d\n", d->palavra, d->ocorr);
    return;
}

int main()
{
    Dicionario d;
    int *c;
    c = malloc(sizeof(int));    
    initDic(&d);
    acrescenta(&d, "abc");
    acrescenta(&d, "xyz");
    acrescenta(&d, "xyz");
    printf("%s ", maisFreq(d, c));
    printf("%d\n", *c);
    printD(d);
    return 0;
}

