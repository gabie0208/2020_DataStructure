/* 
File Name : hw1_naive.c (using naive algorithm)
Time Complexity : O(mn)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// string size: ~9,999,999 & pattern size: ~2,999 characters
#define max_str 10000000
#define max_pat 3000

char str[max_str];
char pat[max_pat];
int M = 0;
int N = 0;

void print(FILE*, int*);

int main(void){
	FILE* fp_str;
	FILE* fp_pat;
	FILE* fp_res;

	// read inputs from 'string.txt' and 'pattern.txt' files
	// output(result) will be stored in 'result_naive.txt' file
	fp_str = fopen("string.txt", "r");
	fp_pat = fopen("pattern.txt", "r");
	fp_res = fopen("result_naive.txt", "w"); 

	// if the input files don't exist, then output a error msg and end the program
	if(!fp_str){
		printf("Error! String file does not exist.\n");
		exit(1);
	}
	if(!fp_pat){
		printf("Error! Pattern file does not exist.\n");
		exit(1);
	}

	// read input files which contain a single line of string
	fgets(str, max_str, fp_str);
	fgets(pat, max_pat, fp_pat);
	
	M = strlen(str);
	N = strlen(pat);
	int i = 0;
	int j = 0;
	int matchedIndex = 0;
	int* result = (int*)malloc(sizeof(int));
	*result = 0;

	for(i = 0; i < M-N+1; i++){
		for(j = 0; j < N; j++){
			if(str[i+j] != pat[j])
				break;
		}
		if(j == N)	{
			matchedIndex++;
			result = (int*)realloc(result, (matchedIndex+1) * sizeof(int));
			++result[0];
			result[matchedIndex] = i;
		}
	}
	
	print(fp_res, result);

	fclose(fp_str);
	fclose(fp_pat);
	fclose(fp_res);
	free(result);

	return 0;
}

// 1st line : the number of appearances of the pattern in string
// 2nd line : all starting positions in the string where the pattern is found
void print(FILE* fp, int* result){
	if(fp){
		fprintf(fp, "%d\n", result[0]);
		for(int i = 1; i <= result[0]; i++)
			fprintf(fp, "%d ", result[i]);
	}
	fprintf(fp, "\n");
	printf("Program complete. Result saved to result_naive.txt\n");
}
