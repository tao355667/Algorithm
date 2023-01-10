#include <iostream>
using namespace std;
int main()
{
    int max, x;
    while (1)
    {
        cin >> x;
        if (x == 0) //第一个数就是0时，程序结束
            break;
        max = x;
        while (x != 0)
        {
            if (x > max)
                max = x;
            cin >> x;
        }
        cout << max << endl;
    }
    return 0;
}
