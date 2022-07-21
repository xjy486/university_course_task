# include <stdio.h>
int fun(int m,int n){
	int q;
	do{
		q=m%n;
		m=n;
		n=q;
	}while(q!=0);
	if(m==1)
	    return 0;
	else
	    return m;    
}
int main()
{
	int a,b,c,d,m,n,q;
	while(scanf("%d",&a)!=EOF){
		scanf("%d%d%d",&b,&c,&d);
		m=(a*d+b*c),n=b*d;
		q=fun(m,n);
		if(q!=1){
			m=m/q,n=n/q;
			printf("%d/%d\n",m,n);
		}
		else
		    printf("%d/%d\n",m,n);
	}
return 0;
}

