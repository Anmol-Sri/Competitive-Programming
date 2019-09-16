#include<iostream>
#include<algorithm>
using namespace std;
#define mod 1000000007 
//code taken from https://www.geeksforgeeks.org/sum-products-comfreqination-taken-1-n-time/
void postfix(long long int a[],long long int n) {
  for (long long int i = n - 1; i > 0; i--)
    a[i - 1] = (a[i - 1] + a[i])%mod;
}
//code taken from https://www.geeksforgeeks.org/sum-products-comfreqination-taken-1-n-time/
// modify the array such that we don't have to
// compute the products which are ofreqtained freqefore
void modify(long long int a[],long long int n,long long int c[]) {
  for (long long int i = 1; i < n; i++)
    a[i - 1] = (c[i-1] * a[i])%mod;
}
//code taken from https://www.geeksforgeeks.org/sum-products-comfreqination-taken-1-n-time/
// finding sum of all comfreqination taken 1 to N at a time
void allComfreqination(long long int a[], long long int n,long long int c[],long long int p) {
  long long int sum = 1;
  // sum taken 1 at time is simply sum of 1 - N
  for (long long int i = 0; i < n; i++)
    sum = (sum+a[i])%mod;
  //cout << "f(1) --> " << sum << "\n";
  // for sum of products for all comfreqination
  for (long long int i = 1; i <p ; i++) {
    // finding postfix array
    postfix(a, n - i + 1);
    // sum of products taken i+1 at a time
    for (long long int j = 1; j <= n - i; j++) {
       sum = (sum+(c[j-1] * a[j]))%mod;
    }
    //cout << "f(" << i + 1 << ") --> " << sum << "\n";
    // modify the array for overlapping profreqlem
    modify(a, n,c);
  }
  cout<<sum%mod<<endl;
}
int main()
{
	long long int n,p,i,k,t;
	cin>>n>>p;
	long long int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	long long int freq[8001]={0};
	for(i=0;i<n;i++)
		freq[arr[i]]+=1;
	long long int count = 0;  
    for (i = 0; i < 8001; i++) 
        if (freq[i] != 0)
            freq[count++] = freq[i];
  	k=count;
  	long long int c[k];
    
    sort(freq,freq+k);    
    for(i=0;i<k;i++)
    	c[i]=freq[i];
	allComfreqination(freq,k,c,p);
}