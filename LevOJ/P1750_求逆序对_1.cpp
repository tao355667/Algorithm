/*
P1750 求逆序对
洛谷P1908
====关键词===================================================
1.归并排序（O(nlogn)）
2.别人的题解https://www.luogu.com.cn/blog/cpp/solution-p1908
====关键词===================================================
====题目===================================================
猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。

最近，TOM 老猫查阅到一个人类称之为 “逆序对” 的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中
ai>aj且i<j 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。注意序列中可能有重复数字。
输入格式
第一行，一个数n，表示序列中有n 个数。 第二行n 个数，表示给定的序列。序列中每个数字不超10^9。
输出格式
输出序列中逆序对的数目。
输入输出样例
输入样例
Copy to Clipboard
6
5 4 2 6 3 1
输出样例
Copy to Clipboard
11
说明 / 提示
对于所有数据，n≤5×10^5
====题目===================================================
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 5e5 + 1;
int a[N];      //存储数据的数组
int a1[N];     //临时存放排序结果
int n;         //几个数
long long ans; //答案
void showArr(int *arr)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
/*
s：起点下标
e：终点下标
*/
void merge_sort(int s, int e)
{
    if (s == e)
        return;//递归终止条件
    int mid = (s + e) / 2;
    merge_sort(s, mid);
    merge_sort(mid + 1, e);
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= e)
    { //挑小的放入临时数组a1[]中
        if (a[i] > a[j])
        {
            a1[k++] = a[j++];
            ans += mid - i + 1; //统计答案
        }
        else
            a1[k++] = a[i++];
    }
    while (i <= mid)
    { //前半部分没用完
        a1[k++] = a[i++];
    }
    while (j <= e)
    { ///后半部分没用完
        a1[k++] = a[j++];
    }
    for (int l = s; l <= e; l++)
    { //将排序结果存入a中
        a[l] = a1[l];
    }
}
int main()
{
    //读数
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    //题解
    // showArr(a);
    merge_sort(1, n); //归并排序
    // showArr(a);
    //输出答案
    printf("%lld", ans);
    return 0;
}