//
// Created by Jimmy on 2021/6/3.
//

#include "SString.h"

Status subString(SString& sub, SString& str, int pos, int length)
{
    if (pos + length > str.length)
    {
        return ERROR;
    }
    for (int i = pos; i < pos + length; i++)
    {
        sub.ch[i - pos + 1] = str.ch[i];
    }
    sub.length = length;
    return OK;
}

int strCompare(SString s, SString t)
{
    for (int i = 1; i <= s.length && i <= t.length; i++)
    {
        if (s.ch[i] != t.ch[i])
        {
            return s.ch[i] - t.ch[i];
        }
    }
    // 扫描过所有字符相同，长度长的串更大
    return s.length - t.length;
}

int index(SString s, SString t)
{
    int i = 1;
    int n = s.length;
    int m = t.length;

    SString sub; // 暂存子串
    while (i <= n - m + 1)
    {
        subString(sub, s, i, m);
        if (strCompare(sub, t) != 0)
        {
            ++i;
        }
        else
        {
            return i;
        }
    }
    return 0;
}

int index_match(SString s, SString t)
{
    int i = 1, j = 1;
    while (i <= s.length && j <= t.length)
    {
        if (s.ch[i] == t.ch[j])
        {
            // 继续比较后续字符
            ++i;
            ++j;
        }
        else
        {
            // 指针后退，重新开始匹配
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > t.length)
    {
        return i - t.length;
    }
    return 0;
}

void get_next(SString t, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < t.length)
    {
        if (j == 0 || t.ch[i] == t.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

void get_next_val(const SString t, const int next[], int next_val[])
{
    next_val[1] = 0;
    for (int j = 2; j < t.length; ++j)
    {
        if (t.ch[next[j]] == t.ch[j])
        {
            next_val[j] = next_val[next[j]];
        } else
        {
            next_val[j] = next[j];
        }
    }
}

int index_kmp(const SString s, const SString t)
{
    int i = 1, j = 1;
    int next[t.length + 1];
    get_next(t, next);
    while (i <= s.length && j <= t.length)
    {
        if (j == 0 || s.ch[i] == t.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > t.length)
    {
        return i - t.length;
    }
    return 0;
}



