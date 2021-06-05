//
// Created by Jimmy on 2021/6/3.
//
#include "../../headers/stack/LinkStack.h"

Status initLintStack(LinkStack &S) {
    S = nullptr;
    return OK;
}

Status pushLinkStack(LinkStack &S, int e) {
    StackNode *p = (StackNode *) malloc(sizeof(StackNode));
    if (!p) {
        return ERROR;
    }
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

Status popLinkStack(LinkStack &S, int &e) {
    if (S == nullptr) {
        return ERROR;
    }
    e = S->data;
    StackNode *p = S;
    S = S->next;
    free(p);
    return OK;
}

void linkStackTraverse(LinkStack &S) {
    StackNode *p = S;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int getLinkStackTop(LinkStack &S) {
    if (S != nullptr) {
        return S->data;
    }
    return NONE;
}

void linkStackOperate() {
    LinkStack S;
    initLintStack(S);
    printf("初始化：");
    linkStackTraverse(S);
    for (int i = 0; i < 11; ++i) {
        pushLinkStack(S, i);
    }
    printf("压栈之后的栈：");
    linkStackTraverse(S);
    int top;
    popLinkStack(S, top);
    printf("弹出栈顶元素：%d\n", top);
    printf("弹出后的栈：");
    linkStackTraverse(S);
    printf("当前栈顶元素：%d\n", getLinkStackTop(S));
}

