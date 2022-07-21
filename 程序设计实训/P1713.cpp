# include <stdio.h>
# include <math.h>
# define N 10000
int x[N],y[N];
void sort(int *x,int n)
{
	int i,j,t;
	for(i=1;i<=n;i++)
	for(j=i;j<=n;j++)
	if(x[i]>x[j]) t=x[i],x[i]=x[j],x[j]=t;
}

int step(int *x,int n,int x0)
{
     int i,s;
	 for(i=1,s=0;i<=n;i++)
	 s+=abs(x[i]-x0);
	 return s;
} 

int main()
{
	int n,sy,sx;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		    scanf("%d%d",&x[i],&y[i]);
		
		sort(y,n);//ÅÅy 
		int y0=y[(n+1)/2]; 
		sy=step(y,n,y0);
		sort(x,n);
		for(int i=1;i<=n;i++)//ÅÅx 
		x[i]=x[i]-i+1; 
		int x0=x[(n+1)/2];
		sx=step(x,n,x0);
		
		printf("%d\n",sx+sy);
		//printf("%d %d\n",x0,y0);
	}
return 0;
}

