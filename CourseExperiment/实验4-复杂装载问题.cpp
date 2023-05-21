/*
实验 04 复杂装载问题
有一批共n个集装箱要装上两艘载重量分别为c1和c2的轮船，其中集装箱i的重量为wi，且w1+w2+…+wn≤c1+c2。
装载问题要求确定是否有一个合理的装载方案可将这些集装箱装上这两艘轮船。如果有，找出一种装载方案。
例如：
n=3，c1=c2=50，w={10，40，40}时，可以将集装箱1和2装到第一艘轮船上，而将集装箱3装到第二艘轮船上。
n=3，c1=c2=50，w={20，40，40}时，则无法将这3个集装箱都装上轮船。

*/
#include <cstdio>
#include <cstring>
#define MAXN 20 //最多集装箱个数
//问题表示
int w[] = {0, 10, 40, 40}; //各集装箱重量,不用下标0的元素
int n = 3;
int c1 = 50, c2 = 50;
int maxw = 0;                             //存放第一艘轮船最优解的总重量
int x[MAXN];                              //存放第一艘轮船最优解向量
void dfs(int i, int tw, int rw, int op[]) //求第一艘轮船的最优解
{
    if (i > n) //找到一个叶子结点
    {
        if (tw > maxw)
        {
            maxw = tw;                   //找到一个满足条件的更优解
            for (int j = 1; j <= n; j++) //复制最优解
                x[j] = op[j];
        }
    }
    else //尚未找完所有集装箱
    {
        if (tw + w[i] <= c1) //左孩子结点剪枝
        {
            op[i] = 1; //选取第i个集装箱
            dfs(i + 1, tw + w[i], rw - w[i], op);
        }
        if (tw + rw - w[i] > maxw) //右孩子结点剪枝
        {
            op[i] = 0; //不选取第i个集装箱,回溯
            dfs(i + 1, tw, rw - w[i], op);
        }
    }
}
bool solve() //求解复杂装载问题
{
    int sum = 0; //累计第一艘轮船装完后剩余的集装箱重量
    for (int j = 1; j <= n; j++)
        if (x[j] == 0)
            sum += w[j];
    if (sum <= c2) //第二艘轮船可以装完
        return true;
    else //第二艘轮船不能装完
        return false;
}
void dispasolution(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if(x[i])
            printf("  将第%d个集装箱装上第一艘轮船\n",i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!x[i])
            printf("  将第%d个集装箱装上第二艘轮船\n", i);
    }
}
int main()
{
    int op[MAXN]; //存放临时解
    memset(op, 0, sizeof(op));
    int rw = 0;
    for (int i = 1; i <= n; i++)
        rw += w[i];
    dfs(1, 0, rw, op); //求第一艘轮船的最优解
    printf("求解结果\n");
    if (solve()) //输出结果
    {
        printf(" 最优方案\n");
        dispasolution(n);
    }
    else
        printf(" 没有合适的装载方案\n");
    return 0;
}
