//
// Created by Jimmy on 2021/6/3.
//

#include "../../headers/queue/SqQueue.h"

Status initQueue(SqQueue& Q)
{
    Q.base = new int[MAXSIZE];
    if (!Q.base)
    {
        return ERROR;
    }
    Q.front = Q.rear = 0;
    return OK;
}

int queueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status enQueue(SqQueue& Q, int e)
{
    // 满队判断
    if ((Q.rear + 1) % MAXSIZE == Q.front)
    {
        return ERROR;
    }
    Q.base[Q.rear] = e;
    // 环状，循环队列
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}

Status deQueue(SqQueue& Q, int& e)
{
    // 空队判断
    if (Q.front == Q.rear)
    {
        return ERROR;
    }
    e = Q.base[Q.front];
    // 队头指针后移
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}

int getHead(SqQueue Q)
{
    if (Q.front != Q.rear)
    {
        return Q.base[Q.front];
    }
}

void sqQueueOperate()
{
    SqQueue Q;
    initQueue(Q);
    printf("入队：\n");
    for (int i = 0; i < 10; ++i)
    {
        enQueue(Q, i + 1);
    }
    printf("获取队首元素：");
    printf("%d\n", getHead(Q));
    printf("队长：%d\n", queueLength(Q));
    int elem;
    printf("出队");
    deQueue(Q, elem);
    printf("%d\n", elem);
    printf("队长：%d\n", queueLength(Q));
    printf("获取队首元素：");
    printf("%d\n", getHead(Q));
}
