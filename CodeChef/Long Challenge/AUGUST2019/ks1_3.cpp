#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<unordered_map>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		unsigned long long int count=0;
		scanf("%d",&n);
		map<long long int,long long int> xorSum;
		long long int i,temp,j;
		for(i=0;i<n;i++){
            scanf("%lld",&temp);
            if(i==0){
            	xorSum[i]=temp;
            }            
            else{
            	xorSum[i]=temp^xorSum[i-1];
            }
            if(xorSum[i]==0){
            	count+=i;
            }
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if((xorSum[i]==xorSum[j])){
                    count+=(j-i-1);
                }
            }
        }
        printf("%llu\n",count);
	}
	return 0;
}