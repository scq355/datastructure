#include "../../headers/queue/LinkQueue.h"

//
// Created by Jimmy on 2021/6/3.
//
Status initQueue(LinkQueue& Q)
{
    // 都指向头结点
    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    if (!Q.front)
    {
        return ERROR;
    }
    Q.front->next = nullptr;
    return OK;
}

Status isEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear) return OK;
    else return ERROR;
}

Status enQueue(LinkQueue& Q, int e)
{
    QNode* p = new QNode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status deQueue(LinkQueue& Q, int& e)
{
    // 空队
    if (Q.front == Q.rear)
    {
        return ERROR;
    }
    QNode* p = Q.front->next;
    e = p->data;
    // 修改头结点的next指针
    Q.front->next = p->next;
    // 最后一个节点出队
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return OK;
}

int getHead(LinkQueue Q)
{
    if (Q.front != Q.rear)
    {
        return Q.front->next->data;
    }
    return NONE;
}

void linkQueuePrint(LinkQueue& Q)
{
    QNode* p = Q.front->next;
    while (p != Q.rear)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d ", p->data);
    printf("\n");
    free(p);
}

void linkQueueOperate()
{
    LinkQueue Q;
    printf("初始化队列：");
    initQueue(Q);
    printf("\n");
    for (int i = 0; i < 10; ++i)
    {
        enQueue(Q, i + 1);
    }
    printf("入队后：");
    linkQueuePrint(Q);
    int elem;
    deQueue(Q, elem);
    printf("出队列元素：%d\n", elem);
    printf("获取队头元素：%d\n", getHead(Q));
}
