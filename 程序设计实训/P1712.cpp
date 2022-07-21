# include <stdio.h>
int main()
{
	int K,s,n;
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d",&n);
		s=1;
		while(n>s){
			n-=s;
			s++;
		}
		n%=9;
		if(n==0) n=9;
		printf("%d\n",n);
		
	}
    return 0;
}

