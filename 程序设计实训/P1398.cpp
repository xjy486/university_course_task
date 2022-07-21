# include <stdio.h>
# define N 500
int a[N][N];
void fun(int n);
int main()
{
	int n;
	
	while(~scanf("%d",&n))
	{
		fun(n);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			printf("%d ", a[i][j]);
			printf("\n");
		}
	}
return 0;
}



void fun(int n)
{
	int i,j;
	for(i=1; i<=n; i++)
	{
		if(i%2==0) a[i][1] = i*i;
		else if(i%2==1) a[1][i] = i*i;
	}
	
	for(i=2; i<=n; i++)
	{
		if(i%2==0)
		{
			for(j=2; j<=i; j++)
			a[i][j]=a[i][1]-(j-1);
			for(j=i-1; j>=1; j--)
			a[j][i]=a[j+1][i]-1;
		}
		if(i%2==1)
		{
			for(j=2; j<=i; j++)
			a[j][i]=a[1][i]-(j-1);
			for(j=i-1; j>=1; j--)
			a[i][j]=a[i][j+1]-1;
		}
	}
}
