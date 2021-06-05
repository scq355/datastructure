//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_SQQUEUE_H
#define DATASTRUCTURE_SQQUEUE_H

#endif //DATASTRUCTURE_SQQUEUE_H

typedef struct {
    int *base;
    int front;
    int rear;
} SqQueue;

Status initQueue(SqQueue &Q);

int queueLength(SqQueue Q);

Status enQueue(SqQueue &Q, int e);

Status deQueue(SqQueue &Q, int &e);

int getHead(SqQueue Q);

void sqQueueOperate();