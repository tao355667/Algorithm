/*
实验6-流水作业调度问题
input 1:
4
5 12 4 8
6 2 14 7
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010; //数组大小
int n;              //产品数量
struct product
{
    int a, b; // a，b加工时间
    int num;  //零件编号
    int minab;
};
product ps[N];  //产品数组
product ps1[N]; // 排好序的产品
void showProducts(product p[], int len)
{
    for (int i = 1; i <= len; i++)
    {
        printf("%d ", p[i].a);
    }
    puts("");
    for (int i = 1; i <= len; i++)
    {
        printf("%d ", p[i].b);
    }
    puts("");
}
bool cmp(product p1, product p2)
{
    return p1.minab < p2.minab;
}
int main()
{
    //读数据
    while (scanf("%d", &n) != EOF)
    {
        // scanf("%d", &n);
        memset(ps, 0, sizeof(ps));
        memset(ps1, 0, sizeof(ps1));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &ps[i].a);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &ps[i].b);
            ps[i].num = i;
            ps[i].minab = min(ps[i].a, ps[i].b);
        }
        // showProducts(ps,n);
        //题解O(nlogn)
        sort(ps + 1, ps + 1 + n, cmp); // ps1按minab升序
        // showProducts(ps, n);
        int l = 1, r = n;
        for (int i = 1; i <= n; i++)
        { //将符合条件的元素插入ps1两端
            if (ps[i].minab == ps[i].a)
            {
                ps1[l++] = ps[i];
            }
            else
                ps1[r--] = ps[i];
        }
        //模拟机器运行过程
        int i = 1;
        int at = 0, bt = 0; // a机器要工作的时间，b机器要工作的时间
        int t = ps1[1].a;   //第一个零件是直接进入a机器
        ps1[n + 1].a = 0;
        while (i <= n)
        { //时间线前进at
            bt += ps1[i].b;
            at = ps1[++i].a;
            if (at < bt)
            {
                bt -= at;
                t += at;
                at = 0;
            }
            else if (at >= bt)
            {
                t += at;
                at = 0;
                bt = 0;
            }
        }
        t += bt;
        //输出结果
        puts("=====实验6-流水作业调度问题 解=====");
        printf("时间 = %d\n", t);
        printf("执行方案：\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", ps1[i].num);
        }
        puts("");
    }
    return 0;
}