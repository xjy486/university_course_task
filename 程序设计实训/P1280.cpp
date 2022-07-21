# include <stdio.h>
# include <string.h>
# define N 200 
char a[N];
void fun(char *a,int n);
int main()
{

	while(scanf("%s",&a)!=EOF)
	{
		int n=strlen(a);
		for(int i=0;i<n;i++)
		{
			fun(a,i);
			if(i<n-1) printf("===");
			if(i==n-1) printf("\n"); 
		}
	 } 
return 0;
}

void fun(char *a,int n)
{
	if(a[n]=='A')
	printf(".-");
	if(a[n]=='B')
	printf("-...");
	if(a[n]=='C')
	printf("-.-.");
	if(a[n]=='D')
	printf("-..");
	if(a[n]=='E')
	printf(".");
	if(a[n]=='F')
	printf("..-.");
	if(a[n]=='G')
	printf("--.");
	if(a[n]=='H')
	printf("....");
	if(a[n]=='I')
	printf("..");
	if(a[n]=='J')
	printf(".---");
	if(a[n]=='K')
	printf("-.-");
	if(a[n]=='L')
	printf(".-..");
	if(a[n]=='M')
	printf("--");
	if(a[n]=='N')
	printf("-.");
	if(a[n]=='O')
	printf("---");
	if(a[n]=='P')
	printf(".--.");
	if(a[n]=='Q')
	printf("--.-");
	if(a[n]=='R')
	printf(".-.");
	if(a[n]=='S')
	printf("...");
	if(a[n]=='T')
	printf("-");
	if(a[n]=='U')
	printf("..-");
	if(a[n]=='V')
	printf("...-");
	if(a[n]=='W')
	printf(".--");
	if(a[n]=='X')
	printf("-..-");
	if(a[n]=='Y')
	printf("-.--");
	if(a[n]=='Z')
	printf("--..");

	if(a[n]=='0')
	printf(".----");
	if(a[n]=='1')
	printf("..---");
	if(a[n]=='2')
	printf("...--");
	if(a[n]=='3')
	printf("....-");
	if(a[n]=='4')
	printf(".....");
	if(a[n]=='5')
	printf("-....");
	if(a[n]=='6')
	printf("--...");
	if(a[n]=='7')
	printf("---..");
	if(a[n]=='8')
	printf("----.");
	if(a[n]=='9')
	printf("-----");
}
