//
// Created by Jimmy on 2021/6/27.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_ALGRAPH_H
#define DATASTRUCTURE_ALGRAPH_H

#define MVNum 100 // 最大顶点数

bool visited[MVNum];

typedef char VerTexType; // 假设顶点的数据类型为字符型

typedef struct ArcNode { // 边节点
    int adjVex; // 边指向的顶点的位置
    struct ArcNode* nextArc; // 指向下一条边的指针
    int info; // 和边相关信息
}ArcNode;

typedef struct VNode { // 顶点信息
    VerTexType data; // 指向第一条依附该顶点的边的类型
    ArcNode* firstArc;
}VNode, AdjList[MVNum]; // 邻接表类型

typedef struct { // 邻接表
    AdjList vertices;
    int vexnum; // 当前顶点数
    int arcnum; // 当前边数
}ALGraph;

#endif //DATASTRUCTURE_ALGRAPH_H

Status createUDG(ALGraph &G);
