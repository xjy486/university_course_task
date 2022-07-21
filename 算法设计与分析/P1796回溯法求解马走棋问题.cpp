#include <iostream>
#include <algorithm>
using namespace std;

void fun(int x, int y, int **a, int &ans);
int n, m;
int dx[2] = {1, 2};
int dy[2] = {2, 1};
int main()
{

	cin >> n >> m;
	int **a = new int *[n + 1];
	for (int i = 0; i <= n; i++)
		a[i] = new int[m + 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = 0;
	int ans = 0;
	fun(1, 1, a, ans);
	cout << ans << endl;
	return 0;
}

void fun(int x, int y, int **a, int &ans)
{
	//到了目标位置,ans++
	if (x == n && y == m)
	{
		ans++;
		return;
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx <= n && ty <= m && a[tx][ty] == 0)
			{
				// cout << tx << "," << ty << endl;
				a[tx][ty] = 1;
				fun(tx, ty, a, ans);
				a[tx][ty] = 0;
			}
		}
	}
}
