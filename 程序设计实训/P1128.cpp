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
//��ÿһ���˰�˳���ţ�Ȼ����������ض�����ʱ��Ӧ���˱��߳�����Ÿ�Ϊ0��ÿ�μ���ֻ������Ų�Ϊ0���ˡ�
//���������ʱ���ٴ�ͷ��ʼ��ֱ����������̭Ϊֹ����out==n 
