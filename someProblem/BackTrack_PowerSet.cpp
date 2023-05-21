/*
  回溯法--求幂集(递归+非递归)
 */
#include <cstdio>
const int N = 100;
int n = 3;    ////集合中元素个数
int state[N]; // 递归要用，0：不选，1：选，2:未确定
int op[N];    //非递归要用，0：不选，1：选，2:未确定
/*
  输出数组中的数字
 */
void print_arr(int arr[], int n)
{
    for (int i = 1; i <= n; i++) //检查有没有2，主要是非递归要用这个，递归不用
        if (arr[i] == 2)
            return;

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            printf("%d ", i);
        }
    }
    puts("");
}
/*
  递归
  u：当前要选择的位置
 */
void dfs(int u)
{
    if (u > n)
    {
        print_arr(state, n);
    }
    else
    {
        state[u] = 0;
        dfs(u + 1);
        // state[u] = 2; //恢复现场，可省略
        state[u] = 1;
        dfs(u + 1);
        // state[u] = 2; //恢复现场，可省略
    }
}
/*
非递归
强行写的，过程上没有怎么优化
其实还是枚举，输出的时候判断下是否存在2（没有确定元素的项），若有则不输出
 */
void BackTrack()
{
    int i = 1;
    while (i >= 1)
    {
        if (i > n)
        {
            print_arr(op, n);
            i--;
        }
        if (op[i] == 2)
        {
            op[i] = 0; // 第i个位置不选
            i++;       // 向下一层前进，扩展分支
        }
        else if (op[i] == 0)
        {
            op[i] = 1; // 重设分支的状态为未定
            i++;       // 向上一层回溯，扩展分支
        }
        else if (op[i] == 1)
        {
            op[i] = 2; // 重设分支的状态为未定
            i--;       // 向上一层回溯，扩展分支
        }
    }
}
int main()
{
    for (int i = 1; i <= n; i++)
    {
        //开始时所有位置未确定
        state[i] = 2;
        op[i] = 2;
    }
    printf("递归求幂集：\n");
    dfs(1);
    printf("非递归求幂集：\n");
    BackTrack();
    return 0;
}