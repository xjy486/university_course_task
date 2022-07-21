#include <iostream>
const int MAXN = 1000001;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;

int pre[MAXN], a[MAXN];

// find
int find(int x)
{
    while (x != pre[x])
        x = pre[x] = pre[pre[x]];

    return x;
}

// pow
int pow(int n)
{
    int a = 1, base = 2;
    for (int i = 1; i <= n; ++i)
    {
        a = (a * base) % mod;
    }

    return a;
}

// main
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int u = find(i), v = find(a[i]);
        if (u != v)
            pre[u] = v;
    }
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (pre[i] == i)
            count++;
    }
    cout << pow(count) - 1 << endl;
    return 0;
}
