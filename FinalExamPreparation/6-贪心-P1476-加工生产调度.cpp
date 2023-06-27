/*
加工时间为：a1+max(a2+a3+a4+...+an,b1+b2+b3+...+bn-1)+bn
开头和结尾的时间一定要分离出来考虑。设ans1=a2+a3+...+an,ans2=b1+b2+b3...+bn
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;

struct Product
{
    int a;
    int b;
    int minab;
    int num; // 编号
    int d;   // a-b的符号
};
Product pd[N];

bool cmp(Product x, Product y)
{
    if (x.d == y.d)
    {
        if (x.d <= 0)
            return x.a < y.a;
        else
            return x.b > y.b;
    }
    return x.d < y.d;
}
int sign(int a, int b)
{
    if (a - b < 0)
        return -1;
    if (a - b > 0)
        return 1;
    return 0;
}
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            pd[i].num = i;
            cin >> pd[i].a;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> pd[i].b;
            pd[i].minab = min(pd[i].a, pd[i].b);
            pd[i].d = sign(pd[i].a, pd[i].b);
        }
        //
        sort(pd + 1, pd + 1 + n, cmp);
        //
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i != 1)
                ans1 += pd[i].a;
            if (i != n)
                ans2 += pd[i].b;
        }
        cout << max(ans1, ans2) + pd[1].a + pd[n].b << endl;
    }
    return 0;
}
