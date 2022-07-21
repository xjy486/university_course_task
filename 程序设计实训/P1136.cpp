# include<stdio.h>
# include<string.h>
# define N 100
char a[N],b[N];
int c[N],d[N],e[10000];
void fun(char *a,int *c)
{
    int j=strlen(a)-1;
    for(int i=0;a[i]!='\0';i++,j--)
    {
    	c[j]=a[i]-'0';
	}
}

void mult(int *c,int *d,int *e)
{
	for(int i=0;i<strlen(a);i++)
	    for(int j=0;j<strlen(b);j++)
	    {
	    	e[i+j]+=c[i]*d[j];
		}
	int len=strlen(a)+strlen(b)-1;
	for(int i=0;i<=len;i++)
		if(e[i]>=10)
		{
			e[i+1]+=e[i]/10;
			e[i]%=10;
		}
	while(e[len]==0)len--;
	for(int i=len;i>=0;i--)
	printf("%d",e[i]);
	printf("\n");
}
int main()
{
    while(scanf("%s %s",a,b)!=EOF)
	{
	    fun(a,c);
		fun(b,d);
	/*	for(int i=0;i<strlen(a);i++)
        printf("%d",c[i]);
        printf("\n");
        for(int i=0;i<strlen(b);i++)
         printf("%d",d[i]);*/
		mult(c,d,e);
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
	}	
	return 0;
}
/*
# include<stdio.h>
# include<string.h>
# define N 100
int main()
{
	char a[N],b[N];
	while(~scanf("%s%s",a,b))
	{
		int c[201]={0};
		int la,lb,i,j;
		la=strlen(a),lb=strlen(b);
		for(i=0;i<la;i++)
		for(j=0;j<lb;j++)
		c[i+j]+=(a[la-i-1]-'0')*(b[lb-j-1]-'0');
		int l=la+lb-1;
		for(i=0;i<l;i++)
		{	c[i+1]+=c[i]/10;
			c[i]%=10;
		}
		while(c[l]==0) l--;
		for(i=l;i>=0;i--) printf("%d",c[i]);
		printf("\n");
	}
	return 0;
}
*/
