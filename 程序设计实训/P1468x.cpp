# include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[25]={0};
		a[1]=1;
		int i,j,r,t,k;
		i=1,t=0;
		while(a[1]<=9)
		{
			if(t==0&&i<n) i++;//是否进行下一位的条件判断 
			for(j=1,r=0;j<=i;j++)
			{
				r=r*10+a[j];//前i位数
				r%=i;//前i位数neng整除i ma?
			}
			if(r!=0)//前i位数不能整除i 
			{
				a[i]++;//+1再来 
				t=1;
				if(a[i]>9)//第i位从0~9全部不行，只能回溯回到上一位+1 
			{
				a[i]=0;
				i--;
				a[i]++;
			}
			}
			
			else t=0;//r=0说明此时满足条件可以考虑进行下一位数字 
			
			
			
			if(i==n&&t==0)//输出一组合格情况 
			{
				for(k=1;k<=n;k++) printf("%d",a[k]);
				printf("\n");
				//getchar();
				//printf("%d\n",k);//
				a[i]++;
			}
		}
	}
return 0;
}

