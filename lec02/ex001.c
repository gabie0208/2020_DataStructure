  1 #include <stdio.h>
  2 #include <stdlib.h>
  3 
  4 void main() {
  5     int i;
  6     int list[5];
  7     for(i=0; i<5; i++) list[i]=i+101;
  8     printf("%p: %d\n", &list[1], list[1]);
  9     printf("%p: %d\n", (list+1), *(list+1));
 10 }
