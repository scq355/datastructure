//
// Created by Jimmy on 2021/6/27.
//
#include "../common/Constants.h"

#ifndef DATASTRUCTURE_AMGRAPH_H
#define DATASTRUCTURE_AMGRAPH_H


#define MaxInt 32767 // 极大值
#define MVNum 100 // 最大顶点数

bool visited[MVNum];
int vexSet[MVNum];

typedef char VerTexType; // 假设顶点的数据类型为字符型
typedef int ArcType; // 假设边的权值类型为数值型

typedef struct {
    VerTexType vexs[MVNum]; // 顶点表
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum; // 当前点数
    int arcnum; // 当前边数
}AMGraph;

struct { // 辅助数组，记录从顶点集U到V-U的权值最小的边
    VerTexType adjVex; // 最小边在U中的那个顶点
    ArcType lowCost; // 最小边上的权值
} closEdge[MVNum];


struct {
    VerTexType head;
    VerTexType  tail;
    ArcType lowCost;
}edge[MVNum];
#endif //DATASTRUCTURE_AMGRAPH_H

Status createUND(AMGraph &G);
