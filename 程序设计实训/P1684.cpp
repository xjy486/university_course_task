# include <stdio.h>
int main()
{
	int n,i,p,q,j,t,s;
	scanf("%d",&n);
	for(i=0,t=0,s=0;i<n;i++)
	{
		scanf("%d%d",&p,&q);
		for(j=1;j<p;j++)
		    if(p%j==0)
		        t+=j;
		for(j=1;j<q;j++)
		    if(q%j==0)
		        s+=j;
	    if(s==p&&t==q)
	    printf("Yes\n");
	    else
	    printf("No\n");
	}
}
