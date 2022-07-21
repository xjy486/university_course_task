	#include<stdio.h> 
	int main() 
	{ 
	   int a[100]; 
	   int n; 
	   while(scanf("%d",&n)!=EOF) 
	{   
	    int i=1,t=0,r,j,s=0; 
	    for(j=1; j<=100; j++) a[j]=0; 
	     a[1]=1; 
	    while(a[1]<=9) 
	   { 
	      if(t==0&&i<n) i++; 
	      for(r=0,j=1; j<=i; j++) 
	      { 
		    r=r*10+a[j]; 
		    r=r%i; 
		  } 
	
	      if(r!=0) 
	    { 
		  a[i]++; t=1; 
	      if(a[i]>9&&i>1) 
	      { a[i]=0; i--; 
		    a[i]++; 
		  } 
		} 
	    else t=0; 
		if(t==0&&i==n) 
	   { 
	      for(j=1; j<=n; j++) 
		  printf("%d",a[j]); 
	      printf("\n"); a[i]++; 
	   } 
	} 
	  } 
	return 0; 
	} 
