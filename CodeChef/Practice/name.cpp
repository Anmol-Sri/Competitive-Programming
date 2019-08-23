#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
void SieveOfEratosthenes(long long int n, bool prime[], 
                        bool primesquare[], int a[]) 
{ 
   for (long long int i = 2; i <= n; i++) 
        prime[i] = true; 
    for (long long int i = 0; i <= (n * n + 1); i++) 
        primesquare[i] = false; 
    prime[1] = false; 
    for (long long int p = 2; p * p <= n; p++) { 
        if (prime[p] == true) { 
            for (long long int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
    long long int j = 0; 
    for (long long int p = 2; p <= n; p++) { 
        if (prime[p]) {           
            a[j] = p; 
            primesquare[p * p] = true; 
            j++; 
        } 
    } 
} 
long long int countDivisors(long long int n) 
{ 
    if (n == 1) 
        return 1; 
    bool prime[n + 1], primesquare[n * n + 1]; 
    int a[n];
    SieveOfEratosthenes(n, prime, primesquare, a); 
    long long int ans = 1; 
    for (long long int i = 0;; i++) { 
        if (a[i] * a[i] * a[i] > n) 
            break; 
        long long int cnt = 1;
        while (n % a[i] == 0)
        { 
            n = n / a[i]; 
            cnt = cnt + 1;
        } 
        ans = ans * cnt; 
    } 
    if (prime[n]) 
        ans = ans * 2; 
    else if (primesquare[n]) 
        ans = ans * 3; 
    else if (n != 1) 
        ans = ans * 4; 
    return ans%MOD;
} 
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        long long int prod=1;
        for(int i=l-1;i<=r-1;i++){
            prod*=arr[i];
        }
        printf("%lld\n",countDivisors(prod));
    }
    return 0;
}