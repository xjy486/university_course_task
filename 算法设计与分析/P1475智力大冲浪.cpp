#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Game
{
    int ddl;   //最迟完成时间
    int fined; //未完成的罚金
} Game;
//快速排序
void Quicksort(Game *a, int i, int n);
int Partition(Game *a, int i, int n);
//贪心
int solve(Game *a, int n);
int main()
{
    // money初始金额，n个小游戏
    int money, n;
    while (cin >> money)
    {
        cin >> n;
        Game g[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> g[i].ddl; //输入游戏的最迟截止时间
        for (int i = 1; i <= n; i++)
            cin >> g[i].fined; //输入游戏不完成的罚金
        //把各个小游戏按照罚金大小升序排序
        Quicksort(g, 1, n);
        int loss = solve(g, n);
        cout << money - loss << endl;
    }
    return 0;
}
void Quicksort(Game *a, int i, int n)
{
    if (i < n)
    {
        int mid = Partition(a, i, n);
        Quicksort(a, i, mid - 1);
        Quicksort(a, mid + 1, n);
    }
}

int Partition(Game *a, int i, int n)
{
    int pivot = a[i].fined;
    Game temp = a[i];
    while (i < n)
    {
        while (a[n].fined > pivot && i < n)
            n--;
        a[i] = a[n];
        while (a[i].fined < pivot && i < n)
            i++;
        a[n] = a[i];
    }
    a[i] = temp;
    return i;
}

int solve(Game *a, int n)
{
    // n个时间段都尚未安排游戏
    bool pos[n + 1] = {false};
    int loss = 0;
    while (n >= 1)
    {
        if (pos[a[n].ddl] == false)
            pos[a[n].ddl] = true;

        //如果该游戏的最迟完成时间已经被占用了，它只能在1....a[n].ddl之前去找一个尚未被安排的时间
        else if (pos[a[n].ddl] == true)
        { //存储的它的最迟完成时间
            int e = a[n].ddl;
            //在pos[1....a[n].ddl]中寻合适的时间
            while (e >= 1)
            {
                //找到了
                if (pos[e] == false)
                {
                    pos[e] = true;
                    break;
                }
                e--;
            }
            //没找到 该游戏没有地方可以安排，接受罚金
            if (e < 1)
                loss += a[n].fined;
        }
        n--;
    }
    return loss;
}