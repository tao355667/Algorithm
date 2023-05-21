/*
  AcWing 1209. 带分数
  00.最暴力的写法
      1.枚举全排列
      2.枚举位数（枚举a和b，可算出c）
      3.直接算出n，判断等式是否成立
      4.时间复杂度：9*9!*C(8,2)=91445760 < 1亿
 */
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 20;
int n = 9;
int state[N];
bool used[N];
int s;     //输入的正整数
int sum;   //记录结果
int a, b, c; //分割出的3个数
//计算右边分式的值
int calc(int l, int r)
{
    int num = 0;
    for (int i = l; i <= r; i++)
    {
        num*=10;
        num += state[i];
    }
    return num;
}
//将9个数字分割，相当于在8个位置放两个隔板
void dfsabc()
{
//    for(int i=1;i<=n;i++){
//        printf("%d ",state[i]);
//    }
//    puts("");
    for (int i = 1; i <= 7; i++)
    {
        for (int j = i + 1; j <= 8; j++)
        {
            //算出a，b，c
            a = calc(1, i); //a 1~i
            b = calc(i + 1, j); //b i+1~j
            c = calc(j + 1, 9); //c j+1~9
            //s==a+b/c
            if (s * c == a * c + b) sum++; //符合条件，结果+1
        }
    }
}
//全排列
void dfs(int u)
{
    if (u > n)
    {
        dfsabc();//计算数字判断
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            state[u] = i;
            used[i] = true;
            dfs(u + 1);
            //恢复现场
            state[u] = 0;
            used[i] = false;
        }
    }

}
int main()
{
    scanf("%d", &s);
    dfs(1);
    printf("%d", sum);
    return 0;
}
