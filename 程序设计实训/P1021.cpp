# include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		n=n%7;
		if(n==0)
		    printf("7\n");
		else
		    printf("%d\n",n); 
	}
return 0;
}
char a[20][100];
char b[21][100],c[100];
