# include<stdio.h>
int main()
{
	int n,m,t;
	while(~scanf("%d/%d%d",&m,&n,&t))
	{
	    printf("%d.",m/n);
	    m%=n;
	    while(t--&&m)
	    {
	    	m*=10;
	    	printf("%d",m/n);
	    	m%=n;
		}
		printf("\n");
	}
	return 0;
}
