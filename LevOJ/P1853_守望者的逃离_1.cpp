/*
P1853 守望者的逃离
====关键词===================================================
1.dp 用跑步替换闪现，因为跑步的过程是“一格一格的”，好写
====关键词===================================================
====题目===================================================
题目描述
守望者在与尤迪安的交锋中遭遇了围杀， 被困在一个荒芜的大岛上。
为了杀死守望者，尤迪安开始对这个荒岛施咒，这座岛很快就会沉下去。到那时，岛上的所有人都会遇难。
守望者的跑步速度为17m/s ，以这样的速度是无法逃离荒岛的。庆幸的是守望者拥有闪烁法术，可在1s 内移动60m ，不过每次使用闪烁法术都会消耗魔法值10 点。守望者的魔法值恢复的速度为4 点每秒，只有处在原地休息状态时才能恢复 现在已知守望者的魔法初值M ，他所在的初始位置与岛的出口之间的距离S ，岛沉没的时间T 。你的任务是写一个程序帮助守望者计算如何在最短的时间内逃离荒岛，若不能逃出，则输出守望者在剩下的时间内能走的最远距离。
注意：守望者跑步、闪烁或休息活动均以秒为单位，且每次活动的持续时间为整数秒。距离的单位为米。
输入描述
输入数据共一行三个非负整数
M,S,T。
(1≤T≤3×10^5,0≤M≤10^3,1≤S≤10^8)
输出描述
输出数据共两行。
第一行一个字符串
Yes
Yes 或
No
No , 即守望者是否能逃离荒岛。
第二行包含一个整数。第一行为
Yes
Yes 时表示守望者逃离荒岛的最短时间，第一行为
No
No 时表示守望者能走的最远距离。
样例输入
Copy to Clipboard
39 200 4
Copy to Clipboard
36 255 10
样例输出
Copy to Clipboard
No
197
Copy to Clipboard
Yes
6
====题目===================================================
*/
#include <iostream>
const int N = 1;
int m, s, t; //魔法初值，出口距离，岛沉没时间
int d[500005];
using namespace std;

int main()
{
    cin >> m >> s >> t;
    //闪现
    for (int i = 1; i <= t; i++) //当前第i秒（循环体内表示从i-1~i秒时，守望者做了什么）
    {

        if (m >= 10)
        {
            m -= 10;
            d[i] = d[i - 1] + 60;
        }
        else //不能闪现就跑步
        {
            d[i] = d[i - 1];
            m += 4; //不能闪现，魔法回复
        }
    }
    //跑步
    for (int i = 1; i <= t; i++)
    {
        if (d[i] < d[i - 1] + 17) //跑步比闪现更优，则替换掉
            d[i] = d[i - 1] + 17;
        if (d[i] >= s)
        {
            cout << "Yes" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    cout << d[t] << endl;

    return 0;
}