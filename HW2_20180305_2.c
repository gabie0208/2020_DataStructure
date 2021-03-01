#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_STRING 30
#define MAX_PAPTTERN 30

void pmatch_delete(char *string, char *pattern, int * fail){
	int i = 0;						 // 문자열의 인덱스 
	int j = 0;						 // 패턴의 인덱스 
	int len_str = strlen(string);	 // 문자열 길이
	int len_pat = strlen(pattern);   // 패턴 길이

	if (len_str < len_pat) {		 // 입력 제한 조건
		printf("program error!");
		exit(1);
	}
	while (i < len_str) {			 
		while (i < len_str && j < len_pat) {	//패턴과 문자열 비교, index가 범위 내에 있을 때
			if (string[i] == pattern[j]) {		
				i++;
				j++;			
			}
			else if (j == 0) {
				i++;
			}
			else 	j = fail[j - 1] + 1;		 // 실패함수를 이용해 패턴의 인덱스 결정
		}
		if (j == len_pat) {						 // 문자열 안에 패턴과 일치하는 부분 존재 -> 위치는 i - len_pat	
			string[i - len_pat] = '\0';			//starting index
			string[i - len_pat + len_pat - 1] = '\0'; //starting index 기준 len_pat -1까지 공백 처리
			j = fail[j - 1] + 1;
		}
		else break;
	}
	for (i = 0; i < len_str; i++) {
		if (string[i] != '\0')				 //문자열에서 공백이 아닌 경우만 출력
			printf("%c", string[i]);
	}	
}
void fail_func(char *pattern, int *fail){
	int i = 0, j = -1;
	fail[0] = -1;
	int len_pat = strlen(pattern);
	while (i < len_pat) {
		if (j == -1 || pattern[i] == pattern[j])
			fail[++i] = ++j;
		else
			j = fail[j];
	}
}
int main(){
	char string[MAX_STRING];
	char pattern[MAX_PAPTTERN];
	int fail[MAX_PAPTTERN];

	scanf("%s", string);
	scanf("%s", pattern);
	fail_func(pattern, fail);
	printf("\n");
	pmatch_delete(string, pattern, fail);
	return 0;
}


