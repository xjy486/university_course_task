#include <iostream>
using namespace std;
int calculate(int m, int n);
int main()
{
    int m, n; //(1,1)-->(m,n)几种方法
    cin >> m >> n;
    cout << calculate(m, n) << endl;
    return 0;
}
//采用数学方法计算
int calculate(int m, int n)
{
    //点在y=0.5*x+0.5上且m是奇数
    if (n == 0.5 * m + 0.5 && m % 2 == 1)
        return 1;
    //点在y=2*x-1上
    else if (n == 2 * m - 1)
        return 1;
    //点在y=2*x-1下方且在y=0.5*x+0.5上方
    else if (n < 2 * m - 1 && n > 0.5 * m + 0.5)
    {
        int k;
        //点在y=-x+3k+2(k=0,1,2,3,...)这条直线上
        if ((m + n - 2) % 3 == 0)
        {
            return calculate(m - 2, n - 1) + calculate(m - 1, n - 2);
        }
        else
            return 0;
    }
    //点在y=2*x-1上方或在y=0.5*x+0.5下方
    else
        return 0;
}