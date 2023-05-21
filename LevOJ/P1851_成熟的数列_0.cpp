/*
P1851 成熟的数列
====关键词===================================================
1.暴力，查找一个数是否在数列中
2.下标根据数列的构造规则跳跃
3.看到查询次数很多，考虑哈希表
4.经过试验，发现这是个斐波那契数列，返回的下标为2的n次方
（如找15，是下标为2，则返回2^(2-1)
找29，下标为4，返回2^(3-1)）
h[15]=2（哈希表，数列中表示下标为2的数据为15）
h[29]=4
h[44]=8
h[73]=16
h[117]=32
h[190]=64
h[307]=128
h[497]=256
h[804]=512
====关键词===================================================
====题目===================================================

====题目===================================================
*/
#include <iostream>
#include <map>
#define N 1000005
#define M 100000005
using namespace std;
int a[N], h[M];
int Z;    //数列的项数
int n, p; //咨询次数,要查找的数字
/*
若数字在数组中，返回下标
否则返回-1
*/
void hash_search(int e)
{
    if (a[0] == e)
    {
        cout << 0 << endl;
        return;
    }
    if (h[e])
    {
        cout << h[e] << endl;
        return;
    }
    cout << -1 << endl;
}
int main()
{
    cin >> a[0] >> a[1] >> Z;
    //构造数列
    for (int i = 2; i < Z; i++)
    {
        a[i] = a[i / 2] + a[i / 4];
        printf("a[%d]=%d\n", i, a[i]);
    }
    h[a[0]] = 0;
    h[a[1]] = 1;
    int pre = 1;
    for (int i = 2; i < Z; i++)
    { //构造哈希表
        if (pre == a[i])
            continue;
        printf("h[%d]=%d\n", a[i], i);
        h[a[i]] = i;
        pre = a[i];
    }
    //查找
    cin >> n;
    while (n--)
    {
        cin >> p;
        hash_search(p);
    }
    return 0;
}