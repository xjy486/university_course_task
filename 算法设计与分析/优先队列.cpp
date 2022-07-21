#include <queue>
#include <iostream>
#include <vector>
using namespace std;
typedef struct edge
{
    int to;   //终点，到何处去
    int next; //与这条边同起点的边的序号
    int w;    //这条边的权重
} edge;
int head[1000];
edge e[1000];
void print(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        int s = head[i]; //下一条边的编号
        while (s)
        {
            cout << i << "--->" << e[s].to << " ,w=" << e[s].w << endl;
            s = e[s].next;
        }
    }
}
int main()
{

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    int u, v, w;

    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v >> w;
        e[i].to = u;
        e[i].next = head[u];
        head[u] = i;
        e[i].w = w;
    }
    print(n, m);
    return 0;
}