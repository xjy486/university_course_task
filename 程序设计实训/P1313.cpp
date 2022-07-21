# include <stdio.h>
# include <string.h>
int main()
{
	char a[1000];
	while(gets(a)){
		int i,count;
		i=count=0;
		while(a[i])
		{
			if(a[i]!=' '&&a[i+1]==' ')
			count++;
			i++;
		}
		printf("%d\n",count+1);
	}
return 0;
}

