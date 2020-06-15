///Combinari de n elem luate cate m

#include <stdio.h>

int s[101], n, m;

void bkt (int k)
{
    int i;
    if(k == m+1)
    {
        for(i = 1; i <=m ; i++)
                printf("%d", s[i]);
            printf("\n");
    }
    else
    {
            if(k > 1)
                s[k] = s[k-1];
            else
                s[k] = 0;
            while(s[k] < n-m+k)
            {
                s[k]++;
                bkt(k+1);
            }
    }
}
int main()
{
    printf("n = ");
    scanf("%d", &n);

    printf("m = ");
    scanf("%d", &m);

    bkt(1);

    return 0;
}
