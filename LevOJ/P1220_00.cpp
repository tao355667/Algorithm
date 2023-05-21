/*
P1220 皇后摆放问题
00.别人写的
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
#include <cstdio>
#include <cmath>
const int N = 10;        //数组的大小
int n = 8;               // n皇后问题
int arr[N][N];           //用于存储棋盘以及之后的皇后摆放位置
int ans;                 //存储最后的答案
bool judge(int x, int y) //用于判断这个地方能否放置皇后
{
    int i, j;
    for (j = 1; j <= n; j++)
    {
        if (arr[j][y])
            return false;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (abs(x - i) == abs(y - j) && arr[i][j] == 1)
                return false;
        }
    }
    return true;
}
void dfs(int v) //深搜，这个函数可以理解为前面v-1个皇后已经摆放好，现在摆放第v个皇后，这里的v也代表第v行
{
    if (v > n) //深搜结束的条件，即当要摆放的皇后超过八个的时候，就说明前面八个皇后已经摆放完成，就可以结束深搜了
    {
        ans++; //说明找到了一种摆放的方式，答案++
        return;
    }

    //棋盘上未摆放皇后的位置为0，摆放皇后的位置为1.
    //现在我们要摆放第v行上的皇后，那么我们就要遍历第v行上的所有位置，看看每个位置能不能放
    //由于本题给定的条件是初始情况下有的皇后已经摆放好了
    //所以我们要首先遍历这一行上是否已经有摆放好的皇后，如果有，flag为0，没有的话flag就为1
    int i, j, flag = 1;
    for (i = 1; i <= n; i++)
    {
        if (arr[v][i])
        {
            flag = 0;
            break;
        }
    }
    //如果第v行上没有已经摆放好的皇后，那么我们就进行下一步
    //遍历第v行上的每一个位置，判断该位置能不能摆放皇后
    //如果可以的话，那我们就让arr[v][i]=1，然后dfs（v+1），即摆放第v+1行的皇后
    if (flag)
    {
        for (i = 1; i <= n; i++)
        {
            if (judge(v, i))
            {
                arr[v][i] = 1;
                dfs(v + 1);
                arr[v][i] = 0; //注意回溯，因为本题求的是所有的摆放种数，所以当前位置摆放完以后，arr[v][i]要变为0，然后继续摆放下一个位置
            }
        }
    }
    //如果flag为0，那么代表第v行额皇后已经摆放好，我们就直接摆放下一行的皇后
    else
    {
        dfs(v + 1);
    }
}
int main()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    dfs(1); //从第一行开始摆
    printf("%d\n", ans);
    return 0;
}
