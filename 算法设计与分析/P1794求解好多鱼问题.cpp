#include <iostream>
using namespace std;

void solve(int *a, int *b, bool *check, int n, int len);

int main()
{
    int minsize, maxsize, n;
    //放入鱼的尺寸范围
    cin >> minsize >> maxsize;
    //鱼缸内🐟的数量
    cin >> n;
    //存储已放入鱼的尺寸
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int len = maxsize - minsize + 1;
    //存储待放入鱼的尺寸
    int *b = new int[len];
    //该种鱼是否可以放入，可以放入true,不能false
    bool *check = new bool[len];
    //第i种鱼的尺寸
    for (int i = 0; i < len; i++)
    {
        b[i] = minsize + i;
        check[i] = true;
    }
    solve(a, b, check, n, len);

    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (check[i] == true)
            ans++;
    }
    cout << ans << endl;
    delete[] a;
    delete[] b;
    delete[] check;
    return 0;
}

void solve(int *a, int *b, bool *check, int n, int len)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < len; j++)
        {
            //放进去得鱼会吃掉鱼缸里的鱼
            if (a[i] * 2 <= b[j] && b[j] <= 10 * a[i])
                check[j] = false;

            //放进去的鱼会被鱼缸里的鱼吃掉
            if (2 * b[j] <= a[i] && a[i] <= 10 * b[j])
                check[j] = false;
        }
    }
}
