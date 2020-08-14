#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void Hanoi(int n, char a, char b, char c, FILE *g)
{
    if(n == 1)
    {
        fprintf(g, "Mutarea: %c => %c\n", a, c); ///Mutarea discului ramas pe tija c
    }
    else
    {
        Hanoi(n-1, a, c, b, g); ///Mutarea a n-1 discuri de pe tija c pe tija b, utilizand ca tija intermediara tija a
        fprintf(g, "Mutarea: %c => %c\n", a, c);
        Hanoi(n-1, b, a, c, g); ///Mutarea a n-1 discuri de pe tija a pe tija b, utilizand ca tija intermediara tija c
    }

}
int main()
{
    FILE *f = fopen("date.in", "r");
    assert(f!= NULL);
    FILE *g = fopen("date.out", "w");
    int n;
    char a = 'A', b= 'B', c= 'C';
    fscanf(f, "%d", &n);
    Hanoi( n, a, b, c, g);

    fclose(f);
    fclose(g);
    return 0;
}
