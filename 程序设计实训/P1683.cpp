# include <stdio.h>
# include <math.h>
int fun(int n)
{
	int i,count;
	for(count=0,i=1;i<=n;i++)
	{
		if(n%i==0)
		count++;
	}
	if(count%2==0)
	return 0;
	else if(count%2==1)
	return 1;
}
int main()
{
    int n;
	while(scanf("%d", &n)!=EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			if(fun(i))
			{
				printf("%d",i);
			printf(" ");
			}
		}
		printf("\n");
		
	}
return 0;	
}
