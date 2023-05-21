/*
P1220 皇后摆放问题
00.自己写的
题目描述
国际象棋的棋盘可以看做是一个 8 × 8 的矩阵，上面每一个格子仅能放一枚棋子，现在给出一个 8 × 8 的由 0 和 1 组成的矩阵，代表象棋棋盘，1 代表当前位置放置了一个皇后，0 则代表什么都没有放，上面有 n（n 为小于 8 的正整数）个位置已经放上了皇后棋子（相互之间不冲突，合理摆放），现在另外给你 8 - n 个皇后，问你有多少合理的摆法。
输入描述
一个 8 × 8 的由 0 和 1 组成的矩阵。
输出描述
一个整数，为摆放的种类数。
样例输入
1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
样例输出
4
*/
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n = 8;           //几个皇后
const int N = 100;   //数组大小（解空间）
int startData[N][N]; // 存储读入的矩阵
int startQueen;      //开始时有几个皇后
int board[N][N];     // 0：空，可放置皇后。1：不可放置皇后。
char queue[N][N];    //+：空。Q：皇后。
int queen[N];        //记录开始时哪些行有皇后
// 8个方向
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int ans; //解的个数
/*
检查第row行是否已经被放置皇后
*/
bool checkQueen(int row)
{
    for (int i = 0; i < startQueen; i++)
    {
        if (queen[i] == row)
            return true;
    }
    return false;
}
/*
在棋盘x，y处放置一个皇后
*/
void put_queen(int x, int y)
{
    //修改board
    board[x][y] = 1;
    for (int i = 1; i <= n; i++)
    { // i：第几圈
        for (int j = 0; j < 8; j++)
        { // j:第几个向量
            int x_step = x + i * dx[j];
            int y_step = y + i * dy[j];
            if (x_step < 1 || x_step > n || y_step < 1 || y_step > n)
                continue;
            board[x_step][y_step] = 1;
        }
    }
}
void showBoard()
{ //显示棋盘
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", board[i][j]);
        }
        puts("");
    }
}
/*
深搜
u表示当前在找第几行
*/
void dfs(int u)
{
    if (u > n)
    {
        ++ans;
        return;
    }
    if (checkQueen(u))
    { //第u行已经有皇后了，直接执行下一行
        dfs(u + 1);
    }
    else
    {
        for (int j = 1; j <= n; j++)
        { //列
            if (board[u][j] == 0)
            {
                int buf[N][N];                     //存储棋盘的状态，用于回溯
                memcpy(buf, board, sizeof(board)); //存储棋盘放皇后之前的状态
                put_queen(u, j);
                dfs(u + 1);
                //拿走x，y位置的皇后
                memcpy(board, buf, sizeof(board)); //恢复棋盘放皇后之前的状态
            }
        }
    }
}
int main()
{
    //读取数据
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &startData[i][j]);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {//测试读取数据是否正常
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ", startData[i][j]);
    //     }
    //     puts("");
    // }
    //题解
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (startData[i][j] == 1)
            {
                put_queen(i, j);
                queen[startQueen++] = i; //记录皇后数目和皇后所在行
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // { //测试数据是否正常
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ", board[i][j]);
    //     }
    //     puts("");
    // }
    dfs(1); //从第一行开始摆
    //输出结果
    printf("%d\n", ans);
    return 0;
}