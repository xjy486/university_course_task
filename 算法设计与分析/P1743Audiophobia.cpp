#include <iostream>
#include <algorithm>
#define INT_MAX 99999999
using namespace std;

int main()
{
    int NO = 1;
    int c, s, q; // c 顶点数 s边数 q问询数
    while (cin >> c >> s >> q)
    {

        int distance[101][101] = {0};
        int x, y;
        //输入两个点之间的权值
        for (int i = 1; i <= s; i++)
        {

            cin >> x >> y;
            cin >> distance[x][y];
            distance[y][x] = distance[x][y];
        }
        for (int i = 1; i <= c; i++)
            for (int j = 1; j <= c; j++)
            {
                if (i == j)
                    distance[i][j] = 0;
                else if (distance[i][j] == 0)
                    //点i和点j之间彼此不通
                    distance[i][j] = INT_MAX;
            }

        //变形的floyd算法
        for (int i = 1; i <= c; i++)
            for (int j = 1; j <= c; j++)
                for (int k = 1; k <= c; k++)
                    distance[j][k] = min(distance[j][k], max(distance[j][i], distance[i][k]));

        cout << "Case #" << NO++ << endl;
        while (q--)
        {
            int a, b;
            cin >> a >> b;

            if (distance[a][b] == INT_MAX || distance[a][b] == 0)
                cout << "no path" << endl;
            else
                cout << distance[a][b] << endl;
        }
    }
    return 0;
}
