/*
B1631 [Usaco2007 Feb]Cow Party
====关键词===================================================
思路：迪杰斯特拉(dijkstra)
1.从地图中，找从x到所有结点的距离（牛返回的路径）
2.从反向地图中，找从x到所有结点的距离（牛出发的路径）
3.将两距离数组相加，遍历（除了结点x），筛选出最大的值，返回
别人的题解
https://blog.csdn.net/weixin_43845956/article/details/111177171
====关键词===================================================
====题目===================================================
题目描述
寒假到了，n 头牛都要去参加一场在编号为 x 的牛的农场举行的派对，农场之间有 m 条有向路，每条路都有一定的长度。
每头牛参加完派对后都必须回家，无论是去参加派对还是回家，每头牛都会选择最短路径，求这 n 头牛的最短路径（一个来回）中最长的一条路径长度。
输入格式
第一行有三个整数，分别表示牛的数量 n，道路数 m 和派对农场编号 x。
接下来 m 行，每行三个整数 u, v, w 表示存在一条由 u 通向 v 的长度为 w 的道路。
对于全部的测试点，保证1≤x≤n≤10^3，1≤m≤10^5 ，1≤u,v≤n，1≤w≤10^2，保证从任何一个结点出发都能到达 x 号结点，且从 x 出发可以到达其他所有节点。
输出格式
输出一行一个整数表示答案。
样例输入
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
样例输出
10
提示
样例说明:
共有 4 只奶牛参加聚会，有 8 条路，聚会位于第 2 个农场.
第 4 只奶牛可以直接到聚会所在地 (花费 3 时间), 然后返程路线经过第 1 和第 3 个农场 (花费 7 时间), 总共 10 时间.
====题目===================================================
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 99999999
using namespace std;

const int N = 1001; //牛数量上限（下标从1开始，多分配一些空间）
int mmap1[N][N];    //地图，0表示无路径，非0表示有路径
int mmap2[N][N];    //反向地图（弧的指向相反），0表示无路径，非0表示有路径
int n, m, x;        //牛数量，道路数，农场编号
int ansdis[N];      //结果
int ans;            //最终结果
//迪杰特斯拉算法求最短路，需要的数组
int pre[N];     //结点的前面结点（可获得路径）
int dis1[N];    //求解出的距离，牛返回
int dis2[N];    //求解出的距离，牛出发
int dis[N];     //存放迪杰特斯拉算法的结果
bool okNode[N]; //结点是否确定了最小距离
void showDisVisited();
void showmmap(int mmap[][N]);
/*
求从起点s到其余点的距离
*/
bool allokNode()
{ //判断结点是否全部被使用
    for (int i = 1; i <= n; i++)
    {
        if (okNode[i] == false)
            return false;
    }
    return true;
}
void updateNode(int mmap[][N], int s)
{ //找临近结点，并更新表
    if (allokNode())
        return; //结点全部被使用，终止递归map

    //更新dis
    for (int j = 1; j <= n; j++)
    { //找s指向的结点
        if (mmap[s][j] != 0)
        { //有指向的结点j
            if (!okNode[j])
            { //结点j未确定最短路
                if (dis[s] + mmap[s][j] < dis[j])
                { //新路径比老路径距离短，升级
                    dis[j] = dis[s] + mmap[s][j];
                    pre[j] = s;
                }
            }
        }
    }
    //寻找并收录权值最小的结点
    int minDis = INF, minNode = 0; //距离最小值,结点下标
    for (int j = 1; j <= n; j++)
    {
        if (okNode[j])
            continue;
        if (dis[j] < minDis)
        { //更新最小权值的结点
            minDis = dis[j];
            minNode = j;
        }
    }
    // showDisVisited();//调试
    pre[minNode] = s;
    okNode[minNode] = true;
    // cout << "okNode[" << minNode << "] = " << okNode[minNode] << endl;//调试

    //更新收录结点的临近结点
    updateNode(mmap, minNode);
}
/*
mmap：地图矩阵
dis：输出的距离矩阵
s：起点下标
*/
void dijkstra(int mmap[][N], int s)
{ //迪杰特斯拉算法求最短路
    //初始化
    memset(pre, -1, sizeof(pre));
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    // memset(dis, INF, sizeof(dis));
    memset(okNode, false, sizeof(okNode));
    //算法
    //第一个结点，直接插入
    dis[s] = 0;  //结点到自己的距离是0
    pre[s] = -1; //第一个结点没有前驱
    okNode[s] = true;
    // cout << "okNode[" << s << "] = " << okNode[s] << endl; //调试
    //后面的结点，调用函数
    // showDisVisited();//调试
    updateNode(mmap, s);
    //返回求解出的数组
}

int main()
{
    //接收数据，数据初始化
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 1; i <= m; i++)
    {
        int s, e, dis;
        scanf("%d%d%d", &s, &e, &dis);
        mmap1[s][e] = dis; //原始地图
        mmap2[e][s] = dis; //反向地图
    }
    // showmmap(mmap1);
    // showmmap(mmap2);
    //题解
    // showDisVisited();//调试
    dijkstra(mmap1, x);
    memcpy(dis1, dis, sizeof(dis)); //返回的路
    // showDisVisited();               //调试
    dijkstra(mmap2, x);
    memcpy(dis2, dis, sizeof(dis)); //出发的路
    // showDisVisited();               //调试
    for (int i = 1; i <= n; i++)
    {
        if (i != x)
            ans = max(ans, dis1[i] + dis2[i]);
    }
    //输出结果
    printf("%d\n", ans);
    return 0;
}

void showmmap(int mmap[][N])
{ //显示地图矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mmap[i][j] != INF)
                printf("%d ", mmap[i][j]);
            else
                printf("INF ");
        }
        puts("");
    }
}
void showDisVisited()
{ //显示结点距离信息
    printf("下标\t");
    for (int i = 1; i <= n; i++)
    {
        printf("%5d ", i);
    }
    puts("");
    printf("okNode[]");
    for (int i = 1; i <= n; i++)
    {
        printf("%5d ", okNode[i]);
    }
    puts("");
    printf("dis[]\t");
    for (int i = 1; i <= n; i++)
    {
        printf("%5d ", dis[i]);
    }
    puts("");
    printf("pre[]\t");
    for (int i = 1; i <= n; i++)
    {
        printf("%5d ", pre[i]);
    }
    puts("");
}