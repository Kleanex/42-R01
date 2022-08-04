
int nb_line(int tab[4][4], int l, int looking_for)
{
    int c;
    int max;
    int nbr;

    max = 0;
    while (c <= 3)
    {
        if (tab[c][l] > max)
        {
            nbr++;
            max = tab[c][l];
        }
        c++;
    }
    if (nbr == looking_for)
        return(1);
    else
        return(0);
}

int nb_columns(int tab[4][4], int c, int looking_for)
{
    int l;
    int max;
    int nbr;

    max = 0;
    while (l <= 3)
    {
        if (tab[c][l] > max)
        {
            nbr++;
            max = tab[c][l];
        }
        l++;
    }
    if (nbr == looking_for)
        return(1);
    else
        return(0);
}

#include <stdio.h>
#include <stdlib.h>

void print_tab (int tab[4][4])
{
    int a, b;

    a = b = 0;
    while (a <= 3)
    {
        while (b <= 3)
        {
            printf("%d",tab[a][b]);
            b++;
        }
        printf("\n");
        b = 0;
        a++;
    }
}
