/*
P1797 求解田忌赛马问题
====关键词===================================================
1.贪心
    1.1 先排序，优先胜利
    1.2 无法胜利，就用下等马消耗对面的上等马（注意平局）
====关键词===================================================
====题目===================================================
问题描述
两千多年前的战国时期，齐威王与大将田忌赛马。双方约定每人各出 300 匹马，并且在上、中、下 3 个等级中各选一匹进行比赛，由于齐威王每个等级的马都比田忌的马略强，比赛的结果可想而知。现在双方各 n 匹马，依次派出一匹马进行比赛，每一轮获胜的一方将从输的一方得到 200 银币，平局则不用出钱，田忌已知所有马的速度值并可以安排出场顺序，问他如何安排比赛获得的银币最多？
Tip: 本题为单组输入
输入描述
第 1 行，一个正整数 n(n≤100000)，表示马的数量； 后两行分别是 n 个整数，表示田忌和齐威王的马的速度值。
输出描述
每个测试用例输出一行，表示田忌获得的最多银币数。
样例输入
3
92 83 71
95 87 74
样例输出
200
====题目===================================================
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int tm[N], qm[N]; //田的马，齐的马
int n;            //马的数量
int ans;          //结果

void my_solve()
{
    //从小到大排序
    sort(tm + 1, tm + 1 + n);
    sort(qm + 1, qm + 1 + n);
    //左右下标指针
    int ltm = 1, lqm = 1;
    int rtm = n, rqm = n;
    for (int i = 1; i <= n; i++)
    {
        if (tm[rtm] > qm[rqm])
        { //右端，田马比齐马快
            ans += 200;
            rtm--;
            rqm--;
            continue;
        }
        if (tm[ltm] > qm[lqm])
        { //左端，田马比齐马快
            ans += 200;
            ltm++;
            lqm++;
            continue;
        }
        //两端田马都没齐马快
        if (tm[ltm] < qm[rqm])
        { //下等马当炮灰
            ans -= 200;
            ltm++;
            rqm--;
        }
        else if (tm[ltm] == qm[rqm])
        { //也可能田下等马速度与齐上等马速度相同
            ltm++;
            rqm--;
        }
    }
}
int main()
{
    //读数据
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tm[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> qm[i];
    }
    //题解
    my_solve();
    //输出结果
    cout << ans << endl;
    return 0;
}