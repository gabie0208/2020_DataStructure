  1 #include <stdio.h>
  2 #include <stdlib.h>
  3 #define MAX_SIZE 100
  4 
  5 float sum(float[], int);
  6 float input[MAX_SIZE], answer;
  7 int i;
  8 
  9 void main() {
 10     for(i=0; i<MAX_SIZE; i++) input[i] = i;
 11     answer = sum(input, MAX_SIZE);
 12     printf("sum is: %f\n", answer);
 13 }
 14 float sum(float list[], int n) {
 15     int i;
 16     float tempsum = 0;
 17     for(i=0; i<n; i++) tempsum += list[i];
 18     return tempsum;
 19 }
