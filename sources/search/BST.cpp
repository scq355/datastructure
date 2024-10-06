#include <cstdlib>
#include <stddef.h>
//
// Created by scq355 on 2024/10/5.
//
// 二叉排序树节点
typedef struct BSTNode
{
    int key;
    struct BSTNode* l_child;
    struct BSTNode* r_child;
} BSTNode, *BSTree;

int BST_Insert(BSTree& t, int key)
{
    if (t == NULL)
    {
        t = (BSTree)malloc(sizeof(BSTNode));
        t->key = key;
        t->l_child = t->r_child = NULL;
        return 1;
    }
    if (key == t->key)
    {
        return 0;
    }
    if (key < t->key)
    {
        return BST_Insert(t->l_child, key);
    }
    if (key > t->key)
    {
        return BST_Insert(t->r_child, key);
    }
}

/**
 * 构建二叉排序树
 */
void create_BST(BSTree& t, int str[], int n)
{
    t = NULL;
    int i = 0;
    while (i < n)
    {
        BST_Insert(t, str[i]);
        i++;
    }
}


/**
 * 二叉排序树的查找
 */
BSTNode* BST_Search(BSTree t, int key)
{
    while (t != NULL && key != t->key)
    {
        // 小于，查找左子树
        if (key < t->key)
        {
            t = t->l_child;
        }
        // 大于，查找右子树
        else
        {
            t = t->r_child;
        }
    }
    return t;
}

/**
 * 二叉排序树的查找-递归实现
 */
BSTNode* BST_Search_Recursion(BSTree t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (key == t->key)
    {
        return t;
    }
    if (key < t->key)
    {
        return BST_Search_Recursion(t->l_child, key);
    }
    if (key > t->key)
    {
        return BST_Search_Recursion(t->r_child, key);
    }
}


