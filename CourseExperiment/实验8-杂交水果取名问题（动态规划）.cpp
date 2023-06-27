/*
实验8  动态规划法-杂交水果取名问题
【问题描述】
两种水果杂交出一种新水果，现在给新水果取名，要求这个名字中包含了以前两种水果
名字的字母，并且这个名字要尽量短。也就是说以前的一种水果名字arr1是新水果名字arr
的子序列，另一种水果名字arr2也是新水果名字arr的子序列。设计一个算法求arr。
例如：输入以下3组水果名称：
apple peach
ananas banana
pear peach
输出的新水果名称如下：
appleach
bananas
pearch
【提示】
本题目的思路是先求 arr1 和 arr2 字符串的最长公共子序列，基本过程参见《教程》
第8章8.5节，再利用递归输出新水果取名。
算法中设置二维动态规划数组dp，dp[i][j]表示arr1[0..i-1]（i个字母）和arr2[0..j-1]（j个
字母）中最长公共子序列的长度。另外设置二维数组b，b[i][j]表示arr1和arr2比较的3种情
况：
b[i][j]=0表示arr1[i-1]=arr2[j-1]；
b[i][j]=1表示arr1[i-1]≠arr2[j-1]并且dp[i-1][j]>dp[i][j-1]；
b[i][j]=2表示arr1[i-1]≠arr2[j-1]并且dp[i-1][j]≤dp[i][j-1]。
input 1:
3
apple peach
ananas banana
pear peach
output 1:
几组测试数据？
3
第1组=========================
apple peach
取名结果：appleach
第2组=========================
ananas banana
取名结果：bananas
第3组=========================
pear peach
取名结果：pearch
*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100;
int m, n;
int dp[N][N];
int b[N][N];
string arr1; //序列x
string arr2; //序列x
//各数据初始化
void init()
{
    memset(dp, 0, sizeof(dp));
    memset(b, -1, sizeof(b));
    arr1.clear();
    arr2.clear();
}
/*
求最长公共子序列长度
*/
int LCSLength()
{
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= m; i++)     //逐行向下
        for (int j = 1; j <= n; j++) //从左至右扫描求值
            if (arr1[i - 1] == arr2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                b[i][j] = 0;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                b[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                b[i][j] = 2;
            }
    return dp[m][n]; //返回最优解值
}
void Output(int i, int j)
{                         //利用递归输出新水果取名
    if (i == 0 && j == 0) //输出完毕
        return;
    if (i == 0)
    { // arr1完毕，输出arr2的剩余部分
        Output(i, j - 1);
        printf("%c", arr2[j - 1]);
        return;
    }
    else if (j == 0)
    { // arr2完毕，输出arr1的剩余部分
        Output(i - 1, j);
        printf("%c", arr1[i - 1]);
        return;
    }

    if (b[i][j] == 0)
    { // arr1[i-1]=arr2[j-1]的情况
        Output(i - 1, j - 1);
        printf("%c", arr1[i - 1]); //两个一样，输出哪个无所谓
        return;
    }
    else if (b[i][j] == 1)
    {
        Output(i - 1, j);
        printf("%c", arr1[i - 1]);
        return;
    }
    else
    {
        Output(i, j - 1);
        printf("%c", arr2[j - 1]);
        return;
    }
}
int main()
{
    int zu;
    cout << "几组测试数据？" << endl;
    cin >> zu;
    for (int i = 1; i <= zu; i++)
    {
        cout << "第" << i << "组=========================" << endl;
        init();
        cin >> arr1 >> arr2;
        m = arr1.length();
        n = arr2.length();
        LCSLength();
        cout << "取名结果：";
        Output(m, n);
        cout << endl;
    }

    return 0;
}