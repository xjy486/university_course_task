# include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[25]={0};
		a[1]=1;
		int i,j,r,t,k;
		i=1,t=0;
		while(a[1]<=9)
		{
			if(t==0&&i<n) i++;//�Ƿ������һλ�������ж� 
			for(j=1,r=0;j<=i;j++)
			{
				r=r*10+a[j];//ǰiλ��
				r%=i;//ǰiλ��neng����i ma?
			}
			if(r!=0)//ǰiλ����������i 
			{
				a[i]++;//+1���� 
				t=1;
				if(a[i]>9)//��iλ��0~9ȫ�����У�ֻ�ܻ��ݻص���һλ+1 
			{
				a[i]=0;
				i--;
				a[i]++;
			}
			}
			
			else t=0;//r=0˵����ʱ�����������Կ��ǽ�����һλ���� 
			
			
			
			if(i==n&&t==0)//���һ��ϸ���� 
			{
				for(k=1;k<=n;k++) printf("%d",a[k]);
				printf("\n");
				//getchar();
				//printf("%d\n",k);//
				a[i]++;
			}
		}
	}
return 0;
}

