#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1001;                //点数
const int maxm = 100001;              //边数
int ans[maxn], dis[maxn], head[maxn]; // ans[]存储一次正向，一次反向,dis[]存储单源最短路径
int u[maxn], v[maxn], w[maxn];
typedef struct edge
{
    int to;   //终点，到何处去
    int next; //与这条边同起点的边的序号
    int w;    //这条边的权重
} edge;
edge e[maxm];
// spfa
void SPFA(int n, int p);

int main()
{
    int n, m, s;
    cin >> n >> m >> s; //顶点数，边数，目标地点
    //输入图信息
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        e[i].to = v[i];
        e[i].next = head[u[i]];
        head[u[i]] = i;
        e[i].w = w[i];
    }
    SPFA(n, s);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = dis[i];
        head[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        e[i].to = u[i];
        e[i].next = head[v[i]];
        head[v[i]] = i;
        e[i].w = w[i];
    }
    SPFA(n, s);
    int res = -1;
    for (int i = 1; i <= n; i++)
    {
        ans[i] += dis[i];
        res = max(ans[i], res);
    }
    cout << res << endl;
    return 0;
}

void SPFA(int n, int p) // n顶点个数,p目标地点
{
    int vis[n + 1];
    memset(dis, 0x3f3f3f3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    queue<int> que;
    dis[p] = 0;
    vis[p] = 1;
    que.push(p);
    while (!que.empty())
    {
        int index = que.front();
        vis[index] = 0;
        que.pop();

        int s = head[index];
        while (s)
        {

            int to = e[s].to;
            if (dis[to] > dis[index] + e[s].w)
            {
                dis[to] = dis[index] + e[s].w;
                if (!vis[to])
                {
                    que.push(to);
                    vis[to] = 1;
                }
            }
            s = e[s].next;
        }
    }
}