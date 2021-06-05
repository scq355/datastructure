//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H

#endif //DATASTRUCTURE_SQSTACK_H

typedef struct {
    int *base;
    int *top;
    int stackSize;
} SqStack;

Status initStack(SqStack &S);

Status stackEmpty(SqStack &S);

int stackLength(SqStack &S);

Status push(SqStack &S, char e);

Status pop(SqStack &S, char &e);

Status destoryStack(SqStack &S);

Status clearStack(SqStack &S);

int getTop(SqStack S);

void stackTraverse(SqStack &S);

void sqStackOperate();


