#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int
//Code taken from geeksgorgeeks Modular exponentation Link - https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
long long int power(long long int x, long long int y, long long int p) 
{ 
   lli res = 1;
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

long long int modInverse(long long int a,long int m)
{
        return power(a, m-2, m);
}

int main(){
	int t;
	scanf("%d",&t);
	long long int fact[100006];
	fact[0]=1;
	for(int i=1;i<=100005;i++)
    	fact[i]=(fact[i-1]*i)%mod;
	while(t--){
		int n;
		scanf("%d",&n);
		int len=2*n;
		int arr[len];
		unordered_map<int,int> freq;
		long long int sum=0;
		for(int i=0;i<len;i++){
			scanf("%d",&arr[i]);
			sum+=arr[i];
			freq[arr[i]]++;
		}
		lli pref=sum/(n+1);
        if(sum%(n+1)!=0){
            printf("0\n");
            continue;
        }
		else if(freq[pref]<2){
			printf("0\n");
		}
		else if(n==1){
			if(arr[0]==arr[1]){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		else{
			lli ans=fact[n-1];
			lli denominator=1;
			int no_of_pairs=0;
			freq[pref]-=2;
			for(int i=0;i<len;i++){
				int x=arr[i];
				int pairs=0;
				int p1=x;
				int p2=pref-x;
				if(freq[p1]>0 &&  freq[p2]>0 && freq[p1]==freq[p2]){
					if(p1!=p2){
						pairs=freq[x];
						ans=(ans*power(2,freq[x],mod))%mod;
					}
					else{
						pairs=freq[x]/2;
					}
					no_of_pairs+=pairs;
					denominator=modInverse(fact[pairs],mod);
					ans=(ans*denominator)%mod;
					freq[p1]=0;
					freq[p2]=0;					
				}
			}
			if( no_of_pairs!=n-1){
			    
				printf("0\n");
			}
			else{
				printf("%lld\n",(ans%mod));
			}

		}
	}
	return 0;
}