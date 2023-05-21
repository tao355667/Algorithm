/*
实验2：矩阵乘法
【实验目的】掌握分治策略的基本思想以及用分治法解决问题的技巧，运用分治法解决矩阵乘法的复杂度过高的问题。
【问题描述】设 A 和 B 是两个 n*n 阶矩阵，求它们的乘积矩阵 C。（假设 n=2k）
最常见算法：O(n^3)
Strassen算法：O(n^2.8)
矩阵是n行方阵，n应该满足：n是偶数，n=2^k(k为正整数)
矩阵下标从1开始
参考：
【Strassen算法】https://www.cnblogs.com/hdk1993/p/4552534.html
【矩阵类】https://blog.csdn.net/m0_37772174/article/details/83018940
【运算符重载】https://blog.csdn.net/lu_embedded/article/details/121599696
用动态数组写了一半，感觉好麻烦，还是面向对象吧
input1：
2 2
1 1
1 1
1 1
1 1
正确答案：
2 2
2 2
input2:
4 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
正确答案：
4 4 4 4
4 4 4 4
4 4 4 4
4 4 4 4
input3：
8 8
1	2	3	4	5	6	7	8
23	5	7	8	5	1	5	8
6	6	4	6	7	8	2	4
5	4	8	7	7	6	8	6
6	5	5	5	5	64	54	5
4	4	4	4	4	5	1	3
4	4	1	4	4	5	1	2
7	4	1	4	4	4	4	8
1	2	3	5	4	7	8	5
7	6	5	5	4	6	4	3
3	7	5	7	5	5	8	2
9	4	4	6	4	7	6	2
3	3	7	1	5	4	1	2
2	1	4	5	6	7	8	9
7	2	9	9	7	9	9	6
8	9	8	5	6	8	4	5

正确结果：
200	158	230	198	201	251	 212	171
267	255	309	332	293	418	 398	249
197	169	223	209	213	274	 245	186
257	215	296	282	267	338	 313	213
662	329	905	956	906	1126 1161	1000
133	122	149	145	143	184	 169	122
116	92	126	119	122	161	 141	111
186	157	206	186	185	250	 208	165
input4：
8 8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

正确结果：
    8    8    8    8    8    8    8    8
    8    8    8    8    8    8    8    8
    8    8    8    8    8    8    8    8
    8    8    8    8    8    8    8    8
    8    8    8    8    8    8    8    8
    8    8    8    8    8    8    8    8
    8    8    8    8    8    8    8    8
    8    8    8    8    8    8    8    8
 */
#include <iostream>
#include <iomanip>

using namespace std;
//矩阵模板类
template <typename T>
class Matrix
{
    int row, col;
    T *m;

public:
    Matrix();                         //构造
    Matrix(int row, int col);         //构造
    Matrix(const Matrix<T> &old_obj); //复制构造
    ~Matrix();                        //析构

    int getRow() const { return row; }        //返回矩阵行数
    int getCol() const { return col; }        //返回矩阵列数
    T *operator[](int k) const;               //重载[]
    Matrix operator+(const Matrix<T> &M1);    //重载+
    Matrix operator-(const Matrix<T> &M1);    //重载-
    void operator=(const Matrix<T> &old_obj); //重载=

