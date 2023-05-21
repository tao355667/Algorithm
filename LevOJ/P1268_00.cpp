/*
P1268 连续子段的最大和
00.自己做(AC)
暴力
*/
#include <iostream>
using namespace std;
int n;          //数据个数
int arr[10001]; //存储数据
int ans = -60000;
int main()
{
    scanf("%d", &n);
    //接收数据
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //题解
    for (int i = 0; i < n; i++)
    { // i是起点
        int sumi = 0;
        for (int j = i; j < n; j++)
        {
            sumi += arr[j];
            ans = max(ans, sumi);
        } //会得到从i到n的最大子段和
    }
    //输出结果
    printf("%d\n", ans);
    return 0;
}