#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"

// Create an empty stack S.
Status InitStack(SqStack& S)
{
	//S.base = new SElemType[STACK_INIT_SIZE];
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

// Check if the stack S is empty.
Boolean StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

//Clearing a Sequential Stack
Status ClearStack(SqStack S) {

	if (S.base)S.top = S.base;
	return OK;
}

//destroy a sequential stack
Status DestroyStack(SqStack& S) {
	if (S.base) {
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

// Insert element e as the new top element of the stack.
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)  //ջ����׷�Ӵ洢�ռ� 
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e; //*S.top=e;S.top++;
	return OK;
}


//��ջ��Ϊ�գ�ɾ��S��ջ��Ԫ�أ���e������ֵ 
//if stack is no empty,delete the top element of stack,returning value is e;
//If the stack is not empty, remove the top element of S, and return its value using e.
Status Pop(SqStack& S, SElemType& e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;  //--S.top;e=*S.top;
	return OK;
}

// ��������ķǸ�ʮ������������ӡ��������ֵ�İ˽�����
//For a given non - negative decimal integer, print the octal(base - 8) equivalent.
void conversion(SqStack S)
{
	int N, e;
	InitStack(S);
	printf("������һ��ʮ��������:");
	scanf("%d", &N);
	while (N) {
		Push(S, N % 8);
		N = N / 8;
	}
	printf("תΪ�˽���:");
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d", e);
	}
	printf("\n");
}

