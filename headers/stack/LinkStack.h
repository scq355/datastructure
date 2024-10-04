//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"
#ifndef DATASTRUCTURE_LINKSTACK_H
#define DATASTRUCTURE_LINKSTACK_H

#endif //DATASTRUCTURE_LINKSTACK_H

typedef struct StackNode
{
    int data;
    struct StackNode* next;
} StackNode, *LinkStack;

Status initLintStack(LinkStack& S);

Status pushLinkStack(LinkStack& S, int e);

Status popLinkStack(LinkStack& S, int& e);

void linkStackTraverse(LinkStack& S);

int getLinkStackTop(LinkStack& S);

void linkStackOperate();
