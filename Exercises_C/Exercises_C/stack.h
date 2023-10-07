#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int Boolean;
typedef int SElemType;

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

//˳��ջ
struct SqStack
{
	SElemType* base;
	SElemType* top;
	int stacksize;
};

//typedef struct {
//	SElemType* base;
//	SElemType* top;
//	int stacksize;
//}SqStack;

//����һ����ջS
// Create an empty stack S.
Status InitStack(SqStack& S);

//���sջ�Ƿ�Ϊ��ջ
// Check if the stack S is empty.
Boolean StackEmpty(SqStack S);

//Clearing a Sequential Stack
Status ClearStack(SqStack S);

//destroy a sequential stack
Status DestroyStack(SqStack& S);


//����Ԫ��eΪ�µ�ջ��Ԫ��
// Insert element e as the new top element of the stack.
Status Push(SqStack& S, int e);


//��ջ��Ϊ�գ�ɾ��S��ջ��Ԫ�أ���e������ֵ 
// If the stack is not empty, remove the top element of S, and return its value using e.
Status Pop(SqStack& S, int& e);


// ��������ķǸ�ʮ������������ӡ��������ֵ�İ˽�����
// For a given non-negative decimal integer, print the octal (base-8) equivalent.
void conversion(SqStack S);
