//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H

#endif //DATASTRUCTURE_LINKQUEUE_H


typedef struct QNode
{
    int data;
    struct QNode* next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;


Status initQueue(LinkQueue& Q);

Status isEmpty(LinkQueue Q);

Status enQueue(LinkQueue& Q, int e);

Status deQueue(LinkQueue& Q, int& e);

Status deQueue(LinkQueue& Q, char& e);

int getHead(LinkQueue Q);

void linkQueuePrint(LinkQueue& Q);

void linkQueueOperate();
