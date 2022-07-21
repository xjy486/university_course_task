# include <stdio.h>
# define N 1000
int a[N];
int main()
{
	int m,n,i,t,count;
	while(~scanf("%d%d",&m,&n))
	{
		for(i=0;i<=m;i++) a[i]=1;
		count=0,t=0,i=1;
		while(count<m)
		{
			if(i==m+1) i=1;
		    if(a[i]==1)
		    {
		    	t++;
			}
			if(t==n)
			{
				a[i]=0;
				t=0;
				count++;
				
			}
			i++;
			
		}
		printf("%d\n",i-1);
	}
return 0;
}

