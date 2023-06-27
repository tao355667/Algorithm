#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
int tm[N], qm[N];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tm[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> qm[i];
    }
    // 题解
    sort(tm + 1, tm + 1 + n, cmp);
    sort(qm + 1, qm + 1 + n, cmp);
    int tl = 1, ql = 1;
    int tr = n, qr = n;
    int ans = 0;
    for (int lun = 0; lun < n; lun++)
    {
        // 田要赢
        if (tm[tl] > qm[ql])
        {
            tl++;
            ql++;
            ans += 200;
            continue;
        }
        if (tm[tr] > qm[qr])
        {
            tr--;
            qr--;
            ans += 200;
            continue;
        }
        // 田赢不了，上炮灰(下等马)，（田<=齐）
        if (tm[tr] < qm[ql])
        {
            tr--;
            ql++;
            ans -= 200;
        }
        else
        { // tm[tl]=qm[qr]
            tl++;
            qr--;
        }
    }
    cout << ans << endl;
    return 0;
}