/*
File Name : hw1_kmp.c (using KMP algorithm)
Time Complexity : O(m+n)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// string size: ~9,999,999 & pattern size: ~2,999 characters
#define max_str 10000000
#define max_pat 3000

char str[max_str];
char pat[max_pat];
int failure[max_pat];
int M = 0;
int N = 0;

void fail();
void print(FILE*, int*);

int main(void){
	
	FILE* fp_str;
	FILE* fp_pat;
	FILE* fp_res;
	// read inputs from 'string.txt' and 'pattern.txt' files
	// output(result) will be stored in 'result_kmp.txt' file
	fp_str = fopen("string.txt", "r");
	fp_pat = fopen("pattern.txt", "r");
	fp_res = fopen("result_kmp.txt", "w"); 

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
	fail();

	int i = 0;
	int j = 0;
	int matchedIndex = 0;
	int* result = (int*)malloc(sizeof(int));
	*result = 0;

	while(i < M){
		while(j >= 0 && str[i] != pat[j])
			j = failure[j];
		i++;
		j++;
		if(j == N){
			matchedIndex++;
			(*result)++;
			result = (int*)realloc(result, (matchedIndex+1) * sizeof(int));
			result[matchedIndex] = i-j;
		}
	}
	print(fp_res, result);

	fclose(fp_str);
	fclose(fp_pat);
	fclose(fp_res);
	free(result);
	return 0;
}

void fail(){
	int i = 0;
	int j = -1;
	failure[0] = -1;

	while(i < N) {
		if(j == -1 || pat[i] == pat[j])
			failure[++i] = ++j;
		else
			j = failure[j];
	}
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
	printf("Program complete. Result saved to result_kmp.txt\n");
}
