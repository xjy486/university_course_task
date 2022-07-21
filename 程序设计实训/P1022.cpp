# include <stdio.h>
void fun(int n,int *M);//判断闰年，修改2月天数// 
int main()
{
	int year , month , day , n , i;
	int M[13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
	while (scanf ("%d" , &n) != EOF)
	{
		month=10,day=10,year=2007;
		for(i=1;i<=n;i++)
		{
			day+=1;
			if(M[month]+1==day)
			{
				day=1;
				month++;
			}
			if(month==13)
			{
				month=1;
				year++;
				fun(year,M);
			} 
		}
		printf("%d-%02d-%02d\n",year,month,day);
	}
    return 0;
}
void fun (int n , int  *M)
{
	if(n % 4 == 0 && n % 100 != 0 || n % 400  == 0)
	    *(M + 2) = 29;
	else
	    *(M + 2) = 28;  
}
