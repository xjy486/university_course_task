# include <stdio.h>
# include <string.h>
# define N 200
int b[2][N]={0};
int main()
{
	char a[2][N];
	int len[2],i,j,k;
	while(scanf("%s %s",a[0],a[1])!=EOF){
		len[0]=strlen(a[0]),len[1]=strlen(a[1]);
		for(i=0;i<=1;i++)
		    for(j=len[i]-1,k=0;j>=0;j--)
		    	b[i][k++]=a[i][j]-'0';
	    
	    for(i=0;i<len[0];i++)
	    {
	    	b[0][i]=b[0][i]-b[1][i];
		}
		for(i=0;i<len[0]-1;i++){
			if(b[0][i]<0)
			{
				b[0][i]+=10;
				b[0][i+1]-=1;
			}
		}
		while(b[0][i]==0){
			i--;
		}
		for(;i>=0;i--)
		    printf("%d",b[0][i]);
		printf("\n");
	}
return 0;
}

/*
#include<stdio.h>
#include<string.h>
	int main(){
		char a[201],b[201];
		int la,lb,l,i,p,c[201];
		while(~scanf("%s%s",a,b)){
			la=strlen(a);lb=strlen(b);
			p=0;
			memset(c,0,201);
			for(i=1;i<=la;i++)
			{
				c[i]+=a[la-i]-'0';
				if(i<=lb) c[i]-=b[lb-i]-'0';
				if(c[i]<0)
				{
					c[i]+=10;
					c[i+1]-=1;
				}
			}
			for(i=la;i>=1&&c[i]==0;i--);
			for(;i>=1;i--) printf("%d",c[i]);
			printf("\n");
	
	}
		return 0;
}
*/ 

