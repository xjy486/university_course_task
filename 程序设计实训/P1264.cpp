# include <stdio.h>
# include <string.h>
# include <math.h>
# define N 100
int shift(int p,char *a)
{
	int b[N];
	int i,j,k,sum;
	i=j=sum=0;
	while(a[i])
	{
		if(a[i]>='0'&&a[i]<='9');
		b[i]=a[i]-'0';
		if(a[i]>='A'&&a[i]<='F')
		b[i]=a[i]-'A'+10;
		i++;
	}
	for(j=i-1,k=0;j>=0;j--,k++)
		sum+=b[j]*pow(p,k);

	return sum;
}

void change(int q,int m,char *c)
{
	int n,i;
	i=0;
	while(m!=0)
	{
	    n=m%q;
		if(n>=10)
			c[i++]=n+55;
		if(n<10)
		    c[i++]=n+48;
		m/=q;	
	 }
	 int len=strlen(c);
		    for(int j=len-1; j>=0; j--)
		    printf("%c",c[j]);
		    printf("\n"); 
	
}

int main()
{
	int p,q,m;
	char a[N];
	while(~scanf("%d %d %s",&p,&q,a))
	{
		
		if(p==0&&q==0&&a[0]=='0') return 0;
		else 
		{
			int b[N];char c[N];
		    m=shift(p,a);//将a转换成十进制数// 
		    change(q,m,c);
		    
		}
	}
return 0;
}

