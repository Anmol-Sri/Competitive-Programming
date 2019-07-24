#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,z;
		scanf("%d",&n);
		scanf("%d",&z);
		int arr[n];
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		sort(arr,arr+n);
		if(n==2){
			if(2*arr[0]<arr[1])
			{
				printf("%d\n",arr[0]*2);
			}
			else printf("%d\n",arr[1]);
			
		}
		else{
			if(arr[0]*n<arr[n-1]){
				printf("%d\n",arr[0]*n);
			}
			else{
				printf("%d\n",arr[n-1]);
			}
		}

	}
	return 0;
}
