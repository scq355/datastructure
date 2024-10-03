//
// Created by Jimmy on 2021/6/3.
//
#include "../../headers/common/Constants.h"
#include "../../headers/list/CLinkList.h"

Status initCLinkList(CLinkList& L)
{
    L = (CLNode*)malloc(sizeof(CLNode));
    if (!L)
    {
        return ERROR;
    }
    // 头结next点指向头结点
    L->next = L;
    return OK;
}

Status getElem(CLinkList L, int i, int& e)
{
    CLNode* p = L->next;
    int j = i;
    while (p != L && j < i)
    {
        p = p->next;
        ++j;
    }
    if (p == L || j > i)
    {
        return ERROR;
    }
    e = p->data;
    return OK;
}


CLNode* locateElem(CLinkList L, int e)
{
    CLNode* p = L->next;
    while (p != L && p->data != e)
    {
        p = p->next;
    }
    return p;
}

int getCLinkListLength(CLinkList& L)
{
    CLNode* p = L->next;
    int length = ZERO;
    if (p == L)
    {
        return length;
    }
    while (p != L)
    {
        p = p->next;
        ++length;
    }
    return length;
}


Status cLinkListInsert(CLinkList& L, int i, int e)
{
    int length = getCLinkListLength(L);
    if (++length < i)
    {
        return ERROR;
    }
    CLNode* p = L->next;
    int j = 0;
    while (p != L && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (j > i - 1)
    {
        return ERROR;
    }
    CLNode* s = (CLNode*)malloc(sizeof(CLNode));
    if (!s)
    {
        return ERROR;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status cLinkListDelete(CLinkList& L, int i)
{
    CLNode* p = L;
    int j = 0;
    while ((p->next != L) && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if ((p->next == L) || (j > i - 1))
    {
        return ERROR;
    }
    CLNode* q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

void cLinkListPrint(CLinkList& L)
{
    CLNode* p = L->next;
    while (p != L)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void createCLinkListHead(CLinkList& L, int n)
{
    for (int i = 0; i < n; ++i)
    {
        CLNode* p = (CLNode*)malloc(sizeof(CLNode));
        if (!p)
        {
            return;
        }
        p->data = i + 1;
        p->next = L->next;
        L->next = p;
    }
}


CLNode* getTailNode(CLinkList& L)
{
    CLNode* p = L;
    while (p->next != L)
    {
        p = p->next;
    }
    return p;
}

Status isTail(CLinkList L, CLNode* p)
{
    if (p->next == L)
    {
        return true;
    }
    return false;
}

void createCLinkListTail(CLinkList& L, int n)
{
    for (int i = 0; i < n; ++i)
    {
        CLNode* p = (CLNode*)malloc(sizeof(CLNode));
        if (!p)
        {
            return;
        }
        p->data = i + 1;
        p->next = L;
        CLNode* tail = getTailNode(L);
        tail->next = p;
    }
}

void mergeCLinkList(CLinkList& LA, CLinkList& LB, CLinkList& LC)
{
    CLNode* pa = LA->next;
    CLNode* pb = LB->next;
    LC = LA;
    CLNode* pc = LC;
    while (pa != LA && pb != LB)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa == LA ? pb : pa;
    while (pc->next != LB)
    {
        pc = pc->next;
    }
    pc->next = LC;
    delete LB;
}


void cLinkListOperate()
{
    CLNode* L;
    printf("初始化循环列表：");
    initCLinkList(L);
    cLinkListPrint(L);
    printf("循环列表插入元素：");
    for (int i = 0; i < 20; ++i)
    {
        cLinkListInsert(L, i, i);
    }
    cLinkListPrint(L);
    int elem;
    getElem(L, 6, elem);
    printf("获取循环列表指定位置为6的元素：");
    printf("%d\n", elem);
    printf("获取元素12所在循环列表的节点：");
    CLNode* location = locateElem(L, 12);
    printf("%d\n", location->data);
    printf("删除位置为7的节点：");
    cLinkListDelete(L, 7);
    cLinkListPrint(L);
}

void cLinkListHeadOperate()
{
    CLNode* L;
    printf("初始化循环列表：");
    initCLinkList(L);
    cLinkListPrint(L);
    createCLinkListHead(L, 5);
    cLinkListPrint(L);
}
