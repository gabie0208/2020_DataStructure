#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20                 // �Է� ���� 20����

typedef char element;

typedef struct {
    element stack[MAX_SIZE];       // stack�� ���� �迭 MAX_SIZE�� 20
    int topIndex;                  // �� ���� ���Ҹ� ��Ÿ�� topIndex ����
}Stack;

void init_stack(Stack* ps);
int is_full(Stack* ps);
int is_empty(Stack* ps);
int push(Stack* ps, element value);
char pop(Stack* ps);
int checking(char *string);

int main() 
{
    char stackStr[MAX_SIZE];
    int valid;
    scanf("%s", stackStr);             
    valid = checking(stackStr);  // valid �Ǻ��ϴ� checking() �Լ� ȣ��
    return 0;
}

int checking(char *string)
{
    int valid = 1;
    int i;
    int n = (int)strlen(string);
    Stack stack1;
    init_stack(&stack1);   //stack �ʱ�ȭ

    for (i = 0; i < n; i++)
    {
        if (string[i] == '(' || string[i] == '{' || string[i] == '[')            // ���� ��ȣ ������ ���ÿ� push
        {
            push(&stack1, string[i]);
        }
        else if (string[i] == ')' && stack1.stack[stack1.topIndex] == '(')       // ) �Է��̰� topIndex�� ( �̸� pop
        {
            pop(&stack1);
        }
        else if (string[i] == '}' && stack1.stack[stack1.topIndex] == '{')       // } �Է��̰� topIndex�� { �̸� pop
        {
            pop(&stack1);
        }
        else if (string[i] == ']' && stack1.stack[stack1.topIndex] == '[')       // ] �Է��̰� topIndex�� [ �̸� pop
        {
            pop(&stack1);
        }
    }
                                //push pop �۾� �� ������ ����ִ��� Ȯ��
    if (is_empty(&stack1))      //������ ��������� VALID, �� ���� ����� �̷���� �ִٴ� ��
    {
        valid = 1;
        printf("true");
    }
    else if (!is_empty(&stack1)) //������ �� ��������� INVALID 
    {
        valid = 0;
        printf("false");
    }
    return valid;   
}

void init_stack(Stack* ps)  //stack�� �ʱ�ȭ
{
    ps->topIndex = -1;
}

int is_empty(Stack* ps) //stack ���� Ȯ��
{
    if (ps->topIndex == -1)
        return 1;
    else return 0;
}

int is_full(Stack* ps)
{
    return (ps->topIndex == MAX_SIZE - 1);
}

int push(Stack* ps, element value) 
{
    if (is_full(ps))
    {
        printf("Stack is full.");
        exit(1);
    }
    else
    {
        ps->stack[ps->topIndex + 1] = value;
        (ps->topIndex)++;
        return 1;
    }
}

element pop(Stack* ps) 
{
    char temp;
    if (is_empty(ps))
    {
        printf("Stack Memory Error!");   
        exit(1);
    }
    temp = ps->stack[ps->topIndex];
    (ps->topIndex) -= 1;
    return temp;
}

element peek(Stack* ps)
{
    if (is_empty(ps))
    {
        printf("Stack Blank Error!");
        exit(1);
    }
    else
    {
        return (ps->stack[ps->topIndex]);
    }
}