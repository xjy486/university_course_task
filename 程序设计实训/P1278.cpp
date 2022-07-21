# include <stdio.h>
# define N 120
int a[N][N];
int main()
{
	int n,i,j;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				 
				 if(j==0) a[i][j]=i+1;
				 if(j%2==1) a[i][j]=a[i][j-1]+(2*n-2*i-1);
				 if(j%2==0&&j!=0) a[i][j]=a[i][j-1]+2*i+1;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
			printf("\n");
		
		}	printf("\n");
	 } 
return 0;
}



