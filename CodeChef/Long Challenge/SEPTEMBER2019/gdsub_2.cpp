#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 
long long int power(long long int x, long long int y, long long int p) 
{ 
	long long int res = 1;
	x = x % p; 
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1;
		x = (x*x) % p; 
	} 
	return res; 
} 
long long int modInverse(long long int n, long long int p) 
{ 
	return power(n, p-2, p); 
} 
long long int nCrModPFermat(long long int n, long long int r, long long int p) 
{ 
if (r==0) 
	return 1; 
	long long int fac[n+1]; 
	fac[0] = 1; 
	for (long long int i=1 ; i<=n; i++) 
		fac[i] = fac[i-1]*i%p; 
	return (fac[n]* modInverse(fac[r], p) % p * 
			modInverse(fac[n-r], p) % p) % p; 
} 
int main() 
{ 
  	long long int  p = 1000000007;
	long long int n,k;
	scanf("%lld %lld",&n,&k);
	long long int arr[n];
	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	long long int ans=1;
	for(long long int i=1;i<n;i++){
		ans+=nCrModPFermat(n,i,p);
	}	 
	cout <<ans<<endl; 
	return 0; 
} 
