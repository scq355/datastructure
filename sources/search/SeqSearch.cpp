//
// Created by scq355 on 2024/10/5.
//
#include "../common/Constants.h"
#include "../list/SqList.h"
typedef struct
{
    int* elem;
    int tableLen;
} SSTable;

int searchSeq(SSTable st, int key)
{
    int i;
    for (i = 0; i < st.tableLen && st.elem[i] != key; i++);
    return i == st.tableLen ? -1 : i;
}

int searchBinary(SSTable st, int key)
{
    int low = 0;
    int high = st.tableLen - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (st.elem[mid] == key)
        {
            return mid;
        }
        if (st.elem[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// 分块查找-索引表
typedef struct
{
    int maxValue;
    int low, high;
} Index;

