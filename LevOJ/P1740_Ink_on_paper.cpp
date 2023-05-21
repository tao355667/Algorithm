/*
P1740 Ink on paper
====关键词===================================================
1.注意数据溢出，选个大一些的数据类型
2.找到最大距离的两个墨水点，计算它们相遇需要多少时间(不对，若它们之间还有点，则会提前连接)
3.找到点之间的最小生成树（Prim）
4.找到最小生成树中最大的边，用这个边计算时间
====关键词===================================================
====题目===================================================
Bob accidentalong longy spilong longed some drops of ink on the paper. The initial position of the i-th drop of ink is (xi , yi),
which expands outward by 0.5 centimeter per second, showing a circle.
The curious Bob wants to know how long it wilong long take for along long the inks to become connected.
In order to facilitate the output, please output the square of the time.
输入描述
The first line of input contains one integer T (1≤T≤5), indicating the number of test cases.
For each test case, the first line contains one integer n (2≤n≤5000),
indicating the number of ink on the paper. Each of the next n lines contains 2 integers (xi , yi)(∣xi∣≤10^9,∣yi∣≤10^9),
indicating that x and y coordinates of the ink.
输出描述
For each test case, output one line containing one decimal, denoting the answer.
样例输入
2
3
0 0
1 1
0 1
5
1 1
4 5
1 4
2 6
3 10
样例输出
1
17
====题目===================================================
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 5001;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f; //定义无穷
struct ink
{
    int x;
    int y;
};
ink ip[N];  // ink on the paper
int t;      //测试用例个数
int n;      //点个数
ll G[N][N]; //无向图
// Prim算法需要的变量
struct
{
    int index;              //距离树最近的顶点索引（它“前面”的结点）
    ll dist;                //当前距离树的最短距离
} closedge[N];              //伴随参数数组
bool visited[N];            //结点是否被访问过
void showClosedgeVisited(); //显示伴随参数和visited[]
ll dist2(ink a, ink b)
{ //距离的平方
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}
ll ansfun()
{ //找到最小生成树中最长的一条边，计算时间(也可以将此过程放入prim算法过程中，以节省时间)
    ll max_dist = 0;
    for (int i = 2; i <= n; i++)
    {
        if (closedge[i].dist > max_dist)
        {
            max_dist = closedge[i].dist;
        }
    }
    return max_dist;
}
void prim()
{
    //解空间初始化
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        closedge[i].index = -1;
        closedge[i].dist = INF;
    }
    //默认从顶点1开始
    closedge[1] = {-1, 0};
    visited[1] = true;
    int now_index = 1;
    for (int kk = 1; kk <= n - 1; kk++)
    { //执行n-1次更新结点信息的操作

        //更新closedge
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && G[now_index][j])
            { //结点未被访问过，且与当前起始结点连通
                if (G[now_index][j] < closedge[j].dist)
                { // j结点距离树更近了
                    closedge[j] = {now_index, G[now_index][j]};
                }
            }
        }
        //找到dist最小的点
        ll minDis = INF;
        int minIndex = 0;
        for (int j = 1; j <= n; j++)
        {
            if (visited[j]) //结点被访问过
                continue;
            if (closedge[j].dist < minDis)
            {
                minIndex = j;
                minDis = closedge[j].dist;
            }
        }
        visited[minIndex] = true; //收录dis最小的结点
        now_index = minIndex;     //将其作为下一轮起始点
    }
}
int main()
{
    cin >> t;
    while (t--)
    {             // t个测试用例
        cin >> n; // n个ink
        for (int i = 1; i <= n; i++)
        {
            cin >> ip[i].x >> ip[i].y;
        }
        //题解
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            { //构造无向图
                ll d = dist2(ip[i], ip[j]);
                G[i][j] = d;
                G[j][i] = d;
            }
        }
        prim();
        // showClosedgeVisited();
        //输出结果
        cout << ansfun() << endl;
    }

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
        cout << closedge[i].index << " ";
    }
    cout << endl;
    cout << "dist ";
    for (int i = 1; i <= n; i++)
    {
        cout << closedge[i].dist << " ";
    }
    cout << endl;
}