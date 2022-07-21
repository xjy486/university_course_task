# include <stdio.h>
# include <string.h>
# include <math.h>
# define N 100
int fun(int n)
{
	if((n%1000)/100==1)
	 return 1;
	else 
	 return 0;
}
int main()
{
	char a[N];
	int b[10];
	while(scanf("%s",a)!=EOF)
	{
		int n=strlen(a);
		int j=0;
		for(int i=1;i*7371<pow(10,n);i++)
		{
			if(fun(i*7371))
			{
				j++;
				b[j]=i*7371;
			}
			if(j==2)//不加入这个提前中止所有大于2的情况的话，那么如果n的位数过大，会超出，可以把这行代码删除再编译试一试// 
			break;
		}
		if(j==1)
		printf("%d\n",b[j]);
		if(j>1||j<1)
		printf("wrong\n");
	} 
return 0;
}

