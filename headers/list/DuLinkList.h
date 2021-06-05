//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_DULINKLIST_H
#define DATASTRUCTURE_DULINKLIST_H

#endif //DATASTRUCTURE_DULINKLIST_H

typedef struct DuLNode{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;


Status initDuLinkList(DuLinkList &L);

DuLNode *locateEnumDuLinkList(DuLinkList &L, int i);

DuLNode *getElemDuLinkList(DuLinkList &L, int e);

Status createDuLinkListHead(DuLinkList &L, int e);

Status createDuLinkListTail(DuLinkList &L, int e);

Status deleteDuLinkList(DuLinkList &L, int i);

void printDuLinkList(DuLinkList &L);

void duLinkListOperate();