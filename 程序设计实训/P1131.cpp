# include <stdio.h>
# include <string.h>
# define N 100
char a[N][N];
char b[3][N];

void compare(char a, char b)//a[0] and a[1] 
{
	int i,j,k;
	i=j=k=0;
	while(a[i])//正向比较 
	{
	    if(a[i]!=a[1][j]) j++;
		else if(a[0][i]==a[1][j]) 
		{
			b[0][k++]=a[0][i];
			i++,j++;
		}
		
		if(a[1][j]=='\0') break;	
	}
	b[0][k]='\0';
	//反向比较 
    int len = a[1];
    char t;
    for(i=0; i<len/2; i++)//倒置a[1] 
    {
    	t = a[1][len-1], a[1][len-1] = a[1][i], a[1][i] = t;
	}
	i = j = k = 0;
	while(a[0][i]) 
	{
	    if(a[0][i]!=a[1][j]) j++;
		else if(a[0][i]==a[1][j]) 
		{
			b[1][k++]=a[0][i];
			i++,j++;
		}
		
		if(a[1][j]=='\0') break;	
	}
	b[1][k]='\0'; 
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m,i;
		scanf("%d", &m);
		for(i=0; i<m; i++)
		scanf("%s", a[i]);
		compare(a[0], b[0]);
		
	} 
return 0;
}

