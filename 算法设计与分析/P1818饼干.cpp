#include <iostream>
using namespace std;
typedef long long ll;
int c[2000001];
int s[2000001];
int ans[2000001];
int n;
//二分查找
int find(int l, int r, int t)
{
    // cout << "l=" << l << "r=" << r << endl;
    // getchar();
    if (l == r)
        return l;
    else
    {
        int mid = (l + r) / 2;
        if (c[mid] >= t) //左侧
            return find(l, mid, t);

        else if (c[mid] < t) //右侧
            return find(mid + 1, r, t);
        // else
    }
}
int main()
{
    int q, w;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        c[i] = c[i - 1] + w;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cout << find(1, n, s[i]) << " ";
    }
    cout << endl;
    return 0;
}