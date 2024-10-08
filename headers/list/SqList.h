//
// Created by Jimmy on 2021/6/3.
//

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H

#endif //DATASTRUCTURE_SQLIST_H
#include "../common/Constants.h"

// 顺序表
typedef struct
{
    int* elem;
    int length;
} SqList;

Status initList(SqList& L);

Status getElem(SqList& L, int i, int& e);

int locateElem(SqList L, int e);

Status insertList(SqList& L, int i, int e);

Status deleteList(SqList& L, int i);

void printList(const SqList& L);

void mergeSqList(const SqList& LA, const SqList& LB, SqList& LC);

void sqListOperate();

void mergeSqListOperate();