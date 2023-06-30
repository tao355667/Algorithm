/*
删除-f[j-1][i]+1
插入-f[i][j-1]+1
替换-f[i-1][j-1]+0或1
*/
#include <iostream>
using namespace std;
const int N = 1010;

char a[N], b[N];
int n, m; // n:a_len   m:b_len

int f[N][N];

void init()
{
    for (int i = 0; i <= m; i++)
        f[0][i] = i;
    for (int i = 0; i <= n; i++)
        f[i][0] = i;
}
int main()
{
    // read
    scanf("%d%s", &n, a + 1);
    scanf("%d%s", &m, b + 1);
    // solve
    init(); // 边界
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    //
    cout << f[n][m] << endl;
    return 0;
}