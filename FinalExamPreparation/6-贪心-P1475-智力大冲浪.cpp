#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510;
struct game
{
    int time;
    int money;
};
game g[N];
int m;
int n;

int timeline[N];
int used[N];
bool cmp(game a, game b)
{
    return a.money > b.money;
}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        timeline[i] = 0;
        used[i] = false;
    }
}
int main()
{
    while (cin >> m >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> g[i].time;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> g[i].money;
        }
        //
        init();
        //
        sort(g + 1, g + 1 + n, cmp);
        //
        for (int i = 1; i <= n; i++)
        {
            for (int j = g[i].time; j >= 1; j--)
            {
                if (timeline[j] == 0)
                {
                    timeline[j] = i;
                    used[i] = true;
                    break;
                }
            }
        }
        //
        for (int i = 1; i <= n; i++)
        {
            if (used[i] == false)
            {
                m -= g[i].money;
            }
        }
        cout << m << endl;
    }
    return 0;
}
