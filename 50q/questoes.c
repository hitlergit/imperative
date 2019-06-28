#include <stdio.h>

#include <math.h>
#include <ctype.h>

int maior()
{
    int read, maior;
    scanf("%d", &read);
    maior = read;
    while (read != 0)
    {
        if (read > maior)
            maior = read;
        scanf("%d", &read);
    }
    printf("%d\n", maior);
    return 0;
}

int media()
{
    int soma, n, read;
    soma = 0;
    n = 0;
    scanf("%d", &read);
    while (read != 0)
    {
        soma += read;
        n++;
        scanf("%d", &read);
    }
    printf("%f", (float)soma / n);
    return 0;
}

int sndM()
{
    int fst, snd, read;
    scanf("%d", &read);
    fst = snd = read;
    while (read != 0)
    {
        if (read > fst)
        {
            snd = fst;
            fst = read;
        }
        else if (read > snd || snd == fst)
            snd = read;
        scanf("%d", &read);
    }
    printf("%d\n", snd);
    return 0;
}

int bitsUm(unsigned int n)
{
    int i;
    i = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
            i++;
        n /= 2;
    }
    return i;
}

int trailingZ(unsigned int n)
{
    int i, e;
    e = 0;
    i = 2;
    while (n % i == 0)
    {
        e++;
        i *= 2;
    }
    return e;
}

int qDig(unsigned int n)
{
    int i;
    i = 0;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return i;
}

char *mystrcat(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i]; i++)
        ;
    for (j = 0; s2[j]; j++)
        s1[i + j] = s2[j];
    s1[i + j] = '\0';
    return s1;
}

char *mystrcpy(char *dest, char source[])
{
    int i;
    for (i = 0; source[i]; i++)
        *(dest + i) = source[i];
    *(dest + i) = '\0';
    return dest;
}

int mystrcmp(char s1[], char s2[])
{
    int i;
    i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i])
        i++;
    return s1[i] - s2[i];
}

char *mystrstr(char s1[], char s2[])
{
    int r1, r2, i;
    char *pos;
    pos = s1;
    r1 = r2 = i = 0;
    while (s1[r1] && s2[r2])
    {
        if (s1[r1] == s2[r2])
        {
            r2++;
            i++;
            if (pos == NULL)
                pos = s1 + r1;
        }
        else
        {
            r1 -= i;
            r2 = 0;
            pos = NULL;
        }
        r1++;
    }
    if (s2[r2])
        pos = NULL;
    return pos;
}

void strrev(char s[])
{
    int i, j;
    char temp;
    for (i = 0; s[i + 1]; i++)
        ;
    for (j = 0; s[j] && j <= i / 2; j++)
    {
        temp = s[j];
        s[j] = s[i - j];
        s[i - j] = temp;
    }
}

int isvowel(char a)
{
    int ctl;
    if (a == 'a' || a == 'A')
        ctl = 1;
    else if (a == 'e' || a == 'E')
        ctl = 1;
    else if (a == 'i' || a == 'I')
        ctl = 1;
    else if (a == 'o' || a == 'O')
        ctl = 1;
    else if (a == 'u' || a == 'U')
        ctl = 1;
    else
        ctl = 0;
    return ctl;
}

void strnoV(char s[])
{
    int r, w;
    w = 0;
    for (r = 0; s[r]; r++)
        if (!isvowel(s[r]))
            s[w++] = s[r];
    s[w] = '\0';
}

void truncW(char s[], int n)
{
    int r, w, ctl;
    w = 0;
    ctl = 0;
    for (r = 0; s[r]; r++)
    {
        if (s[r] == ' ')
        {
            ctl = 0;
            s[w++] = s[r];
        }
        else if (ctl < n)
        {
            ctl++;
            s[w++] = s[r];
        }
    }
    s[w] = '\0';
}

char charMaisfreq(char s[])
{
    int r, cmp, atual, total;
    char c;
    total = 0;
    for (r = 0; s[r]; r++)
    {
        atual = 0;
        for (cmp = 0; s[cmp]; cmp++)
            if (s[r] == s[cmp])
                atual++;
        if (atual > total)
        {
            total = atual;
            c = s[r];
        }
    }
    return c;
}

