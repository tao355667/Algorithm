/*
实验7 最长公共子序列问题
abcbdab
bdcaba
*/
#include <iostream>
#include <string>
using namespace std;
const int N = 1e3;
int c[N][N];
int s[N][N];
string x; //序列x
string y; //序列y
int m, n; //序列x长度为m序列y长度为n（m行n列）

int LCSLength()
{
    for (int i = 0; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;
    for (int i = 1; i <= m; i++)     //逐行向下
        for (int j = 1; j <= n; j++) //从左至右扫描求值
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                s[i][j] = 1; //由 c[i-1][j-1]计算 c[i][j]
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                s[i][j] = 2; //由 c[i-1][j]得到 c[i][j]
            }
            else
            {
                c[i][j] = c[i][j - 1];
                s[i][j] = 3; //由 c[i][j-1]得到 c[i][j]
            }
    return c[m][n]; //返回最优解值
}
void CLCS(int i, int j) //构造最长公共子序列并输出
{
    if (i == 0 || j == 0)
        return; //终止条件
    if (s[i][j] == 1)
    {
        CLCS(i - 1, j - 1);
        //        cout<<"x["<<i-1<<"]"<<endl;
        cout << x[i - 1]; //输出
    }
    else if (s[i][j] == 2)
        CLCS(i - 1, j);
    else
        CLCS(i, j - 1);
}
int main()
{
    cout << "===========读数据============" << endl;
    cin >> x >> y;
    m = x.length();
    n = y.length();
    cout << "===========过程=============" << endl;
    cout << "x[] = " << x << " , y[] = " << y << endl;
    cout << "m = " << m << " , n = " << n << endl;
    cout << "LCSLength = " << LCSLength() << endl;
    cout << "c[][]=" << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << "s[][]=" << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===========结果=============" << endl;
    cout << "最长公共子序列为：";
    CLCS(m, n);
    return 0;
}