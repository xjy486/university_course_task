#include <iostream>
using namespace std;

int competition(int *a, int *b, int s1, int t1, int s2, int t2);
//快速排序
void QuickSort(int a[], int s, int t);
int Partition(int a[], int s, int t);
int main()
{
	int n; //马的数量
	cin >> n;
	int *tianji = new int[n]; //田忌的马的速度
	int *qiwei = new int[n];  //齐威王的马的速度
	for (int i = 0; i < n; i++)
		cin >> tianji[i];
	for (int i = 0; i < n; i++)
		cin >> qiwei[i];
	//为马按马的速度由低到高排序
	QuickSort(tianji, 0, n - 1);
	QuickSort(qiwei, 0, n - 1);
	cout << competition(tianji, qiwei, 0, n - 1, 0, n - 1) << endl;

	return 0;
}
// a[...]田忌的马
// b[...]齐威王的马
int competition(int *a, int *b, int s1, int t1, int s2, int t2)
{
	int coin = 0; //银币数量
	while (s1 <= t1)
	{
		//田忌最快的马比齐威王最快的马还慢
		//用田忌最慢的马和齐威王最快的马比
		if (a[t1] < b[t2])
		{
			coin -= 200; //输了200银币
			t2--;		 //齐威王目前最快的马参加了比赛
			s1++;		 //田忌目前最慢的马参加了比赛
		}
		//田忌最快的马比齐威王最快的马还慢
		//用田忌最快的马和齐威王最快的马比
		else if (a[t1] > b[t2])
		{
			coin += 200; //赢了200银币
			t1--;		 //田忌目前最快的马参加了比赛
			t2--;		 //齐威王目前最快的马参加了比赛
		}
		//田忌最快的马与齐威王最快的马马速相等
		//再分3种情况
		else
		{
			//田忌最慢的马比齐威王最慢的马快
			//用田忌最慢的马和齐威王最慢的马比
			if (a[s1] > b[s2])
			{
				coin += 200;
				s1++;
				s2++;
			}
			// 田忌最慢的马比齐威王最慢的马慢/相等
			else
			{
				//田忌最慢的马比齐威王最快的马慢
				if (a[s1] < b[t2])
					coin -= 200;
				s1++;
				t2--;
			}
		}
	}
	return coin;
}

void QuickSort(int a[], int s, int t)
{
	//对a[s....t]元素进行递增排序
	if (s < t)
	{
		int i = Partition(a, s, t);
		QuickSort(a, s, i - 1);
		QuickSort(a, i + 1, t);
	}
}

int Partition(int a[], int s, int t)
{
	int i = s, j = t;
	int temp = a[s]; //用第一个记录作为基准
	while (i != j)	 //从序列两端交替向中间扫描，直到i=j为止
	{
		while (j > i && a[j] >= temp)
			j--; //从右向左扫描，找到第一个小于temp的a[j]
		a[i] = a[j];
		while (i < j && a[i] <= temp)
			i++; //从右向左扫描，找到第一个大于temp的a[i]
		a[j] = a[i];
	}
	a[i] = temp;
	return i;
}
