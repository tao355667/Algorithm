/*
895. 最长上升子序列

给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式第一行包含整数 N。

第二行包含 N 个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤1000，
−109≤数列中的数≤109
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int a[N], f[N];
int n;
int max_len;
int main()
{
    // 读数据
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 题解
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // 起码是1
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1); // f(i)：以a[i]结尾的子序列，它的最长长度
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res << endl;
    return 0;
}