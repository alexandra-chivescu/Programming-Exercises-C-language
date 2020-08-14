#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void citire_fotografie(char *file, int **A, int n, int m)
{
    FILE *f = fopen(file, "r");
    assert(f!= NULL);

    fseek(f, 4, SEEK_SET);

    for(int i =0 ; i<n; i++)
        for(int j = 0; j< m; j++)
            fscanf(f, "%d", &A[i][j]);

    fclose(f);
}

int divimp (int **A, int n , int m, int sus, int jos)
{
    if(sus > jos)
        return 0;
    if(sus == jos)
        return numara_direct(A[sus], m);

    int mijloc, piese_sus, piese_jos, piese_intersectie;
    mijloc = (sus + jos)/ 2;
    //printf("%d ", mijloc);
    piese_sus = divimp (A, n, m, sus, mijloc);
    piese_jos = divimp (A, n, m, mijloc+1, jos);
    piese_intersectie = numara_intersectie(A[mijloc], A[mijloc+1], m);

    return piese_sus + piese_jos- piese_intersectie;
}

int numara_direct(int *v, int m) {
    int i, nr=0, prev = 0;
    for(i = 0; i< m; i++) {
        if(v[i] != prev && v[i] == 1)
            nr++;
        prev = v[i];
    }
    return nr;
}

int numara_intersectie(int *v, int *r ,int m)
{
    int i, nr = 0, prev = 0, ipoz=0;
    for (i = 0; i < m; i++)
    {
        if(v[i]!= 0)
            ipoz = i;
        if(i == 0 && v[i] != prev && v[i] == 1 && v[i] == r[i] )
            nr++;
        if(i>=1 && (v[i]!= prev ||r[i]!= r[i-1] && ipoz == i) && v[i] == 1 && v[i] == r[i] )
            nr++;
        prev = v[i];
    }
    return nr;

}
void afisare_fotografie(char *file, int **A, int n, int m)
{
    FILE *g = fopen(file, "w");
    assert(g!=NULL);

    for(int i = 0; i<n; i++)
    {
        for(int j=0; j< m; j++)
            fprintf(g, "%d ", A[i][j]);
        fprintf(g, "\n");
    }
    fclose(g);
}

int main()
{
    int n, m;
    FILE *f = fopen("date.in", "r");
    assert(f!= NULL);
    fscanf(f, "%d %d", &n, &m);

    int **A = (int **)malloc(n*sizeof(int*));
    for(int i = 0; i<n; i++)
    {
        A[i] = (int*)malloc(m*sizeof(int));
    }

    citire_fotografie("date.in", A, n, m);

    FILE *g = fopen("date.out", "w");
    assert(g!=NULL);
    fprintf(g, "%d", divimp (A, n, m, 0, n-1));
    ///afisare_fotografie("date.out", A, n, m);
    for(int i = 0; i<n; i++)
      free(A[i]);
    free(A);
    fclose(f);
    fclose(g);
    return 0;
}
