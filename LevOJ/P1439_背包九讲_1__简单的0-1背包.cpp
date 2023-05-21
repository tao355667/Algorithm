/*
P1439 背包九讲(1)：简单的0-1背包
====关键词===================================================
DP（动态规划），二维DP数组
====关键词===================================================
====题目===================================================
题目描述
有一个箱子容量为 V（正整数，0＜＝V＜＝20000），同时有 n 个物品（0＜n＜＝30），每个物品有一定的体积和价值。要求 n 个物品中，任取若干个装入箱内，在箱子能放得下的前提下，满足箱子内部的价值最大。
输入描述
一个整数 v，表示箱子容量
一个整数 n，表示有 n 个物品
接下来 n 个整数，分别表示这 n 个物品的各自体积和价值
输出描述
一个整数，表示箱子能装下的最大价值。
样例输入
Copy to Clipboard
3
2
2 100
4 200
样例输出
Copy to Clipboard
100
样例解释
输入：
3 // 箱子的总的容量为 3
2 // 一共有两个物品
2 100 // 第一个物品的体积为 2 价值为 100
4 200 // 第二个物品的体积为 4 价值为 200
输出:
100
在箱子能装下的前提下，应该选择第 1 个物品，最大的价值为 100
====题目===================================================
*/
#include <iostream>
using namespace std;
const int N = 31;
const int Vmin = 0;
const int Vmax = 20001;
int n;              //物品数量
int v;              //箱子容量
int volume[N];      //物品的体积
int value[N];       //物品的价值
int ans;            //结果
int dpans[N][Vmax]; //解矩阵dp_ans
int main()
{
    //读取数据
    while (scanf("%d%d", &v, &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &volume[i], &value[i]);
        }
        //题解
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                //不放第i个物品
                int bufang = dpans[i - 1][j];
                //放第i个物品
                if (j >= volume[i])
                { //容量足够
                    int fang = dpans[i - 1][j - volume[i]] + value[i];
                    //更新解数组
                    dpans[i][j] = max(bufang, fang);
                }
                else
                { //容量不够
                    //更新解数组
                    dpans[i][j] = bufang;
                }
            }
        }
        ans = dpans[n][v];
        //输出结果
        printf("%d\n", ans);
    }

    return 0;
}