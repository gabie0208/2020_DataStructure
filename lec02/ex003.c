  1 #include <stdio.h>
  2 #include <stdlib.h>
  3 
  4 void print1(int*, int);
  5 void main() {
  6     int one[] = {0,1,2,3,4};
  7     print1(one, 5);
  8 }
  9 void print1(int *ptr, int rows) {
 10     //print out a one-dimensional array using a pointer
 11     int i;
 12     printf("address contents\n");
 13     for(i=0; i<rows; i++) printf("%8p%5d\n", ptr+i, *(ptr+i));
 14     printf("\n");
 15 }
