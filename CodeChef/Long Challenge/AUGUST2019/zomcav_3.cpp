#include <iostream>
#include<stdio.h>
#include <bits/stdc++.h> 
using namespace std; 
struct query { 
	int start, end; 
}; 
void incrementByD(long long int arr[], struct query q_arr[], 
				int n, int m, int d) 
{ 
	int sum[n]; 
	memset(sum, 0, sizeof(sum)); 
	for (int i = 0; i < m; i++) { 
		sum[q_arr[i].start] += d; 
		if ((q_arr[i].end + 1) < n) 
			sum[q_arr[i].end + 1] -= d; 
	} 
	arr[0] += sum[0]; 
	for (int i = 1; i < n; i++) { 
		sum[i] += sum[i - 1]; 
		arr[i] += sum[i]; 
	} 
} 
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n,i,j,start,end;
		scanf("%lld",&n);
		long long int c[n],health[n],ans[n];
		memset(ans,0,sizeof(ans));
		struct query q_arr[n];
		for(i=0;i<n;i++){
			scanf("%lld",&c[i]);
		}
		for(i=0;i<n;i++){
			scanf("%lld",&health[i]);
		}
		for(i=0;i<n;i++){
			if((i-c[i])<0)
			start=0;
			else start =i-c[i];
			
			if((i+c[i])>(n-1))
			end=n-1;
			else end=i+c[i];
			q_arr[i].start=start;
			q_arr[i].end=end;

		}
		incrementByD(ans,q_arr,n,n,1);
		sort(ans,ans+n);
		sort(health,health+n);
		int m=1;
		for(i=0;i<n;i++){
			if(health[i]!=ans[i]){
				printf("NO\n");
				m=0;
				break;
			}
		}
		if(m==1)
		printf("YES\n");
	}
	return 0;
}
