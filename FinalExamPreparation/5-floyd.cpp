#include <iostream>
using namespace std;
const int N = 10010;
const int INF = 1e9;
int n, m, k; // n:vextex   m:edge  k:ask number
int d[N][N];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }
}
void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main()
{
    // read data
    cin >> n >> m >> k;
    init();
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        // huan
        if (x == y)
            continue;
        // chong bian
        if (z < d[x][y])
            d[x][y] = z;
    }
    // solve
    floyd();
    // ask
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (d[x][y] > INF / 2)
            cout << "impossible" << endl;
        else
            cout << d[x][y] << endl;
    }
    return 0;
}