# include <stdio.h>
# include <string.h>
# define N 60000 
void shift(char *a, int *beichu, int *chu)
{
	int i,m,k,j;
	i=0,m=1,j=k=1;
	while(a[i])
	{
	    
		if(m==1)
			beichu[k++] = a[i]-'0';
		else if(m==2)
		    chu[j++] = a[i]-'0';
		i++;
		if(a[i]=='/')
		    m =2, i++;	
	}
	chu[0] = j-1; beichu[0] = k-1;
}



void chufa(int *beichu, int chushu,int n,int *result)
{
	int i,m,x;
	m=beichu[0]+n;
	for(i=1,x=0; i<=100; i++)//°´Î»Ïà³ý// 
	{
		result[i] = (x*10+beichu[i])/chushu;
		x=(x*10+beichu[i])%chushu;
	}
}


int main()
{
	char a[N];
	int chu[N] = {0};
	int beichu[N] = {0};
	int result[N] = {0};
	int n,chushu,beichushu;
	while(~scanf("%s", a))
	{
		scanf("%d", &n);
		shift(a, beichu, chu);
	    beichushu=chushu=0;
	    /*for(int i=1; i<= beichu[0]; i++)
	    printf("%d", beichu[i]);
	    printf("\n");*/
	    for(int i=1; i<= chu[0]; i++)
             chushu*=10, chushu+=chu[i];
	    for(int i=1; i<= beichu[0]; i++)
             beichushu*=10, beichushu+=beichu[i];
	    chufa(beichu,chushu,n,result);
	    
	    if(beichushu>chushu&&beichushu%chushu!=0)
	    {
	    	int m=beichushu/chushu;
	    	int count,i;
	    	count=0,i=1;
	    	while(m)
	    	{
	    		m/=10;
				count++; 
			}
			while(result[i]==0) i++;
			count+=i-1;
			for(;i<=count;i++)
			printf("%d",result[i]);
			printf(".");
			for(;i<=n;i++)
			printf("%d",result[i]);
			printf("\n");
		}
		else if(beichushu>chushu&&beichushu%chushu==0) printf("%d\n",beichushu/chushu);
		
		if(chushu>beichushu)
		{ 
		    int k;
			printf("0.");
			for(k=1;k<=n;k++) printf("%d",result[k]); printf("%d\n");
			
		} 
	    
		
	}
return 0;
}

