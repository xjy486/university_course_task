#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1001;
int n, m, ans, cnt; // ans答案，cnt存储到达结点之后已经路过的结点数量
int g[N][N] = {0};
int in[N] = {0};
int out[N] = {0};
void dfs(int x);
int main()
{
    int s, e;
    while (cin >> n >> m)
    {
        ans = cnt = 0;
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        memset(g, 0, sizeof g);
        for (int i = 1; i <= m; i++)
        {
            cin >> s >> e;
            g[s][e] = 1;
            out[s]++; //出度+1
            in[e]++;  //入度+1
        }
        //寻找入度为0的点
        for (int i = 0, k = 0; i < n; i++)
            if (in[i] == 0) //寻找入度为0的点，即食物链的起点
                dfs(i);
        ans++;
        cout << ans << endl;
    }
    return 0;
}

void dfs(int x)
{

    for (int i = 1; i <= n; i++)
    {
        if (g[x][i] == 0)
            ans = max(ans, cnt); //这条食物链到终点了
        else
        {
            cnt++;
            dfs(i);
            cnt--;
        }
    }
}