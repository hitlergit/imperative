#include <stdio.h>
#include <ctype.h>
#include <math.h>

int isVowel (char a)
{
    a = toupper(a);
    return (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'); 
}

//1
int maior()
{
    int read,maior;
    scanf("%d",&read);
    maior = read;
    while (read != 0)
    {
        if (read > maior)
            maior = read;
        scanf("%d",&read);
    }
    printf("%d\n",maior);
    return 0;
}

//2
int media()
{
    int read,soma,n;
    float media;
    scanf("%d",&read);
    soma = 0;
    n = 0;
    while (read != 0)
    {
        soma += read;
        n++;
        scanf("%d",&read);
    }
    media = (float) soma/n;
    printf("%f\n",media);
    return 0;
}

//3
int sndM()
{
    int read,fst,snd;
    scanf("%d",&read);
    fst = snd = read;
    while (read != 0)
    {
        if(read > fst)
        {
            snd = fst;
            fst = read;
        }

        else if (read > snd || snd == fst)
            snd = read;
        
        scanf("%d",&read);
    }
    printf("%d\n",snd);
    return 0;
}

//4
int bitsUm (unsigned int n)
{
    int total;
    total = 0;
    while (n != 0)
        if (n%2 == 1)
        {
            total++;
            n /= 2;
        }
        else
            n/=2;
    return total;
}

//5
int trailingZ (unsigned int n)
{
    int z,x;
    z = -1;
    x = 1;
    while (n%x==0)
    {
        x *= 2;
        z++;
    }
    return z;
}

//6
int qDig (unsigned int n)
{
    int d;
    d = 0;
    while (n != 0)
    {
        n /= 10;
        d++;
    }
    return d;
}

//7
char *mystrcat(char s1[], char s2[])
{
    // adicione aqui o seu código
    int i, j;
    for (i = 0; s1[i]; i++);
    for (j = 0; s2[j]; j++)
        s1[i + j] = s2[j];
    s1[i + j] = '\0';
    return s1;
}

//8
char *mystrcpy(char *dest, char source[])
{
    int i;
    for (i = 0; source[i]; i++)
        *(dest + i) = source[i];
    *(dest + i) = '\0';
    return dest;
}

//9
int mystrcmp(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i]; i++);
    return s1[i]-s2[i];
}

//10 
char * mystrstr (char s1[], char s2[])
{
    int r1, r2;
    char * pos;
    pos = s1;
    r1 = 0;
    r2 = 0;
    while (s1[r1] && s2[r2])
    {
        if (s1[r1] == s2[r2])
        {
            r2++;
            if (pos == NULL)
                pos = s1+r1;
        }
        else 
        {
            r2 = 0;
            pos = NULL;
        }
        r1++;
    }
    if (s2[r2]) 
        pos = NULL;
    return pos;
}

//11
void strrev(char s[])
{
    char tmp;
    int i, j;
    for (i=0; s[i]; i++)
        ;
    for (j=0; j<i/2; j++)
    {
        tmp = s[j];
        s[j] = s[i-j-1];
        s[i-j-1] = tmp;
    }
}

//12
void strnoV(char s[])
{
    int i,w;
    w = 0;
    for (i=0; s[i]; i++)
        if (!isVowel(s[i]))
             s[w++] = s[i];
    s[w] = '\0';
}

//13
void truncW(char t[], int n)
{
    int i, r, w;
    r = 0;
    w = 0;
    i = 0;
    while (t[r])
    {
        if (t[r] == ' ')
        {
            i = 0;
            t[w] = t[r];
            w++;
            r++;
        }
        else if (i < n)
        {
            t[w] = t[r];
            i++;
            w++;
            r++;
        }
        else
            r++;
    }
    t[w] = '\0';
}

//14
char charMaisfreq(char s[])
{
    int i, j, qt, qta;
    char freq;
    freq = s[0];
    qt = 0;
    qta = 0;
    for (i = 0; s[i]; i++)
    {
        for (j = i; s[j]; j++)
            if (s[i] == s[j])
                qta++;
        if (qta > qt)
        {
            qt = qta;
            freq = s[i];
        }
        qta = 0;
    }
    if (!s[0])
        freq = 0;
    return freq;
}

//15
int iguaisConsecutivos(char s[])
{
    int sum, sumA, i;
    sum = 0;
    sumA = 1;
    i = 0;
    while (s[i])
        if (s[i] == s[i + 1])
        {
            sumA++;
            i++;
        }
        else
        {
            if (sumA > sum)
                sum = sumA;
            sumA = 1;
            i++;
        }
    return sum;
}

//16
int difConsecutivos(char s[])
{
    int sum, sumA, sumI, i, j, x, ctl;
    sum = 0;
    for (x = 0; s[x]; x++)
    {
        ctl = 1;
        sumA = 0;
        for (i = x; s[i] && ctl; i++)
        {
            sumI = 1;
            for (j = x; j < i && ctl; j++)
                if (s[j] == s[i])
                    ctl = 0;
                else
                    sumI++;
            if (sumI > sumA)
                sumA = sumI;
        }
        if (sumA > sum)
            sum = sumA;
    }
    return sum;
}

