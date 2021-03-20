#include <stdio.h>
#define MAX_SIZE 100

int factorial(int n) {
	if (n == 0) return 1;
	int result = 1;
	for (int i = n; i > 1; i--) {
		result *= i;
	}
	return result;
}

int recursive_bino(int n, int k) {
	static int A[MAX_SIZE][MAX_SIZE];
	if (A[n][k] > 0) return A[n][k];
	else if (k == 0 || k == n) return A[n][k] = 1;
	else if ((0 < k) && (k < n)) 
		return A[n][k] = recursive_bino(n - 1, k - 1) + recursive_bino(n - 1, k);
	else return 0;
}

int main(void) {
	int n, k, fac_result, rec_result;
	fscanf(stdin, "%d %d", &n, &k);
	fac_result = factorial(n) / (factorial(k) * factorial(n - k));
	rec_result = recursive_bino(n, k);
	fprintf(stdout, "%d %d\n", fac_result, rec_result);
	return 0;
}
