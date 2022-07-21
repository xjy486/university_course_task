#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 2001;
vector<pair<int, int>> g[N];
void prim();
int n, m, maxlen;
int main()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[v].push_back(make_pair(w, u));
        g[u].push_back(make_pair(w, v));
    }
    prim();
    cout << maxlen << endl;
}

void prim()
{
    maxlen = -1;
    int vis[n + 1] = {0};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int num, s;
    num = 1, s = 1;
    while (num < n)
    {
        vis[s] = 1; //加入割集的顶点
        for (int i = 0; i < g[s].size(); i++)
            q.push(g[s][i]);

        int to, w;
        while (true)
        {
            w = q.top().first;
            to = q.top().second;
            q.pop();

            //这个点不在在割集中
            if (!vis[to])
                break;
        }

        maxlen = max(maxlen, w);
        s = to;
        num++;
    }
}