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
    int r;
    for (r = 0; a; a = a->prox, r++)
        ;
    return r;
}

void freeL(LInt a)
{
    LInt next;
    while (a)
    {
        next = a->prox;
        a->prox = NULL;
        free(a);
        a = next;
    }
}

void imprimeL(LInt a)
{
    for (; a; a = a->prox)
        printf("%d\n", a->valor);
}

LInt reverseL(LInt l)
{
    LInt r, ant, next;
    r = l;
    ant = NULL;
    if (l && l->prox)
    {
        while (r && r->prox)
        {
            next = r->prox;
            r->prox = ant;
            ant = r;
            r = next;
        }
        r->prox = ant;
    }
    return r;
}

void insertOrd(LInt *a, int x)
{
    LInt p, r, ant;
    ant = NULL;
    p = *a;
    if (!p)
    {
        *a = malloc(sizeof(struct lligada));
        (*a)->valor = x;
        (*a)->prox = NULL;
    }
    else
    {
        while (p && p->valor < x)
        {
            ant = p;
            p = p->prox;
        }
        r = malloc(sizeof(struct lligada));
        r->valor = x;
        if (ant)
        {
            r->prox = p;
            ant->prox = r;
        }
        else
        {
            r->prox = p;
            (*a) = r;
        }
    }
}

int removeOneOrd(LInt *a, int x)
{
    LInt pt, ant;
    int r;
    r = 1;
    ant = NULL;
    pt = *a;
    if (pt)
    {
        while (pt && pt->valor != x)
        {
            ant = pt;
            pt = pt->prox;
        }
        if (!ant && pt->valor == x)
        {
            pt = pt->prox;
            free(*a);
            *a = pt;
            r = 0;
        }
        else if (pt && pt->valor == x)
        {
            ant->prox = pt->prox;
            free(pt);
            r = 0;
        }
    }
    return r;
}

void merge(LInt *r, LInt a, LInt b)
{
    if (!a)
        *r = b;
    else if (!b)
        *r = a;
    else if (a->valor < b->valor)
    {
        *r = a;
        merge(&(*r)->prox, a->prox, b);
    }
    else
    {
        *r = b;
        merge(&(*r)->prox, a, b->prox);
    }
}

void splitQS(LInt l, int x, LInt *mx, LInt *Mx)
{
    if (l)
    {
        if (l->valor < x)
        {
            *mx = malloc(sizeof(struct lligada));
            (*mx)->valor = l->valor;
            splitQS(l->prox, x, &(*mx)->prox, Mx);
        }
        else
        {
            *Mx = malloc(sizeof(struct lligada));
            (*Mx)->valor = l->valor;
            splitQS(l->prox, x, mx, &(*Mx)->prox);
        }
    }
}

LInt parteAmeio(LInt *l)
{
    LInt ant, pt;
    ant = NULL;
    int tam, i;
    for (tam = 0, pt = *l; pt; pt = pt->prox, tam++)
        ;
    pt = *l;
    for (i = 0; *l && i < tam / 2; i++)
    {
        ant = *l;
        *l = (*l)->prox;
    }
    if (ant)
        ant->prox = NULL;
    else
        pt = NULL;
    return pt;
}

int removeAll(LInt *l, int x)
{
    int r;
    r = 0;
    LInt ant, pt, next;
    if (*l)
    {
        ant = NULL;
        pt = *l;
        while (pt)
        {
            if (ant && pt->valor == x)
            {
                ant->prox = pt->prox;
                free(pt);
                pt = ant;
                ant = pt;
                pt = pt->prox;
                ++r;
            }
            else if (pt->valor == x)
            {
                pt = (*l)->prox;
                free(*l);
                *l = pt;
                ++r;
            }
            else
            {
                ant = pt;
                pt = pt->prox;
            }
        }
    }
    return r;
}

