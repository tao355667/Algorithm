/*
  AcWing 92. 递归实现指数型枚举
  从 1∼n这 n个整数中随机选取任意多个，输出所有可能的选择方案。
  组合数，最终结果种类为2^n
  二项式定理
  相关词：递归，递归搜索树，深搜
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 16;
int arr[N]; // 0：还没考虑。1：选。2：不选
int a;

void dfs(int n)
{
    if (n > a)
    {
        for (int i = 1; i <= a; i++)
        {
            if (arr[i] == 1)
                cout << i << ' ';
        }
        puts("");
        return;
    }
    //左孩子，不选
    arr[n] = 2;
    dfs(n + 1);
    arr[n] = 0; //回溯时保护现场
    //右孩子，选
    arr[n] = 1;
    dfs(n + 1);
    arr[n] = 0; //回溯时保护现场
}

main()
{
    cin >> a;
    dfs(1);
}