//17
int maiorPrefixo(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i]; i++)
        ;
    return i;
}

//18 
int maiorSufixo (char s1[], char s2[])
{
    int i,j,r;
    for (i=0; s1[i]; i++);
    for (j=0; s2[j];j++);
    r = -1;
    while (s1[i--] == s2 [j--])
        r++;
    return r;
}

//19
int sufPref(char s1[], char s2[])
{
    int i, r, t;
    r = 0;
    t = 0;
    for (i = 0; s1[i]; i++)
    {
        if (s1[i] == s2[r++])
            t++;
        else
            t = r = 0;
    }
    return t;
}

//20
int contaPal(char s[])
{
    int i, pal;
    pal = 0;
    for (i = 0; s[i]; i++)
    {
        if (!isspace(s[i]) && !s[i + 1])
            pal++;
        
        else if (!isspace(s[i]) && isspace(s[i + 1]))
            pal++;
    }
    return pal;
}

//21
int contaVogais(char s[])
{
    int r, total;
    total = 0;
    for (r=0; s[r]; r++)
    {
        if(isVowel(s[r]))
            total++;
    }
    return total;
}

//22
int contida(char a[], char b[])
{
    int i, j, c;
    c = 1;
    for (i = 0; a[i] && c; i++)
    {
        c = 0;
        for (j = 0; b[j] && !c; j++)
            if (a[i] == b[j])
                c = 1;
    }
    return c;
}

//23
int palindorome (char s[])
{
    int n,i,r;
    r = 1;
    for (n=0; s[n]; n++);
    for (i=0; i<=n && r; i++)
        if (s[i] == s[n-1])
        {
            r = 1;
            n--;
        }
        else 
            r = 0;
    return r;
}

//24
int remRep(char x[])
{
    int r, w;
    w = 1;
    for (r = 0; x[r]; r++)
        if (x[r] != x[r + 1])
        {
            x[w] = x[r + 1];
            w++;
        }
    return w - 1;
}

//25
int limpaEspacos(char t[])
{
    int r, w;
    w = 0;
    for (r = 0; t[r]; r++)
        if (!isspace(t[r]))
            t[w++] = t[r];

        else if (isspace(t[r]) && !isspace(t[r + 1]))
            t[w++] = t[r];

        else if (!isspace(t[r]) && isspace(t[r + 1]))
            t[w++] = t[r];

    t[w] = '\0';
    return w;
}

//26 maybe not working
void insere(int v[], int N, int x)
{
    int i;
    for (i = N - 1; v[i] > x; i--)
        v[i + 1] = v[i];
    v[i] = x;
}

//27
void merge (int r[], int a[], int b[], int na, int nb)
{
    int ra,rb,w;
    ra = rb = w = 0;
    while (ra<na && rb < nb)
    {
        if (a[ra]<b[rb]) 
            r[w++] = a[ra++];
        
        else 
            r[w++] = b[rb++];
    }
    while (ra<na)
        r[w++] = a[ra++];
    
    while (rb<nb)
        r[w++] = b[rb++];
}

//28
int crescente (int a[], int i, int j)
{
    int r;
    r = 1;
    for(;i<j && r;i++)
        if(a[i]>a[i+1])
            r = 0;
    
    return r;
}

//29
int retiraNeg (int v[], int N)
{
    int r,w,tam;
    w = 0;
    tam = N;
    for (r=0; r<N; r++)
        if (v[r] >= 0)
        {
            v[w++] = v[r]; 
        }
        else
            tam--;
    return tam;
}

//30
int menosFreq (int v[], int N)
{
    int r,cmp,freq,mFreq,vMF;
    mFreq = N;
    vMF = v[0];
    for (cmp = 0; cmp < N && mFreq != 1; cmp++)
    {
        freq = 0;
        for (r=0;r<N;r++)
            if (v[cmp] == v[r])
                freq++;
        if (mFreq>freq)
        {
            mFreq = freq;
            vMF = v[cmp];
        }
    }
    return vMF;
}

//31
int maisFreq (int v[], int N)
{
    int r,cmp,freq,mFreq,vMF;
    mFreq = 0;
    for (cmp = 0; cmp<N; cmp++)
    {
        freq = 0;
        for (r=0; r<N; r++)
            if (v[cmp] == v[r]) 
                freq++;
        if (freq > mFreq)
        {
            mFreq = freq;
            vMF = v[cmp];
        }
    }
    return vMF;    
}

//32
int maxCresc(int v[], int N)
{
    int r, nT, nA;
    nT = 0;
    nA = 1;
    for (r = 0; r < N; r++)
    {
        if (v[r + 1] >= v[r])
            nA++;
        else if (nA > nT)
        {
            nT = nA;
            nA = 1;
        }
        else
            nA = 1;
    }
    return nT;
}

//33
int elimRep(int v[], int n)
{
    int r, w, cmp, ctl;
    for (r = 0; r < n; r++)
    {
        w = r + 1;
        ctl = 0;
        for (cmp = r + 1; cmp < n + 1; cmp++)
            if (v[cmp] != v[r])
                v[w++] = v[cmp];
            else
                ctl++;
        n -= ctl;
    }
    return w;
}

