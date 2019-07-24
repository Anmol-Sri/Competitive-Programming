#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int add=0,ans=0,minimum;
		int n;
		scanf("%d",&n);
		vector<int> v;
		int temp;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			v.push_back(temp);
		}
		int len,y;
		vector<int>::iterator it;
		while(v.size()!=1){
			minimum=LONG_MAX;
			 y=0;
			it=v.begin();
			len=v.size();
			for(int j=0;j<len;j++){
				if(j<len-1) add=v[j]+v[j+1];
				else add=v[j]+v[0];
				temp=ans+add;
				if(temp<minimum){
					y=j;
					minimum=temp;
				}
			}
			if(y<len-1){
				v[y]=v[y]+v[y+1];
				ans=ans+v[y];
				it+=y+1;
				v.erase(it);
			}
			else{
				v[y]=v[y]+v[0];
				ans=ans+v[y];
				v.erase(it);
			}
		}
		printf("%lld\n",ans);
		v.clear();
	}
	return 0;
}