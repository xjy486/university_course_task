#include <iostream>
typedef long long ll;
using namespace std;
const int N = 5001;
int n;
ll dis[N][N];
ll X[N],Y[N];
int main()
{
    int T,x,y;
    
    cin >> T;
    while (T--)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> X[i] >> Y[i];
        }
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
            {
                dis[i][j] = dis[j][i] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
            }
    }
    return 0;
}