//
// Created by scq355 on 2024/10/5.
//
//  平衡二叉树节点
typedef struct AVLNode
{
    int key;
    int balance;
    struct AVLNode* l_child;
    struct AVLNode* r_child;
} AVLNode, *AVLTree;


