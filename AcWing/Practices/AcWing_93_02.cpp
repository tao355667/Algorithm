/*
  93. 递归实现组合型枚举
  02.y总版本
      -way[] 位置
      -u 当前枚举的位置
      -start 当前最小可以以哪些数开始
  -加入剪枝，从而减少运行时间（从146ms减少至39ms）
      -如dfs(4,x)是无解的，不需要浪费时间去搜索
      -总共能选择的个数记为x：(u-1)+(n-start+1)=u+n-start
      -无解：(x<m)即(u+n-start<m)

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
    if(u+n-start<m)
        return;
    //输出调试信息
    for(int i=1;i<=u;i++){
        printf("\t");
    }
    printf("dfs(%lld,%lld)\n",u,start);
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
    scanf("%lld%lld", &n, &m);
    dfs(1, 1);
    return 0;
}
