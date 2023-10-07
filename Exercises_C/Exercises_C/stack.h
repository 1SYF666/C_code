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

//顺序栈
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

//构造一个空栈S
// Create an empty stack S.
Status InitStack(SqStack& S);

//检查s栈是否为空栈
// Check if the stack S is empty.
Boolean StackEmpty(SqStack S);

//Clearing a Sequential Stack
Status ClearStack(SqStack S);

//destroy a sequential stack
Status DestroyStack(SqStack& S);


//插入元素e为新的栈顶元素
// Insert element e as the new top element of the stack.
Status Push(SqStack& S, int e);


//若栈不为空，删除S的栈顶元素，用e返回其值 
// If the stack is not empty, remove the top element of S, and return its value using e.
Status Pop(SqStack& S, int& e);


// 对于输入的非负十进制整数，打印输出与其等值的八进制数
// For a given non-negative decimal integer, print the octal (base-8) equivalent.
void conversion(SqStack S);
