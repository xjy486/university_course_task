#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];

int main()
{
    int n, m;
    long long key;
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
        else // a[0]<=low<=a[n]
        {
            while (low <= high)
            {
                mid = (low + high) / 2;
                // Case1 a[low]<=key<=a[mid] 合并了a[mid]==key的情况
                if (a[mid] >= key)
                {
                    //因为接下来有mid-1的情况，为防止下标越界这里提前判断一下
                    if (mid == 1)
                    {
                        cout << a[1] << endl;
                        break;
                    }
                    // a[mid-1]<=key<=a[mid]
                    else if (a[mid - 1] <= key)
                    {
                        // key离a[mid-1]更近相较于a[mid]
                        if ((key - a[mid - 1]) <= (a[mid] - key))
                            cout << a[mid - 1] << endl;
                        else
                            cout << a[mid] << endl;
                        break;
                    }
                    // key<=a[mid-1]<a[mid]
                    else
                        high = mid - 1;
                }
                // Case2 a[mid]<key<=a[high]
                else
                {
                    //因为接下来有mid+1的情况，为防止下标越界这里提前判断一下
                    if (mid == n)
                    {
                        cout << a[mid] << endl;
                        break;
                    }
                    // a[mid]<key<=a[mid+1]
                    else if (a[mid + 1] >= key)
                    {
                        // key离a[mid]更近相较于a[mid+1]
                        if ((key - a[mid]) <= (a[mid + 1] - key))
                            cout << a[mid] << endl;
                        else
                            cout << a[mid + 1] << endl;
                        break;
                    }
                    // a[mid]<a[mid+1]<=key
                    else
                        low = mid + 1;
                }
            }
        }
    }
    return 0;
}
