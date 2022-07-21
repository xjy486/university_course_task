# include <stdio.h>
# include <string.h> 
# define N 100000
char a[N],b[N]; 
int main()
{
	while(scanf("%s %s",a,b)!=EOF){
		int i,j,m,n;
		i=0;j=0;
		m=strlen(a);n=strlen(b);
		a[m+1]='\0',b[n+1]='\0';
		while(a[i]!='\0')
		{
			
			while(a[i]!=b[j])
			{
				
		    	j++;
		    	if(b[j]=='\0')
				{ 
				  break;
				  break;
				}
			}
		    
			i++;
		}
		
	
		if(a[i]=='\0'&&b[j]!='\0')
		printf("Yes\n");
		else if(a[i]!='\0'||b[j]=='\0')
		printf("No\n");
	}
return 0;
}

