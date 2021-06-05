//
// Created by Jimmy on 2021/6/3.
//
#include "../common/Constants.h"
#ifndef DATASTRUCTURE_HUFFMANTREE_H
#define DATASTRUCTURE_HUFFMANTREE_H

#endif //DATASTRUCTURE_HUFFMANTREE_H

typedef char **HuffmanCode;

typedef struct {
    int weight;
    int parent;
    int l_child;
    int r_child;
}HTNode, *HuffmanTree;

void selectMinElem(HuffmanTree ht, int n, int &min1, int &min2);

void createHuffmanTree(HuffmanTree &ht, int n);

void createHuffmanCode(HuffmanTree ht, HuffmanCode &hc, int n);

void huffmanTreeOperate();