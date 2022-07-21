#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
vector<pair<int, int>> p;
int temp[10001];
bool comp(const pair<int, int> a, const pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first > b.first)
        return false;
    else
    {
        if (a.second <= b.second)
            return true;
        else if (a.second > b.second)
            return false;
    }
}
bool cmps(const int a, const int b)
{
    return p[a].second < p[b].second;
}
double get_dis(int a, int b)
{
    return sqrt((p[a].first - p[b].first) * (p[a].first - p[b].first) + (p[a].second - p[b].second) * (p[a].second - p[b].second));
}
double divide(int l, int r)
{
    if (l == r)
        return 0x3f3f3f3f;
    else if (l + 1 == r)
        return get_dis(l, r);

    else
    {
        int mid = (l + r) / 2;

        double d1 = divide(l, mid);

        double d2 = divide(mid + 1, r);

        double d = min(d1, d2);
        int midx = p[mid].first; //中位线

        int k = 0;
        for (int i = l; i < r; i++)
            if (fabs(p[i].first - p[mid].first) <= d)
                temp[k++] = i;
        sort(temp, temp + k, cmps);
        for (int i = 0; i < k; i++)
            for (int j = i + 1; j < k && p[temp[j]].second - p[temp[i]].second < d; j++)
                d = min(d, get_dis(temp[i], temp[j]));

        return d;
    }
}
int main()
{
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    sort(p.begin(), p.end(), comp);

    printf("%.4f\n", divide(0, p.size() - 1));
    return 0;
}