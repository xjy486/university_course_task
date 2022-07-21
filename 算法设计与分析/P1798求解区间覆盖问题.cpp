#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    // 区间个数 n和所需线段数 m
    cin >> n >> m;
    int D[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> D[i];
    sort(D + 1, D + n + 1);
    int M[n];
    //相邻两个区间的距离-1
    for (int i = 1; i < n; i++)
        M[i] = D[i + 1] - D[i] - 1;
    sort(M + 1, M + n, greater<int>()); //降序排列

    int dp[m + 1];
    for (int i = 1; i <= m; i++)
    {
        if (i == 1)
            dp[1] = D[n] - D[1] + 1;
        else if (i >= n)
            dp[i] = m;
        else
            dp[i] = dp[i - 1] - M[i - 1];
    }
    cout << dp[m] << endl;
}