# include <stdio.h>
# include <string.h>
# define N 100
char a[N][N],b[N][N];
int c[N],d[N]; 
int main()
	int n,i,k,t;
	char temp[N];
	while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++){
		scanf("%d",&d[i]);
		scanf("%s",a[i]);
		scanf("%d",&c[i]);
		scanf("%s",b[i]); 
		}
	for(i=0;i<n;i++)
    {
    	if(strcmp("China",a[i])==0)
    	{
    		strcpy(temp,a[i]);
			strcpy(a[i],a[n-1]);
			strcpy(a[n-1],temp);
			strcpy(temp,b[i]);
			strcpy(b[i],b[n-1]);
			strcpy(b[n-1],temp);
			t=c[i];
			c[i]=c[n-1];
			c[n-1]=t;
		    t=d[i];
			d[i]=d[n-1];
		    d[n-1]=t;
		    break;
		}
	}
    for(i=0;i<n-1;i++)
        for(k=0;k<n-2-i;k++)
        {
             if(strcmp(a[k],a[k+1])>0)
			 {
			     strcpy(temp,a[k]);
			     strcpy(a[k],a[k+1]);
			     strcpy(a[k+1],temp);
			     strcpy(temp,b[k]);
			     strcpy(b[k],b[k+1]);
			     strcpy(b[k+1],temp);
			     t=c[k];
			     c[k]=c[k+1];
			     c[k+1]=t;
			     t=d[k];
			     d[k]=d[k+1];
			     d[k+1]=t;
			 }
		 }    
	for(i=0;i<n;i++)
	{
		printf("%d %s %d %s",d[i],a[i],c[i],b[i]);
	printf("\n");
	}
}
return 0;
}

