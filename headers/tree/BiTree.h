//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_BITREE_H
#define DATASTRUCTURE_BITREE_H

#endif //DATASTRUCTURE_BITREE_H
typedef struct BiTNode {
    char data;
    struct BiTNode *l_child;
    struct BiTNode *r_child;
} BiTNode, *BiTree;

void firstTraverseRecursion(BiTree T);

void inOrderTraverseRecursion(BiTree T);

void lastTraverseRecursion(BiTree T);

void inOrderTraverse(BiTree T);

void createBiTree(BiTree &T);

void copyBiTree(BiTree T, BiTree &newT);

int biTreeDepth(BiTree T);

int biNodeCount(BiTree T);

void biTreeOperate();