#include <iostream>
#include <algorithm>
using namespace std;
typedef struct gangplank
{
    int pos; //跳板所在位置
    int len; //跳板能跳的长度
} gangplank; //跳板

int ans = 0;
int n;

void solve(gangplank *g, int target);
int main()
{
    int target; //目的地
    cin >> n >> target;
    gangplank g[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> g[i].pos >> g[i].len;

    solve(g, target);
    cout << ans << endl;
    return 0;
}
void solve(gangplank *g, int target)
{
    //起点位置
    int loc = 0;
    int i = 1;
    while (loc < target)
    {
        //小胡没有在跳板，要走过去
        if (loc < g[i].pos && i <= n)
        {
            ans += g[i].pos - loc;
            loc = g[i].pos;
        }
        //小胡已经站在了跳板上
        else if (loc == g[i].pos && i <= n)
        {
            //跳板所能到达的最远距离
            int temp = loc + g[i].len;
            int j;
            for (j = i + 1; j <= n; j++)
            {
                //超出跳板范围了
                if (g[j].pos > temp)
                    break;
                //到炸鸡店了
                else if (g[j].pos + g[j].len >= target)
                {
                    temp = target;
                    break;
                }
                else if (g[j].pos + g[j].len >= temp)
                    temp = g[j].pos + g[j].len;
            }
            i = j;
            loc = temp;
        }
        //跳板用完了，还是没到炸鸡店
        else if (i == n + 1)
        {
            ans += (target - loc);
            loc = target;
        }
    }
}
