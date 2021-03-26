  1 #include <stdio.h>
  2 #include <stdlib.h>
  3 
  4 void main() {
  5     int i, n , m, *data;
  6     printf("How many integers do you want to generate? ");
  7     scanf("%d", &n);
  8     data = malloc(n*sizeof(int));
  9     for(i=0; i<n; i++) data[i] = rand();
 10     printf("How many integers do you want to generate additionally? ");
 11     scanf("%d", &m);
 12     data = realloc(data, (n+m)*sizeof(int));
 13     for(i; i<n+m; i++) data[i] = rand();
 14     for(i=0; i<n+m; i++) printf("%3d: %8d\n", i+1 ,data[i]);
 15     free(data);
 16 }
