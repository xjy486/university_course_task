#include <iostream>
#include <iomanip>
using namespace std;
typedef struct coin
{
    int m;          //质量
    int v;          //价值
    float mv;       // v/m的值
    bool is = true; //还有金币吗？
} coin;
int main()
{
    int N;
    float T; // N堆金币，背包容量为T
    cin >> N >> T;
    coin c[N];
    for (int i = 0; i < N; i++)
    {
        cin >> c[i].m >> c[i].v;
        c[i].mv = double(c[i].v) / c[i].m;
    }
    //直接插入排序，按照性值比进行排序，由高到低
    int i = 1;
    while (i < N)
    {
        int pre = i - 1;
        coin now = c[i];
        while (pre >= 0 && now.mv > c[pre].mv)
        {
            c[pre + 1] = c[pre];
            pre--;
        }
        c[pre + 1] = now;
        i++;
    }
    float V = 0;
    //贪心
    while (T > 0)
    {
        for (i = 0; i < N; i++)
        {
            if (c[i].is) //金币还有吗  有
            {
                if (T > c[i].m) //背包足以装下全部这堆金币
                {
                    V += c[i].v;
                    T -= c[i].m;
                    c[i].is = false;
                }
                else //只能装下部分金币
                {
                    V += T * c[i].v / double(c[i].m);
                    T = 0;
                    break;
                }
            }
        }
    }
    cout << fixed << setprecision(2) << V << endl;
    return 0;
}
