/*
P1796 求解马走棋问题
====关键词===================================================
dfs暴力搜索（有点像八皇后）
====关键词===================================================
====题目===================================================
问题描述
在 m 行 n 列的棋盘上有一个中国象棋中的马，马走日字且只能向右走。
请找到可行路径的条数，使得马从棋盘的左下角 (1,1) 走到右上角 (m,n)。
Tip 1: 本题为单组输入。
Tip 2: 马向右走指从 (X,Y) 走到 (X+2, Y+1) 或 (X+1, Y+2) 位置
输入描述
一行，两个正整数 n m。
输出描述
一行，表示相应的路径条数。
样例输入
4 4
样例输出
2
====题目===================================================
*/
#include <iostream>
using namespace std;
const int N = 200;
int m, n; // m行n列
int cb[N][N];//chess board
int ans; //答案

// Tip 2 : 马向右走指从(X, Y) 走到(X + 2, Y + 1) 或(X + 1, Y + 2) 位置
int dx[2] = {2, 1};
int dy[2] = {1, 2};
/*
x：当前第几行
y：当前第几列
*/
void dfs(int x, int y)
{
    if (x == m && y == n)
    { //马走到终点
        ans++;
        return;
    }
    for (int i = 0; i < 2; i++)
    { // 2个分支
        if (x + dx[i] < 1 || x + dx[i] > m && y + dy[i] < 1 || y + dy[i] > n)
            continue;
        dfs(x + dx[i], y + dy[i]); //走下一步
    }
}
int main()
{
    //读数据
    cin >> n >> m;
    //题解
    dfs(1, 1);
    //输出答案
    cout << ans << endl;
    return 0;
}