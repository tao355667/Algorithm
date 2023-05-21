/*
P1477 部分背包问题
====关键词===================================================
DP（动态规划），二维DP数组?
贪心!先把价值高的全拿走！
====关键词===================================================
====题目===================================================
题目描述
阿里巴巴走进了装满宝藏的藏宝洞。藏宝洞里面有N(N≤100)
N(N≤100) 堆金币，第i 堆金币的总重量和总价值分别是
mi,vi,(1<=mi,vi<=100)。阿里巴巴有一个承重量为
T(T≤1000) 的背包，但并不一定有办法将全部的金币都装进去。他想装走尽可能多价值的金币。所有金币都可以随意分割，分割完的金币重量价值比（也就是单位价格）不变。请问阿里巴巴最多可以拿走多少价值的金币？
输入描述
第一行两个整数N,T。
接下来N行，每行两个整数mi,vi​。
输出描述
一个实数表示答案，输出两位小数。
样例输入
Copy to Clipboard
4 50
10 60
20 100
30 120
15 45
样例输出
Copy to Clipboard
240.00
====题目===================================================
*/
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct jbd //金币堆
{
    int m;               //金币堆的重量
    int v;               //金币堆的总价值
    double averageValue; //金币堆的单价
};
const int N = 101;
const int T = 1001;
jbd a[N]; //金币堆
int n;    //金币堆数
int t;    //背包容量
//显示金币堆信息
void showArr()
{
    for (int i = 1; i <= n; i++)
    { //遍历金币堆
        printf("重量=%d，价值=%d，单价=%lf\n", a[i].m, a[i].v, a[i].averageValue);
    }
}
/*
比较函数，sort()要用
*/
bool cmp(jbd a, jbd b)
{
    return a.averageValue > b.averageValue;
}
int main()
{
    //读取数据
    while (scanf("%d%d", &n, &t) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i].m, &a[i].v);
            a[i].averageValue = double(a[i].v) / a[i].m; //计算金币单价
        }
        //变量初始化
        int jb_m = 0;    //已有金币的总重量
        double jb_v = 0; //已有金币的总价值
        //题解
        sort(a + 1, a + 1 + n, cmp); //按单价排序，，从大到小
        for (int i = 1; i <= n; i++)
        { //遍历金币堆
            if (jb_m + a[i].m <= t)
            { //当前金币能全部装走
                // printf("jb_v=%lf\n", jb_v);
                jb_m += a[i].m; //重量增加
                jb_v += a[i].v; //价值增加
            }
            else
            {                                           //当前金币不能全部装走，分割
                jb_v += (t - jb_m) * a[i].averageValue; //价值增加
                jb_m += (t - jb_m);                     //重量增加
                break;
            }
        }
        //输出结果
        // showArr();
        printf("%.2lf\n", jb_v);
    }
    return 0;
}