//34
int elimRepOrd(int v[], int n)
{
    int r, w;
    w = 1;
    for (r = 1; r < n; r++)
        if (v[r - 1] != v[r])
            v[w++] = v[r];
    return w;
}

//35
int comunsOrd(int a[], int na, int b[], int nb)
{
    int ra, rb, comuns;
    rb = 0;
    ra = 0;
    comuns = 0;
    while (ra < na && rb < nb)
        if (a[ra] > b[rb])
            rb++;

        else if (a[ra] == b[rb])
        {
            ra++;
            rb++;
            comuns++;
        }

        else
            ra++;

    return comuns;
}

//36
int comuns(int a[], int na, int b[], int nb)
{
    int ra, rb, comuns;
    for (ra=0; ra<na; ra++)
        for (rb=0; rb<nb; rb++)
            if (a[ra] == b[rb])
                comuns++;
    return comuns;
}

//37
int minInd(int v[], int n)
{
    int r, minI;
    minI = 0;
    for (r = 0; r < n; r++)
        if (v[minI] > v[r])
            minI = r;
    return minI;
}

//38
void somasAc(int v[], int Ac[], int N)
{
    int i, sum;
    sum = 0;
    for (i = 0; i < N; i++)
        Ac[i] = sum += v[i];
}

//39
int triSup (int N, float m [N][N])
{
    int i,j,x;
    x = 1;
    for (i = 0; i < N && x; i++)
        for (j = 0; j < i && x; j++)
            if (m[i][j] != 0)
                x = 0;
    return x;
}

//40 
void transposta (int N, float m[N][N])
{
    int i,j,tmp;
    for (i = 0; i < N; i++)
        for (j = 0; j < N && i != j; j++)
        {
            tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
}

//41
void addTo(int N, int M, int a[N][M], int b[N][M])
{
    int i,j;
    for (i=0; i<N; i++)
        for (j=0; j<M; j++)
            a[i][j] += b[i][j];
}

//42
int unionSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for(i=0; i<N; i++)
        r[i] = (v1[i] || v2[i]);
    return 0;
}

//43
int intersectSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for (i = 0; i < N; i++)
        r[i] = (v1[i] && v2[i]);
    return 0;
}

//44

//45
 
//46

//47
typedef enum movimento { Norte,
                         Oeste,
                         Sul,
                         Este } Movimento;
typedef struct posicao
{
    int x, y;
} Posicao;

Posicao posFinal(Posicao inicial, Movimento mov[], int N)
{
    int i;
    for(i = 0; i < N; i++)
        if (mov[i] == Norte) 
            inicial.y++;
        
        else if(mov[i] == Sul)
            inicial.y--;
        
        else if(mov[i] == Este)
            inicial.x++;
        
        else 
            inicial.x--;
    return inicial;
}

//48
int caminho(Posicao inicial, Posicao final, Movimento mov[], int N)
{
    int movX, movY, nmovX, nmovY, i;
    movX = inicial.x - final.x;
    movY = inicial.y - final.y;
    if (movX < 0)
        nmovX = -movX;
    else
        nmovX = movX;

    if (movY < 0)
        nmovY = -movY;
    else
        nmovY = movY;

    if (nmovX + nmovY > N)
        N -= nmovX + nmovY;
    else
        N = nmovX + nmovY;

    for (i = 0; i < nmovX && i < N; i++)
        if (movX < 0)
            mov[i] = Este;
        else if (movX > 0)
            mov[i] = Oeste;

    for (; i < N; i++)
        if (movY > 0)
            mov[i] = Sul;
        else if (movY < 0)
            mov[i] = Norte;

    return N;
}

//49
int maiscentral(Posicao pos[], int N)
{
    int i, ind;
    float dist;
    dist = sqrt(pos[0].x * pos[0].x + pos[0].y * pos[0].y);
    ind = 0;
    for (i = 1; i < N; i++)
        if (dist > sqrt(pos[i].x * pos[i].x + pos[i].y * pos[i].y))
        {
            dist = sqrt(pos[i].x * pos[i].x + pos[i].y * pos[i].y);
            ind = i;
        }
    return ind;
}

//50 
int vizinhos(Posicao p, Posicao pos[], int N)
{
    int i,r;
    r = 0;
    for(i=0; i<N; i++)
    {
        if (p.x == pos[i].x)
            if (p.y == pos[i].y + 1 || p.y == pos[i].y -1)
                r++;
            else;
        
        else if(p.y == pos[i].y)
            if (p.x == pos[i].x + 1 || p.x == pos[i].x - 1)
                r++;
    }
    return r;
}

//main
int main()
{
    Posicao z;
    z.x = -1;
    z.y = -1;
    Movimento x[7] = {Oeste, Oeste, Oeste, Oeste, Oeste, Oeste};
    printf("%d\n", posFinal(z, x, 7).x);
    printf("%d\n", posFinal(z, x, 7).y);
    return 0;
}