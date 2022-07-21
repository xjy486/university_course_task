#include <iostream>
#include <cmath>
using namespace std;
#define N 9
int q[N] = {0};
int ans = 0;
void queen(int row);
bool place(int row, int col);
int main()
{
    int temp;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            cin >> temp;
            if (temp)
                q[i] = j;
        }
    ans = 0;
    queen(1);
    cout << ans << endl;

    return 0;
}

void queen(int row)
{
    if (row > 8)
        ans++;

    else
    { //已经被提取安排好了
        if (q[row])
            queen(row + 1);
        else
        {
            for (int col = 1; col <= 8; col++)
            {
                bool flag = place(row, col);
                if (flag)
                {
                    q[row] = col;
                    queen(row + 1);
                    q[row] = 0;
                }
            }
        }
    }
}

bool place(int row, int col)
{

    //不能在同一行
    if (q[row] != 0)
        return false;
    else
    {
        for (int i = 1; i <= 8; i++)
        {
            //第i行有棋子
            if (q[i])
            {
                // 不能在对角线上,不能在同一列上
                if ((abs(i - row) == abs(q[i] - col)) || q[i] == col)
                    return false;
            }
        }
    }
    return true;
}