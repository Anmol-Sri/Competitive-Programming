#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int arr[3];
		int s,ans=0;
		scanf("%d",&s);
		for(int i=0;i<3;i++) scanf("%d",&arr[i]);
		if(arr[0]+arr[1]+arr[2]<=s) ans=1;
		else if(arr[0]+arr[1]<=s) ans =2;
		else if(arr[1]+arr[2]<=s) ans=2;
		else ans=3;
		printf("%d\n",ans);
	}
	return 0;
}