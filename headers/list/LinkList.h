//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H

#endif //DATASTRUCTURE_LINKLIST_H

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

Status initList(LinkList &L);

Status getElem(LinkList L, int i, int &e);

LNode *locateElem(LinkList L, int e);

void printList(LinkList &L);

void traverseList(LinkList L);

void createListHead(LinkList &L, int n);

void createListTail(LinkList &L, int n);

Status insertList(LinkList &L, int i, int e);

Status deleteList(LinkList &L, int i);

void mergeLinkList(LinkList &LA, LinkList &LB, LinkList &LC);

void linkListOperate();

void headOperate();

void tailOperate();

void mergeLinkListOperate();