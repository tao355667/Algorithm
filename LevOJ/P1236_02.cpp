/*
P1236 夺取宝藏
01.仿写别人的（https://www.cnblogs.com/xjy881/articles/16053955.html）
动态规划
*/
#include <iostream>
using namespace std;
int map[1001][1001];   //地图
int money[1001][1001]; //走到地图上对应的点，最多会有多少钱
int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
                money[i][j] = map[i][j] + max(money[i - 1][j], money[i][j - 1]);
            }
        }
        cout << money[m][n] << endl;
    }
    return 0;
}
