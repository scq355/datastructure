//
// Created by Jimmy on 2021/6/3.
//

#include "../../headers/list/SqList.h"

Status initList(SqList& L)
{
    L.elem = new int[MAXSIZE];
    if (!L.elem)
    {
        return ERROR;
    }
    L.length = 0;
    return OK;
}

Status getElem(SqList& L, int i, int& e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}

int locateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; ++i)
    {
        if (L.elem[i] == e)
        {
            return i + 1;
        }
    }
    return NONE;
}

Status insertList(SqList& L, int i, int e)
{
    if ((i < 1) || (i > L.length + 1))
    {
        return ERROR;
    }
    if (L.length == MAXSIZE)
    {
        return ERROR;
    }
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    ++L.length;
    return OK;
}

Status deleteList(SqList& L, int i)
{
    if ((i < 1) || (i > L.length))
    {
        return ERROR;
    }
    for (int j = i; j <= L.length; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    --L.length;
    return OK;
}

void printList(const SqList& L)
{
    for (int i = 0; i < L.length; ++i)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

void mergeSqList(const SqList& LA, const SqList& LB, SqList& LC)
{
    LC.length = LA.length + LB.length;
    LC.elem = new int[LC.length];
    int* pc = LC.elem;
    const int* pa = LA.elem;
    const int* pb = LB.elem;
    const int* paLast = LA.elem + LA.length - 1;
    const int* pbLast = LB.elem + LB.length - 1;
    while ((pa <= paLast) && (pb <= pbLast))
    {
        if (*pa < *pb)
        {
            *pc++ = *pa++;
        }
        else
        {
            *pc++ = *pb++;
        }
    }
    while (pa <= paLast)
    {
        *pc++ = *pa++;
    }
    while (pb <= pbLast)
    {
        *pc++ = *pb++;
    }
}

void sqListOperate()
{
    SqList L;
    printf("初始化线性表：");
    initList(L);
    printList(L);
    printf("将元素插入线性表：");
    for (int i = 0; i < 10; ++i)
    {
        insertList(L, i, i);
    }
    printList(L);
    printf("确定元素8在线性表中的位置：");
    int location = locateElem(L, 8);
    printf("%d\n", location);
    int elem;
    getElem(L, 4, elem);
    printf("获取线性表中位置为4的元素：");
    printf("%d\n", elem);
    printf("删除线性表中位置为3的元素：");
    deleteList(L, 3);
    printList(L);
}


void mergeSqListOperate()
{
    SqList LA;
    printf("初始化线性表LA：");
    initList(LA);
    printList(LA);
    printf("将元素插入线性表LA：");
    for (int i = 0; i < 6; ++i)
    {
        insertList(LA, i + 1, i + 3);
    }
    printList(LA);

    SqList LB;
    printf("初始化线性表LB：");
    initList(LB);
    printList(LB);
    printf("将元素插入线性表LB：");
    for (int i = 0; i < 5; ++i)
    {
        insertList(LB, i + 1, i + 10);
    }
    printList(LB);

    SqList LC;
    printf("初始化线性表LC：");
    initList(LC);
    mergeSqList(LA, LB, LC);
    printList(LC);
}


