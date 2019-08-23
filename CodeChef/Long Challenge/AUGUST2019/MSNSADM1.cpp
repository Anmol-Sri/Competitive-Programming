#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[n],b[n],ans[n];
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(i=0;i<n;i++){
			ans[i]=(a[i]*20)-(b[i]*10);
			if(ans[i]<0) ans[i]=0;
		}
		sort(ans,ans+n);
		printf("%d\n",ans[n-1]);
	}
	return 0;
}