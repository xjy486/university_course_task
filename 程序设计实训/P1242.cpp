# include <stdio.h>
# define N 5000
void min(int *a,int n){
	int t;
	for(int i=0; i<n; i++)
	for(int j=i; j<n; j++)
			if(a[i]>a[j])
					t=a[j],a[j]=a[i],a[i]=t;

}

int main()
{
	int j,i,n,t,a[N];
	while(~scanf("%d%d",&n,&t))
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		min(a,n);
		j=0;
		while(t>=0)
		{
		   	t-=a[j];
		    j++;
		    if(j==n) break;
		}
		 
		printf("%d\n",j-1);
	}
return 0;
}
/*
6 10
1 5 3 2 4 6
*/

