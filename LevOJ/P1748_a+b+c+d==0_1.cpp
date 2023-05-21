/*
P1748 a+b+c+d==0
====关键词===================================================
1.暴力（4层for循环，O(n^4)，会超时）
2.STL中的map（复杂度为O(n^2)）
    （https://www.cnblogs.com/ACM-YYDS/p/16342266.html）
====关键词===================================================
====题目===================================================
求和问题可以被看做是以下的公式，给定 A，B，C，D 四个列表，计算有多少四元组满足 (a, b, c, d) ∈ A × B × C × D 且 a + b + c + d = 0。我们推测所有的列表都有 n 个数字。
注：不同的四元组是指元素位置不一样的四元组
数据范围
n<=2e3
样例输入
输入的第一个数字指明有 T 组。每一组这样描述，第一行是列表大小 n， 然后有 n 行。每一行都有四个整型数字，分别属于 A，B，C，D 四列。
样例输出
对于每一个测试用例，统计有多少个四元组满足他们的和是 0 。每一组数据一行。
Sample Input
1
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45
Sample Output
5
====题目===================================================
*/
#include <iostream>
#include <map>
using namespace std;
const int N = 2010;
int T;                      //几组数据
int n;                      //数据有几行
int A[N], B[N], C[N], D[N]; //四列数据
int ans;                    //答案
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        }
        //题解
        ans = 0;           //答案
        map<int, int> res; // result[a]=b;表示值为a的元素有b个
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int sum = A[i] + B[j];
                res[sum] += 1; //值为sum的元素数量增加了
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int sum = C[i] + D[j];
                if (res[-sum] > 0) //存在相反数
                {
                    ans += res[-sum];
                }
            }
        }
        //输出答案
        cout << ans << endl;
    }

    return 0;
}