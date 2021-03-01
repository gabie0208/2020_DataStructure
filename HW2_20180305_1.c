#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define MAX_STRING 30

//연속된 중복문자를 지우는 함수
void remove_duplicates(char input_str[]) 
{
	int check = 0;
	int i;
	int n = strlen(input_str);

	if ((n < 2) || (n > 30)) //입력 기준 제한
	{
		printf("program error!");
		exit(1);
	}
	for (i = 0; i < n; i++) {
		if (input_str[check] == input_str[check + 1])
		{
			input_str[check + 1] = '\0'; //앞뒤 문자 비교해서 같으면 뒷문자는 공백으로
			strcat(input_str, input_str + check + 2); // check 기준 다다음 위치로 전체 문자열 복사
			check--;
		}
		check++;
	}
}

int main() 
{
	char input_string[MAX_STRING] = "";
	scanf("%s", input_string);
	remove_duplicates(input_string);
	printf("%s", input_string);
	return 0;
}



