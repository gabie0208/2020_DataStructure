#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20                 // 입력 제한 20까지

typedef char element;

typedef struct {
    element stack[MAX_SIZE];       // stack을 위한 배열 MAX_SIZE는 20
    int topIndex;                  // 맨 위의 원소를 나타낼 topIndex 변수
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
    valid = checking(stackStr);  // valid 판별하는 checking() 함수 호출
    return 0;
}

int checking(char *string)
{
    int valid = 1;
    int i;
    int n = (int)strlen(string);
    Stack stack1;
    init_stack(&stack1);   //stack 초기화

    for (i = 0; i < n; i++)
    {
        if (string[i] == '(' || string[i] == '{' || string[i] == '[')            // 여는 괄호 나오면 스택에 push
        {
            push(&stack1, string[i]);
        }
        else if (string[i] == ')' && stack1.stack[stack1.topIndex] == '(')       // ) 입력이고 topIndex가 ( 이면 pop
        {
            pop(&stack1);
        }
        else if (string[i] == '}' && stack1.stack[stack1.topIndex] == '{')       // } 입력이고 topIndex가 { 이면 pop
        {
            pop(&stack1);
        }
        else if (string[i] == ']' && stack1.stack[stack1.topIndex] == '[')       // ] 입력이고 topIndex가 [ 이면 pop
        {
            pop(&stack1);
        }
    }
                                //push pop 작업 후 스택이 비어있는지 확인
    if (is_empty(&stack1))      //스택이 비어있으면 VALID, 두 쌍이 제대로 이루어져 있다는 뜻
    {
        valid = 1;
        printf("true");
    }
    else if (!is_empty(&stack1)) //스택이 안 비어있으면 INVALID 
    {
        valid = 0;
        printf("false");
    }
    return valid;   
}

void init_stack(Stack* ps)  //stack의 초기화
{
    ps->topIndex = -1;
}

int is_empty(Stack* ps) //stack 공백 확인
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