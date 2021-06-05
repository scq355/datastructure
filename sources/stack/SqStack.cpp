//
// Created by Jimmy on 2021/6/3.
//
#include "../../headers/stack/SqStack.h"


Status initStack(SqStack &S) {
    S.base = new int[MAXSIZE];
    if (!S.base) {
        return ERROR;
    }
    S.top = S.base;
    S.stackSize = MAXSIZE;
    return OK;
}

Status stackEmpty(SqStack &S) {
    return S.base == S.top;
}

int stackLength(SqStack &S) {
    return S.top - S.base;
}

Status push(SqStack &S, char e) {
    if (S.top - S.base == S.stackSize) {
        return ERROR;
    }
    *S.top++ = e;
    return OK;
}

Status pop(SqStack &S, char &e) {
    if (S.top == S.base) {
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

Status destoryStack(SqStack &S) {
    S.top = nullptr;
    S.base = nullptr;
    S.stackSize = ZERO;
    return OK;
}

Status clearStack(SqStack &S) {
    if (S.base) {
        S.top = S.base;
    }
    return S.top == S.base;
}

int getTop(SqStack S) {
    if (S.top != S.base) {
        return *(S.top - 1);
    }
    return NONE;
}

void stackTraverse(SqStack &S) {
    int *p = S.base;
    while (p != S.top) {
        printf("%d ", *p);
        ++p;
    }
    printf("\n");
}

void sqStackOperate() {
    SqStack S;
    printf("初始化栈：\n");
    initStack(S);
    printf("压栈：");
    for (int i = 0; i <= 10; ++i) {
        push(S, i);
    }
    stackTraverse(S);
    printf("栈当前长度：%d\n", stackLength(S));
    printf("栈顶元素：%d\n", getTop(S));
    char elem;
    printf("出栈：");
    for (int i = S.top - S.base; i > 0; i--) {
        pop(S, elem);
        printf("%d ", elem);
    }
}