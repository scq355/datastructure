//
// Created by Jimmy on 2021/6/3.
//
#include <cstring>
#include "../../headers/tree/HuffmanTree.h"

void selectMinElem(HuffmanTree ht, int n, int &min1, int &min2) {
    if (n < 2) {
        return;
    }
    int weight = ht[1].weight;
    for (int i = 2; i <= n; ++i) {
        if (ht[i].parent != 0) {
            continue;
        }
        if (weight > ht[i].weight) {
            weight = ht[i].weight;
            min1 = i;
        }
    }
    weight = ht[1].weight;
    for (int i = 1; i <= n; ++i) {
        if (ht[i].parent != 0 || i == min1) {
            continue;
        }
        if (weight > ht[i].weight) {
            weight = ht[i].weight;
            min2 = i;
        }
    }
}

void createHuffmanTree(HuffmanTree &ht, int n) {
    if (n <= 1) {
        return;
    }
    int m = 2 * n - 1;
    ht = new HTNode[m + 1];
    for (int i = 1; i <= m; ++i) {
        ht[i].parent = 0;
        ht[i].l_child = 0;
        ht[i].r_child = 0;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d ", &ht[i].weight);
    }
    for (int i = n + 1; i <= m; ++i) {
        int min1;
        int min2;
        selectMinElem(ht, i - 1, min1, min2);
        ht[min1].parent = i;
        ht[min2].parent = i;
        ht[i].l_child = min1;
        ht[i].r_child = min2;
        ht[i].weight = ht[min1].weight + ht[min2].weight;
    }
}

void createHuffmanCode(HuffmanTree ht, HuffmanCode &hc, int n) {
    hc = new char* [n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';
    for (int i = 1; i <= n; ++i) {
        int start = n - 1;
        int c = i;
        int f = ht[i].parent;
        while (f != 0) {
            --start;
            if (ht[f].l_child == c) {
                cd[start] = '0';
            } else {
                cd[start] = '1';
            }
            c = f;
            f = ht[f].parent;
            hc[i] = new char[n - start];
            strcpy(hc[i], &cd[start]);
        }
    }
    delete[] cd;
}

void huffmanTreeOperate() {
    HuffmanTree ht;
    createHuffmanTree(ht, 5);
}
