# include <stdio.h>
int divorce(int m,int n)
{
	if(m==1||n==1)//���mƻ�� ���� n����ֻ��һ��ʱ����ôֻ��һ�ַַ�// 
	return 1;
	if(m<n)//���mƻ�� �� n�����٣���ô�͵ȼ���m��ƻ���ŵ�m��������ȥ// 
	return divorce(m,m);
	if(m>n)//���mƻ�� ������ n���ӣ���ô�������ַŷ���һ����ÿһ�����Ӷ���һ��ƻ����������û�п����ӣ�����������һ����������û��ƻ��// 
	return divorce(m-n,n)+divorce(m,n-1); 
	if(m=n)
	return divorce(m,n-1)+divorce(m,1);
}

int main()
{
	int m,n;//mƻ��������n��������// 
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		printf("%d\n",divorce(m,n));
	}
return 0;
}

