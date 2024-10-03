//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_DULINKLIST_H
#define DATASTRUCTURE_DULINKLIST_H

#endif //DATASTRUCTURE_DULINKLIST_H

// 双向列表
typedef struct DuLNode
{
    int data;
    struct DuLNode* prior;
    struct DuLNode* next;
} DuLNode, *DuLinkList;


Status initDuLinkList(DuLinkList& L);

/**
 * 初始化循环双列表
 */
Status initCDuLinkList(DuLinkList& L);

Status empty(DuLinkList L);

Status emptyCDuLinkList(DuLinkList L);

/**
 * 判断节点p是否为循环双列表尾结点
 */
Status isTailCDuLinkList(DuLinkList L, DuLNode* p);

// p节点后插入s节点
Status insertNextDuNode(DuLNode* p, DuLNode* s);

DuLNode* locateEnumDuLinkList(DuLinkList& L, int i);

DuLNode* getElemDuLinkList(DuLinkList& L, int e);

Status createDuLinkListHead(DuLinkList& L, int e);

Status createDuLinkListTail(DuLinkList& L, int e);

Status deleteDuLinkList(DuLinkList& L, int i);

/**
* 删除p节点的后继节点
*/
Status deleteNextNode(DuLNode* p);

void destroyDuList(DuLinkList& L);

void printDuLinkList(DuLinkList& L);

void duLinkListOperate();
