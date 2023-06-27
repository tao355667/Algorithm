/*
1-二分查找-复习
参考：http://c.biancheng.net/view/7537.html
1.2-STL里的二分查找binary_search()函数
binary_search() 函数定义在<algorithm>头文件中，用于查找指定区域内是否包含某个目标元素。
//查找 [first, last) 区域内是否包含 val
bool binary_search (ForwardIterator first, ForwardIterator last, const T& val);
//根据 comp 指定的规则，查找 [first, last) 区域内是否包含 val
bool binary_search (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int a[] = {0, 4, 2, 6, 6, 6, 8, 10, 12, 14, 16, 18, 20};
int n = sizeof(a) / sizeof(a[0]);
int findnum; //要找的数

void print_arr(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << setw(3) << a[i];
    }
    cout << endl;
}
int main()
{
    // 1-排序再二分查找
    sort(a, a + n);
    print_arr(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i;
    }
    cout << endl;
    // 2-二分查找
    while (1)
    {
        int num;
        cout << "你要找几？";
        cout.flush();
        cin >> num;
        cout << "查找结果为（0：未找到，1：找到）：" << binary_search(a, a + n, num) << endl;
    }

    return 0;
}