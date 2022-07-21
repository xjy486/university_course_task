# include<stdio.h>
int main()
{
	int i;
	double n,M,p;
	while(scanf("%lf",&M)!=EOF){
		n=0.0171/12;
		p=0;
		for(i=1; i<=48; i++)
		{
			p=(p+M)/(1+n);
			
		}
	    printf("%.2f\n",p);
	}
	return 0;
}
