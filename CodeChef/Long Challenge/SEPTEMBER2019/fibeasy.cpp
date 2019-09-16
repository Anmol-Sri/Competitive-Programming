#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
long long int fib[60];
int main(){
	int t;
	scanf("%d",&t);
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<60;i++)
		fib[i]=(fib[i-1]%10+fib[i-2]%10)%10;
	while(t--){
		long long int n,pow2,temp;
		scanf("%lld",&n);
		pow2=(long long int)pow(2,(long long int)log2(n));
		printf("%lld\n",fib[(pow2%60)-1]);
	}
	return 0;
}