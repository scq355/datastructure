//
// Created by scq355 on 2024/10/5.
//
#include "ThreadBiTree.h"

ThreadBiNode* p;
ThreadBiNode* pre = NULL;
ThreadBiNode* final = NULL;

void visit(ThreadBiNode* q)
{
    // 左子树为空，建立前驱线索
    if (q->l_child == nullptr)
    {
        q->l_child = pre;
        q->l_tag = 1;
    }
    // 建立前驱节点的后继线索
    if (pre != nullptr && pre->r_child == nullptr)
    {
        pre->r_child = q;
        pre->r_tag = 1;
    }
    pre = q;
}

void inOrderThread(ThreadBiTree T)
{
    if (T != NULL)
    {
        inOrderThread(T->l_child);
        visit(T);
        inOrderThread(T->r_child);
    }
}

void createInThread(ThreadBiTree T)
{
    pre = NULL;
    if (T != nullptr)
    {
        inOrderThread(T);
        if (pre->r_child == nullptr)
        {
            pre->r_tag = 1;
        }
    }
}

void preThread(ThreadBiTree T)
{
    if (T != NULL)
    {
        visit(T);
        if (p->l_tag == 0)
        {
            preThread(T->l_child);
        }
        preThread(T->r_child);
    }
}

void createPreThread(ThreadBiTree T)
{
    pre = NULL;
    if (T != nullptr)
    {
        preThread(T);
        if (pre->r_child == nullptr)
        {
            pre->r_tag = 1;
        }
    }
}

void postThread(ThreadBiTree T)
{
    if (T != NULL)
    {
        postThread(T->l_child);
        postThread(T->r_child);
        visit(T);
    }
}

void createPostThread(ThreadBiTree T)
{
    pre = NULL;
    if (T != nullptr)
    {
        postThread(T);
        if (pre->r_child == nullptr)
        {
            pre->r_tag = 1;
        }
    }
}


/**
 * 找到以p为根的子树中，第一个被中序遍历的节点
 */
ThreadBiNode* firstNode(ThreadBiNode* p)
{
    while (p->l_tag == 0)
    {
        p = p->l_child;
    }
    return p;
}

/**
 * 中序线索二叉树中找到节点p的后继节点
 */
ThreadBiNode* nextNode(ThreadBiNode* p)
{
    if(p->r_tag == 0)
    {
        return firstNode(p->r_child);
    }
    else
    {
        return p->r_child;
    }
}

/**
 * 对中序线索二叉树进行中序遍历（非递归）
 */
void inOrder(ThreadBiNode* T)
{
    for (ThreadBiNode* p = firstNode(T); p != nullptr; p = nextNode(p))
    {
        visit(p);
    }
}

/**
 * 找到以p为根的子树中，最后一个被中序遍历的节点
 */
ThreadBiNode* lastNode(ThreadBiNode* p)
{
    while (p->r_tag == 0)
    {
        p = p->r_child;
    }
    return p;
}

/**
 * 中序线索二叉树中找到节点p的前驱节点
 */
ThreadBiNode* preNode(ThreadBiNode* p)
{
    if (p->l_tag == 0)
    {
        return lastNode(p->l_child);
    }
    else
    {
        return p->l_child;
    }
}

/**
 * 中序线索二叉树逆向中序遍历
 */
void revInOrder(ThreadBiNode* T)
{
    for (ThreadBiNode* p = lastNode(T); p != nullptr; p = preNode(p))
    {
        visit(p);
    }
}