#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<unordered_map>
using namespace std;
int findchain(int start[],int end[],int no,int i){
	int ans=-1;
	for(;i>=0;i--){
		if(end[i]==no-1){
			no=start[i];
			ans=i;
		}
		else{
			return ans;
		}
	}
return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		unsigned long long int count=0;
		scanf("%d",&n);
		vector<int> a;
		int q;
		for(int i=0;i<n;i++){
			scanf("%d",&q);
			a.push_back(q);
		}
		unordered_map<int, int> hashMap;
		hashMap[0] = -1;
		int xor_sum = 0;
		int start[n],end[n];
		for(q=0;q<n;q++){
			end[q]=-1;
			start[q]=-1;
		}
		q=0;
		for(int i = 0; i < n; i++){
    		xor_sum ^= a[i];
    		if(hashMap.find(xor_sum) != hashMap.end()) {    			
    			start[q]=hashMap[xor_sum] + 1;
    			end[q]=i;
    			q++;
    		}
    		hashMap[xor_sum] = i;
		}
		count=end[0]-start[0];
		int temp;
		for(int i=1;i<q;i++){
			count=count+(end[i]-start[i]);
			temp=findchain(start,end,start[i],i-1);
			if(temp!=-1){
				for(q=temp;q<=i;q++){
					count=count+(end[i]-start[q]);
				}
			}
		}
		printf("%llu\n",count);
	}
	return 0;
}