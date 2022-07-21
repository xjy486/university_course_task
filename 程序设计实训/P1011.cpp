# include <stdio.h>
# define N 8
int fun(int a,int b[]){
	int i;
	for(i=0;a!=0;i++){
		b[i]=a%2;
		a=a/2;
	}
	return i;
}
int main()
{
	int i,n,b[N],k,a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		b[N]={0};
		scanf("%d",&a);
		k=fun(a,b);
		for(k=k-1;k>=0;k--)
		printf("%d",b[k]);
		printf("\n");
		
	} 
return 0;
}

