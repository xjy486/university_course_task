# include<stdio.h>
# include<string.h>
# define N 201
void fun(char *a,int *a1)
{
	int s=strlen(a);
	int i,j;
	a1[0]=s;
	for(i=1,j=s-1;j>=0;j--,i++)
	a1[i]=a[j]-'0';
 } 
void fun1(int *a1,int *b1,int *sum)
{
	int s,i;
	if(a1[0]>b1[0]) s=a1[0]; else s=b1[0];
	for(i=1;i<=s;i++)
	{
		sum[i]=sum[i]+a1[i]+b1[i];
		sum[i+1]+=sum[i]/10;
		sum[i]%=10;
	}
	if(sum[i]!=0)
	sum[0]=i;
	else
	sum[0]=i-1;
}
int main()
{
	char a[N],b[N];
	while(scanf("%s%s",a,b)!=EOF)
	{
		int a1[N],b1[N],sum[N];
		memset(a1,0,N);
		memset(sum,0,N);
		memset(b1,0,N);
		fun(a,a1); fun(b,b1);

		fun1(a1,b1,sum);
		
		for(int i=sum[0];i>=1;i--) printf("%d",sum[i]);
		
		printf("\n");
	}
	return 0;
}
/*
# include<stdio.h>
# include<string.h>
# define N 201
int main()
{
	char a[N],b[N];
	while(scanf("%s%s",a,b)!=EOF)
	{
		int sum[N]={0};
		int la,lb,l,p,i;
		p=0;
		la=strlen(a),lb=strlen(b);
		la>lb? l=la:l=lb;
		for(i=0;i<=l;i++) //为什么这里i<=l会带上=号// 
		{
		    if(i<la) p+=a[la-i-1]-'0';
		    if(i<lb) p+=b[lb-i-1]-'0';
		    sum[i]+=p%10;
		    p/=10;
		}
		for(i=l;i>=0&&sum[i]==0;i--);
		for(;i>=0;i--) printf("%d",sum[i]);
		printf("\n");
	}
	return 0;
}
*/
