#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;

struct T
{
    int l, r;
    int v, count;
} tr[N];

int n, m;

int main()
{
    cin >> m;
    while (m--)
    {
        int tag, x;
        cin >> tag >> x;
        if (tag == 1)
        {
            int u = 1;
            int tmp = 0;
            bool flag = false;
            while (tr[u].v != 0)
            {
                if (tr[u].v == x)
                {
                    tr[u].count++;
                    break;
                }
                if (x < tr[u].v)
                {
                    // printf("<-");
                    cout << "<-";
                    tmp = u;
                    flag = false;
                    if (!tr[u].l)
                        break;
                    u = tr[u].l;
                }
                else if (x > tr[u].v)
                {
                    // printf("->");
                    cout << "->";
                    tmp = u;
                    flag = true;
                    if (!tr[u].r)
                        break;
                    u = tr[u].r;
                }
            }
            puts("");
            if (tr[u].v != x)
            {
                ++n;
                if (!flag)
                    tr[tmp].l = n;
                else
                    tr[tmp].r = n;
                tr[n].count = 1;
                tr[n].v = x;
            }
        }
        else
        {
            int u = 1;
            while (tr[u].v != x && tr[u].v != 0)
            {
                if (tr[u].v == x)
                {
                    tr[u].count++;
                    break;
                }
                if (x < tr[u].v)
                {
                    cout << "<-";
                    u = tr[u].l;
                }
                else if (x > tr[u].v)
                {
                    // printf("->");
                    cout << "->";
                    u = tr[u].r;
                }
            }
            puts("");
            // printf("%d\n", tr[u].count);
            cout << tr[u].count << endl;
        }
    }
}
