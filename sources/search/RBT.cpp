//
// Created by scq355 on 2024/10/5.
//
// 红黑树节点定义
struct RBTNode
{
    int key;
    RBTNode* parent;
    RBTNode* l_child;
    RBTNode* r_child;
    int color;
};
