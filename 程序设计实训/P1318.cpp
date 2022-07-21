# include <stdio.h>
# define N 10
int a[N]={0};
int main()
{
	int n,i=0;
	while(scanf("%d",&n)!=EOF){
		while(i<=n){
			if(i==1)
			    a[i]=1;
			if(i==2)
			    a[i]=2;
			if(i>=3)
			    a[i]=a[i-1]+a[i-2];
			i++;
		}
		printf("%d\n",a[n]);
	} 
return 0;
}

