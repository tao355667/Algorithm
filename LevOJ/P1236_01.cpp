/*
P1236 夺取宝藏
01.别人的（https://www.cnblogs.com/xjy881/articles/16053955.html）
动态规划
*/
#include <iostream>
#include <algorithm>
using namespace std;
int map[1001][1001];
int price[1001][1001] = {0};
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
                price[i][j] = map[i][j] + max(price[i - 1][j], price[i][j - 1]);
            }
        cout << price[m][n] << endl;
    }
    return 0;
}
