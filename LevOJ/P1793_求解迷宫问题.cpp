/*
P1793 求解迷宫问题
====关键词===================================================
1.dfs暴力搜索
====关键词===================================================
====题目===================================================
问题描述
有一 8×8 的迷宫图，其中 O 表示通路方块，X 表示障碍方块。假设入口位置为 (0,0)，出口为右下角方块位置 (7,7)。设计一个程序求指定入口到出口的一条迷宫路径。
输入描述
8 行，每行 8 个字符表示迷宫。
输入保证至少存在一条合法路径。
输出描述
8 行，每行 8 个字符，空格表示所选路径。
样例输入
OXXXXXXX
OOOOOXXX
XOXXOOOX
XOXXOXXO
XOXXXXXX
XOXXOOOX
XOOOOXOO
XXXXXXXO
样例输出
 XXXXXXX
  OOOXXX
X XXOOOX
X XXOXXO
X XXXXXX
X XX   X
X    X
XXXXXXX
====题目===================================================
*/
#include <iostream>
using namespace std;
const int N = 8;
char a[N][N];
//四个移动方向
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
bool endFlag; //问题解决的标志
void showMap()
{ //显示地图
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}
/*
r:当前行
c：当前列
*/
void dfs(int r, int c)
{
    a[r][c] = ' '; //标记该点
    if (endFlag)   //问题得解，不需要再计算了
        return;
    if (r == N - 1 && c == N - 1)
    {
        showMap(); //输出结果
        endFlag = true;
        // a[r][c] = 'O';
        return;
    }
    for (int i = 0; i < 4; i++) //四个方向
    {
        if (r + dr[i] < 0 && r + dr[i] > N - 1 || c + dc[i] < 0 && c + dc[i] > N - 1) //坐标在限度内
            continue;
        if (a[r + dr[i]][c + dc[i]] == 'O')
            dfs(r + dr[i], c + dc[i]); //有路可走
    }
    a[r][c] = 'O'; //恢复现场
}
int main()
{
    //读数据
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }
    //题解&输出结果
    dfs(0, 0);
    return 0;
}