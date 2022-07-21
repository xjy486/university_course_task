# include <stdio.h>
int main()
{
	int n,wage,price,m,i,j,a=200;
	while(~scanf("%d%d",&n,&m))
	{
		i=0;//年份 
		while(i<=20)
		{
			price=a+i*m;//房价 
			wage=n*i;//工资 
		    if(wage>=price) 
			break;
			i++;	
		}
		if(i<=20)
	    printf("%d\n",i);
	    if(i>20)
	    printf("Impossible\n");
	}
return 0;
}

