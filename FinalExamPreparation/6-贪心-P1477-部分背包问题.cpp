#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int n;
struct Gold
{
    int m;
    int v;
    double mv;
} g[N];

int t;
bool cmp(Gold x, Gold y)
{
    return x.mv > y.mv;
}
int main()
{
    while (cin >> n >> t)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> g[i].m >> g[i].v;
            g[i].mv = 1.0 * g[i].v / g[i].m;
        }
        //
        sort(g + 1, g + 1 + n, cmp);
        //
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (g[i].m < t)
            {
                ans += g[i].v;
                t -= g[i].m;
            }
            else
            {
                if (t > 0)
                {
                    ans += int(t * g[i].mv);
                    t = 0;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
