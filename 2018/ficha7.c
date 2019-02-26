#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slist *LInt;

typedef struct slist {
    int valor;
    LInt prox;
} Nodo;

//a 1

LInt func (LInt a)
{
    a = malloc(sizeof(struct slist));
    a -> valor = 10;
    a -> prox = malloc(sizeof(struct slist));
    a -> prox -> valor = 5;
    a -> prox -> prox = malloc(sizeof(struct slist));
    a -> prox -> prox -> valor = 15;
    a -> prox -> prox -> prox = NULL;
    return a;
}

LInt cons(LInt l, int x)
{
    LInt new;
    new = malloc(sizeof(struct slist));
    new -> valor = x;
    new -> prox = l;
    return new;
}

LInt tail(LInt l)
{
    LInt r;
    r = l->prox;
    free(l);
    return r;
}

LInt init(LInt l)
{
    LInt pt;
    pt = l;
    if(pt == NULL || pt->prox == NULL)
        l = NULL;
    else
    {
        while(pt->prox->prox != NULL)
            pt = pt->prox;
        free(pt->prox);
        pt->prox= NULL;
    }
    return l;
}

LInt snoc(LInt l, int x)
{
    LInt pt, new;
    pt = l;

    while(pt != NULL && pt->prox !=NULL)
        pt = pt->prox;
    new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;
    if(pt == NULL)
        l = new;
    else
        pt->prox = new;
    return l;
}

LInt concat(LInt a, LInt b)
{
    LInt pt;
    for(pt = a; pt->prox != NULL; pt = pt->prox);
    pt->prox = b;
    return a;
}

void printList(LInt a)
{
    for(; a != NULL; a = a->prox)
        printf("%d ", a->valor);
    putchar('\n');
    return;
}

int main()
{
    LInt a;
    a = malloc(sizeof(struct slist));
    a = func(a);
    a = cons(a, 2);
    a = tail(a);
    a = init(a);
    a = snoc(a, 30);
    //a = concat(a,a);
    printList(a);
    return 0;
}

//2

typedef struct aluno {
    char nome[60];
    int numero;
    int nota;
} Aluno;

typedef struct turma {
    struct aluno aluno;
    struct turma *prox;
} *Turma;

int acrescentaAluno(Turma *t, Aluno a)
{
    int r;
    Turma new;
    if((*t) == NULL)
    {
        new = malloc(sizeof(struct turma));
        new->aluno = a;
        new->prox = NULL;
        *t = new;
        r = 0;
    }
    else
    {
        while((*t)->prox != NULL && (*t)->aluno.numero <= a.numero)
            *t = (*t)->prox;
        if((*t)->aluno.numero == a.numero)
            r = 1;
        else
        {
            new = malloc(sizeof(struct turma));
            new->aluno = a;
            new->prox = (*t)->prox;
            (*t)->prox = new;
            r = 0;
        }
    }
    return r;
}

Aluno *procura(Turma t, int numero)
{
    Aluno *aluno;
    for(; t != NULL && t->aluno.numero != numero; t = t->prox);
    if(t == NULL)
        aluno = NULL;
    else
        aluno = &(t->aluno);
    return aluno;
}

int passou(Turma t)
{
    int count;
    count = 0;
    for(; t != NULL; t = t->prox)
        if(t->aluno.nota >= 10)
            ++count;
    return count;
}

void imprimeT(Turma t)
{
    for(; t != NULL; t = t->prox)
        printf("%s %d %d \n", t->aluno.nome, t->aluno.numero, t->aluno.nota);
    return;
}

int main1()
{
    Aluno a;
    strcpy(a.nome, "Ola");
    a.numero = 123;
    a.nota = 9;
    Turma t;
    t = NULL;   
    acrescentaAluno(&t, a);
    if(procura(t, 123) != NULL)
        printf("Existe\n");
    if(procura(t, 456) == NULL)
        printf("aa\n");
    printf("%d\n", passou(t));
    imprimeT(t);
    return 0;
}
