/*
P1204 电池的寿命
贪心
*/
#include <cstdio>
int n;
int sum;
int main()
{
    while((cin>>n)>>m)
    {

    }
    while (scanf("%d", &n) != EOF)
    {
        // printf("n=%d", n);
        if (n == 0 || n == 1)
        { // 0个或1个电池，直升机使用时间为0
            printf("%.1f\n", 0.0);
        }
        else if (n == 2)
        { // 2个电池,取最小的
            int a1 = 0, a2 = 0;
            scanf("%d%d", &a1, &a2);
            if (a1 <= a2)
            {
                printf("%.1f\n", (double)a1);
            }
            else
            {
                printf("%.1f\n", (double)a2);
            }
        }
        else if (n >= 3)
        { // 3个及以上电池，求和除以2（只限本题）
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                int buf = 0;
                scanf("%d", &buf);
                sum += buf;
            }
            printf("%.1f\n", sum / 2.0);
        }
    }
    return 0;
}
