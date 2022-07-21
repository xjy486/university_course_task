# include <stdio.h>
# define N 1337 
int fun(int x,long long n)
{
	long long ans;
	if(n==0) ans=1;
	else
	{
		ans=fun(x,n/2);
		ans=ans*ans%N;
		if(n%2==1) ans=ans*x%N; 
	}
	return ans;
}
int main()
{
	int x;
	long long n;
	while(~scanf("%d%lld",&x,&n))
	{
		printf("%d\n",fun(x,n));
	}
    return 0;
}

