# include <stdio.h>
#  define N 1000
int main()
{
	int n,m,i,out,count,a[N]={0};
	while(scanf("%d %d",&n,&m)!=EOF){
		for(i=1;i<=n;i++)
		    a[i]=i;
		i=1;
		out=count=0;    
		while(out<n){
			if(a[i]!=0)
				count++;
			if(count==m)
			{
				a[i]=0;
				printf("%d ",i);
				count=0;
				out++;
			}
			i++;
			if(i==n+1)
			    i=1;	
		}
		printf("\n"); 
  
	}
return 0;
}
//给每一个人按顺序标号，然后计数，到特定数字时对应的人被踢出，标号改为0。每次计数只计数标号不为0的人。
//当标号走完时，再从头开始，直到所以人淘汰为止，即out==n 
