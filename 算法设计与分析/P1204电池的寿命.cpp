#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n; //电池节数
    float max_battery, other_total_battery;
    while (cin >> n)
    {
        float battery[n];
        max_battery = other_total_battery = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> battery[i];            //电池容量
            if (battery[i] > max_battery) //求最大电池容量
                max_battery = battery[i];
            other_total_battery += battery[i];
        }
        other_total_battery -= max_battery;

        if (max_battery > other_total_battery) //最大电池容量大于其他电池容量之和
            cout << fixed << setprecision(1) << other_total_battery << endl;
        else //最大电池容量小于等于其他电池容量之和
            cout << fixed << setprecision(1) << (other_total_battery + max_battery) / 2 << endl;
    }
}