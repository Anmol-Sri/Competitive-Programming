#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int binaryCount(int n){
	int c=0;
	while(n!=0){
		n=n&(n-1);
		c++;
	}
	return c;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int q;
		scanf("%d",&q);
		vector<int> v;
		int *p = new int[1000000]();
		long long int even=0,odd=0;
		while(q--){
			int x,k;
			scanf("%d",&x);
			if(p[x]){
				printf("%lld %lld\n",even,odd);
				continue;
			}
			p[x]=1;
			v.push_back(x);
			k=binaryCount(x)%2;
			if(k==1) odd++;
			else even++;
			int len=v.size();
			int temp;
			for(int i=0;i<len-1;i++){
				temp=v[i]^x;
				if(!p[temp]){
					p[temp]=1;
					v.push_back(temp);
					k=binaryCount(temp)%2;
					if(k==1) odd++;
					else even++;
				}
			}
			printf("%lld %lld\n",even,odd);
		}
		v.clear();
		delete[] p;
	}
	return 0;
}