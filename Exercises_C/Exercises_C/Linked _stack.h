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

//Linked_stack
typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;
LinkStack S;

//initial the linked stack
int InitStack(LinkStack& S);

//if is the empty
Status StackEmpty(LinkStack S);

//push the element in the stack
Status Push_stack(LinkStack& S, SElemType e);

//Pop the element in the stack
Status Pop_stack(LinkStack& S, SElemType& e);

//Get the top element
SElemType GetTop(LinkStack S);


