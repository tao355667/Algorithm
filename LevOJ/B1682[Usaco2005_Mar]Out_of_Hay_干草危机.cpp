/*
B1682 [Usaco2005 Mar]Out of Hay 干草危机
洛谷P1547 [USACO05MAR]Out of Hay S
====关键词===================================================
prim算法（最小生成树）
1.WA，没有加重复边的判断
2.加了重复边的判断，还是WA，但分数高了一点
3.照着别人AC的代码重写了逻辑，过了
====关键词===================================================
====题目===================================================
题目描述
Bessie 计划调查N（2≤N≤2000）个农场的干草情况，它从1 号农场出发。农场之间总共有
M（1≤M≤10^4）条双向道路，所有道路的总长度不超过10^9。有些农场之间存在着多条道路，所有的农场之间都是连通的。
Bessie 希望计算出该图中最小生成树中的最长边的长度。
输入格式
第 1 行输入两个整数N 和M; 接下来M 行，每行输入三个整数，表示一条道路的起点终点和长度。
输出格式
一个整数，表示最小生成树中的最长边的长度。
样例输入
Copy to Clipboard
3 3
1 2 23
2 3 1000
1 3 43
样例输出
Copy to Clipboard
43
由 1 到达 2，需要经过长度 23 的道路；回到 1 再到 3，通过长度 43 的道路．最长道路为 43
提示
没有写明提示
题目来源
Silver
====题目===================================================
*/
#include <iostream>
using namespace std;
const int INF = 0x7fffffff;
const int N = 2001; //农场数量上限
int a[N][N];        //地图矩阵
int n;              //农场数量
int m;              //边数量
int ans;            //答案
// prim算法需要的变量
bool visited[N];
struct
{
    int pre;  //距离结点最近的，前面的结点
    int dist; //最小生成树中该节点到pre结点距离
} closedge[N];
void showClosedgeVisited(); //显示伴随参数和visited[]
/*
prim算法
*/
void prim()
{
    //初始化变量
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        closedge[i].pre = -1;
        closedge[i].dist = INF;
    }
    //第一个结点直接写
    closedge[1] = {-1, 0};
    visited[1] = true;
    for (int i = 1; i <= n; ++i) //更新1的临近结点
        closedge[i].dist = a[i][1];

    //之后执行n-1次操作
    for (int kk = 1; kk <= n - 1; kk++)
    {
        //找到closedge[]中dist最小的结点，更新visited
        int min_dist = INF; //对应的边长
        int min_index = -1; //结点下标
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && closedge[j].dist < min_dist) //结点没有确定&&距离更小的结点
            {
                min_dist = closedge[j].dist;
                min_index = j;
            }
        }
        visited[min_index] = true;
        //更新答案
        if (closedge[min_index].dist > ans) //更新答案
            ans = closedge[min_index].dist;
        //找相邻结点,更新closedge[]
        for (int j = 1; j <= n; j++)
            if (!visited[j] && a[min_index][j] < closedge[j].dist)
            { // j结点未确定最小距离&&j结点到已确定最小值的结点集合的距离应最小
                closedge[j] = {min_index, a[min_index][j]};
            }
    }
}
int main()
{
    //读数据
    scanf("%d%d", &n, &m);
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
    prim();

    // for (int i = 2; i <= n; i++)
    // { //找到最小生成树中最长的边
    //     if (closedge[i].dist > ans)
    //     {
    //         ans = closedge[i].dist;
    //     }
    // }
    //输出结果
    // showClosedgeVisited();
    printf("%d\n", ans);
    return 0;
}

void showClosedgeVisited()
{
    cout << "下标 ";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "visited ";
    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << " ";
    }
    cout << endl;
    cout << "index ";
    for (int i = 1; i <= n; i++)
    {
        cout << closedge[i].pre << " ";
    }
    cout << endl;
    cout << "dist ";
    for (int i = 1; i <= n; i++)
    {
        cout << closedge[i].dist << " ";
    }
    cout << endl;
}