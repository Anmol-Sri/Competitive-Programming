#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n];
		long long int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		double mean=(double)sum/n;
		if((mean*(n-1))-(long long int)(mean*(n-1)) != 0 ){
			printf("Impossible\n");
			continue;
		}
		long long int val=(sum)-(long long int)((n-1)*mean);
		int i;
		for(i=0;i<n;i++){
			if(arr[i]==val){
				printf("%d\n",(i+1));
				break;
			}
		}
		if(i==n)
			printf("Impossible\n");
	}
	return 0;
}