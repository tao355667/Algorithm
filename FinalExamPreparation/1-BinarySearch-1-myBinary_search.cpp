/*
1-二分查找-复习
1-自己写的二分查找
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int a[] = {0, 4, 2, 6, 6, 6, 8, 10, 12, 14, 16, 18, 20};
int n = sizeof(a) / sizeof(a[0]);
int findnum; //要找的数
bool check(int m, int find)
{
    return a[m] >= find;
}
/*
param
l：起点下标
r：终点下标
find：要找的数
return
找到则返回下标，否则返回-1
思路
将数组分为两块
1：l~m
2：m+1~r
若数组中元素不重复：会尽可能找到>=find的第一个元素(find超过上限的时候，就返回最后一个下标)
若数组中元素重复，且存在解，则找到的位置不确定（与计算过程有关）
若数组中元素重复，且不存在解，则会找到>=find的第一个元素
*/
int Binary_search(int l, int r, int find)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid, find))
            r = mid;
        else
            l = mid + 1;
    }
    // if (a[l] == find) //此时l==r，返回哪个都行
    return l;
    // else
    //     return -1;
}
void print_arr(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << setw(3) << a[i];
    }
    cout << endl;
}
int main()
{
    // 1-排序再二分查找
    sort(a, a + sizeof(a) / sizeof(a[0]));
    print_arr(a, sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i;
    }
    cout << endl;
    // 2-二分查找
    while (1)
    {
        int num;
        cout << "你要找几？";
        cout.flush();
        cin >> num;
        cout << "你要找的元素的下标为：" << Binary_search(0, n - 1, num) << endl;
    }

    return 0;
}