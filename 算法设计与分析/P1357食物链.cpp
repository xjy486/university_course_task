#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1001;
int n, m, ans, cnt; // ans�𰸣�cnt�洢������֮���Ѿ�·���Ľ������
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
            out[s]++; //����+1
            in[e]++;  //���+1
        }
        //Ѱ�����Ϊ0�ĵ�
        for (int i = 0, k = 0; i < n; i++)
            if (in[i] == 0) //Ѱ�����Ϊ0�ĵ㣬��ʳ���������
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
            ans = max(ans, cnt); //����ʳ�������յ���
        else
        {
            cnt++;
            dfs(i);
            cnt--;
        }
    }
}