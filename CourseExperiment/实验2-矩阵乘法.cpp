/*
实验2：矩阵乘法
【实验目的】掌握分治策略的基本思想以及用分治法解决问题的技巧，运用分治法解决矩阵乘法的复杂度过高的问题。
【问题描述】设 A 和 B 是两个 n*n 阶矩阵，求它们的乘积矩阵 C。（假设 n=2k）
最常见算法：O(n^3)
Strassen算法：O(n^2.8)
矩阵是n行方阵，n应该满足：n是偶数，n=2^k(k为正整数)
矩阵下标从1开始
参考：https://www.cnblogs.com/hdk1993/p/4552534.html
写了一半，感觉好麻烦，还是面向对象吧
input：

 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int N = 1005;

void MatrixMultiply(int **A, int **B, int **C)
{
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}
void Strassen(int n, int **A, int **B, int **C)
{
    if (n == 2)
        MatrixMultiply(A, B, C);
    else
    {
        // 声明
        int **A11, **A12, **A21, **A22;
        int **B11, **B12, **B21, **B22;
        int **C11, **C12, **C21, **C22;
        int **M1, **M2, **M3, **M4, **M5, **M6, **M7;
        int **AResult;
        int **BResult;
        int **A11addA22, **B11addB22, **A21addA22, **B12subB22, **B21subB11, **A11subA12, **A21subA11, **B11addB12, **A12aubA22, **B21addB22;
        // 分配内存空间
        int newRow = n / 2;
        int newCol = n / 2;
        A11 = new int *[newRow];
        A12 = new int *[newRow];
        A21 = new int *[newRow];
        A22 = new int *[newRow];
        B11 = new int *[newRow];
        B12 = new int *[newRow];
        B21 = new int *[newRow];
        B22 = new int *[newRow];
        C11 = new int *[newRow];
        C12 = new int *[newRow];
        C21 = new int *[newRow];
        C22 = new int *[newRow];
        M1 = new int *[newRow];
        M2 = new int *[newRow];
        M3 = new int *[newRow];
        M4 = new int *[newRow];
        M5 = new int *[newRow];
        M6 = new int *[newRow];
        M7 = new int *[newRow];

        AResult = new int *[newRow];
        BResult = new int *[newRow];
        for (int i = 0; i < newCol; i++)
        {
            A11[i] = new int[newCol];
            A12[i] = new int[newCol];
            A21[i] = new int[newCol];
            A22[i] = new int[newCol];
            B11[i] = new int[newCol];
            B12[i] = new int[newCol];
            B21[i] = new int[newCol];
            B22[i] = new int[newCol];
            C11[i] = new int[newCol];
            C12[i] = new int[newCol];
            C21[i] = new int[newCol];
            C22[i] = new int[newCol];
            M1[i] = new int[newCol];
            M2[i] = new int[newCol];
            M3[i] = new int[newCol];
            M4[i] = new int[newCol];
            M5[i] = new int[newCol];
            M6[i] = new int[newCol];
            M7[i] = new int[newCol];
            AResult[i] = new int[newCol];
            BResult[i] = new int[newCol];
        }
        //矩阵分块
        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < newCol; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A21[i][j] = A[i + n / 2][j + n / 2];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B21[i][j] = B[i + n / 2][j + n / 2];
            }
        }
        //计算
        // B12subB22
        //分治，计算M1~M7
        // Strassen(n / 2, A11, B12 - B22, M1);
        // Strassen(n / 2, A11 + A12, B22, M2);
        // Strassen(n / 2, A21 + A22, B11, M3);
        // Strassen(n / 2, A22, B21 - B11, M4);
        // Strassen(n / 2, A11 + A22, B11 + B22, M5);
        // Strassen(n / 2, A12 - A22, B21 + B22, M6);
        // Strassen(n / 2, A11 - A21, B11 + B12, M7);
        //结果
        
    }
}
int main()
{
    //读数据
    int n; //矩阵规模
    cout << "请输入矩阵规模（2的次幂）：";
    cin >> n;
    //申请空间
    int **A, **B, **C;
    A = new int *[n];
    for (int i = 0; i < n; i++)
        A[i] = new int[n];
    B = new int *[n];
    for (int i = 0; i < n; i++)
        B[i] = new int[n];
    C = new int *[n];
    for (int i = 0; i < n; i++)
        C[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B[i][j] = C[i][j] = 0;
    //读矩阵
    cout << "请输入矩阵A：" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    cout << "请输入矩阵B：" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    //算法
    Strassen(n, A, B, C); // Strassen算法
    cout << "A*B = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << C[i][j];
        puts("");
    }

    return 0;
}
