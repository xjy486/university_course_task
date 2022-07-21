# include<stdio.h>
int main()
{
	long long a[51];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		a[1]=3;
		a[2]=9;
		a[3]=21;
		for(int i=4;i<=n;i++)
		{
			a[i]=a[i-1]*2+a[i-2];
		}
		printf("%lld\n",a[n]);
	}
	return 0;
}
