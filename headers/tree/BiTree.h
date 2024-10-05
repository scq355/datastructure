//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"
#include "queue/LinkQueue.h"
#ifndef DATASTRUCTURE_BITREE_H
#define DATASTRUCTURE_BITREE_H

#endif //DATASTRUCTURE_BITREE_H
typedef struct BiTNode
{
    char data;
    struct BiTNode* l_child;
    struct BiTNode* r_child;
} BiTNode, *BiTree;

/**
 * 先序递归遍历
 */
void firstTraverseRecursion(BiTree T);

/**
 * 中序递归遍历
 */
void inOrderTraverseRecursion(BiTree T);

/**
 * 后序递归遍历
 */
void lastTraverseRecursion(BiTree T);

/**
 * 中序遍历
 */
void inOrderTraverse(BiTree T);

/**
 * 构建二叉树
 */
void createBiTree(BiTree& T);

/**
 * 树的层次遍历，辅助队列
 */
void levelOrder(BiTree T);

/**
 * 复制二叉树
 */
void copyBiTree(BiTree T, BiTree& newT);

/**
 * 二叉树深度
 */
int biTreeDepth(BiTree T);

/**
 * 二叉树节点个数
 */
int biNodeCount(BiTree T);

void biTreeOperate();
