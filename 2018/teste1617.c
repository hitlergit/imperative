#include <ctype.h>

int limpaEspacos(char s[])
{
    int i, r;
    for (i = 0, r = 0; s[i + 1]; i++)
    {
        if (isspace(s[i]) && isspace(s[i + 1]))
            ;
        else
        {
            s[r] = s[i];
            r++;
        }
    }
    s[r] = '\0';
    return r;
}
