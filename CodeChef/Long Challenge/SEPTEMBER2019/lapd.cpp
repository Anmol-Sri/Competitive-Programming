#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h> 
#define MOD 1000000007 
using namespace std; 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		long long int ans=0,flag=1,count=0;
		if(A<B && C<B)
			flag=0;
		/*for(int b=1;b<=B;b++){
			long long int k=0;
			for(int a=1;a<=A;a++){
				for(int c=1;c<=C;c++){
					if(a>b && c>b){
						ans=(ans+((A-a+1)%MOD*(C-c+1)%MOD)%MOD)%MOD;
					}
					count++;
					b=b%MOD;
					long long int tb,ta,tc;
					tb=(b*b)%MOD;
					ta=(a-1)%MOD;
					tc=(c-1)%MOD;
					if((tb-(ta*tc))%MOD<0){
						ans=ans+(C-c)+1;
						ans=ans%MOD;
						break;
					}
				}
			}
		}*/
		int a,b,c;
		for(b=1;b<=B;b++){
			for(a=1;a<=A;a++){
				c=(((int)(((b*b)%MOD)/(a-1)))%MOD+2);
				if(c<C){
					ans=(ans+((C-c+1)*(A-a+1))%MOD)%MOD;
					break;
				}
			}
		}
		printf("%lld\n",ans%MOD);
	}
	return 0;
}