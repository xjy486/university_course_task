#include <iostream>
#include <vector>
using namespace std;

int get_dis(int k)
{
    if (!(k & (k - 1)))
        return 0;
    else
    {
        int temp = k & (k - 1);
        int t;
        while (temp != 0)
        {
            t = temp;
            temp = t & (t - 1);
        }
        return k - t;
    }
}

int main()
{
    int n, k;
    vector<int> m;
    while (cin >> n >> k)
    {
        int key;
        for (int i = 1; i <= n; i++)
        {
            cin >> key;
            if (key == k)
            {
                m.push_back(get_dis(i));
            }
        }
        int ans = 0;
        for (int i = 0; i < m.size(); i++)
        {
            if (ans >= m[i])
                ans += 1;
            else
                ans = m[i] + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
