#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Task
{
    int Ma;
    int Mb;
} Task;
bool compare1(const Task &a, const Task &b)
{
    return a.Ma > b.Ma;
}
bool compare2(const Task &a, const Task &b)
{
    return a.Mb > b.Mb;
}
int leastTime(vector<Task> &a, vector<Task> &b);
int main()
{
    int n;
    while (cin >> n)
    {
        Task task[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> task[i].Ma;
        for (int i = 1; i <= n; i++)
            cin >> task[i].Mb;
        // task[i].Ma <= task[i].Mb
        vector<Task> group1;
        // task[i].Ma > task[i].Mb
        vector<Task> group2;
        for (int i = 1; i <= n; i++)
        {
            if (task[i].Ma <= task[i].Mb)
                group1.push_back(task[i]);
            else
                group2.push_back(task[i]);
        }

        sort(group1.begin(), group1.end(), compare1); //½µÐò
        sort(group2.begin(), group2.end(), compare2); //ÉýÐò
        // for (vector<Task>::iterator it = group1.begin(); it < group1.end(); it++)
        // {
        //     cout << (*it).Ma << "," << (*it).Mb << endl;
        // }
        cout << leastTime(group1, group2) << endl;
    }

    return 0;
}

int leastTime(vector<Task> &a, vector<Task> &b)
{
    int fa, fb;
    fa = fb = 0;
    for (vector<Task>::iterator it = a.begin(); it < a.end(); it++)
    {
        fa += (*it).Ma;
        fb = max(fa, fb) + (*it).Mb;
    }
    for (vector<Task>::iterator it = b.begin(); it < b.end(); it++)
    {
        fa += (*it).Ma;
        fb = max(fa, fb) + (*it).Mb;
    }
    return fb;
}