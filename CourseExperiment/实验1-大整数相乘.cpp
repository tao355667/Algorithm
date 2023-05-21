/*
  实验1：求解大整数乘法问题
  书P108（算法设计与分析，李春葆）
  输入的X和Y的位数应相同，都为n。n应该满足：n是偶数，n大于0
 */
#include<iostream>
#include<cmath>

using namespace std;
typedef long long ll;
int funflag;//记录递归层数
ll getWei(ll e)
{
    //获取一个整数的位数
    if (e == 0)return 1;
    ll a = 0;
    while (e > 0)
    {
        e = e / 10;
        a++;
    }
    return a;
}
ll numHigh(ll e)
{
    //整数从中间分开，高位
    ll wei = getWei(e);
    ll mid = wei / 2; //低位的最高位
    ll ret = 0;
    ret = e / (ll)pow(10, mid);
    return ret;

    return 0;
}
ll numLow(ll e)
{
    //整数从中间分开，低位
    ll wei = getWei(e);
    ll mid = wei / 2; //低位的最高位
    ll ret = 0;
    ret = e % (ll)pow(10, mid);
    return ret;
}
//大整数乘法函数
ll multipleXY(ll X, ll Y)
{
    cout << "=================函数开始==================" << ++funflag << endl;
    if (getWei(X) > 2 || getWei(Y) > 2)
    {
        ll n = (getWei(X) + getWei(Y)) / 2;
        ll A = numHigh(X);
        ll B = numLow(X);
        ll C = numHigh(Y);
        ll D = numLow(Y);
        cout << "A=" << A << ",B=" << B << ",C=" << C << ",D=" << D << endl;
        ll AsubB = A - B;
        ll DsubC = D - C;
        cout << "AsubB=" << AsubB << ",DsubC=" << DsubC << endl;
        ll AC = multipleXY(A, C);
        ll BD = multipleXY(B, D);
        ll AsBmDsC = multipleXY(abs(AsubB), abs(DsubC));
        cout << "AC=" << AC << ",BD=" << BD << endl;
        cout << "=================函数结束==================" << funflag-- << endl;
        return AC * (ll)pow(10, n) + (AC + BD + AsBmDsC) * (ll)pow(10, n / 2) + BD;
    }
    else
    {
        ll n = (getWei(X) + getWei(Y)) / 2;
        ll A = numHigh(X);
        ll B = numLow(X);
        ll C = numHigh(Y);
        ll D = numLow(Y);
        cout << "A=" << A << ",B=" << B << ",C=" << C << ",D=" << D << endl;
        ll AsubB = A - B;
        ll DsubC = D - C;
        cout << "AsubB=" << AsubB << ",DsubC=" << DsubC << endl;
        ll AC = A * C;
        ll BD = B * D;
        cout << "AC=" << AC << ",BD=" << BD << endl;
        cout << "=================函数结束==================" << funflag-- << endl;
        return AC * (ll)pow(10, n) + (AsubB * DsubC + AC + BD) * (ll)pow(10, n / 2) + BD;
    }


}
void test()
{
    //测试函数是否正常
    ll testn = 0;
    cout << "testn=" << testn << endl;
    cout << "getWei(testn)=" << getWei(testn) << endl;
    cout << "numLow(testn)=" << numLow(testn) << endl;
    cout << "numHigh(testn)=" << numHigh(testn) << endl;
}
void test1()
{
    //要相乘的两个数
    ll X, Y;
    X = 3141;
    Y = 5327;
    cout << "multipleXY(" << X << "," << Y << ")=" << endl <<
         multipleXY(X, Y) << endl;
}
int main()
{
//    test();
    test1();
    return 0;
}

