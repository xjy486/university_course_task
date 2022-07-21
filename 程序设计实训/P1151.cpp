# include <stdio.h>
# include <string.h>
char a[20][100]={{"0"},{"pop"},{"no"},{"zip"},{"zotz"},{"tzec"},{"xul"},{"yoxkin"},{"mol"},{"chen"},{"yax"},{"zac"},{"ceh"},{"mac"},{"kankin"},{"muan"},{"pax"},{"koyab"},{"cumhu"},{"uayet"}};
char b[21][100],c[100];
int fun(char *c)
{
	if(strcmp(c,"pop") == 0) return 1; 
	if(strcmp(c,"no") == 0) return 2;
	if(strcmp(c,"zip") == 0) return 3;
	if(strcmp(c,"zotz") == 0) return 4;
	if(strcmp(c,"tzec") == 0) return 5;
	if(strcmp(c,"xul") == 0) return 6;
	if(strcmp(c,"yoxkin") == 0) return 7;
	if(strcmp(c,"mol") == 0) return 8;
	if(strcmp(c,"chen") == 0) return 9;
	if(strcmp(c,"yax") == 0) return 10;
	if(strcmp(c,"zac") == 0) return 11;
	if(strcmp(c,"ceh") == 0) return 12;
	if(strcmp(c,"mac") == 0) return 13;
	if(strcmp(c,"kankin") == 0) return 14;
	if(strcmp(c,"muan") == 0) return 15; 
	if(strcmp(c,"pax") == 0) return 16;
	if(strcmp(c,"koyab") == 0) return 17;
	if(strcmp(c,"cumhu") == 0) return 18;
	if(strcmp(c,"uayet") == 0) return 19;
}
void bu(int m)
{
	if(m==1) printf("imix");
	if(m==2) printf("ik");
	if(m==3) printf("akbal");
	if(m==4) printf("kan");
	if(m==5) printf("chicchan");
	if(m==6) printf("cimi");
	if(m==7) printf("manik");
	if(m==8) printf("lamat");
	if(m==9) printf("muluk");
	if(m==10) printf("ok");
	if(m==11) printf("chuen");
	if(m==12) printf("eb");
	if(m==13) printf("ben");
	if(m==14) printf("ix");
	if(m==15) printf("mem");
	if(m==16) printf("cib");
	if(m==17) printf("caban");
	if(m==18) printf("eznab");
	if(m==19) printf("canac");
	if(m==20) printf("ahau");
}
int main()
{   
	int n,day,year,j,sum;
	scanf("%d",&n); 
	while(n--)
	{   sum=0;
		scanf("%d%s%d",&day,c,&year);
		j=fun(c);
		//printf("%d\n",j);//
		sum=year*365+(j-1)*20+day+1;
		int year1=sum/260;
		int month1=sum%260%13;
		int day1=sum%260%20;
		printf("%d ",month1);
		bu(day1);
		printf(" %d\n",year1);
		
	}
return 0;
}

