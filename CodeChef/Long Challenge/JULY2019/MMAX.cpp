#include <stdio.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int modby(const char str[], int n ){
	int ans=0;
	int len=strlen(str);
	for(int i=0;i<len;i++){
		ans=(ans*10+(str[i]-'0'))%n;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		string str;
		cin >> str;
		const char* chr = str.c_str();
		int r=modby(chr,n);
		if(r==0){
			printf("0\n");
		}
		else if(n%2==0){
			if(r==n/2)
				printf("%lld\n",n-1);
			else if(r<(n/2)){
				printf("%lld\n",2*r);
			}
			else printf("%lld\n",2*(n-r));
		}
		else{
			if(r<((n/2)+1)) printf("%lld\n",2*r);			
			else if(r==((n/2)+1)) printf("%lld\n",n-1);		
			else printf("%lld\n",2*(n-r));
		}
	}
	return 0;
}