/*
P1296 分形宇宙
00.自己做
暴力
*/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 3000;
int n; //分形的度
char matrix[N][N];

/*
n：分形的度
x：行
y：列
*/
void setUni(int n, int x, int y)
{
    if (n == 1)
    {
        matrix[x][y] = 'X';
        return;
    }
    else
    {
        int d = pow(3, n - 2);
        // 5个需要输出'X'的单元
        setUni(n - 1, x, y);
        setUni(n - 1, x, y + 2 * d);
        setUni(n - 1, x + d, y + d);
        setUni(n - 1, x + 2 * d, y);
        setUni(n - 1, x + 2 * d, y + 2 * d);
    }
}
/*
输出宇宙
*/
void printUni(int n)
{
    for (int i = 0; i < pow(3, n - 1); i++)
    {
        for (int j = 0; j < pow(3, n - 1); j++)
        {
            printf("%c", matrix[i][j]);
        }
        puts("");
    }
}
int main()
{
    //接收数据,多组输入
    while (scanf("%d", &n) != EOF)
    {
        //题解
        memset(matrix, ' ', sizeof(matrix));
        setUni(n, 0, 0);
        printUni(n);
        puts("-");
    }
    return 0;
}