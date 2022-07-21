# include <stdio.h>
# include <math.h>
int fun(int p,int t) 
{
	int m,count;
	m=count=0;
	while(p)
	{
		m+=(p%10)*pow(t,count);
		p/=10;
		count++;
	}
	return m;
}
int funny(int p,int q,int r)//È·¶¨t 
{
	int max1,max2,max3,max;
	max=max1=max2=max3=-1;
	while(p)
	{
		if(max1<p%10) max1=p%10;
		p/=10;
	}
	while(q)
	{
		if(max2<q%10) max2=q%10;
		q/=10;
	}
	while(r)
	{
		if(max3<r%10) max3=r%10;
		r/=10;
	}
	if(max1>max2) max=max1; else max=max2;
	if(max<max3) max=max3;
	return max+1;
	
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int p,q,r,t,k;
		int p1,q1,r1;
		scanf("%d%d%d",&p,&q,&r);
		t=funny(p,q,r);
		k=0;
        while(t<=16&&k==0)
		{
			p1=fun(p,t);
			q1=fun(q,t);
			r1=fun(r,t);
			if(r1==p1*q1) k=1;
			else t++;
	    }
	    if(k==1) printf("%d\n",t);
	    else printf("0\n");
	}
return 0;
}

