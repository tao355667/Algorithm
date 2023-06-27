#include <iostream>
using namespace std;
const int V = 20010;
const int N = 40;
struct box
{
    int area;
    int value;
};
box b[N];
int dp[V][N];
int n;
int v;
int main()
{
    while (cin >> v >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i].area >> b[i].value;
        }
        //
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= v; j++)
            { // i：第i个物品。j：容量为j
                // 简化
                if (j < b[i].area)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], b[i].value + dp[i - 1][j - b[i].area]);
                }
                // // 不放
                // int bufang = dp[i - 1][j];
                // // 想放
                // if (j < b[i].area)
                // { // 想放但空间不够
                //     dp[i][j] = bufang;
                // }
                // else
                // {//放
                //     int fang = dp[i - 1][j - b[i].area] + b[i].value;
                //     dp[i][j] = max(fang, bufang);
                // }
            }
        }
        cout << dp[n][v] << endl;
    }
    return 0;
}