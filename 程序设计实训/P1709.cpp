# include <stdio.h>
int main()
{
	long long n;
	int h,m,s,hour;
	while(scanf("%lld",&n)!=EOF)
	{
		n/=1000;
		h=n/3600;
		m=n%3600/60;
		s=n%3600%60;
		hour=0;
		while(h>0)
		{
			hour++;
			if(hour==24)
			  hour=0;
			h--;
		}
		printf("%02d:%02d:%02d\n",hour,m,s);
	} 
return 0;
}


