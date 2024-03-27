#include "push_swap.h"

int same_char(const char *c, char **s)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (s[i])
    {
        while(c[j] == s[i][j])
            j++;
        if (c[j] == '\0' && s[i][j] == '\0')
            return -1;
        j = 0;
        i++;
    }
    return 0;
}

int check_error(char **s)
{
    size_t i;
    size_t j;

    i = 0;
    j =0;
    while(s[i])
    {
        while(s[i][j])
        {
            if ((s[i][j] != '-' && s[i][j] < 48)  || s[i][j] >57 )
                return -1;
            j++;
        }
        if (same_char(s[i], s + i) == -1) // a faire plutot avec liste chaine qui ont leurs vqleurs propres
            return -1;
        i++;
        j = 0;
    }
    return 0;
}