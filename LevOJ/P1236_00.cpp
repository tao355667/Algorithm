/*
P1236 夺取宝藏
00.自己写（Wrong Answer我也不知道为啥）
dfs暴力搜索
scanf加上while后，WA没了，但超时了（注意是多组输入）
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
const int M = 1001; //容器大小
const int N = 1001; //容器大小
int map[M][N];      //下标从1开始存
int m, n;           //网格大小
int ans;            //结果
int x = 1, y = 1;   //起始位置
/*
u：当前是第几步（起始点为第1步）
money：当前身上积累的钱
*/
void dfs(int u, int money)
{
    // printf("递归%d  x=%d,y=%d,钱%d\n", u, x, y, money);
    if (x == m && y == n)
    {
        // printf("钱%d  x=%d,y=%d\n", money, x, y);
        ans = max(ans, money);
        return;
    }
    else if (y == n) //向下到尽头，只能向右
    {
        //向右走
        x++;
        dfs(u + 1, money + map[x][y]);
        x--;
    }
    else if (x == m) //向右到尽头，只能向下
    {
        //向下走
        y++;
        dfs(u + 1, money + map[x][y]);
        y--;
    }
    else
    {
        //两个分支：下和右
        //向下走
        y++;
        dfs(u + 1, money + map[x][y]);
        y--;
        //向右走
        x++;
        dfs(u + 1, money + map[x][y]);
        x--;
    }
}
int main()
{
    //读入数据
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }
        //题解
        dfs(1, map[1][1]);
        //输出结果
        printf("%d\n", ans);
    }

    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ", map[i][j]);
    //     }
    //     puts("");
    // }

    return 0;
}