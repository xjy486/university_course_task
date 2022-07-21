# include <stdio.h>
int main()
{
	long long n;
	int h,m,s,hour;
	while(scanf("%lld",&n)!=EOF)
	{
		n/=1000;
		h=n/3600%24;
		m=n%3600/60;
		s=n%3600%60;
		printf("%02d:%02d:%02d\n",h,m,s);
	} 
return 0;
}
