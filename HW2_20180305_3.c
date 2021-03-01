#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<stdbool.h>

#define MAX 256
#define MAX_STRING 10
#define MAX_PATTERN 10

// 두 개의 배열을 비교하여, 같으면 true, 다르면 false 리턴하는 bool타입 함수 선언
bool compare_arrs(char arr1[], char arr2[]){
	int i;
	for (i = 0; i < MAX; i++)
		if (arr1[i] != arr2[i])
			return false;
	return true;
}

// sliding window 알고리즘 원리를 이용하여 str 안에 있는 pat(anagram) 찾기
void anagram_search(char* pat, char* str){ 
	int lenp = strlen(pat);
	int lens = strlen(str);
	int i; 
	char cnt_ch_pat[MAX] = { 0 };
	char cnt_ch_str[MAX] = { 0 };

	if ((lenp == 0 || lens == 0) || (lenp > lens)) // 입력 제한 조건
	{
		printf("program error!");
		exit(1);
	}

	for (i = 0; i < lenp; i++){
		(cnt_ch_pat[pat[i]])++;
		(cnt_ch_str[str[i]])++;
	}
	for (i = lenp; i < lens; i++){					// str 끝까지 pat의 길이 기준으로 loop
		if (compare_arrs(cnt_ch_pat, cnt_ch_str)) { // 현재 str window의 카운트와 패턴의 카운트 비교
			printf("%d ", i - lenp);
		}
		(cnt_ch_str[str[i]])++;						// 현재 window에 새로운 문자(비교 이후 문자) 추가
													// window 한 칸 씩 밀면서 이전 첫 문자 삭제 
		cnt_ch_str[str[i - lenp]]--;
	}
	//str의 마지막 window 체크
	if (compare_arrs(cnt_ch_pat, cnt_ch_str))
		printf("%d ", lens - lenp);
}

int main(){
	char string[MAX_STRING];
	scanf("%s", string);
	char pattern[MAX_PATTERN];
	scanf("%s", pattern);
	anagram_search(pattern, string);
	return 0;
}

