//
// Created by Jimmy on 2021/6/3.
//
#include "../../headers/tree/BiTree.h"

void firstTraverseRecursion(BiTree T)
{
    if (T)
    {
        printf("%c ", T->data);
        firstTraverseRecursion(T->l_child);
        firstTraverseRecursion(T->r_child);
    }
}

void inOrderTraverseRecursion(BiTree T)
{
    if (T)
    {
        inOrderTraverseRecursion(T->l_child);
        printf("%c ", T->data);
        inOrderTraverseRecursion(T->r_child);
    }
}

void lastTraverseRecursion(BiTree T)
{
    if (T)
    {
        lastTraverseRecursion(T->l_child);
        lastTraverseRecursion(T->r_child);
        printf("%c ", T->data);
    }
}

// 1 2 # # 4 5 # 6 # # # #
void createBiTree(BiTree& T)
{
    char ch;
    scanf("%c ", &ch);
    if (ch == '#')
    {
        T = nullptr;
    }
    else
    {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        if (!T)
        {
            return;
        }
        T->data = ch;
        createBiTree(T->l_child);
        createBiTree(T->r_child);
    }
}

void levelOrder(BiTree T)
{
    LinkQueue Q;
    initQueue(Q);
    BiTree p;
    enQueue(Q, T->data);
    while (isEmpty(Q))
    {
        deQueue(Q, p->data);
        printf("%c ", p->data);
        if (p->l_child != nullptr)
        {
            enQueue(Q, p->l_child->data);
        }
        if (p->r_child != nullptr)
        {
            enQueue(Q, p->r_child->data);
        }
    }
}

void copyBiTree(BiTree T, BiTree& newT)
{
    if (T == nullptr)
    {
        newT = nullptr;
        return;
    }
    else
    {
        newT = new BiTNode;
        newT->data = T->data;
        copyBiTree(T->l_child, newT->l_child);
        copyBiTree(T->r_child, newT->r_child);
    }
}

int biTreeDepth(BiTree T)
{
    if (T == nullptr)
    {
        return ZERO;
    }
    else
    {
        int l = biTreeDepth(T->l_child);
        int r = biTreeDepth(T->r_child);
        // 树的深度 = MAX(左子树深度，右子树深度) + 1
        if (l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
    }
}

int biNodeCount(BiTree T)
{
    if (T == nullptr)
    {
        return ZERO;
    }
    else
    {
        return biNodeCount(T->l_child) + biNodeCount(T->r_child) + 1;
    }
}

void biTreeOperate()
{
    BiTree T;
    printf("创建一棵二叉树：");
    createBiTree(T);
    printf("\n计算二叉树的深度：%d", biTreeDepth(T));
    printf("\n计算二叉树的节点数：%d", biNodeCount(T));
    printf("\n中序遍历二叉树：");
    inOrderTraverseRecursion(T);
    printf("\n先序遍历二叉树：");
    firstTraverseRecursion(T);
    printf("\n后序遍历二叉树：");
    lastTraverseRecursion(T);
}
