# include <stdio.h>
# define N 1001
int a[N]; 
int main()//����������һģһ��// 
{
	int n,k,i,j,m;
	while(~scanf("%d%d",&n,&k))
	{   for(i=1;i<=N;i++) a[i]=-1;
		i=1;//�˵ı��
		m=-1; 
		while(i<=k)
		{
			for(j=1;j<=n;j++)//j�ǵ��� 
				if(j%i==0) 
					a[j]=a[j]*m; 
		/*	for(j=1;j<=n;j++)
			printf("%d ",a[j]);
			printf("\n");*/
			i++;
		}
	
		for(j=1;j<=n;j++)
		if(a[j]==-1) printf("%d ",j);
		printf("\n");
	}
return 0;
}

