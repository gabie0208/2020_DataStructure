#include <stdio.h>

int min_Tiles(int N, int M)
{
    if (N == 0 || M == 0)                   return 0;
    else if (N % 2 == 0 && M % 2 == 0)      return min_Tiles(N / 2, M / 2);
    else if (N % 2 == 1 && M % 2 == 0)      return (M + min_Tiles(N / 2, M / 2));
    else if (N % 2 == 0 && M % 2 == 1)      return (N + min_Tiles(N / 2, M / 2));
    else                                    return (N + M - 1 + min_Tiles(N / 2, M / 2));

    min_Tiles(N, M);
}

int main(void)
{
    int n, m;
    fscanf(stdin, "%d %d", &n, &m);
    fprintf(stdout, "%d", min_Tiles(n, m));
    return 0;
}





