//
// Created by Jimmy on 2021/6/27.
//

#include "../../headers/graph/ALGraph.h"

int locateVex(ALGraph &G, int value) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (value == G.vertices[i].data) {
            return i;
        }
    }
    return ZERO;
}

Status createUDG(ALGraph &G) {
    // 总顶点数，总边数
    scanf("%d%d", &G.vexnum, &G.arcnum);
    for (int i = 0; i < G.vexnum; ++i) {
        scanf("%s", &G.vertices[i].data);
        G.vertices->firstArc = nullptr;
    }
    for (int i = 0; i < G.arcnum; ++i) {
        // 输入一条边依附的两个顶点
        int v1 = 0;
        int v2 = 0;
        scanf("%d%d", &v1, &v2);
        // 确定 v1 和 v2 在 G 中位置，即顶点在 G.vertices 中的序号
        int j = locateVex(G, v1);
        int k = locateVex(G, v2);
        // 生成一个新的边结点*p1
        ArcNode *p1 = new ArcNode;
        p1->adjVex = k;
        // 将新结点*p1 插入顶点 vj 的边表头部
        p1->nextArc = G.vertices[j].firstArc;
        G.vertices[j].firstArc = p1;
        ArcNode *p2 = new ArcNode;
        p2->adjVex = j;
        p2->nextArc = G.vertices[k].firstArc;
        G.vertices[k].firstArc = p2;
    }
    return OK;
}

void DFS_AL(ALGraph G, int v) {
    printf("%d", v);
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstArc;
    while (p != nullptr) {
        int w = p->adjVex;
        if (!visited[w]) {
            DFS_AL(G, w);
        }
        p = p->nextArc;
    }
}