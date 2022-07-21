#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int main()
{
    long long n, m;

    while (cin >> n >> m)
    {
        long long x, y, have_eat;
        priority_queue<pair<long long, long long>> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> y >> x;
            q.push(make_pair(min(y, x), max(y, x)));
        }
        have_eat = 0;

        while (m && !q.empty())
        {
            y = q.top().first;
            x = q.top().second;
            q.pop();

            have_eat += y * y;
            x -= y;
            if (y > 0 && x > 0)
                q.push(make_pair(min(y, x), max(y, x)));
            m -= 1;
        }
        cout << have_eat << endl;
    }
    return 0;
}