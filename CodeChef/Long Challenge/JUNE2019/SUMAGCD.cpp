#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int checkDistinct(int arr[],int n){
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]) return 0;
	}
	return 1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n,greater<int>());
		if(n==2){
			printf("%d\n",(arr[0]+arr[1]));
			continue;
		}
		else if(checkDistinct(arr,n)){
			int max1,max2;
			int hcf=arr[2];
			for(int i=3;i<n;i++){
				if(arr[i]>hcf)
				hcf=gcd(arr[i],hcf);
				else hcf=gcd(hcf,arr[i]);
			}
			max1=gcd(arr[0],hcf);
			max2=gcd(arr[1],hcf);
			max1=max1+arr[1];
			max2=max2+arr[0];
			if(max1>max2)
			printf("%d\n",max1);
			else printf("%d\n",max2);
		}
		else{
			int g0H,g0S;
			int max1=arr[0];
			int max2,j;
			for(j=1;j<n;j++){
				if(arr[j]!=max1) break;
				arr[j]=arr[n-1];
			}
			if(j==n){
				printf("%d\n",(arr[0]+arr[1]));
				continue;
			}
			max2=arr[j];
			for(j++;j<n;j++){
				if(arr[j]!=max2) break;
				arr[j]=arr[n-1];
			}
			if(j==n){
				printf("%d\n",(max1+max2));
				continue;
			}
			int g0=arr[j];
			for(int i=j+1;i<n;i++){
				if(arr[i]>g0)
				g0=gcd(arr[i],g0);
				else g0=gcd(g0,arr[i]);
			}
			g0H=gcd(max1,g0);
			g0S=gcd(max2,g0);
			if((max2+g0H)>(max1+g0S)){
				printf("%d\n",(g0H+max2));
			}
			else printf("%d\n",(g0S+max1));
		}
	}
	return 0;
}