#define _CRT_SECURE_NO_WARNINGS 1

//#include"queue.h"

///*
// * 初始化循环队列
//*/
//Queue InitQueue() {
//    Queue q;
//    // 分配循环队列空间
//    q->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//    q->front = q->rear = 0;
//    return q;
//}
//
//
///*
// *  循环队列判满
// *  q 循环队列
//*/
//int QueueFull(Queue q) {
//    if (q == NULL) {
//        return FALSE;
//    }
//    return (q->rear + 1) % MAXSIZE == q->front;
//}
//
///*
// *  循环队列判空
// *  q 循环队列
//*/
//int QueueEmpty(Queue q) {
//    if (q == NULL) {
//        return FALSE;
//    }
//    return q->front == q->rear;
//}
//
//
///*
// *  计算循环队列长度
// *  q 循环队列
//*/
//int QueueLength(Queue q) {
//    if (q == NULL) {
//        return FALSE;
//    }
//    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
//}
//
//
///*
// *  循环队列 入队
// *  q 循环队列
// *  data 入队元素
//*/
//int EnQueue(Queue q, ElemType data) {
//    if (QueueFull(q)) {
//        return FALSE;
//    }
//    // 队尾入队
//    q->base[q->rear] = data;
//    // 更新队尾指针
//    q->rear = (q->rear + 1) % MAXSIZE;
//    return TRUE;
//}
//
//
///*
// *  循环队列 出队
// *  q 循环队列
// *  *val 用来存出队元素的数据
//*/
//int DeQueue(Queue q, ElemType* val) {
//    if (QueueEmpty(q)) {
//        return FALSE;
//    }
//    // 队头元素出队
//    *val = q->base[q->front];
//    // 更新队头指针
//    q->front = (q->front + 1) % MAXSIZE;
//    return TRUE;
//}
//
//
///*
// * 打印队满、队空、队长状态
// * q 循环队列
//*/
//void QueueStatus(Queue q) {
//    printf("QueueFull():%d\n", QueueFull(q));
//    printf("QueueEmpty():%d\n", QueueEmpty(q));
//    printf("QueueLength():%d\n\n", QueueLength(q));
//}

//// 程序主入口
//int main(int argc, char const* argv[])
//{
//    Queue q = InitQueue();
//    printf("QueueMaxSize: %d\n\n", MAXSIZE);
//    QueueStatus(q); // 打印队满、队空、队长状态
//
//    // 入队
//    printf("EnQueue():");
//    for (int i = 1; i < MAXSIZE * 2; i += 2) {
//        printf("%d\t", i);
//        EnQueue(q, i);
//    }
//
//    printf("\n");
//    QueueStatus(q);
//
//    // 出队
//    int val;
//    printf("DeQueue():");
//    while (!QueueEmpty(q)) {
//        DeQueue(q, &val);
//        printf("%d\t", val);
//    }
//    printf("\n");
//    QueueStatus(q);
//
//    // 测试循环队列是否会假溢出
//    int num = 20;
//    printf("EnQueue(%d): %d\t(0 Failed, 1 Success)\n", num, EnQueue(q, num));
//    QueueStatus(q);
//    return 0;
//}


#include"queue.h"

// the initial of queue
Status InitQueue(SqQueue& Q) {
	
	//Q.base = new QElemType[MAXQSIZE];
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));

	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

//get the length of queue
int QueueLength(SqQueue Q) {

	return((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);

}

//push in the queue 
Status ENQueue(SqQueue& Q, QElemType e) {

	if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;  //the full of queue

	Q.base[Q.rear] = e;                                    // add the back of queue
	Q.rear = (Q.rear + 1) % MAXQSIZE;                      // 
	return OK;

}


//pop in the queue 
Status DeQueue(SqQueue& Q, QElemType e) {

	if (Q.front == Q.rear) return ERROR; //the queue is empty
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	
	return OK;
}

//get the head element of queue
QElemType GetHead(SqQueue Q) {
	if (Q.front != Q.rear)   //if queue is no empty
		return Q.base[Q.front];


}