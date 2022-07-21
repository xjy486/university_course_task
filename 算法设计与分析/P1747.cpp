#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];

int main()
{
    int n, m;
    int key;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    while (m--)
    {
        int low, mid, high;
        low = 1, high = n;
        cin >> key;

        if (a[1] > key) // key比最小的值还小
            cout << a[1] << endl;
        else if (a[n] < key) // key比最大的值还大
            cout << a[n] << endl;
        else // a[1]<=low<=a[n]
        {
            while (low < high - 1) //保留查找到最后只有两个元素的情况(low=high-1)，而不是只有一个元素的情况（low=high）
            {
                mid = (low + high) / 2;
                // Case1 a[low]<key<a[mid] 合并了a[mid]==key的情况
                if (a[mid] >= key)
                    high = mid;
                // Case2 a[mid]<=key<a[high]
                else
                    low = mid;
            }
            if ((key - a[low]) <= (a[high] - key))
                cout << a[low] << endl;
            else
                cout << a[high] << endl;
        }
    }
    return 0;
}
