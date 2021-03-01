#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_STRING 30
#define MAX_PAPTTERN 30

void pmatch_delete(char *string, char *pattern, int * fail){
	int i = 0;						 // ���ڿ��� �ε��� 
	int j = 0;						 // ������ �ε��� 
	int len_str = strlen(string);	 // ���ڿ� ����
	int len_pat = strlen(pattern);   // ���� ����

	if (len_str < len_pat) {		 // �Է� ���� ����
		printf("program error!");
		exit(1);
	}
	while (i < len_str) {			 
		while (i < len_str && j < len_pat) {	//���ϰ� ���ڿ� ��, index�� ���� ���� ���� ��
			if (string[i] == pattern[j]) {		
				i++;
				j++;			
			}
			else if (j == 0) {
				i++;
			}
			else 	j = fail[j - 1] + 1;		 // �����Լ��� �̿��� ������ �ε��� ����
		}
		if (j == len_pat) {						 // ���ڿ� �ȿ� ���ϰ� ��ġ�ϴ� �κ� ���� -> ��ġ�� i - len_pat	
			string[i - len_pat] = '\0';			//starting index
			string[i - len_pat + len_pat - 1] = '\0'; //starting index ���� len_pat -1���� ���� ó��
			j = fail[j - 1] + 1;
		}
		else break;
	}
	for (i = 0; i < len_str; i++) {
		if (string[i] != '\0')				 //���ڿ����� ������ �ƴ� ��츸 ���
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


