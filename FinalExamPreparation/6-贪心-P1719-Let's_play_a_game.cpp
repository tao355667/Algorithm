#include <iostream>
using namespace std;
const int N = 300010;

int n, k;
int a[N];
//
int base = 1;
int sum, ex;
void init()
{
    sum = ex = 0;
    base = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}
int main()
{
    while (cin >> n >> k)
    {
        init();
        //
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        // 题解
        for (int i = 1; i <= n; i++)
        {
            if (i > base)
            {
                base *= 2;
            }
            if (a[i] == k)
            {
                if (base > i)
                {
                    base /= 2;
                }                             // 此时base<=i // i - base - sum：删除该元素所需的额外操作次数
                ex = max(ex, i - base - sum); // ex为最大额外操作次数
                sum++;                        // 删除了该元素
            }
        }
        // 输出答案
        cout << sum + ex << endl;
    }
    return 0;
}