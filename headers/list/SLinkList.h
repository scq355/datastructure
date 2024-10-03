//
// Created by scq355 on 2024/10/3.
//
#include "../common/Constants.h"

#ifndef STATICLIST_H
#define STATICLIST_H

#endif //STATICLIST_H

// typedef struct
// {
//     int data;
//     int next;
// } SLinkList[MAXSIZE];

// 静态链表
struct SLNode
{
    int data;
    int next;
};
typedef struct SLNode SLinkList[MAXSIZE];