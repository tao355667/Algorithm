/*
n皇后问题
关于思路：
深搜
关于程序：
棋盘坐标从1~n
board[]中数字表示此处是否被攻击（要修改放皇后函数和拿走皇后函数）
*/
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n = 8;         //几个皇后
const int N = 100; //数组大小（解空间）
int board[N][N];   // 0：空，可放置皇后。>=1：不可放置皇后。

char queen[N][N]; //+：空。Q：皇后。
//八个方向向量
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int ansCount; //解的个数
/*
在棋盘x，y处放置一个皇后
*/
void put_queen(int x, int y)
{
    //修改queen
    queen[x][y] = 'Q';
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
/*
拿走x，y位置的皇后
*/
void off_queen(int x, int y)
{
    //修改queen
    queen[x][y] = '+';
    //修改board在dfs()中
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
void showQueen()
{ //显示皇后摆放位置

    for (int i = 1; i <= n + 1; i++)
    {
        printf("==");
    }
    puts("");
    for (int i = 1; i <= n; i++)
    {
        printf("|");
        for (int j = 1; j <= n; j++)
        {

            printf("%c ", queen[i][j]);
        }
        puts("|");
    }
    for (int i = 1; i <= n + 1; i++)
    {
        printf("==");
    }
    puts("");
}
/*
深搜
u表示当前在找第几行
*/
void dfs(int u)
{
    if (u > n)
    {
        printf("第%d个解\n", ++ansCount);
        showQueen(); //显示皇后的摆放位置
        return;
    }

    for (int j = 1; j <= n; j++)
    { //列
        if (board[u][j] == 0)
        {
            int buf[N][N];                     //存储棋盘的状态，用于回溯
            memcpy(buf, board, sizeof(board)); //存储棋盘放皇后之前的状态
            put_queen(u, j);
            dfs(u + 1);
            off_queen(u, j);
            memcpy(board, buf, sizeof(board)); //恢复棋盘放皇后之前的状态
        }
    }
}

void test()
{ //测试函数功能是否正常
    // showBoard();
    put_queen(1, 3);
    put_queen(2, 3);
    showBoard();
    showQueen();
}

int main()
{
    //变量初始化
    memset(queen, '+', sizeof(queen));
    //测试函数
    // test();
    //题解
    dfs(1);
    printf("共有%d个解\n", ansCount);
    return 0;
}