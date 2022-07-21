//时间复杂度O(n!)
//肯定不能被AC的
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Task
{
    int Ma;
    int Mb;
} Task;
int n;
int x[1000];
int bestf;
void dfs(int i, int &f1, int *f2, Task *task);
int main()
{

    while (cin >> n)
    {
        bestf = 100000;
        Task task[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> task[i].Ma;
        for (int i = 1; i <= n; i++)
            cin >> task[i].Mb;
        for (int i = 1; i <= n; i++)
            x[i] = i;
        int f1 = 0;
        int f2[n + 1] = {0};
        dfs(1, f1, f2, task);
        cout << bestf << endl;
    }

    return 0;
}
void dfs(int i, int &f1, int *f2, Task *task)
{
    if (i > n)
    {
        if (f2[n] < bestf)
            bestf = f2[n];
    }
    else
    {
        //没有到达叶子节点，考虑i到n的作业
        for (int j = i; j <= n; j++)
        {

            //在第i层选择执行作业Task[j]
            f1 += task[x[j]].Ma;
            f2[i] = max(f1, f2[i - 1]) + task[x[j]].Mb;
            //剪枝：仅仅扩展当前总时间小于bestf的结点
            if (f2[i] < bestf)
            {
                swap(x[i], x[j]);
                // cout << task[j].Ma << "," << task[j].Mb << endl;
                dfs(i + 1, f1, f2, task);
                swap(x[j], x[i]);
            }
            //回溯，即回撤第i层的对作业task[j]的选择，以便再选择其他的作业
            f1 -= task[x[j]].Ma;
        }
    }
}