#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define INFINITY 65535
const int maxn = 1001;    //����
const int maxm = 100001;  //����
int ans[maxn], dis[maxn]; // ans[]�洢һ������һ�η���,dis[]�洢��Դ���·��
int arcs[maxn][maxn];     //�ڽӾ���洢��Ȩ��Ϣ
//���ڽӾ�����г�ʼ��
void init_arcs(int n)
{
    for (int i = 1; i <= n; i++)
    {
        memset(arcs[i], 0x3f3f3f3f, sizeof(arcs[i]));
        arcs[i][i] = 0;
    }
}
//�Ͻ�˹����
void DJT(int n, int x);
int main()
{
    int u[maxm], v[maxm], w[maxm];
    int n, m, x;
    cin >> n >> m >> x; //��������������Ŀ��ص�
    init_arcs(n);
    //����ͼ��Ϣ
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        arcs[u[i]][v[i]] = w[i];
    }

    DJT(n, x);
    for (int i = 1; i <= n; i++)
        ans[i] = dis[i];
    // memset(dis, 0, sizeof dis);
    init_arcs(n);
    for (int i = 1; i <= m; i++)
        arcs[v[i]][u[i]] = w[i];

    DJT(n, x);
    int res = -1;
    for (int i = 1; i <= n; i++)
    {
        ans[i] += dis[i];
        res = max(ans[i], res);
    }
    cout << res << endl;
    return 0;
}

// void DJT(int n, int p)
// {
//     bool final[n + 1];

//     int todex;

//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = arcs[p][i];
//         final[i] = false;
//     }
//     dis[p] = 0;
//     final[p] = true;

//     for (int k = 1; k <= n; k++)
//     {
//         int dist = INFINITY;
//         for (int j = 1; j <= n; j++)
//         {
//             if (!final[j])
//             {
//                 if (dist > dis[j])
//                 {
//                     dist = dis[j];
//                     todex = j;
//                 }
//             }
//         }
//         final[todex] = true;
//         // cout << todex << " " << dis[todex] << endl;
//         for (int i = 1; i <= n; i++)
//         {
//             if (!final[i] && (dist + arcs[todex][i] < dis[i]))
//             {
//                 dis[i] = dist + arcs[todex][i];
//             }
//         }
//     }
// }

void DJT(int n, int p) // n�������,pĿ��ص�
{
    int vis[n + 1];
    memset(dis, 0x3f3f3f3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    dis[p] = 0;
    que.push(make_pair(dis[p], p));

    while (!que.empty())
    {
        int dist = que.top().first; //Ȩֵ
        int to = que.top().second;  //���
        que.pop();

        // if (vis[to] == 1) //���Ϊto�Ķ�����ʹ���
        //     continue;
        vis[to] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dist + arcs[to][i] < dis[i])
            {
                dis[i] = dist + arcs[to][i];
                que.push(make_pair(dis[i], i));
            }
        }
    }
}