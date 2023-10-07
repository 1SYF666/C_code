#pragma once


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>

typedef int QElemType;
typedef int Status;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct Qnode {
	QElemType data;
	struct Qnode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front; // head point of queue
	QueuePtr rear; // head point of queue
}LinkQueue;


//initial of linked queue
Status InitQueue(LinkQueue& Q);

//destroy the queue
Status DestroyQueue(LinkQueue& Q);

//Enqueue elements
Status EnQueue(LinkQueue& Q, QElemType e);

//Dequeue elements
Status DeQueue(LinkQueue& Q, QElemType& e);

//Get the head element
Status GetHeadQueue(LinkQueue& Q, QElemType& e);


