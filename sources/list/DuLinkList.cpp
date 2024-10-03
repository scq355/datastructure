//
// Created by Jimmy on 2021/6/3.
//

#include "../../headers/list/DuLinkList.h"

Status initDuLinkList(DuLinkList& L)
{
    L = new DuLNode;
    if (L == nullptr)
    {
        return ERROR;
    }
    L->next = L->prior = nullptr;
    return OK;
}

Status initCDuLinkList(DuLinkList& L)
{
    L = new DuLNode;
    if (L == nullptr) return false;
    L->prior = L->next = L;
    return OK;
}

Status empty(DuLinkList L)
{
    if (L->next == nullptr)
    {
        return true;
    }
    return false;
}

Status emptyCDuLinkList(DuLinkList L)
{
    if (L->next == L)
    {
        return OK;
    }
    return ERROR;
}

Status isTailCDuLinkList(DuLinkList L, DuLNode* p)
{
    if (p->next == L)
    {
        return OK;
    }
    return ERROR;
}

Status insertNextDuNode(DuLNode* p, DuLNode* s)
{
    if (p == nullptr || s == nullptr)
    {
        return ERROR;
    }
    s->next = p->next;
    // 如果p有后继节点(循环双列表不需要判断)
    if (p->next != nullptr)
    {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
}

DuLNode* locateEnumDuLinkList(DuLinkList& L, int i)
{
    DuLNode* p = L->next;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    {
        return nullptr;
    }
    return p;
}

DuLNode* getElemDuLinkList(DuLinkList& L, int e)
{
    DuLNode* p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

Status createDuLinkListHead(DuLinkList& L, int e)
{
    DuLNode* p = L;
    DuLNode* q = new DuLNode;
    q->data = e;
    q->next = p->next;
    if (p->next != nullptr)
    {
        p->next->prior = q;
    }
    p->next = q;
    q->prior = p;
    return OK;
}

Status createDuLinkListTail(DuLinkList& L, int e)
{
    DuLNode* p = L;
    DuLNode* q = (DuLNode*)malloc(sizeof(DuLNode));
    if (!q)
    {
        return ERROR;
    }
    while (p->next)
    {
        p = p->next;
    }
    q->data = e;
    q->next = p->next;
    q->prior = p;
    p->next = q;
    return OK;
}

Status deleteDuLinkList(DuLinkList& L, int i)
{
    DuLNode* p = L->next;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    {
        return ERROR;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

Status deleteNextNode(DuLNode* p)
{
    if (p == nullptr) return ERROR;
    DuLNode* q = p->next;
    if (q == nullptr) return ERROR;
    p->next = q->next;
    if (q->next != nullptr)
    {
        q->next->prior = p;
    }
    free(q);
    return OK;
}

void destroyDuList(DuLinkList& L)
{
    while (L->next != nullptr)
    {
        deleteNextNode(L);
    }
    free(L);
    L = nullptr;
}

void printDuLinkList(DuLinkList& L)
{
    DuLNode* p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void duLinkListOperate()
{
    DuLinkList L;
    printf("初始化双向链表：");
    initDuLinkList(L);
    printDuLinkList(L);
    printf("\n头插法插入双向链表：");
    for (int i = 0; i < 10; ++i)
    {
        createDuLinkListHead(L, i + 1);
    }
    printDuLinkList(L);
    printf("\n尾插法插入双向链表：");
    for (int i = 10; i < 20; ++i)
    {
        createDuLinkListTail(L, i + 1);
    }
    printDuLinkList(L);
    printf("\n确定元素15所在节点位置：");
    DuLNode* node = getElemDuLinkList(L, 15);
    printf("%d", node->data);
    printf("\n删除双向链表中第三个元素：");
    deleteDuLinkList(L, 3);
    printDuLinkList(L);
    printf("\n获取双向链表的第七个节点：");
    node = locateEnumDuLinkList(L, 7);
    printf("%d", node->data);
}
