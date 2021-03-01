#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define MAX_STRING 30

//���ӵ� �ߺ����ڸ� ����� �Լ�
void remove_duplicates(char input_str[]) 
{
	int check = 0;
	int i;
	int n = strlen(input_str);

	if ((n < 2) || (n > 30)) //�Է� ���� ����
	{
		printf("program error!");
		exit(1);
	}
	for (i = 0; i < n; i++) {
		if (input_str[check] == input_str[check + 1])
		{
			input_str[check + 1] = '\0'; //�յ� ���� ���ؼ� ������ �޹��ڴ� ��������
			strcat(input_str, input_str + check + 2); // check ���� �ٴ��� ��ġ�� ��ü ���ڿ� ����
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



