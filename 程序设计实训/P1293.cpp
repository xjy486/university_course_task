# include <stdio.h>
int divorce(int m,int n)
{
	if(m==1||n==1)//如果m苹果 或者 n盘子只有一个时，那么只有一种分法// 
	return 1;
	if(m<n)//如果m苹果 比 n盘子少，那么就等价于m个苹果放到m个盘子里去// 
	return divorce(m,m);
	if(m>n)//如果m苹果 不少于 n盘子，那么就有两种放法。一是先每一个盘子都放一个苹果，这样就没有空盘子，二是至少有一个盘子盘子没有苹果// 
	return divorce(m-n,n)+divorce(m,n-1); 
	if(m=n)
	return divorce(m,n-1)+divorce(m,1);
}

int main()
{
	int m,n;//m苹果数量，n盘子数量// 
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		printf("%d\n",divorce(m,n));
	}
return 0;
}

