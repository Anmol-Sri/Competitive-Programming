#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int a;
		cin>>a;
		long long int max=(long long int)(pow(10,n));
		long long int s=2*max+a;
		cout<<s<<"\n"<<flush;
		long long int b;
		cin>>b;
		cout<<(max-b)<<"\n"<<flush;
		long long int d;
		cin>>d;
		cout<<(max-d)<<"\n"<<flush;
		long long int ans;
		cin>>ans;
		if(ans!=1) break;
	}
	return 0;
}