#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
	int n;
	scanf("%d",&n);
	long long int arr[n][n];
	if(n == 1){
		printf("Hooray\n1\n");
	}
	else if(n % 2){
		printf("Boo\n");
	}
	else{
		printf("Hooray\n");
		for(int i=0;i<n;i=i+1){
			arr[i][i] = n;
		}
		for(int i=1;i<n;i=i+1){
			arr[i][0] = i;
		}
		for(int j=1;j<n;j=j+1)
		{
			int temp[n+1]={};
			for(int i=0;i<j;i=i+1)
			{
				temp[arr[j][i]] = 1;
			}
			int pehla=(2+arr[j][j-1])%(n-1);
			if(pehla == 0)
			{
				pehla+=n-1;
			}
			vector<int> myown;
			for(int i = pehla; i <= n - 1; i=i+1)
			{
				if(!temp[i]){
					myown.push_back(i);
				}
			}
			for(int i = 1; i < pehla; i=i+1)
			{
				if(!temp[i]){
					myown.push_back(i);
				}
			}
			int shuruwat = j + 1;
			while(shuruwat<n)
			{
				arr[shuruwat][j]=myown[shuruwat-j-1];
				shuruwat++;
			}
		}
		for(int i=0;i<=n-1;i=i+1)
		{for(int j=0;j<=n-1;j=j+1)
			{
				if(i<j)
				{
					arr[i][j]=2*n-arr[j][i];
				}
			}
		}
		for(int i=0;i<=n-1;i=i+1)
		{
			for(int j=0;j<=n-1;j=j+1)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
	}
}}