#include<stdio.h>

int s[101], n;

int solp(int k)
{
    int i;
    for(i = 1; i < k; i++)
        if(s[k] == s[i])
            return 0;
    return 1;
}

void bkt(int k)
{
    int i, v;

    for(v = 1; v <= n; v++)
    {
        s[k] = v;
        if(solp(k) == 1)
            if(k == n)
            {
                for(i = 1; i <= k; i++)
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