    template <typename U>
    friend ostream &operator<<(ostream &out, const Matrix<U> &M); //重载<<
};
//构造，复制构造，析构
template <typename T>
Matrix<T>::Matrix()
{
    row = col = 0;
    m = nullptr;
}
template <typename T>
Matrix<T>::Matrix(int row, int col)
{
    this->row = row;
    this->col = col;
    m = new T[row * col];
    for (int i = 0; i < row * col; i++)
    {
        m[i] = 0;
    }
}
template <typename T>
Matrix<T>::Matrix(const Matrix<T> &old_obj)
{
    row = old_obj.row;
    col = old_obj.col;
    m = new T[row * col];
    for (int i = 0; i < row * col; i++)
    {
        m[i] = old_obj.m[i];
    }
}
template <typename T>
Matrix<T>::~Matrix()
{
    if (m)
        delete[] m;
}
//重载[]
template <typename T>
T *Matrix<T>::operator[](int k) const
{
    return &m[k * col];
}
//重载+
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &M1)
{
    if (row == M1.row && col == M1.col)
    {
        Matrix M2(row, col);
        for (int i = 0; i < row * col; i++)
        {
            M2.m[i] = m[i] + M1.m[i];
        }
        return M2;
    }
    else
    {
        return *this;
    }
}
//重载-
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &M1)
{
    if (row == M1.row && col == M1.col)
    {
        Matrix M2(row, col);
        for (int i = 0; i < row * col; i++)
        {
            M2.m[i] = m[i] - M1.m[i];
            // printf("M2.m[%d] = m[%d] - M1.m[%d] = %d\n", i, i, i, M2.m[i]);
        }
        return M2;
    }
    else
    {
        return *this;
    }
}
//重载=
template <typename T>
void Matrix<T>::operator=(const Matrix<T> &old_obj)
{
    row = old_obj.row;
    col = old_obj.col;
    if (m)
        delete[] m;
    m = new T[row * col];
    for (int i = 0; i < row * col; i++)
    {
        m[i] = old_obj.m[i];
    }
}
//重载<<
template <typename T>
ostream &operator<<(ostream &out, const Matrix<T> &M)
{
    for (int i = 0; i < M.row; i++)
    {
        for (int j = 0; j < M.col; j++)
        {
            out << setw(5) << M[i][j];
        }
        out << endl;
    }
    return out;
}
template <typename T>
void print_matrix(const Matrix<T> &M)
{
    for (int i = 0; i < M.getRow(); i++)
    {
        for (int j = 0; j < M.getCol(); j++)
        {
            cout << setw(5) << M[i][j];
        }
        cout << endl;
    }
}
// 2*2矩阵乘法
template <typename T>
void MatrixMultiply(Matrix<T> A, Matrix<T> B, Matrix<T> &C)
{
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}
//大矩阵乘法
template <typename T>
void Strassen(int n, Matrix<T> A, Matrix<T> B, Matrix<T> &C)
{
    if (n == 2)
        MatrixMultiply(A, B, C);
    else
    {
        // 声明
        Matrix<T> A11(n / 2, n / 2), A12(n / 2, n / 2), A21(n / 2, n / 2), A22(n / 2, n / 2);
        Matrix<T> B11(n / 2, n / 2), B12(n / 2, n / 2), B21(n / 2, n / 2), B22(n / 2, n / 2);
        Matrix<T> D1(n / 2, n / 2), D2(n / 2, n / 2), D3(n / 2, n / 2), D4(n / 2, n / 2), D5(n / 2, n / 2), D6(n / 2, n / 2), D7(n / 2, n / 2);
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n / 2][j];
                B22[i][j] = B[i + n / 2][j + n / 2];
            }
        }
        // cout << "A11=" << endl;
        // print_matrix(A11);
        // cout << "A12=" << endl;
        // print_matrix(A12);
        // cout << "A21=" << endl;
        // print_matrix(A21);
        // cout << "A22=" << endl;
        // print_matrix(A22);
        // cout << "B11=" << endl;
        // print_matrix(B11);
        // cout << "B12=" << endl;
        // print_matrix(B12);
        // cout << "B21=" << endl;
        // print_matrix(B21);
        // cout << "B22=" << endl;
        // print_matrix(B22);
        //分治，计算d1~d7
        Strassen(n / 2, A11 + A22, B11 + B22, D1);
        Strassen(n / 2, A21 + A22, B11, D2);
        Strassen(n / 2, A11, B12 - B22, D3);
        Strassen(n / 2, A22, B21 - B11, D4);
        Strassen(n / 2, A11 + A12, B22, D5);
        Strassen(n / 2, A21 - A11, B11 + B12, D6);
        Strassen(n / 2, A12 - A22, B21 + B22, D7);
        //结果
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                C[i][j] = D1[i][j] + D4[i][j] - D5[i][j] + D7[i][j];
                C[i][j + n / 2] = D3[i][j] + D5[i][j];
                C[i + n / 2][j] = D2[i][j] + D4[i][j];
                C[i + n / 2][j + n / 2] = D1[i][j] + D3[i][j] - D2[i][j] + D6[i][j];
            }
        }
    }
}
void test_matrix_1()
{
    //不加延时的话，输出会有些乱,应该是重载<<有问题(缓冲)，先不管了，用函数print_matrix（）凑活一下
    // int r = 5, c = 5;
    // Matrix<int> m1(r, c), m2(r, c);
    // m1[0][0] = 8;
    // m1[1][2] = 3;
    // m1[2][2] = 6;
    // m2[1][2] = m1[1][2] + m1[2][2];
    // cout << "m1=" << endl;
    // cout << m1 << endl;
    // _sleep(1);
    // cout << "m2=" << endl;
    // cout << m2 << endl;
    // _sleep(1);
    // Matrix<int> m3 = m1;
    // cout << "m3=m1=" << endl;
    // cout << m3 << endl;
    // _sleep(1);
    // m3 = m1 + m2;
    // cout << "m3=m1+m2=" << endl;
    // cout << m3 << endl;
    // _sleep(1);
    // m3 = m1 - m2;
    // cout << "m3=m1-m2=" << endl;
    // cout << m3 << endl;
    // _sleep(1);
    // cout << "m1+m2=" << endl;
    // cout << m1 + m2 << endl;
    // _sleep(1);
    // cout << "m1-m2=" << endl;
    // cout << m1 - m2 << endl;
    // _sleep(1);
    // cout << "结束" << endl;
}
void test_matrix_2()
{
    //不加延时的话，输出会有些乱,应该是重载<<有问题，先不管了，用函数print_matrix（）凑活一下
    int r = 5, c = 5;
    Matrix<int> m1(r, c), m2(r, c);
    m1[0][0] = 8;
    m1[1][2] = 3;
    m1[2][2] = 6;
    m2[1][2] = m1[1][2] + m1[2][2];
    cout << "m1=" << endl;
    print_matrix(m1);
    cout << endl;
    cout << "m2=" << endl;
    print_matrix(m2);
    cout << endl;
    Matrix<int> m3 = m1;
    cout << "m3=m1=" << endl;
    print_matrix(m3);
    cout << endl;
    m3 = m1 + m2;
    cout << "m3=m1+m2=" << endl;
    print_matrix(m3);
    cout << endl;
    m3 = m1 - m2;
    cout << "m3=m1-m2=" << endl;
    print_matrix(m3);
    cout << endl;
    cout << "m1+m2=" << endl;
    print_matrix(m1 + m2);
    cout << endl;
    cout << "m1-m2=" << endl;
    print_matrix(m1 - m2);
    cout << endl;
    cout << "结束" << endl;
}

int main()
{
    // test_matrix_2();//测试矩阵类
    //读数据
    int row, col;
    cout << "请输入矩阵的行数和列数：";
    cin >> row >> col;
    Matrix<int> A(row, col), B(row, col), C(row, col);
    cout << "请输入矩阵A：" << endl;
    for (int i = 0; i < A.getRow(); i++)
        for (int j = 0; j < A.getCol(); j++)
            cin >> A[i][j];
    cout << "请输入矩阵B：" << endl;
    for (int i = 0; i < B.getRow(); i++)
        for (int j = 0; j < B.getCol(); j++)
            cin >> B[i][j];
    cout << "A = " << endl
         << A << endl
         << "B = " << endl
         << B;
    //算法
    Strassen<int>(row, A, B, C);
    cout << "C = " << endl
         << C << endl;
    return 0;
}