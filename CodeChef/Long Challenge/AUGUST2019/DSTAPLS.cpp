#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		unsigned long long int n,k,a;
		scanf("%llu %llu",&n,&k);
		a=n/k;
		if(k==1){
			printf("NO\n");
		}
		else if(a%k==0){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}