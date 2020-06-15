#include <stdio.h>
#include <stdlib.h>

#define Nr_Max 101

void afisareSir(int i, int sir[], int pred[], const char *fis) {
    if(i != -1)
    {
        afisareSir(pred[i], sir, pred, fis);
        fprintf(fis,"%d ", sir[i]);
    }
}

int main()
{
    FILE *f = fopen("date.in", "r");
    FILE *g = fopen("date.out", "w");

    int n, sir[Nr_Max], lg[Nr_Max], pred[Nr_Max];
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++)
        fscanf(f, "%d", &sir[i]);
    pred[0]  = -1;
    for(int i = 0; i < n; i++)
    {
        int maxim = 0;
        pred[i] = -1;
        for(int j = 0; j < i; j++)
            if( sir[j] < sir[i] && lg[j] > maxim)
            {
                maxim = lg[j];
                pred[i] = j;
            }
        lg[i] = maxim+1;
    }

    int maxim = lg[0];
    int pmax;
    for(int i = 0; i < n; i++)
        if(lg[i] > maxim )
        {
            maxim = lg[i];
            pmax = i;
        }
    fprintf(g, "%d\n", maxim);
    afisareSir(pmax, sir, pred, g);
    fclose(f);
    fclose(g);
    return 0;
}
