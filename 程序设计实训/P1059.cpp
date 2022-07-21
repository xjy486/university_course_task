# include <stdio.h>
# define N 1005

int a[N][N]; //为什么把a[N][N]放在main函数内部就不对呢？// 
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF){

		for(i=1;i<=n;i++)
		    for(j=1;j<=i;j++)
		      	scanf("%d",&a[i][j]);
		      	
	    for(i=n-1;i>=1;i--)
	        for(j=1;j<=i;j++)
	        {
	        	if(a[i+1][j]<a[i+1][j+1])
	        	    a[i][j]+=a[i+1][j];
	        	else
	        	    a[i][j]+=a[i+1][j+1];
			}
			
		printf("%d\n",a[1][1]);	
	}
	return 0;
}
