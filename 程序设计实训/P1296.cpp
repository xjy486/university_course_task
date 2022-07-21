# include <stdio.h>
# include <math.h>
char map[3000][3000];
void dfs(int n, int x, int y){
	if(n==1)
	map[x][y]='X';
	else
	{
		int size=pow(3,n-2);
		dfs(n-1, x, y);//左上角 
		dfs(n-1, x, y+2*size);//右上角 
		dfs(n-1, x+2*size, y);//左下角 
		dfs(n-1, x+2*size, y+2*size);//右下角 
		dfs(n-1, x+size, y+size);//中间 
	}
}

int main()
{ 	
    int n,size,i,j;
    while(scanf("%d",&n)!=EOF)
    {
       if(n==-1)
	   break;
	   size=pow(3,n-1);
	   
	   for(i=1;i<=size;i++)
	   for(j=1;j<=size;j++)
	   map[i][j]=' ';
	   
	   dfs(n,1,1);
	   
	   for(i=1;i<=size;i++)
	   {
	   	 for(j=1;j<=size;j++)
	   	    printf("%c",map[i][j]);
	   	 printf("\n");   
	   }
	   printf("-\n");
	}

    return 0;
}

