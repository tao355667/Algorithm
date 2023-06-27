#include <iostream>
using namespace std;
const int N = 10010;
int a[N];
int dp[N];
int n;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
    }
}
void print_debug()
{
    for (int i = 1; i <= n; i++)
    {
        cout <<a[i]<<" ";
    }
    puts("");
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    puts("");
}
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        //
        init();
        int maxn = a[1];
        dp[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1] + a[i], a[i]);
            maxn = max(maxn, dp[i]);
        }
        // print_debug();
        cout << maxn << endl;
    }
    return 0;
}