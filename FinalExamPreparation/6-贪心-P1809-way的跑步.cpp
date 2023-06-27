#include <iostream>
using namespace std;
const int N = 10010;
int n, m, k;
int r[N]; // 水坑1，路0
int f[N]; // f[i]：到位置i，最少需要踩几次水坑
void init()
{
    for (int i = 1; i <= n; i++)
    {
        f[i] = 0x3f3f3f3f;
    }
}
int main()
{
    while (cin >> n >> m >> k)
    {
        init();
        for (int i = 1; i <= m; i++)
        {
            int temp;
            cin >> temp;
            r[temp] = 1;
        }
        //
        f[1] = r[1];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i - j < 1)
                    continue;
                f[i] = min(f[i], f[i - j] + r[i]);
            }
        }
        cout << f[n] << endl;
    }

    return 0;
}