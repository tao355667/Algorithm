/*
1-二分查找-复习
参考：http://c.biancheng.net/view/7527.html
1.4-STL里的二分查找upper_bound()函数
**查找的是[first, last) 区域内查找大于 val 的元素
**注意返回的是一个指针
//在 [first, last) 区域内查找不小于 val 的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);
//在 [first, last) 区域内查找第一个不符合 comp 规则的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);

*/
#include <iostream>  // std::cout
#include <algorithm> // std::upper_bound
#include <vector>    // std::vector
using namespace std;
//以普通函数的方式定义查找规则
bool mycomp(int i, int j) { return i > j; }
//以函数对象的形式定义查找规则
class mycomp2
{
public:
    bool operator()(const int &i, const int &j)
    {
        return i > j;
    }
};
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    //从 a 数组中找到第一个大于 3 的元素
    int *p = upper_bound(a, a + 5, 3);
    cout << "*p = " << *p << endl;
    vector<int> myvector{5, 4, 3, 2, 1};
    //根据 mycomp2 规则，从 myvector 容器中找到第一个违背 mycomp2 规则的元素
    vector<int>::iterator iter = upper_bound(myvector.begin(), myvector.end(), 3, mycomp2());
    cout << "*iter = " << *iter;
    return 0;
}