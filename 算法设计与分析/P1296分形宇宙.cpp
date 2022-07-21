#include <iostream>
#include <cmath>
using namespace std;
char map[3000][3000];
void fun(int n, int x, int y);
int main()
{
    int n;
    while (cin >> n)
    {
        int size = pow(3, n - 1);
        for (int i = 1; i <= size; i++)
            for (int j = 1; j <= size; j++)
                map[i][j] = ' ';

        fun(n, 1, 1);

        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
                cout << map[i][j];
            cout << endl;
        }

        cout << "-" << endl;
    }
    return 0;
}

void fun(int n, int x, int y)
{
    if (n == 1)
        map[x][y] = 'X';
    else
    {
        int size = pow(3, n - 2);
        fun(n - 1, x, y);                       //左上角
        fun(n - 1, x + 2 * size, y);            //左下角
        fun(n - 1, x + size, y + size);         //中间
        fun(n - 1, x, y + 2 * size);            //右上角
        fun(n - 1, x + 2 * size, y + 2 * size); //右下角
    }
}