int iguaisConsecutivos(char s[])
{
    int r, cmp, total;
    total = cmp = 1;
    if (!s[0])
        total = 0;
    for (r = 0; s[r]; r++)
    {
        if (s[r] == s[r + 1])
            cmp++;
        else if (cmp > total)
        {
            total = cmp;
            cmp = 1;
        }
        else
            cmp = 1;
    }
    return total;
}
//not working
int difConsecutivos(char s[])
{
    int i, j, z, cmp, total;
    total = 0;
    for (i = 0; s[i]; i++)
        for (j = i; s[j]; j++)
        {
            cmp = 0;
            for (z = i + 1; z < i; z++)
                if (s[j] != s[z])
                    cmp++;
            if (cmp > total)
                total = cmp;
        }
    return total;
}

int maiorPrefixo(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i] && s2[i]; i++)
        ;
    return i;
}

int maiorSufixo(char s1[], char s2[])
{
    int i, j, total;
    total = -1;
    for (i = 0; s1[i]; i++)
        ;
    for (j = 0; s2[j]; j++)
        ;
    while (s1[i] == s2[j])
    {
        i--;
        j--;
        total++;
    }
   // if(!s1[0] || !s2[0])
     //   total = 0;
    return total;
}

int sufPref(char s1[], char s2[])
{
    int i, j, total;
    j = 0;
    total = 0;
    for (i = 0; s1[i]; i++)
    {
        if (s1[i] == s2[j++])
            total++;
        else
            total = j = 0;
    }
    return total;
}

int contaPal(char s[])
{
    int i, pal;
    pal = 0;
    for (i = 0; s[i]; i++)
        if (!isspace(s[i]) && !s[i + 1])
            pal++;
        else if (!isspace(s[i]) && isspace(s[i + 1]))
            pal++;

    return pal;
}

int contaVogais(char s[])
{
    int i, total;
    total = 0;
    for (i = 0; s[i]; i++)
        if (isvowel(s[i]))
            total++;
    return total;
}

int contida(char a[], char b[])
{
    int i, j, ctl, ctl1;
    ctl = 1;
    for (i = 0; a[i] && ctl; i++)
    {
        ctl1 = 0;
        for (j = 0; b[j] && !ctl1; j++)
            if (a[i] == b[j])
                ctl1 = 1;
        ctl = ctl1;
    }
    return ctl;
}

int palindroma(char s[])
{
    int i, j, ctl;
    ctl = 1;
    for (i = 0; s[i + 1]; i++)
        ;
    for (j = 0; s[j] && j < i && ctl; j++)
        if (s[j] != s[i--])
            ctl = 0;
    return ctl;
}

int remRep(char x[])
{
    int i, w, count;
    count = w = 0;
    for (i = 0; x[i]; i++)
        if (x[i] != x[i + 1])
        {
            count++;
            x[w++] = x[i];
        }
    x[w] = '\0';
    return count;
}

int limpaEspacos(char t[])
{
    int i, w;
    w = 0;
    for (i = 0; t[i]; i++)
        if (isspace(t[i]) && isspace(t[i + 1]))
            ;
        else
            t[w++] = t[i];
    t[w] = '\0';
    return w;
}

void insere(int v[], int N, int x)
{
    while (v[N - 1] > x)
        v[N] = v[--N];
    v[N] = x;
}

void merge(int r[], int a[], int b[], int na, int nb)
{
    int i, j, z;
    j = z = 0;
    for (i = 0; j < na && z < nb; i++)
        if (a[j] < b[z] && j < na)
            r[i] = a[j++];
        else
            r[i] = b[z++];

    while (j < na)
        r[i++] = a[j++];
    while (z < nb)
        r[i++] = b[z++];
}

int crescente(int a[], int i, int j)
{
    int ctl;
    ctl = 1;
    for (; i < j && ctl; i++)
        if (a[i] > a[i + 1])
            ctl = 0;
    return ctl;
}

int retiraNeg(int v[], int N)
{
    int i, w;
    w = 0;
    for (i = 0; i < N; i++)
        if (v[i] >= 0)
            v[w++] = v[i];
    return w;
}

int menosFreq(int v[], int N)
{
    int freqA, n, freq, i;
    freq = N;
    freqA = 0;
    n = v[0];
    for (i = 0; i < N; i++)
        if (v[i] == v[i + 1])
            freqA++;
        else if (freqA < freq)
        {
            freq = freqA;
            freqA = 0;
            n = v[i];
        }
        else
            freqA = 0;
    return n;
}

