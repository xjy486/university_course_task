#include <iostream>
using namespace std;

int competition(int *a, int *b, int s1, int t1, int s2, int t2);
//��������
void QuickSort(int a[], int s, int t);
int Partition(int a[], int s, int t);
int main()
{
	int n; //�������
	cin >> n;
	int *tianji = new int[n]; //��ɵ�����ٶ�
	int *qiwei = new int[n];  //������������ٶ�
	for (int i = 0; i < n; i++)
		cin >> tianji[i];
	for (int i = 0; i < n; i++)
		cin >> qiwei[i];
	//Ϊ������ٶ��ɵ͵�������
	QuickSort(tianji, 0, n - 1);
	QuickSort(qiwei, 0, n - 1);
	cout << competition(tianji, qiwei, 0, n - 1, 0, n - 1) << endl;

	return 0;
}
// a[...]��ɵ���
// b[...]����������
int competition(int *a, int *b, int s1, int t1, int s2, int t2)
{
	int coin = 0; //��������
	while (s1 <= t1)
	{
		//������������������������
		//���������������������������
		if (a[t1] < b[t2])
		{
			coin -= 200; //����200����
			t2--;		 //������Ŀǰ������μ��˱���
			s1++;		 //���Ŀǰ��������μ��˱���
		}
		//������������������������
		//�������������������������
		else if (a[t1] > b[t2])
		{
			coin += 200; //Ӯ��200����
			t1--;		 //���Ŀǰ������μ��˱���
			t2--;		 //������Ŀǰ������μ��˱���
		}
		//������������������������������
		//�ٷ�3�����
		else
		{
			//���������������������������
			//�����������������������������
			if (a[s1] > b[s2])
			{
				coin += 200;
				s1++;
				s2++;
			}
			// ����������������������������/���
			else
			{
				//��������������������������
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
	//��a[s....t]Ԫ�ؽ��е�������
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
	int temp = a[s]; //�õ�һ����¼��Ϊ��׼
	while (i != j)	 //���������˽������м�ɨ�裬ֱ��i=jΪֹ
	{
		while (j > i && a[j] >= temp)
			j--; //��������ɨ�裬�ҵ���һ��С��temp��a[j]
		a[i] = a[j];
		while (i < j && a[i] <= temp)
			i++; //��������ɨ�裬�ҵ���һ������temp��a[i]
		a[j] = a[i];
	}
	a[i] = temp;
	return i;
}
