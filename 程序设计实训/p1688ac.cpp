#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	while(scanf("%d",&T)!=EOF) {
		while(T--) {
			int a,b,c,d,e,mins,maxs;
			int x1[10],x2[10],x3[10],x4[10],x5[10];
			int i,j,count1=0;
			int s1,s2,s3,s4,s5,sum1,sum2,sum3,sum4;
			scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
			for(i=0; i<a; i++) scanf("%d",&x1[i]);
			for(i=0; i<b; i++) scanf("%d",&x2[i]);
			for(i=0; i<c; i++) scanf("%d",&x3[i]);
			for(i=0; i<d; i++) scanf("%d",&x4[i]);
			for(i=0; i<e; i++) scanf("%d",&x5[i]);
			scanf("%d %d",&mins,&maxs);
			for(s4=0; s4<d; s4++) {
				for(i=s4; i<d; i++) {
					if(i==s4) sum1=x4[s4];
					else sum1=x4[s4]+x4[i];
					for(s5=0; s5<e; s5++) {
						for(j=s5; j<e; j++) {
							if(j==s5)sum2=x5[s5];
							else sum2=x5[s5]+x5[j];
							for(s2=0; s2<b; s2++) for(s1=0; s1<a; s1++) {
									sum3=x2[s2]+x1[s1];
									int sum=sum1+sum2+sum3;
									if(sum>=mins&&sum<=maxs) count1++;
								}
							for(s3=0; s3<c; s3++) {
								sum4=x3[s3];
								int sum=sum1+sum2+sum4;
								if(sum>=mins&&sum<=maxs) count1++;
							}
						}
					}
				}
			}
			printf("%d\n",count1);
		}
	}
	return 0;
}