int removeDups(LInt *l)
{
    int i;
    i = 0;
    if (l)
    {
        LInt ant, next, pt;
        pt = *l;
        while (pt)
        {
            ant = pt;
            next = pt->prox;
            while (next)
            {
                if (pt->valor == next->valor)
                {
                    ant->prox = next->prox;
                    free(next);
                    next = ant->prox;
                    ++i;
                }
                else
                {
                    ant = next;
                    next = next->prox;
                }
            }
            pt = pt->prox;
        }
    }
    return i;
}

int removeMaiorL(LInt *l)
{
    LInt pt, ant;
    ant = NULL;
    int maior;
    maior = (*l)->valor;
    for (pt = *l; pt; pt = pt->prox)
        if (pt->valor > maior)
            maior = pt->valor;
    pt = *l;
    while (pt->valor != maior)
    {
        ant = pt;
        pt = pt->prox;
    }
    if (ant)
    {
        ant->prox = pt->prox;
        free(pt);
    }
    else
    {
        pt = pt->prox;
        free(*l);
        *l = pt;
    }
    return maior;
}

void init(LInt *l)
{
    if (*l)
    {
        LInt pt, ant;
        for (pt = *l, ant = NULL; pt->prox; ant = pt, pt = pt->prox)
            ;
        if (ant)
        {
            free(pt);
            ant->prox = NULL;
        }
        else
        {
            pt = pt->prox;
            free(*l);
            *l = pt;
        }
    }
}

void appendL(LInt *l, int x)
{
    LInt pt, new;
    for (pt = *l; pt && pt->prox; pt = pt->prox)
        ;
    new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if (!pt)
        *l = new;
    else
        pt->prox = new;
}

void concatL(LInt *a, LInt b)
{
    if (*a)
    {
        LInt pt;
        for (pt = *a; pt->prox; pt = pt->prox)
            ;
        pt->prox = b;
    }
    else
        *a = b;
}

LInt cloneL(LInt l)
{
    LInt r, pt;
    r = NULL;
    if (l)
    {
        r = malloc(sizeof(struct lligada));
        r->valor = l->valor;
        r->prox = cloneL(l->prox);
    }
    return r;
}

int maximo(LInt l)
{
    int maior;
    maior = l->valor;
    l = l->prox;
    for (; l; l = l->prox)
        if (l->valor > maior)
            maior = l->valor;
    return maior;
}

int take(int n, LInt *l)
{
    int i;
    LInt next, pt, ant;
    pt = *l;
    for (i = 0, ant = NULL; pt && n > 0; n--, ant = pt, pt = pt->prox)
        ++i;
    for (; pt && pt->prox; pt = pt->prox)
    {
        next = pt->prox;
        pt = NULL;
        free(pt);
        pt = next;
    }
    if (ant)
    {
        free(pt);
        ant->prox = NULL;
    }
    return i;
}

int drop(int n, LInt *l)
{
    int i;
    LInt next;
    for (i = 0; *l && (*l)->prox && n > 0; n--)
    {
        next = (*l)->prox;
        free(*l);
        *l = next;
        i++;
    }
    if (*l && !(*l)->prox && n > 0)
    {
        ++i;
        free(*l);
        *l = NULL;
    }
    return i;
}

LInt Nforward(LInt l, int n)
{
    for (; l && n > 0; n--, l = l->prox)
        ;
    return l;
}

int listToArray(LInt l, int v[], int N)
{
    int i;
    for (i = 0; i < N && l; l = l->prox, i++)
        v[i] = l->valor;
    return i;
}

LInt arrayToList(int v[], int N)
{
    int i;
    LInt r;
    r = NULL;
    if (N > 0)
    {
        r = malloc(sizeof(struct lligada));
        r->valor = v[0];
        r->prox = arrayToList(v + 1, N - 1);
    }
    return r;
}

