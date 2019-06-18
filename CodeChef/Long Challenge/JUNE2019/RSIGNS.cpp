#include <iostream>
#include <stdio.h> 
#define MOD 1000000007
using namespace std;
unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long int p) 
{ 
    unsigned long long int res = 1;
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
int main()
{
	int t;
	cin>>t;
	while(t--){
		unsigned long long int k;
		cin>>k;
		unsigned long long int ans = power(2,k, 1000000007);
		ans = ans*5;
		ans = ans%1000000007;
		cout<<ans<<endl;
	}
	return 0;
}