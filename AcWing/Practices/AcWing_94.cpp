/*
  AcWing 94. 递归实现排列型枚举
  1~n，不重复，全排列
  结果数目为n!
  时间复杂度O(n*n!),推导见https://www.cnblogs.com/FishSmallWorld/p/17078969.html#autoid-1-0-0
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 10; //最大数据9个，有一个不用，故总共10个
int state[N];    //各位置选的是谁
bool used[N];    //对应下标的元素是否被使用
int n;

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
            printf("%d ", state[i]);
        puts("");
        return;
    }
    //按顺序选择第u个位置的元素
    for (int i = 1; i <= n; i++)
    {
        if (!used[i]) // i元素未被使用
        {
            state[u] = i;
            used[i] = true;
            dfs(u + 1);
            //保护现场。state[]不需要保护，会自动覆盖
            state[u] = 0;
            used[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1); //第几个空位
    return 0;
}