LInt somasAcL(LInt l)
{
    int soma;
    LInt r, pt;
    if (l)
    {
        soma = 0;
        r = malloc(sizeof(struct lligada));
        pt = r;
        while (l)
        {
            soma += l->valor;
            pt->valor = soma;
            if (l->prox)
            {
                pt->prox = malloc(sizeof(struct lligada));
                pt = pt->prox;
            }
            l = l->prox;
        }
        pt->prox = NULL;
    }
    return r;
}

void remreps(LInt l)
{
    LInt pt, ant;
    for (; l; l = l->prox)
        for (pt = l, ant = NULL; pt; ant = pt, pt = pt->prox)
        {
            if (pt->valor == l->valor && ant)
            {
                ant->prox = pt->prox;
                free(pt);
                pt = ant;
            }
        }
}

LInt rotateL(LInt l)
{
    if (l && l->prox)
    {
        LInt move, pt;
        move = l;
        l = l->prox;
        pt = l;
        for (pt = l; pt->prox; pt = pt->prox)
            ;
        move->prox = NULL;
        pt->prox = move;
    }
    return l;
}

LInt parte(LInt l)
{
    LInt top;
    top = NULL;
    if (l && l->prox)
    {
        LInt r;
        top = l->prox;
        while (l && l->prox)
        {
            r = l->prox;
            l->prox = r->prox;
            l = r;
        }
    }
    return top;
}

typedef struct nodo
{
    int valor;
    struct nodo *esq, *dir;
} * ABin;

int altura(ABin a)
{
    int altur, hd, he;
    altur = 0;
    if (a)
    {
        hd = 1 + altura(a->dir);
        he = 1 + altura(a->esq);
        altur = hd > he ? hd : he;
    }
    return altur;
}

ABin cloneAB(ABin a)
{
    ABin r;
    r = NULL;
    if (a)
    {
        r = malloc(sizeof(struct nodo));
        r->valor = a->valor;
        r->dir = cloneAB(a->dir);
        r->esq = cloneAB(a->esq);
    }
    return r;
}

void mirror(ABin *a)
{
    ABin temp;
    if (*a)
    {
        temp = (*a)->dir;
        (*a)->dir = (*a)->esq;
        (*a)->esq = temp;
        mirror(&(*a)->esq);
        mirror(&(*a)->dir);
    }
}

void inorder(ABin a, LInt *l)
{
    if (a)
    {
        LInt new, pt;
        inorder(a->esq, l);
        for (; *l; l = &(*l)->prox)
            ;
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l = &(*l)->prox;
        inorder(a->dir, l);
    }
    else
        *l = NULL;
}

void preorder(ABin a, LInt *l)
{
    if (a)
    {
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l = &(*l)->prox;
        preorder(a->esq, l);
        for (; *l; l = &(*l)->prox)
            ;
        preorder(a->dir, l);
    }
    else
        *l = NULL;
}

void posorder(ABin a, LInt *l)
{
    if (a)
    {
        posorder(a->esq, l);
        for (; *l; l = &(*l)->prox)
            ;
        posorder(a->dir, l);
        for (; *l; l = &(*l)->prox)
            ;
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
    }
    else
        *l = NULL;
}

int depth(ABin a, int x)
{
    int r, hd, he;
    r = -1;
    if (a && a->valor == x)
        r = 1;
    else if (a)
    {
        hd = depth(a->dir, x);
        he = depth(a->esq, x);
        if (hd < 0 && he < 0)
            r = -1;
        else if (hd < 0)
            r = ++he;
        else if (he < 0)
            r = ++hd;
        else
            r = 1 + (hd < he ? hd : he);
    }
    return r;
}

int freeAB(ABin a)
{
    int r;
    r = 0;
    if (a)
    {
        r = 1;
        r += freeAB(a->dir);
        r += freeAB(a->esq);
        free(a);
    }
    return r;
}

