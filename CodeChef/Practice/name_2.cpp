#include<bits/stdc++.h>
using namespace std;
const long long MAX = 1000010;
const long long MOD = 1000000007;
int n, t, l, r, num;    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);     
int prime[] = {2, 3, 5, 7};     
cin>>n>>t;
long long arr[n+1][4];
memset(arr, 0, sizeof(arr));
for( int i = 0; i < n; i++ ){
	cin>>num;
	for( int j = 0; j < 4; j++ ){
		arr[i+1][j] = arr[i][j];
    	int c = 0;
    	while( num % prime[j] == 0 ){
    		c++;
    		num /= prime[j];
    	}
    	arr[i+1][j] += (1LL * c);
    	}
    }
    while(t--){
    	cin>>l>>r;
    	long long res = 1;
    	for( int i = 0; i < 4; i++ ){
    		long long tmp=arr[r][i]-arr[l-1][i]+1;
    		res=(res * tmp) % MOD;
    	}
    	cout<<res<<"\n";
    }
    return 0;
}