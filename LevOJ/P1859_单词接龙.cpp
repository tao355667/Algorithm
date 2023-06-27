/*
P1859 单词接龙
搜索与回溯，dfs，
贪心？剪枝？（每一次的公共字符串长度都取最小，则龙最长）
*/
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int N = 21; //数组大小
int n;            //单词个数
string word[N];   //存储单词
string head;      //首字母
int ans;          //龙的长度
int used[N];      //下标为i的字符串是否被使用过
/*
求a的尾巴和b的头部最少有几个元素相同
*/
int calc_len(const string &a, const string &b)
{
    int len = min(a.length(), b.length());
    for (int i = 1; i <= len; i++)
    {
        string s1 = a.substr(a.length() - i, i); // a取尾部
        string s2 = b.substr(0, i);              // b取开头
        if (s1 == s2)
            return i; //这里返回的是最小的
    }
    return 0;
}
/*
p是起始下标，len是当前龙的长度
*/
void dfs(int p, int len)
{
    ans = max(ans, len); //更新龙的长度
    for (int i = 1; i <= n; i++)
    {
        if (used[i] >= 2)
            continue;
        int cnt = calc_len(word[p], word[i]); //检查字符串重合度
        if (cnt > 0)
        {
            used[i]++;                            //字符串被使用了一次
            dfs(i, len + word[i].length() - cnt); //新龙长度=旧龙长度+新字符串长度-公共长度
            //恢复现场
            used[i]--;
        }
    }
}
int main()
{
    //读数据
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> word[i];
    }
    cin >> head;
    //算法
    for (int i = 1; i <= n; i++)
    {
        if (!word[i].compare(0, 1, head, 0, head.size())) //递归分支
        {                                                 //以head开头
            // cout << word[i] << endl;
            // cout << head << endl;
            memset(used, 0, sizeof(used)); //置为0
            used[i] = 1;
            dfs(i, word[i].length()); //搜索
            //恢复现场，此处可省略
            used[i] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}