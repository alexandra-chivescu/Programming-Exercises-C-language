#include <stdio.h>

int s[101], n;

///Am adaugat cond de a avea numai termeni diferiti (term_dif)

///Cond de a avea numai elemente pare

///Cond de a fi nr strict crescatoare

int term_dif(int *s, int k)
{
    int i;
    for(i=1; i<k; i++)
        if(s[i]==s[k])
            return 0;
    return 1;
}

int nr_par(int nr)
{
    if(nr % 2 != 0)
        return 0;
    return 1;
}

int ord_cresc(int *s,int k)
{
    for(int i = 1; i < k ; i++)
            if(s[i] >= s[k])
                return 0;
    return 1;
}
int suma(int k)
{
    int i, scrt;
    scrt = 0;

    for( i = 1; i <= k ; i++)
        scrt = scrt + s[i];

    return scrt;
}

void bkt (int k)
{
    int i, v, scrt;

    for( v = 1; v<= n-k+1; v++)
    {
        s[k] = v;
        scrt = suma(k);
        ///if(term_dif(s,k))
        ///if(nr_par(v))
        if(ord_cresc(s,k))
        if(scrt <= n)
            if(scrt == n)
            {
                for (i = 1; i<= k; i++)
                    printf("%d ", s[i]);
                printf("\n");
            }
            else
                bkt(k+1);

    }
}

int main()
{
    printf("n = ");
    scanf("%d", &n);

    bkt(1);

    return 0;
}
