/*
  93. 递归实现组合型枚举
  00.y总版本
      -way[] 位置
      -u 当前枚举的位置
      -start 当前最小可以以哪些数开始
  运行时间146 ms
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
const ll N = 100; //位置个数
ll n;//每个位置可选几个数
ll m;//几个位置
ll way[N];    //各位置选的是谁

/*
  -u 当前枚举的位置
  -start 当前最小可以以哪些数开始
 */
void dfs(ll u, ll start)
{
    if (u == m + 1)
    {
        for (int i = 1; i < u; i++)
        {
            printf("%lld ", way[i]);
        }
        puts("");
        return;
    }
    for (int i = start; i <= n; i++)//n个分支
    {
        way[u] = i;
        dfs(u + 1, i + 1);
        //恢复现场
        way[u] = 0;
    }
}
int main()
{
    scanf("%lld %lld", &n, &m);
    dfs(1, 1);
    return 0;
}
