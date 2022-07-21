#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int maxn = 2501;	 //����
const int maxm = 100001; //����
int n, m;
int path[maxn][maxn];
int arcs[maxn][maxn];
void floyd();

int main()
{
	cin >> n >> m;
	//��ʼ���ڽӾ���
	for (int i = 1; i <= n; i++)
	{
		memset(arcs[i], 0x3f3f3f3f, sizeof arcs[i]);
		arcs[i][i] = 0;
	}
	//��ͼ
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		arcs[u][v] = w;
		arcs[v][u] = w;
	}
	floyd();
	// ������

	return 0;
}

void floyd()
{

	for (int i = 1; i <= n; i++)
		memset(path[i], -1, sizeof path[i]);
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= n; k++)
			for (int j = 1; j <= n; j++)
			{
				if (arcs[i][j] >= arcs[i][k] + arcs[k][j])
				{
					arcs[i][j] = arcs[i][k] + arcs[k][j];
					path[i][j] = k;
				}
			}
}
