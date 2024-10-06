//
// Created by scq355 on 2024/10/6.
//
// 直接插入排序
void insert_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            temp = a[i];
            for (j = i - 1; j >= 0 && a[j] > temp; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}

// 插入排序-带哨兵
void insert_sort2(int a[], int n)
{
    int i, j;
    for (i = 2; i <= n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            a[0] = a[i];
            for (j = i - 1; a[j] > a[0]; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = a[0];
        }
    }
}

//折半插入排序
void insert_sort3(int a[], int n)
{
    int i, j, low, high, mid;
    for (i = 2; i <= n; ++i)
    {
        a[0] = a[i];
        low = 1;
        high = i - 1;
        // 折半查找
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (a[mid] > a[0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // 统一后移元素，空出查找位置
        for (j = i - 1; j >= high + 1; j--)
        {
            a[j + 1] = a[j];
        }
        a[high + 1] = a[0];
    }
}

//希尔排序
void shell_sort(int a[], int n)
{
    int d, i, j;
    for (d = n / 2; d >= 1; d = d / 2)
    {
        for (i = d + 1; i <= n; i++)
        {
            if (a[i] < a[i - d])
            {
                a[0] = a[i];
                for (j = i - d; j > 0 && a[j] > a[0]; j = j - d)
                {
                    a[j + d] = a[j];
                }
                a[j + d] = a[0];
            }
        }
    }
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 冒泡排序
void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        bool flag = false;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (!flag)
        {
            return;
        }
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
        {
            high--;
        }
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
        {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}
// 快速排序
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
}
// 简单选择排序
void select_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[i], a[min]);
        }
    }
}