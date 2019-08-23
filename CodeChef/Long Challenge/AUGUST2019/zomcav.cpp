#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n,i,j,start,end;
		scanf("%lld",&n);
		long long int c[n],health[n],ans[n];
		memset(c,0,sizeof(c));
		memset(health,0,sizeof(health));
		memset(ans,0,sizeof(ans));
		for(i=0;i<n;i++){
			scanf("%lld",&c[i]);
		}
		for(i=0;i<n;i++){
			scanf("%lld",&health[i]);
		}
		for(i=0;i<n;i++){
			if((i-c[i])<0)
			start=0;
			else start =i-c[i];
			
			if((i+c[i])>(n-1))
			end=n-1;
			else end=i+c[i];

			for(j=start;j<=end;j++){
				ans[j]++;
			}
		}
		sort(ans,ans+n);
		sort(health,health+n);
		int m=1;
		for(i=0;i<n;i++){
			if(health[i]!=ans[i]){
				printf("NO\n");
				m=0;
				break;
			}
		}
		if(m==1)
		printf("YES\n");
	}
	return 0;
}