int pruneAB(ABin *a, int l)
{
    int r;
    r = 0;
    if (*a && l == 1)
    {
        r += pruneAB(&(*a)->dir, l - 1);
        r += pruneAB(&(*a)->esq, l - 1);
        (*a)->dir = (*a)->esq = NULL;
    }
    else if (*a && l < 1)
    {
        r = 1;
        r += pruneAB(&(*a)->dir, l);
        r += pruneAB(&(*a)->esq, l);
        free(*a);
        *a = NULL;
    }
    else if (*a)
    {
        r += pruneAB(&(*a)->dir, l - 1);
        r += pruneAB(&(*a)->esq, l - 1);
    }
    return r;
}

int iguaisAB(ABin a, ABin b)
{
    int r;
    r = 1;
    if ((a && !b) || (b && !a))
        r = 0;
    else if (a && b)
    {
        if (a->valor != b->valor)
            r = 0;
        else
            r = iguaisAB(a->dir, b->dir) && iguaisAB(a->esq, b->esq);
    }
    return r;
}

int dumpAbin(ABin a, int v[], int N)
{
    int r;
    r = 0;
    if (a && N > 0)
    {
        r = dumpAbin(a->esq, v, N - 1);
        v[r] = a->valor;
        ++r;
        r += dumpAbin(a->dir, v + r, N - r);
    }
    return r;
}

ABin somasAcA(ABin a)
{
    ABin r, pt;
    r = NULL;
    if (a)
    {
        r = malloc(sizeof(struct nodo));
        r->valor = a->valor;
        r->dir = somasAcA(a->dir);
        r->esq = somasAcA(a->esq);
        if (r->dir)
            r->valor += r->dir->valor;
        if (r->esq)
            r->valor += r->esq->valor;
    }
    return r;
}

int contaFolhas(ABin a)
{
    int r;
    r = 0;
    if (a)
    {
        if (!a->dir && !a->esq)
            r = 1;
        else
            r = contaFolhas(a->dir) + contaFolhas(a->esq);
    }
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
        r->esq = cloneMirror(a->dir);
        r->dir = cloneMirror(a->esq);
    }
    return r;
}

int addOrd(ABin *a, int x)
{
    ABin pt;
    int r, ctl;
    pt = *a;
    r = 0;
    ctl = 1;
    while (pt && !r && ctl)
    {
        if (pt->valor == x)
            r = 1;
        else if (pt->valor < x && pt->dir)
            pt = pt->dir;
        else if (pt->valor > x && pt->esq)
            pt = pt->esq;
        else if (pt->valor < x)
        {
            pt->dir = malloc(sizeof(struct nodo));
            pt->dir->valor = x;
            pt->dir->dir = pt->dir->esq = NULL;
            ctl = 0;
        }
        else
        {
            pt->esq = malloc(sizeof(struct nodo));
            pt->esq->valor = x;
            pt->esq->dir = pt->esq->esq = NULL;
            ctl = 0;
        }
    }
    if (!pt)
    {
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->dir = (*a)->esq = NULL;
    }
    return r;
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
    int r, ctl;
    ctl = 0;
    while (a && !ctl)
    {
        if (a->valor < x)
            a = a->dir;
        else if (a->valor > x)
            a = a->esq;
        else
            ctl = 1;
        r++;
    }
    if (!ctl)
        r = -1;
    return r;
}

int maiorAB(ABin a)
{
    for (; a->dir; a = a->dir)
        ;
    return a->valor;
}

void removeMaiorA(ABin *a)
{
    if (*a)
    {
        ABin pt, ant;
        for (pt = *a, ant = NULL; pt->dir; ant = pt, pt = pt->dir)
            ;
        if (ant)
        {
            free(ant->dir);
            ant->dir = pt->esq;
        }
        else
        {
            *a = pt->esq;
            free(pt);
        }
    }
}

int quantosMaiores(ABin a, int x)
{
    int r;
    r = 0;
    if (a)
    {
        if (a->valor > x)
            ++r;
        r += quantosMaiores(a->dir, x) + quantosMaiores(a->esq, x);
    }
    return r;
}
