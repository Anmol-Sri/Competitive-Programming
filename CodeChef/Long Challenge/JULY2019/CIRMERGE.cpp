#include <stdio.h>
#include<iostream>
#include <bits/stdc++.h> 
#include <algorithm>
#define ull unsigned long long int
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n];
		int ans=0;
		vector<int> v;
		int len=n;
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		vector<pair<int,pair<int,int>>>sumarr;
		while(true){
			for(int i=0;i<len;i++)
				if(arr[i]!=0)
					v.push_back(arr[i]);
		for(int i=0;i<v.size();i++)
			arr[i]=v[i];			
		len=v.size();

		if(v.size()==1) break;
		for(int i=0;i<v.size()-1;i++)
			sumarr.push_back(make_pair(v[i]+v[i+1],make_pair(i,i+1)));
		if(arr[len-1]!=0 && arr[0]!=0)
			sumarr.push_back(make_pair(arr[len-1]+arr[0],make_pair(0,len-1)));
			sort(sumarr.begin(), sumarr.end());
			ans+=sumarr[0].first;
			arr[sumarr[0].second.first]=sumarr[0].first;
			arr[sumarr[0].second.second]=0;
			sumarr.clear();
			v.clear();			
		}
		printf("%d\n",ans);
	}
	return 0;
}