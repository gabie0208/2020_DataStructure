#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<stdbool.h>

#define MAX 256
#define MAX_STRING 10
#define MAX_PATTERN 10

// �� ���� �迭�� ���Ͽ�, ������ true, �ٸ��� false �����ϴ� boolŸ�� �Լ� ����
bool compare_arrs(char arr1[], char arr2[]){
	int i;
	for (i = 0; i < MAX; i++)
		if (arr1[i] != arr2[i])
			return false;
	return true;
}

// sliding window �˰��� ������ �̿��Ͽ� str �ȿ� �ִ� pat(anagram) ã��
void anagram_search(char* pat, char* str){ 
	int lenp = strlen(pat);
	int lens = strlen(str);
	int i; 
	char cnt_ch_pat[MAX] = { 0 };
	char cnt_ch_str[MAX] = { 0 };

	if ((lenp == 0 || lens == 0) || (lenp > lens)) // �Է� ���� ����
	{
		printf("program error!");
		exit(1);
	}

	for (i = 0; i < lenp; i++){
		(cnt_ch_pat[pat[i]])++;
		(cnt_ch_str[str[i]])++;
	}
	for (i = lenp; i < lens; i++){					// str ������ pat�� ���� �������� loop
		if (compare_arrs(cnt_ch_pat, cnt_ch_str)) { // ���� str window�� ī��Ʈ�� ������ ī��Ʈ ��
			printf("%d ", i - lenp);
		}
		(cnt_ch_str[str[i]])++;						// ���� window�� ���ο� ����(�� ���� ����) �߰�
													// window �� ĭ �� �и鼭 ���� ù ���� ���� 
		cnt_ch_str[str[i - lenp]]--;
	}
	//str�� ������ window üũ
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

