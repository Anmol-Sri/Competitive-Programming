#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
vector<long long int> initializeDiffArray(int n) 
{ 
    vector<long long int> D(n + 1); 
    for (int i = 0; i <= n; i++) 
        D[i] = 0;
    return D; 
} 
void update(vector<long long int>& D, int l, int r, int x) 
{ 
    D[l] += x; 
    D[r + 1] -= x; 
} 
vector<long long int> compute(vector<long long int>& A, vector<long long int>& D,int n) 
{ 
    for (int i = 0; i < n; i++) { 
        if (i == 0) 
            A[i] = D[i]; 
        else
            A[i] = D[i] + A[i - 1]; 
    }
    return A;
} 
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n,i,j,start,end;
		scanf("%lld",&n);
		vector<long long int> c,health,ans,dif;
		long long int temp;
		for(i=0;i<n;i++){
			scanf("%lld",&temp);
			c.push_back(temp);
		}
		for(i=0;i<n;i++){
			scanf("%lld",&temp);
			health.push_back(temp);
		}
		dif=initializeDiffArray(n);
		for(i=0;i<n;i++){
			if((i-c[i])<0)
			start=0;
			else start =i-c[i];
			if((i+c[i])>(n-1))
			end=n-1;
			else end=i+c[i];
			update(dif,start,end,1);
		}
		ans=compute(ans,dif,n);
		sort(ans.begin(),ans.end());
		sort(health.begin(),health.end());

		for(auto x:ans)
		cout<<x<<",";
	/*	for(auto x:health)
		cout<<x<<",";*/
		
		if(ans==health) printf("YES\n");
		else printf("NO\n");
		/*int m=1;
		for(i=0;i<n;i++){
			if(health[i]!=ans[i]){
				printf("NO\n");
				m=0;
				break;
			}
		}
		if(m==1)
		printf("YES\n");*/
	}
	return 0;
}