/*
实验 03 求解 0/1 背包问题
202283730040 许辰涛 计科二学位1班
input 1：
10
6 4 8 2 7 16 4 8 3 5
9 6 13 15 25 14 9 15 8 9
34
output 1:

input 2：
10
16 5 8 2 8 16 4 8 7 4
9 6 12 15 25 14 9 15 12 9
34
output 2:
------------------------------------
解：
------------------------------------
最大总价值：85
------------------------------------
物品编号  3  4  5  7  8 10
物品重量  8  2  8  4  8  4
物品价值 12 15 25  9 15  9
------------------------------------

*/
#include <iostream>
using namespace std;
const int N = 1005;
int n;      //几个物品
int w[N];   //物品重量
int v[N];   //物品体积
int ans[N]; //最优解
//函数相关变量
int OP[N]; //解空间（0：不选 1：选）
int W;     //重量上限
int RW;    //所有物品重量和
int maxv;  //最大总价值
/*
i：当前物品下标
tw：当前背包中物品总重量
tv：当前背包中物品总价值
rw：当前剩余所有物品重量和
op：解空间
*/
void dfs(int i, int tw, int tv, int rw, int op[])
{
    //初始调用时 rw 为所有物品重量和
    int j;
    if (i > n) //找到一个叶子结点
    {
        if (tw == W && tv > maxv) //找到一个满足条件的更优解,保存
        {
            maxv = tv;
            for (j = 1; j <= n; j++) //复制最优解
                ans[j] = op[j];
        }
    }
    else //尚未找完所有物品
    {
        if (tw + w[i] <= W) //左孩子结点剪枝
        {
            op[i] = 1; //选取第 i 个物品
            dfs(i + 1, tw + w[i], tv + v[i], rw - w[i], op);
        }
        if (tw + rw - w[i] >= W)
        {
            op[i] = 0; //不选取第 i 个物品,回溯
            dfs(i + 1, tw, tv, rw - w[i], op);
        }
    }
}
void print_ans()
{
    printf("------------------------------------\n");
    printf("解：\n");
    printf("------------------------------------\n");
    printf("最大总价值：%d\n", maxv);
    printf("------------------------------------\n");
    printf("%6s", "物品编号");
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 1)
            printf("%3d", i);
    }
    printf("\n");
    printf("%6s", "物品重量");
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 1)
            printf("%3d", w[i]);
    }
    printf("\n");
    printf("%6s", "物品价值");
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 1)
            printf("%3d", v[i]);
    }
    printf("\n");
    printf("------------------------------------\n");
}
int main()
{
    //读数
    cout << "输入物品个数：";
    cin >> n;
    cout << "输入物品重量：";
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        RW += w[i];
    }
    cout << "输入物品价值：";
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cout << "输入重量上限：";
    cin >> W;
    //题解
    dfs(1, 0, 0, RW, OP);
    //输出答案
    print_ans();
    return 0;
}