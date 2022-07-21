// 题目描述：
// 从一组数据（长度为 n，其中 n <= 10000，数据的值都大于 -60000）中找出连续的一段数，使得这段数的和最大。
// 输入描述：
// 第一行是一个正整数 n，表示数据的个数，从第二行开始是 n 个数据。
// 输出描述：
// 一行，子段的最大和。
// 样例输入：
// 5
// 1 -3 4 1 -9
// 样例输出：
// 5

#include <iostream>
using namespace std;

int smax(int a[], int low, int high);
int crossingsmax(int a[], int low, int mid, int high);
int main()
{
    int n;
    while (cin >> n)
    {
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << smax(a, 1, n) << endl;
    }
    return 0;
}

int smax(int a[], int low, int high)
{
    int mid, s1, s2, s3, s;
    if (low == high)
        return a[low];
    else
    {
        mid = (low + high) / 2;
        s1 = smax(a, low, mid);
        s2 = smax(a, mid + 1, high);
        s3 = crossingsmax(a, low, mid, high);
        s = s1 > s2 ? (s1 > s3 ? s1 : s3) : (s2 > s3 ? s2 : s3);
        return s;
    }
}

int crossingsmax(int a[], int low, int mid, int high)
{
    int left, right, temp;
    left = right = -99999;
    temp = 0;
    for (int i = mid; i >= low; i--)
    {
        temp += a[i];
        if (temp > left)
            left = temp;
    }
    temp = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        temp += a[i];
        if (temp > right)
            right = temp;
    }
    return right + left;
}