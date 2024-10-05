//
// Created by scq355 on 2024/10/5.
//

#ifndef THREADBINODE_H
#define THREADBINODE_H

#endif //THREADBINODE_H
#include "../common/Constants.h"

// 线索二叉树
    typedef struct ThreadBiNode
{
    int data;
    struct ThreadBiNode* l_child;
    // tag = 0:指向孩子；1:是线索
    int l_tag;
    struct ThreadBiNode* r_child;
    int r_tag;
} ThreadBiNode, *ThreadBiTree;
