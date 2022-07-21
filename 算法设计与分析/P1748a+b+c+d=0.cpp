#include <iostream>
#include <map>
using namespace std;
const int N = 2002;
int a[N], b[N], c[N], d[N];
int ans = 0;
map<int, int> m;
int main()
{
    int n, T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i] >> c[i] >> d[i];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int s = (a[i] + b[j]) * (-1);
                m[s]++;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int s = c[i] + d[j];
                ans += m[s];
            }
        cout << ans << endl;
    }
}