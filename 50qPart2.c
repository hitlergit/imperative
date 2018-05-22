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

void freeL(LInt a)
{
    LInt prox;
    while (a != NULL)
    {
        prox = a->prox;
        free(a);
        a = NULL;
        a = prox;
    }
    return;
}

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

LInt cloneL(LInt l)
{
    LInt r;
    if (l == NULL)
        r = NULL;
    else
    {
        r = malloc(sizeof(LInt));
        r->valor = l->valor;
        r->prox = cloneL(l->prox);
    }
    return r;
}

// LInt cloneRev(LInt l)
// {
//     LInt r;
//     if(l == NULL)
//         r = NULL;
//     else if(l->prox == NULL)
//     {

//     }
// }

int maximo(LInt l)
{
    int maior;
    maior = l->valor;
    l = l->prox;
    for (; l != NULL; l = l->prox)
        if (l->valor > maior)
            maior = l->valor;
    return maior;
}

int take(int n, LInt *l)
{
    int i;
    LInt pt, next, stop;
    stop = NULL;
    pt = *l;
    if (pt == NULL)
        i = 0;
    else
    {
        for (i = 0; i < n && pt != NULL; i++)
        {
            stop = pt;
            pt = pt->prox;
        }
        while (pt != NULL && pt->prox != NULL)
        {
            next = pt->prox;
            free(pt);
            pt = next;
        }
        if (stop != NULL)
            stop->prox = NULL;
    }
    return i;
}

int drop(int n, LInt *l)
{
    int i;
    LInt pt, next;
    pt = *l;
    for (i = 0; i < n && pt != NULL; i++)
    {
        next = pt->prox;
        free(pt);
        pt = next;
    }
    *l = pt;
    return i;
}

LInt NForward(LInt l, int N)
{
    int i;
    for (i = 0; i < N; i++, l = l->prox)
        ;
    return l;
}

int listToArray(LInt l, int v[], int N)
{
    int i;
    for (i = 0; l != NULL && i < N; i++, l = l->prox)
        v[i] = l->valor;
    return i;
}

LInt arrayToList(int v[], int N)
{
    LInt r;
    if (N > 0)
    {
        r = malloc(sizeof(LInt));
        r->valor = v[0];
        r->prox = arrayToList(v + 1, N - 1);
    }
    else
        r = NULL;
    return r;
}

LInt somasAcL(LInt l)
{
    LInt top, new;
    int sum;
    sum = 0;
    if (l == NULL)
        top = NULL;
    else
    {
        top = malloc(sizeof(LInt));
        new = top;
        while (l != NULL)
        {
            sum += l->valor;
            new->valor = sum;
            if (l->prox != NULL)
            {
                new->prox = malloc(sizeof(LInt));
                new = new->prox;
            }
            l = l->prox;
        }
        new->prox = NULL;
    }
    return top;
}

void remreps(LInt l)
{
    LInt next;
    while (l && l->prox)
    {
        next = l->prox;
        if (l->valor == next->valor)
        {
            l->prox = next->prox;
            free(next);
            next = l->prox;
        }
        else
            l = l->prox;
    }
}

LInt rotateL(LInt l)
{
    if (l && l->prox)
    {
        LInt fst;
        fst = l;
        while (l->prox)
            l = l->prox;
        l->prox = fst;
        l = fst->prox;
        fst->prox = NULL;
    }
    return l;
}

LInt parte(LInt l)
{
    LInt r, top, ant;
    int i;
    i = 1;
    if (!l || !l->prox)
        top = NULL;
    else
    {
        top = l->prox;
        while (l->prox)
        {
            r = l->prox;
            l->prox = l->prox->prox;
            l = r;
        }
    }
    return top;
}

int main()
{
    LInt l, x, r;
    x = l = NULL;
    r = malloc(sizeof(struct lligada));
    l = newLInt(2, l);
    l = newLInt(1, l);
    l = newLInt(1, l);
    freeL(l);
    printLInt(l);
    // printf("%d\n", length(l));
    // insertOrd(&l, 10);
    // x = newLInt(45, x);
    // x = newLInt(32, x);
    // printLInt(x);
    // // l = reverseL(l);
    // // removeOneOrd(&l, 2);
    // merge(&r, x, l);
    // printLInt(r);
    // printLInt(cloneL(r));
    // printf("%d\n", length(r));
    return 0;
}

typedef struct nodo
{
    int valor;
    struct nodo *dir, *esq;
} * ABin;

int altura(ABin a)
{
    int h, hd, he;
    if (a == NULL)
        h = -1;
    else
    {
        hd = 1 + altura(a->dir);
        he = 1 + altura(a->esq);
        h = hd > he ? hd : he;
    }
    return h;
}

ABin cloneAB(ABin a)
{
    ABin r;
    if (a == NULL)
        r = NULL;
    else
    {
        r = malloc(sizeof(ABin));
        r->valor = a->valor;
        r->dir = cloneAB(a->dir);
        r->esq = cloneAB(a->esq);
    }
    return r;
}

void mirror(ABin *a)
{
    if (*a != NULL)
    {
        ABin swap;
        swap = (*a)->dir;
        (*a)->dir = (*a)->esq;
        (*a)->esq = swap;
        mirror(&(*a)->dir);
        mirror(&(*a)->esq);
    }
}

LInt *inorder(ABin a, LInt *l)
{
    LInt new;
    if (a == NULL)
    {
        *l = NULL;
    }
    else
    {
        *l = *inorder(a->esq, l);
        new = malloc(sizeof(LInt));
        new->valor = a->valor;
        new->prox = *inorder(a->dir, l);
        (*l)->prox = new;
    }
    return l;
}

