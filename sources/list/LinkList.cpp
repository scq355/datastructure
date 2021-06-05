//
// Created by Jimmy on 2021/6/3.
//

#include "../../headers/list/LinkList.h"

Status initList(LinkList &L) {
    L = new LNode;
    L->next = nullptr;
    return OK;
}

Status getElem(LinkList L, int i, int &e) {
    LNode *p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    e = p->data;
    return OK;
}

LNode *locateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

void printList(LinkList &L) {
    LNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void traverseList(LinkList L) {
    if (L) {
        printf("%d ", L->data);
        traverseList(L->next);
    }
}

void createListHead(LinkList &L, int n) {
    L = new LNode;
    L->next = nullptr;
    for (int i = 0; i < n; ++i) {
        LNode *p = new LNode;
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

void createListTail(LinkList &L, int n) {
    L = new LNode;
    L->next = nullptr;
    LNode *t = L;
    for (int i = 0; i < n; ++i) {
        LNode *p = new LNode;
        scanf("%d ", &p->data);
        p->next = nullptr;
        t->next = p;
        t = p;
    }
}

Status insertList(LinkList &L, int i, int e) {
    LNode *p = L;
    int j = 0;
    while (p && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) {
        return ERROR;
    }
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status deleteList(LinkList &L, int i) {
    LNode *p = L;
    int j = 0;
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || (j > i - 1)) {
        return ERROR;
    }
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

void mergeLinkList(LinkList &LA, LinkList &LB, LinkList &LC) {
    LNode *pa = LA->next;
    LNode *pb = LB->next;
    LC = LA;
    LNode *pc = LC;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete LB;
}

void linkListOperate() {
    LNode *L;
    printf("初始化单链表：");
    initList(L);
    printList(L);
    printf("单链表插入元素：");
    for (int i = 1; i <= 20; ++i) {
        insertList(L, i, i);
    }
    printList(L);
    int elem;
    getElem(L, 6, elem);
    printf("获取单链表指定位置为6的元素：");
    printf("%d\n", elem);
    printf("获取元素12所在单链表的节点：");
    LNode *location = locateElem(L, 12);
    printf("%d\n", location->data);
    printf("删除位置为7的节点：");
    deleteList(L, 7);
    printList(L);
}

void headOperate() {
    LNode *L;
    printf("初始化单链表：");
    initList(L);
    printList(L);
    createListHead(L, 5);
    printList(L);
}

void tailOperate() {
    LNode *L;
    printf("初始化单链表：");
    initList(L);
    printList(L);
    createListTail(L, 5);
    printList(L);
}

void mergeLinkListOperate() {
    LinkList LA;
    printf("初始化LA：");
    initList(LA);
    printList(LA);
    printf("LA插入元素：");
    for (int i = 0; i < 6; ++i) {
        insertList(LA, i + 1, i + 3);
    }
    printList(LA);

    LinkList LB;
    printf("初始化LB：");
    initList(LB);
    printList(LB);
    printf("LB插入元素：");
    for (int i = 0; i < 5; ++i) {
        insertList(LB, i + 1, i + 10);
    }
    printList(LB);

    LinkList LC;
    printf("初始化LC：");
    initList(LC);
    mergeLinkList(LA, LB, LC);
    printf("\n合并后的链表：");
    printList(LC);
}