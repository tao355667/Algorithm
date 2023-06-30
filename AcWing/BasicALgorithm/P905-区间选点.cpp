#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Range
{
    int l;
    int r;
} r[N];
int n;
bool cmp(Range x, Range y)
{
    return x.r < y.r;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i].l >> r[i].r;
    }
    // solve
    sort(r + 1, r + 1 + n, cmp);
    int ans = 0, ed = -1e10;
    for (int i = 1; i <= n; i++)
    {
        if(r[i].l>ed)
        {
            ans++;
            ed = r[i].r;
        }
    }
    cout << ans << endl;
    return 0;
}