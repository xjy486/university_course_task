#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

int main()
{
    int n, m;

    while (cin >> n)
    {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> m;
            q.push(m);
        }
        while (!q.empty())
        {
            ll a = q.top();
            q.pop();
            ll b = q.top();
            q.pop();
            ll c = a * b + 1;
            q.push(c);
            if (q.size() == 1)
                break;
        }
        cout << q.top() << endl;
        q.pop();
    }
    return 0;
}