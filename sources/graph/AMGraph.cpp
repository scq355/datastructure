//
// Created by Jimmy on 2021/6/27.
//
// #include "../../headers/graph/AMGraph.h"
//
// int locateVex(AMGraph &G, int value) {
//     for (int i = 0; i < G.vexnum; ++i) {
//         if (value == G.vexs[i]) {
//             return i;
//         }
//     }
//     return ZERO;
// }
//
// Status createUND(AMGraph &G) {
//     // 总顶点数，总边数
//     scanf("%d%d", &G.vexnum, &G.arcnum);
//     // 点的信息
//     for (int i = 0; i < G.vexnum; ++i) {
//         scanf("%s", &G.vexs[i]);
//     }
//     // 初始化邻接矩阵，边的权值设置为极大值
//     for (int i = 0; i < G.vexnum; ++i) {
//         for (int j = 0; j < G.vexnum; ++j) {
//             G.arcs[i][j] = MaxInt;
//         }
//     }
//     for (int i = 0; i < G.arcnum; ++i) {
//         int v1 = 0;
//         int v2 = 0;
//         int w = 0;
//         scanf("%d%d%d", &v1, &v2, &w);
//         int j = locateVex(G, v1);
//         int k = locateVex(G, v2);
//         G.arcs[j][k] = w;
//         G.arcs[k][j] = G.arcs[j][k];
//     }
//     return OK;
// }
//
// void DFS_AM(AMGraph G, int v) {
//     printf("%d", v);
//     visited[v] = true;
//     for (int w = 0; w < G.vexnum; ++w) {
//         if ((G.arcs[v][w] != 0) && (!visited[w])) {
//             DFS_AM(G, w);
//         }
//     }
// }
//
// void MiniSpanTreePrim(AMGraph G, VerTexType u) {
//     int k = locateVex(G, u);
//     for (int j = 0; j < G.vexnum; ++j) {
//         if (j != k) {
//             closEdge[j] = {u, G.arcs[k][j]};
//         }
//     }
//     closEdge[k].lowCost = 0;
//     for (int i = 1; i < G.vexnum; ++i) {
// //        k = min(closEdge);
//         VerTexType u0 = closEdge[k].adjVex;
//         ArcType v0 = G.vexs[k];
//         printf("%hhd%d", u0, v0);
//         closEdge[k].lowCost = 0;
//         for (int j = 0; j < G.vexnum; ++j) {
//             if (G.arcs[k][j] < closEdge[j].lowCost) {
//                 closEdge[j] = {G.vexs[k], G.arcs[k][j]};
//             }
//         }
//     }
// }
//
//
// void MiniSpanTreeKruskal(AMGraph G) {
//     for (int i = 0; i < G.vexnum; ++i) {
//         vexSet[i] = i;
//     }
//     for (int i = 0; i < G.arcnum; ++i) {
//         int v1 = locateVex(G, edge[i].head);
//         int v2 = locateVex(G, edge[i].tail);
//         int vs1 = vexSet[v1];
//         int vs2 = vexSet[v2];
//         if (vs1 != vs2) {
//             printf("%d%d", edge[i].head, edge[i].tail);
//             for (int j = 0; j < G.vexnum; ++j) {
//                 if (vexSet[j] == vs2) {
//                     vexSet[j] = vs1;
//                 }
//             }
//         }
//     }
// }




