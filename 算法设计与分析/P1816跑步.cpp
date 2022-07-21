#include <iostream>
#include <cstring>
using namespace std;
int n, m, k;
int a[10001] = {0};
int cal();
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        int pos;
        memset(a, 0, sizeof a);
        for (int i = 1; i <= m; i++)
        {
            cin >> pos;
            a[pos] = 1; //有水坑
        }
        cout << cal() << endl;
        }
    return 0;
}

int cal()
{
    int l, r, ans;
    l = 1, r = n, ans = 0;
    while (l < r)
    {
        //踩到了水坑
        if (a[l] == 1)
            ans++;
        //找到下一个位置是水坑的位置
        int flag = 0;
        while (a[l] == 0)
        {
            l++;
            flag = 1;
        }
        if (flag)
            l -= 1;

        //寻找最佳落点位置
        int off = 1;
        while (off <= k)
        {
            //跳跃范围内有一个没坑的地方,跳这去
            if (a[l + off] == 0)
                break;
            //否则跳至最远端
            off++;
        }
        if (off >= k)
            off = k;
        l += off;
    }
    if (a[n] == 1)
        ans++;
    return ans;
}