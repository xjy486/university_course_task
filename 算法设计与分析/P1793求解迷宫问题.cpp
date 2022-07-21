#include <iostream>
using namespace std;
const int N = 9;
char map[N][N];
int pos[] = {-1, 0, 1, 0, -1};
bool path[N][N];
void dfs(int x, int y);
int main()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			map[i][j] = getchar();
		}
		getchar();
	}
	dfs(1, 1);
	return 0;
}

void dfs(int x, int y)
{
	if (x == 8 && y == 8)
	{
		path[x][y] = true;
		for (int m = 1; m < N; m++)
		{
			for (int n = 1; n < N; n++)
			{
				if (path[m][n] == true)
					cout << " ";
				else
					cout << map[m][n];
			}
			cout << endl;
		}
		return;
	}
	int l, w;

	for (int i = 0; i < 4; i++)
	{
		l = x + pos[i], w = y + pos[i + 1];
		if (l > 0 && w > 0 && l < N && w < N && map[l][w] == 'O' && path[l][w] == false) //路通吗？
		{
			path[x][y] = true;
			dfs(l, w);
			path[x][y] = false;
		}
	}
	return;
}
// OXXXXXXX
// OOOOOXXX
// XOXXOOOX
// XOXXOXXO
// XOXXXXXX
// XOXXOOOX
// XOOOOXOO
// XXXXXXXO
