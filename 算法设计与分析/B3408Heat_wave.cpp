#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 2501;     //点数
const int maxm = 6201 * 2; //边数
int dis[maxn], head[maxn]; // dis[]存储单源最短路径
int u, v, w;
typedef struct edge
{
    int to;   //终点，到何处去
    int next; //与这条边同起点的边的序号
    int w;    //这条边的权重
} edge;
edge e[maxm];
// spfa
void SPFA(int n, int p);
void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int s = head[i];
        while (s)
        {
            cout << i << "-->" << e[s].to << ", w=" << e[s].w << endl;
            cout << s << endl;
            s = e[s].next;
        }
    }
}
int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t; //顶点数，边数，目标地点
    //输入图信息
    int j = 1;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        //正向边
        e[j].to = v;
        e[j].next = head[u];
        head[u] = j;
        e[j].w = w;
        j++;
        // 反向边
        e[j].to = u;
        e[j].next = head[v];
        head[v] = j;
        e[j].w = w;
        j++;
    }
    SPFA(n, s);
    // print(n);
    cout << dis[t] << endl;
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
                // cout << index << "-->" << to << "  " << dis[to] << endl;
                if (!vis[to])
                {
                    que.push(to);
                    vis[to] = 1;
                }
            }
            s = e[s].next;
        }
        // cout << "q.size " << que.size() << endl;
        // getchar();
    }
}