#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define INFINITY 65535
const int maxn = 251;        //点数
const int maxm = 250001;     //边数
int parent[maxn], dis[maxn]; // parent[]存储父节点 dis[]存储单源最短路径
int arcs[maxn][maxn];        //邻接矩阵存储边权信息

void init_arcs(int n)
{
    for (int i = 1; i <= n; i++)
    {
        memset(arcs[i], 0x3f3f3f3f, sizeof(arcs[i]));
        arcs[i][i] = 0;
    }
}
//迪杰斯特拉
void DJT(int n);
int main()
{
    int u, v, w;
    int n, m;
    int X, Y;
    Y = -1;
    cin >> n >> m; //顶点数，边数，目标地点
    init_arcs(n);
    //输入图信息
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        arcs[u][v] = w;
        arcs[v][u] = w;
    }
    DJT(n);
    X = dis[n];
    int s = parent[n]; // start
    int e = n;         // end

    while (s) //找到最短路径上那条最长的边
    {
        int temp_w = arcs[s][e];
        arcs[s][e] = 2 * temp_w;
        arcs[e][s] = 2 * temp_w;
        DJT(n);
        Y = max(Y, dis[n]);
        arcs[s][e] = temp_w;
        arcs[e][s] = temp_w;
        e = s;
        s = parent[s];
    }
    cout << Y - X << endl;
    return 0;
}

void DJT(int n) // n顶点个数
{
    int p = 1;
    int vis[n + 1];
    memset(dis, 0x3f3f3f3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(parent, 0, sizeof parent);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    dis[p] = 0;
    que.push(make_pair(dis[p], p));

    while (!que.empty())
    {
        int min = que.top().first;   //权值
        int m_in = que.top().second; //编号
        que.pop();

        if (vis[m_in] == 1) //编号为m_in的顶点访问过了
            continue;
        vis[m_in] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && min + arcs[m_in][i] < dis[i])
            {
                dis[i] = min + arcs[m_in][i];
                parent[i] = m_in;
                que.push(make_pair(dis[i], i));
            }
        }
    }
}