void preorder(ABin a, LInt *l)
{
    LInt pt;
    if (a == NULL)
        *l = NULL;
    else
    {
        *l = malloc(sizeof(LInt));
        (*l)->valor = a->valor;
        preorder(a->esq, &(*l)->prox);
        pt = *l;
        while (pt->prox != NULL)
            pt = pt->prox;
        preorder(a->dir, &pt->prox);
    }
}

// void posorder(ABin a, LInt *l)
// {
//     LInt pt, new;
//     if (a == NULL)
//         *l = NULL;
//     else
//     {
//         posorder(a->esq, l);
//         for (pt = *l; !pt->prox; pt = pt->prox)
//             ;
//         posorder(a->dir, &pt->prox);
//         for (; !pt->prox; pt = pt->prox)
//             ;
//         new = malloc(sizeof(LInt));
//         new->valor = a->valor;
//         new->prox = NULL;
//         pt->prox = new;
//     }
// }

int depth(ABin a, int x)
{
    int h, hd, he;
    if (a == NULL)
        h = -1;
    else if (a->valor == x)
        h = 1;
    else
    {
        hd = depth(a->dir, x);
        he = depth(a->esq, x);
        if (hd < 0 && he < 0)
            h = -1;
        else if (hd < 0)
            h = ++he;
        else if (he < 0)
            h = ++hd;
        else
            h = 1 + (hd > he ? he : hd);
    }
    return h;
}

int freeAB(ABin a)
{
    int r;
    if (a == NULL)
        r = 0;
    else
    {
        r = 1 + freeAB(a->dir) + freeAB(a->esq);
        free(a);
    }
    return r;
}

int pruneAB(ABin *a, int l)
{
    int r;
    if (*a == NULL)
        r = 0;
    else if (l > 1)
        r = pruneAB(&(*a)->esq, l - 1) + pruneAB(&(*a)->dir, l - 1);
    else if (l == 1)
    {
        r = pruneAB(&(*a)->esq, l - 1) + pruneAB(&(*a)->dir, l - 1);
        (*a)->esq = (*a)->dir = NULL;
    }
    else
    {
        r = pruneAB(&(*a)->esq, l - 1) + pruneAB(&(*a)->dir, l - 1);
        *a = NULL;
        free(*a);
        ++r;
    }
    return r;
}

int iguaisAB(ABin a, ABin b)
{
    int r;
    r = 1;
    if ((a && !b) || (b && !a))
        r = 0;
    else if (!a && !b)
        r = 1;
    else if (a->valor == b->valor)
        r = iguaisAB(a->dir, b->dir) && iguaisAB(a->esq, b->esq);
    else
        r = 0;
    return r;
}

ABin somasAcA(ABin a)
{
    ABin r, dir, esq;
    if (a == NULL)
        r = NULL;
    else
    {
        r = malloc(sizeof(struct nodo));
        r->valor = 0;
        dir = somasAcA(a->dir);
        esq = somasAcA(a->esq);
        r->dir = dir;
        r->esq = esq;
        if (dir)
            r->valor += dir->valor;
        if (esq)
            r->valor += esq->valor;
        r->valor += a->valor;
    }
    return r;
}

int contaFolhas(ABin a)
{
    int r;
    r = 0;
    if (a && !a->dir && !a->esq)
        ++r;
    else if (a)
        r = contaFolhas(a->dir) + contaFolhas(a->esq);
    return r;
}

ABin cloneMirror(ABin a)
{
    ABin r;
    r = NULL;
    if (a)
    {
        r = malloc(sizeof(struct nodo));
        r->valor = a->valor;
        r->dir = cloneMirror(a->esq);
        r->esq = cloneMirror(a->dir);
    }
    return r;
}

int addOrd(ABin *a, int x)
{
    int r;
    r = 0;
    ABin pt, new;
    if (*a == NULL)
    {
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->dir = (*a)->esq = NULL;
    }
    else
    {
        pt = *a;
        while (pt && pt->valor != x)
        {
            if (pt->valor < x && !pt->esq)
            {
                new = malloc(sizeof(struct nodo));
                new->valor = x;
                new->dir = new->esq = NULL;
                pt->esq = new;
            }
            else if (pt->valor < x)
                pt = pt->esq;
            else if (pt->valor > x && !pt->dir)
            {
                new = malloc(sizeof(struct nodo));
                new->valor = x;
                new->dir = new->esq = NULL;
                pt->dir = new;
            }
            else if (pt->valor > x)
                pt = pt->dir;
            else
                r = 1;
        }
    }
}

int lookupAB(ABin a, int x)
{
    int r;
    r = 0;
    while (a && !r)
    {
        if (a->valor < x)
            a = a->dir;
        else if (a->valor > x)
            a = a->esq;
        else
            r = 1;
    }
    return r;
}

int depthOrd(ABin a, int x)
{
    int r;
    r = 1;
    while (a && a->valor != x)
    {
        if (a->valor > x)
            a = a->esq;
        else if (a->valor < x)
            a = a->dir;
        ++r;
    }
    if (!a)
        r = -1;
    return r;
}

int deProcura(ABin a)
{
    int rDir, rEsq, r;
    rDir = 1;
    rEsq = 1;
    r = 1;
    if (a)
    {
        if (a && !a->dir && !a->esq)
            r = 1;
        if (a && a->dir && a->valor < a->dir->valor)
            rDir = deProcura(a->dir);
        else if (a && a->esq && a->valor > a->esq->valor)
            rEsq = deProcura(a->esq);
        r = rDir && rEsq;
    }
    return r;
}