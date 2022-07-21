# include<stdio.h>
# define N 3000
int main()
{
	int a[N][N];
	int n,i,j;
    scanf("%d",&n);
	for(i=1;i<=N;i++)
	for(j=1;j<=i;j++)
	{
		if(j==1||j==i) a[i][j]=1;
		if(i>2)
		a[i][j]=a[i-1][j-1]+a[i-1][j];
		if(n==a[i][j])
		{
			printf("%d\n",i*(i-1)/2+j);
			return 0;
		}
	}

}
