#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f = fopen("date.in", "r");
    FILE *g = fopen("date.out", "w");
    char a[10], b[10];
    fscanf(f, "%s", a);
    fscanf(f, "%s", b);
    int m = strlen(a);
    int n = strlen(b);

    int dyn[n+1][m+1];

    for(int i = 0; i <= n; i++)
        dyn[i][0] = i;
    for(int i = 0; i <= m; i++)
        dyn[0][i] = i;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
        {
            if( a[j-1] == b[i-1] )
                dyn[i][j] = dyn[i-1][j-1];
            else
            {
                int minim = dyn[i-1][j];
                if( dyn[i-1][j-1] < minim )
                    minim = dyn[i-1][j-1];

                dyn[i][j] = minim + 1;

            }
        }

    fprintf(g, "Distanta de editare: %d\n\n", dyn[n][m]);

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m ; j++)
            fprintf(g, "%d ", dyn[i][j]);
        fprintf(g, "\n");
    }

    fclose(f);
    fclose(g); 
    return 0;
}
