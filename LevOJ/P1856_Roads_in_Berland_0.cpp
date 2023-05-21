/*
P1856 Roads in Berland
====关键词===================================================
1.稠密图，先floyd，得到全局最短路,之后每接收到一个新道路，判断，若该道路长度小于城市最短距离，就替换，用floyd求出最短路
    1点个AC，1个点WA，1个点TLE
2.先floyd，存储每条最短路的路径，之后每接收到一个新道路，判断，若该道路长度小于城市最短距离，就替换所有用到这条路径的距离值，
====关键词===================================================
====题目===================================================
题目描述
有n 个城市，编号1 到n, 每两个城市i,j 之间距离为d(i,j)(0≤d≤1000), 对于同一对城市，它们之间的距离是一样的. 为了行动方便，市政府决定造依次建造 k 条双向道路，每条道路都连接2 个城市，长度为w(0≤w≤1000)，在每条道路建设完毕后，市政府都需要统计一次 所有 城市对 (每两个城市) 之间的最短距离之和. 请注意，城市对(a,b) 和(b,a) 是同一对，不要重复统计.
输入描述
第一行，一个正整数(2≤n≤300), 表示有n 个城市
接下来n 行，每行n 个数， 第i 行第j 列的数字，表示城市,i,j 之间的距离(0≤d≤1000)，保证
d(i,i)=0, d(i, j)= d(j,i)
下一行，一个正整数k (1 ≤  k  ≤ 300), 表示依次建造k 条道路 接下来k 行，每行三个正整数
ui,vi,wi, 表示 城市
ui,vi(1≤ui, vi≤n, ui!= vi) 之间新建了一条长度为w 的道路(0≤w≤1000) 这条道路的编号为i (第一条道路的编号为1, 以此类推)
输出描述
输出一行，k 个用空格分开的整数qi(1≤ i ≤ k)
qi等于 在1 ~i 条道路建成后，所有城市对之间的最短距离之和.
样例输入
Copy to Clipboard
2
0 5
5 0
1
1 2 3
Copy to Clipboard
3
0 4 5
4 0 9
5 9 0
2
2 3 8
1 2 1
样例输出
Copy to Clipboard
3
Copy to Clipboard
17 12
====题目===================================================
*/
#include <iostream>
#define INF 0x3f3f3f3f;
using namespace std;
const int N = 1005;
int n, k; //结点数，道路数
int d[N][N];
void print_d()
{
    puts("d[][]=");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d[i][j] << " ";
        }
        puts("");
    }
}
void print_ans()
{
    long long ans = 0; //输出的结果
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // printf("d[%d][%d] =%d\n", i, j, d[i][j]);
            ans += d[i][j];
        }
    }
    cout << ans;
}
void floyd()
{
    for (int v = 1; v <= n; v++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (v == i || v == j)
                    continue;
                d[i][j] = min(d[i][j], d[i][v] + d[v][j]);
                d[j][i] = d[i][j];
                // printf("d[%d][%d] =%d\n",i,j,d[i][j]);
            }
        }
    }
}
int main()
{
    //读数据
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }
    // print_d();
    floyd();
    // print_d();
    cin >> k;
    while (k--)
    {
        int r, c, dist;
        cin >> r >> c >> dist;
        if (dist < d[r][c]) //若新道路比旧道路更短，就用新的
        {                   //题解//输出结果
            d[c][r] = dist;
            d[r][c] = dist;
            floyd();
        }
        // print_d();
        print_ans();
        if (k != 0)
            cout << " ";
    }

    return 0;
}