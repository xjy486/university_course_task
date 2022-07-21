#include <iostream>
#include <algorithm>
using namespace std;
int R, C;
int arr[101][101];
int s[101][101];
bool is[101][101] = {false};
int direct[] = {-1, 0, 1, 0, -1};
int fun(int x, int y);
int main()
{
    while (cin >> R >> C)
    {
        for (int i = 1; i < 1 + R; i++)
            for (int j = 1; j < 1 + C; j++)
            {
                cin >> arr[i][j];
                s[i][j] = 1;
            }

        int ans = -1;
        //每个点都当做起点跑一次
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
            {
                if (ans < fun(i, j))
                    ans = fun(i, j);
            }
        cout << ans << endl;
    }
    return 0;
}

int fun(int x, int y)
{
    int dx, dy;
    // s[x][y] = 1;
    if (is[x][y])
        return s[x][y];
    for (int i = 0; i < 4; i++)
    {
        dx = x + direct[i], dy = y + direct[i + 1];
        if (dx > 0 && dy > 0 && dx < C + 1 && dy < R + 1 && arr[dx][dy] < arr[x][y])
        {
            fun(dx, dy);
            s[x][y] = max(s[x][y], s[dx][dy] + 1);
        }
    }
    is[x][y] = true;
    return s[x][y];
}
