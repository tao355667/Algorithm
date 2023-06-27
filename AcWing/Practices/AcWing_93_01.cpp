/*
  93. 递归实现组合型枚举
  01.自己根据94.排列型枚举改的
  时间巨长，达到了1045ms
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
const ll N = 100; //位置个数
ll n;//每个位置可选几个数
ll m;//几个位置
ll state[N];    //各位置选的是谁
//bool used[N];    //对应下标的元素是否被使用

void dfs(ll u)//u当前枚举的位置
{
    if (u > m)
    {
        for (ll i = 1; i <= m; i++)
        {
            printf("%lld ", state[i]);
        }
        printf("\n");
        return;
    }
    for (ll i = 1; i <= n; i++)//第u个位置，5个分支
    {
        //输出递归过程的信息
//        for (int i = 0; i < u; i++)
//            printf("\t");
//        printf("%lld %lld \n", u, i);
        if (u == 1 || state[u - 1] < i)
        {
            //1.第一个位置无脑选
            //2.当前分支选择的数，大于，上一个选择的数
            state[u] = i; //选中i
            dfs(u + 1);
            //保护现场
            state[u] = 0; //清空u位置的元素
        }
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    dfs(1);
    return 0;
}
