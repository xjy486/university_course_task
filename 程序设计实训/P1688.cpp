# include<stdio.h>
int soup[11],meal[11],noodle[11],meat[11],su[11];
int main()
{
	int i,n,a,b,c,d,e,min,max;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		for(int j=1;j<=a;j++)
		    scanf("%d",&soup[j]);
		for(int j=1;j<=b;j++)
		    scanf("%d",&meal[j]);
		for(int j=1;j<=c;j++)
		    scanf("%d",&noodle[j]);
		for(int j=1;j<=d;j++)
		    scanf("%d",&meat[j]);
		for(int j=1;j<=e;j++)
		    scanf("%d",&su[j]);
		scanf("%d%d",&min,&max);
		meat[0]=su[0]=0;
		int temp,count;
		count=0;
		for(int j=1;j<=d;j++)
		{
			temp=meat[j];printf("%10d\n",temp);
			for(int k=0;k<=d;k++)
			{
				if(meat[k]!=meat[j])
				temp+=meat[k];
				for(int p=1;p<=e;p++)
				{
					temp+=su[p];
					for(int q=0;q<=e;q++)///
					{
						if(su[q]!=su[p])
						temp+=su[q];printf("%3d\n",temp);
						
						int z=temp;
						for(int x=1;x<=a;x++)//good
						{
							z+=soup[x];
							for(int y=1;y<=b;y++)
							{
								z+=meal[y];
								if(min<=z&&z<=max)
								count++;
							}
						}
						z=temp;
						for(int x=1;x<=c;x++)//bad
						{
							z+=noodle[x];
							if(min<=z&&z<=max)
								count++;
						}
					}
				}
			}
		}
		printf("%d\n",count);
		
	}
	return 0;
}
