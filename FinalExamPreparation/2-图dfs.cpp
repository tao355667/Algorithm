#include <iostream>
using namespace std;
const int N = 100;
int n = 5;
int g[N][N] = {
    {0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0}};
int visited[N];
int start = 0;
int name[N] = {1, 2, 3, 4, 5};

void dfs(int s) // s：start node
{
    visited[s] = 1;
    cout << name[s] << "->";
    for (int e = 0; e < n; e++)
    {
        if (!visited[e] && g[s][e] != 0)
        {
            dfs(e);
        }
    }
}
main()
{
    dfs(0);
    return 0;
}