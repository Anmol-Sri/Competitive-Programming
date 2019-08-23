#include <iostream>
#include<stdio.h>
#include <bits/stdc++.h> 
using namespace std; 
int main(){
	int n,d,r;
	while(true){
		scanf("%d %d %d",&n,&d,&r);
		if(n==0 && d==0 && r==0)
		break;
		int mor[n],eve[n];
		for(int i=0;i<n;i++)
		scanf("%d",&mor[i]);
		for(int i=0;i<n;i++)
		scanf("%d",&eve[i]);
		long long int sum=0;
		for(int i=0;i<n;i++)
		sum+=(mor[i]+eve[i]);
		sum=(sum-(n*d))*r;
		printf("%lld\n",sum);	
	}
	return 0;
}