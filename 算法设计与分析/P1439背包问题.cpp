#include <iostream>
#include <algorithm>
using namespace std;
int fun(int *w, int *v, int c, int n); //动态规划
int main()
{
    int c, n; // capacity,num
    while (cin >> c >> n)
    {
        int w[n + 1]; // weight
        int v[n + 1]; // value
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i] >> v[i];
        }
        cout << fun(w, v, c, n) << endl;
    }
    return 0;
}

int fun(int *w, int *v, int c, int n)
{
    int p[n + 1][c + 1] = {0}; //表格
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (i == 0 || j == 0)
                p[i][j] = 0;
            else if (j < w[i])
                p[i][j] = p[i - 1][j];
            else
                // p[i][j] = (p[i - 1][j] > (p[i - 1][j - w[i]] + v[i])) ? p[i - 1][j] : (p[i - 1][j - w[i]] + v[i]);
                p[i][j] = max(p[i - 1][j], p[i - 1][j - w[i]] + v[i]);
        }
    }
    return p[n][c];
}