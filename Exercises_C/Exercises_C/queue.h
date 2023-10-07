#pragma once

//#include <stdio.h>
//#include <malloc.h>


//#define TRUE  1
//#define FALSE 0
//#define MAXSIZE 100
//
////typedef int ElemType;
//
//
//// 定义循环队列结构体
//typedef struct Queue {
//
//	int* base;	// 队列首地址
//	int front;	// 队列头下标
//	int rear;	// 队列尾下标
//
//}Queue;



//
///********************* 循环队列的常规操作 **************************/
//
//void     InitQueue();             	// 初始化循环队列
//int      QueueFull();               // 循环队列判满
//int      QueueEmpty();              // 循环队列判空
//int      QueueLength();             // 求循环队列长度(元素个数)
//int      EnQueue();                 // 循环队列 入队
//int      DeQueue();                 // 循环队列 出队
//
//void     QueueStatus();             // 打印队满、队空、队长状态
///****************************************************************/


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


#define MAXQSIZE 100

typedef int QElemType;
typedef int Status;

typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;


// the initial of queue
Status InitQueue(SqQueue& Q);

//get the length of queue
int QueueLength(SqQueue Q);

//push in the queue 
Status ENQueue(SqQueue& Q, QElemType e);

//pop in the queue 
Status DeQueue(SqQueue& Q, QElemType e);

//get the head element of queue
QElemType GetHead(SqQueue Q);