#define _CRT_SECURE_NO_WARNINGS 1

//#include"queue.h"

///*
// * ��ʼ��ѭ������
//*/
//Queue InitQueue() {
//    Queue q;
//    // ����ѭ�����пռ�
//    q->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//    q->front = q->rear = 0;
//    return q;
//}
//
//
///*
// *  ѭ����������
// *  q ѭ������
//*/
//int QueueFull(Queue q) {
//    if (q == NULL) {
//        return FALSE;
//    }
//    return (q->rear + 1) % MAXSIZE == q->front;
//}
//
///*
// *  ѭ�������п�
// *  q ѭ������
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
// *  ����ѭ�����г���
// *  q ѭ������
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
// *  ѭ������ ���
// *  q ѭ������
// *  data ���Ԫ��
//*/
//int EnQueue(Queue q, ElemType data) {
//    if (QueueFull(q)) {
//        return FALSE;
//    }
//    // ��β���
//    q->base[q->rear] = data;
//    // ���¶�βָ��
//    q->rear = (q->rear + 1) % MAXSIZE;
//    return TRUE;
//}
//
//
///*
// *  ѭ������ ����
// *  q ѭ������
// *  *val ���������Ԫ�ص�����
//*/
//int DeQueue(Queue q, ElemType* val) {
//    if (QueueEmpty(q)) {
//        return FALSE;
//    }
//    // ��ͷԪ�س���
//    *val = q->base[q->front];
//    // ���¶�ͷָ��
//    q->front = (q->front + 1) % MAXSIZE;
//    return TRUE;
//}
//
//
///*
// * ��ӡ�������ӿա��ӳ�״̬
// * q ѭ������
//*/
//void QueueStatus(Queue q) {
//    printf("QueueFull():%d\n", QueueFull(q));
//    printf("QueueEmpty():%d\n", QueueEmpty(q));
//    printf("QueueLength():%d\n\n", QueueLength(q));
//}

//// ���������
//int main(int argc, char const* argv[])
//{
//    Queue q = InitQueue();
//    printf("QueueMaxSize: %d\n\n", MAXSIZE);
//    QueueStatus(q); // ��ӡ�������ӿա��ӳ�״̬
//
//    // ���
//    printf("EnQueue():");
//    for (int i = 1; i < MAXSIZE * 2; i += 2) {
//        printf("%d\t", i);
//        EnQueue(q, i);
//    }
//
//    printf("\n");
//    QueueStatus(q);
//
//    // ����
//    int val;
//    printf("DeQueue():");
//    while (!QueueEmpty(q)) {
//        DeQueue(q, &val);
//        printf("%d\t", val);
//    }
//    printf("\n");
//    QueueStatus(q);
//
//    // ����ѭ�������Ƿ������
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