//
// Created by Jimmy on 2021/6/3.
//

#ifndef DATASTRUCTURE_SSTRING_H
#define DATASTRUCTURE_SSTRING_H
#include "Constants.h"

#endif //DATASTRUCTURE_SSTRING_H

typedef struct
{
    char ch[MAXSIZE];
    int length;
} SString;

// typedef struct
// {
//     char* ch;
//     int length;
// } HString;


Status subString(SString& sub, SString& str, int pos, int length);

int strCompare(SString s, SString t);

int index(SString s, SString t);

/**
 * 朴素模式匹配算法
 */
int index_match(SString s, SString t);


int index_kmp(SString s, SString t);