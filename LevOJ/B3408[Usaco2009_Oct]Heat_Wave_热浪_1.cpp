/*
B3408 [Usaco2009 Oct]Heat Wave 热浪
洛谷P1339 [USACO09OCT]Heat Wave G
====关键词===================================================
图论，最短路
1.这个洛谷上过了，但是levOJ显示Memory Limit Exceeded
2.尝试去掉无关变量，使用更小的变量类型（用short存储边权，而非int）
====关键词===================================================
====题目===================================================
题目描述
有一个n 个点m 条边的无向图，请求出从s 到t 的最短路长度。
输入格式
第一行四个正整数n,m,s,t。 接下来m 行，每行三个正整数u,v,w，表示一条连接u,v 长为w 的边。
1≤n≤2500，1≤m≤6200，1≤w≤1000。
输出格式
输出一行一个整数，表示答案。
样例输入
Copy to Clipboard
7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1
样例输出
Copy to Clipboard
7
提示
没有写明提示
题目来源
Gold
====题目===================================================
*/
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2600; //农场数量上限
short a[N][N];      //地图矩阵
int n;              //农场数量
int m;              //边数量
int ans;            //答案
// dijkstra算法需要的变量
int s; //起点下标
int t; //终点下标
bool visited[N];
short dist[N]; //最小生成树中该节点到pre结点距离
/*
dijkstra算法
*/
void dijkstra()
{
    //初始化变量
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        dist[i] = INF;
    }
    //第一个结点直接写
    dist[s] = 0;
    visited[s] = true;
    for (int i = 1; i <= n; ++i) //更新s的临近结点
        dist[i] = a[i][s];

    //之后执行n-1次操作
    for (int kk = 1; kk <= n - 1; kk++)
    {
        //找到closedge[]中dist最小的结点，更新visited
        int min_dist = INF;
        int min_index = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_index = j;
            }
        }
        visited[min_index] = true;
        //更新答案
        if (min_index == t)
        {
            ans = dist[min_index];
            return;
        }
        //找相邻结点,更新closedge[]
        for (int j = 1; j <= n; j++)
            if (!visited[j] && dist[min_index] + a[min_index][j] < dist[j])
            {
                dist[j] = dist[min_index] + a[min_index][j];
            }
    }
}
int main()
{
    //读数据
    scanf("%d%d%d%d", &n, &m, &s, &t);
    //图初始化
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i != j)
                a[i][j] = INF;
            else
                a[i][j] = 0;
        }
    while (m--)
    {
        int s, e, dis; //起点，终点，距离
        scanf("%d%d%d", &s, &e, &dis);
        if (s == e) //去掉环(本题好像没有环)
            continue;
        if (a[s][e] != 0 && dis > a[s][e]) //去掉重复边
            continue;
        a[s][e] = a[e][s] = dis;
    }
    //题解
    dijkstra();
    //输出结果
    printf("%d", ans);
    return 0;
}
