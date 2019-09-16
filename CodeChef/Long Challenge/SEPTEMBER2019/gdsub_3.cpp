#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 
long long int power(long long int x, long long int y) 
{ 
    unsigned long long int res = 1; 
    while (y > 0){
          if (y & 1) 
            res = res*x;
        y = y>>1;
        x = x*x;
    } 
    return res; 
}
int main() 
{ 
  	long long int p = 1000000007;
	long long int n,k,i;
	scanf("%lld %lld",&n,&k);
	long long int arr[n];
	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	long long int map[8001]={0};
	for(i=0;i<n;i++)
		map[arr[i]]++;
	long long int x[n]={0};
	long long int count=0;
	for(i=0;i<8001;i++){
		if(map[i]!=0){
			x[count]=map[i];
		count++;
		}
	}
	unsigned long long int ans;
	for(i=)
	return 0; 
} 
