#define _CRT_SECURE_NO_WARNINGS 1

#include"Linked _stack.h"

//initial the linked stack
int InitStack(LinkStack& S) {
	//creat the empty stack;
	S = NULL;
	return OK;
}

//if is the empty
Status StackEmpty(LinkStack S) {
	if (S == NULL)return TRUE;
	else return FALSE;
}

//push the element in the stack
Status Push_stack(LinkStack& S, SElemType e) {
	LinkStack p;
	p = (LinkStack)malloc(sizeof(StackNode));  //Creat the new node

	p->data = e;         //push element
	p->next = S;
	S = p;           //change the top point of stack

	return OK;
}

//Pop the element in the stack
Status Pop_stack(LinkStack& S, SElemType& e) {

	LinkStack p;
	if (S == NULL) return ERROR;
	e = S->data;  //pop the element
	p = S;
	S = S->next;   //change the top point of stack
	delete p;

	return OK;
}

//Get the top element
SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}



