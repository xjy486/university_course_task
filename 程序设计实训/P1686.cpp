# include<stdio.h>
int f(int n)
{
	int i;
	if(n==1) return 2;
	if(n==2) return 4;
	if(n>2) return f(n-1)+2*(n-1);
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int sum;
		sum=f(n);
		printf("%d\n",sum);
	}
}