int maisFreq(int v[], int N)
{
    int freqA, n, freq, i;
    freq = 0;
    freqA = 0;
    n = v[0];
    for (i = 0; i < N; i++)
        if (v[i] == v[i + 1])
            freqA++;
        else if (freqA > freq)
        {
            freq = freqA;
            freqA = 0;
            n = v[i];
        }
        else
            freqA = 0;
    return n;
}

int maxCresc(int v[], int N)
{
    int i, freqA, freq;
    freqA = freq = 1;
    for (i = 0; i < N; i++)
        if (v[i] <= v[i + 1])
            freqA++;
        else if (freqA > freq)
        {
            freq = freqA;
            freqA = 1;
        }
        else
            freqA = 1;
    return freq;
}

int elimRep(int v[], int n)
{
    int i, w, j, ctl;
    w = 0;
    for (i = 0; i < n; i++)
    {
        w = i + 1;
        ctl = 0;
        for (j = i + 1; j < n + 1; j++)
            if (v[i] == v[j])
                ctl++;
            else
                v[w++] = v[j];
        n -= ctl;
    }
    return w;
}

int elimRepOrd(int v[], int n)
{
    int i, w;
    w = 0;
    for (i = 0; i < n; i++)
        if (v[i] != v[i + 1])
            v[w++] = v[i];
    if (w == 0)
        w++;
    return w;
}

int comunsOrd(int a[], int na, int b[], int nb)
{
    int i, j, total, ctl;
    total = 0;
    j = 0;
    for (i = 0; i < na; i++)
    {
        ctl = 0;
        while (a[i] >= b[j] && !ctl && j < nb)
            if (a[i] == b[j++])
            {
                ctl = 1;
                total++;
            }
    }
    return total;
}

int comuns(int a[], int na, int b[], int nb)
{
    int total, i, j, ctl;
    total = 0;
    for (i = 0; i < na; i++)
    {
        ctl = 0;
        for (j = 0; j < nb && !ctl; j++)
            if (a[i] == b[j])
            {
                total++;
                ctl = 1;
            }
    }
    return total;
}

int minInd(int v[], int n)
{
    int i, ind;
    ind = 0;
    for (i = 0; i < n; i++)
        if (v[i] < v[ind])
            ind = i;
    return ind;
}

void somasAc(int v[], int Ac[], int N)
{
    int soma, i;
    soma = 0;
    for (i = 0; i < N; i++)
    {
        soma += v[i];
        Ac[i] = soma;
    }
}

int triSup(int N, float m[N][N])
{
    int i, j, ctl;
    ctl = 1;
    for (i = 0; i < N && ctl; i++)
        for (j = 0; j < i && ctl; j++)
            ctl = !m[i][j];
    return ctl;
}

void transposta(int N, float m[N][N])
{
    int i, j, temp;
    for (i = 0; i < N; i++)
        for (j = 0; j < i; j++)
        {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
}

void addTo(int N, int M, int a[M][N], int b[M][N])
{
    int i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            a[i][j] += b[i][j];
}

int unionSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for (i = 0; i < N; i++)
        r[i] = (v1[i] || v2[i]);
    return 0;
}

int intersectMSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (v1[i] < v2[i])
            r[i] = v1[i];
        else
            r[i] = v2[i];
    }
    return 0;
}

int intersectSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for (i = 0; i < N; i++)
        r[i] = (v1[i] && v2[i]);
    return 0;
}

int cardinalMSet(int N, int v[N])
{
    int i, m;
    m = 0;
    for (i = 0; i < N; i++)
        m += v[i];
    return m;
}

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
    for (i = 0; i < N; i++)
        if (mov[i] == Norte)
            inicial.y++;

        else if (mov[i] == Sul)
            inicial.y--;

        else if (mov[i] == Este)
            inicial.x++;

        else
            inicial.x--;
    return inicial;
}

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

int vizinhos(Posicao p, Posicao pos[], int N)
{
    int i, r;
    r = 0;
    for (i = 0; i < N; i++)
    {
        if (p.x == pos[i].x)
            if (p.y == pos[i].y + 1 || p.y == pos[i].y - 1)
                r++;
            else
                ;

        else if (p.y == pos[i].y)
            if (p.x == pos[i].x + 1 || p.x == pos[i].x - 1)
                r++;
    }
    return r;
}

int main()
{
    char a[] = "a";
    char b[] = "";
    int x = maiorSufixo(a, b);
    printf("%d\n", x);
    return 0;
}
