//
// Created by Jimmy on 2021/6/3.
//
#include "LinkList.h"
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_CLINKLIST_H
#define DATASTRUCTURE_CLINKLIST_H

#endif //DATASTRUCTURE_CLINKLIST_H

// 循环列表
typedef struct CLNode
{
    int data;
    struct CLNode* next;
} CLNode, *CLinkList;

Status initCLinkList(CLinkList& L);

Status getElem(CLinkList L, int i, int& e);

CLNode* locateElem(CLinkList L, int e);

int getCLinkListLength(CLinkList& L);

Status cLinkListInsert(CLinkList& L, int i, int e);

Status cLinkListDelete(CLinkList& L, int i);

void cLinkListPrint(CLinkList& L);

void createCLinkListHead(CLinkList& L, int n);

CLNode* getTailNode(CLinkList& L);

Status isTail(CLinkList L, CLNode* p);

void createCLinkListTail(CLinkList& L, int n);

void mergeCLinkList(CLinkList& LA, CLinkList& LB, CLinkList& LC);

void cLinkListOperate();

void cLinkListHeadOperate();
