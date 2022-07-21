#include <iostream>
using namespace std;

long long s = 0;
void divide(int *a, int left, int right);
void merge(int *a, int b1, int e1, int b2, int e2); //归并排序
int main()
{
    int n;
    cin >> n;
    int a[500010];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    divide(a, 1, n);
    cout << s << endl;
}

void divide(int *a, int left, int right)
{
    int mid = (left + right) / 2;

    if (left < right)
    {
        divide(a, left, mid);
        divide(a, mid + 1, right);
        merge(a, left, mid, mid + 1, right);
    }
}

void merge(int *a, int b1, int e1, int b2, int e2)
{
    int i, j, k;
    i = b2, j = b1, k = 0;
    long long temp[e2 - b1 + 2]; //辅助数组
    while (i <= e2 && j <= e1)   //归并排序
    {
        if (a[i] < a[j]) //左边比右边大
        {
            s += (e1 - j + 1);
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    if (i <= e2)
        for (; i <= e2; i++, k++)
            temp[k] = a[i];
    if (j <= e2)
        for (; j <= e1; j++, k++)
            temp[k] = a[j];
    k--;
    // 把排序后的数据在复制回a数组中
    for (i = b1, j = 0; j <= k && i <= e2; j++, i++)
        a[i] = temp[j];
}