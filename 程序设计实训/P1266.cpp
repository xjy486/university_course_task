/*# include <stdio.h>
# include <string.h>
# include <math.h>
# define N 201 
char a[N];
int main()
{
	int i,m,t,sum;
	while(scanf("%s",a)!=EOF)
	{
		int b[N]={0}; 
		i=0,m=1,sum=t=0;
		while(a[i])
		{
			if(a[i]=='+')
			{
				t++;
				m=0; 
			}
			
			else if(m==1)
			{
				b[t]*=10;
				b[t]+=a[i]-'0';

			}
			i++;
			if(m==0)
			{
				m=1;
				
			}

		}
		for(int j=0; j<=t; j++)
			sum+=b[j];
		printf("%d\n",sum);
	}
    return 0;
}
*/
# include<stdio.h>
# define N 200
int main()
{
    char a[N];
    while(scanf("%s",a)!=EOF)
    {
    	int i,m,sum;
    	i=sum=m=0;
    	while(a[i])
    	{
    		if(a[i]!='+')
    		{
    			m*=10;
    			m+=a[i]-'0';
			}
			if(a[i]=='+')
			{
				sum+=m;
				m=0;
			}
			i++;
		}
		sum+=m;
		printf("%d\n",sum);
	}
	return 0;
}

