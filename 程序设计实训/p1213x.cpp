# include <stdio.h>
int fun(int m,int k)
{
	int j,count;
	for(j=1,count=0;j<=k;j++)
	{
		if(m%j==0) count++;
	}
	if(count%2==1) return 0;
	if(count%2==0) return 1;
}
int main()
{
	int m,k;
	while(~scanf("%d%d",&m,&k))
	{
		int i;
		for(i=1;i<=m;i++)
		{
			if(fun(i,k)) printf("%d ",i);
		}
		printf("\n");
	}
return 0;
}

