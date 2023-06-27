/*
P1475 智力大冲浪
====关键词===================================================
贪心
====关键词===================================================
====题目===================================================
题目描述
小伟报名参加中央电视台的智力大冲浪节目。本次挑战赛吸引了众多参赛者，主持人为了表彰大家的勇气，先奖励每个参赛者 m 元。先不要太高兴！因为这些钱还不一定都是你的？！接下来主持人宣布了比赛规则：首先，比赛时间分为 n 个时段 (n≤500)，它又给出了很多小游戏，每个小游戏都必须在规定期限 ti 前完成 (1≤ti≤n)。如果一个游戏没能在规定期限前完成，则要从奖励费 m 元中扣去一部分钱 wi，wi 为自然数，不同的游戏扣去的钱是不一样的。当然，每个游戏本身都很简单，保证每个参赛者都能在一个时段内完成，而且都必须从整时段开始。主持人只是想考考每个参赛者如何安排组织自己做游戏的顺序。作为参赛者，小伟很想赢得冠军，当然更想赢取最多的钱！注意：比赛绝对不会让参赛者赔钱！
输入描述
多组输入，每组共 4 行，
第 1 行为 m，表示一开始奖励给每位参赛者的钱；
第 2 行为 n，表示有 n 个小游戏；
第 3 行有 n 个数，分别表示游戏 1 到 n 的规定完成期限；
第 4 行有 n 个数，分别表示游戏 1 到 n 不能在规定期限前完成的扣款数。
输出描述
对于每组输入，仅 1 行，表示小伟能赢取最多的钱
样例输入
Copy to Clipboard
10000
7
4 2 4 3 1 4 6
70 60 50 40 30 20 10
样例输出
Copy to Clipboard
9950
====题目===================================================
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 501;
int n; //游戏数目
int m; //初始钱
struct game
{
    int time; //活动截止时间
    int subm; //活动消耗多少钱
};
game g[N];
bool timeline[N]; //表示时间线
bool used[N];     //表示是否被使用
bool cmp(game a, game b)
{ //从大到小排序
    return a.subm > b.subm;
}
int main()
{
    //接收数据
    while (scanf("%d%d", &m, &n) != EOF)
    {
        // printf("m=%d,n=%d", m, n);
        //初始化
        memset(timeline, false, sizeof(timeline));
        memset(used, false, sizeof(used));
        memset(g, 0, sizeof(g));
        //接收数据
        for (int i = 1; i <= n; i++)
        { // n个游戏
            scanf("%d", &g[i].time);
            // printf("g[i].time=%d\n", g[i].time);
        }
        for (int i = 1; i <= n; i++)
        { // n个游戏
            scanf("%d", &g[i].subm);
            // printf("g[i].subm=%d\n", g[i].subm);
        }
        //题解
        sort(g + 1, g + 1 + n, cmp); //排序，从大到小，消耗钱的能力
        for (int i = 1; i <= n; i++)
        { //遍历活动
            // 1.想办法将损害大的活动插入timeline[]，从而获得大收益
            // 2.插入到最后期限，以获得最大收益
            // 3.timeline[1]代表0~1天，timeline[2]代表1~2天，timeline[3]代表2~3天，
            // 4.设任务截止时间是3，即要在第三天之前完成，可在timeline[1]~timeline[3]中进行选择
            for (int j = g[i].time; j >= 1; j--)
            {                             // j表示可选时间下标的最大值
                if (timeline[j] == false) //时间序列中有空位
                {
                    timeline[j] = true; //将活动插入时间线
                    used[i] = true;     //第i号活动被使用
                    break;
                }
            }
        } //此时将所有活动都插入列表了
        for (int i = 1; i <= n; i++)
        { //找到没有执行的活动，扣钱
            // printf("timeline[%d]=%d ", i, timeline[i]);
            if (used[i] == false)
            {
                // printf("g[i].subm=%d ", g[i].subm);
                m -= g[i].subm;
            }
        }
        //输出结果
        printf("%d\n", m);
    }
    return 0;
}