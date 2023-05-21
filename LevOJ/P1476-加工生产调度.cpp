/*
LevOJ P1476 加工生产调度
洛谷 P1248 加工生产调度
====关键词===================================================
贪心
此题要求必须先送到A再送到B，所以要使A和B两车间的空闲时间最少：
（1）就要把在A车间加工时间最短的部件最先加工，这样使得B车间能更快开始加工。
（2）就要把在B车间加工时间最短的部件最后加工，这样使得A车间的空闲时间最短。
====关键词===================================================
====题目===================================================
# 加工生产调度
## 题目描述

某工厂收到了 $n$ 个产品的订单，这 $n$ 个产品分别在 A、B 两个车间加工，并且必须先在 A 车间加工后才可以到 B 车间加工。

某个产品 $i$ 在 A、B 两车间加工的时间分别为 $A_i,B_i$。怎样安排这 $n$ 个产品的加工顺序，才能使总的加工时间最短。

这里所说的加工时间是指：从开始加工第一个产品到最后所有的产品都已在 A、B 两车间加工完毕的时间。

## 输入格式

第一行仅—个整数 $n$，表示产品的数量。

接下来一行 $n$ 个整数是表示这 $n$ 个产品在 A 车间加工各自所要的时间。

最后的 $n$ 个整数是表示这 $n$ 个产品在 B 车间加工各自所要的时间。

## 输出格式

第一行一个整数，表示最少的加工时间。

第二行是一种最小加工时间的加工顺序。

## 样例 #1

### 样例输入 #1

```
5
3 5 8 7 10
6 2 1 4 9
```

### 样例输出 #1

```
34
1 5 4 2 3
```

## 提示

$1\leq n\leq 1000$。
====题目===================================================
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
        int at = 0, bt = 0;//a机器要工作的时间，b机器要工作的时间
        int t = ps1[1].a;//第一个零件是直接进入a机器
        ps1[n + 1].a = 0;
        while (i <= n)
        {//时间线前进at
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
        printf("%d\n", t);
        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d ", ps1[i].num);
        // }
        // puts("");
    }
    return 0;
}