#include<iostream>
#define MOD 1000000007
using namespace std;


int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
        unsigned long long int n,k;
        cin>>n>>k;
        unsigned long long int ans,q,i;
        n = (n-1);
        k = (k-1);
        i = (k/n);
        q = k%n;
        ans = 0;
        n=n%MOD;
        q=q%MOD;
        if(i%2==0)
        {
        	ans = i/2;
        	i=i%MOD;
        	ans=ans%MOD;
        	ans = (ans*n)%MOD;
        	ans = (ans+q)%MOD;
        	ans = (ans*(i+1))%MOD;
        }
        else
        {
        	ans = (i+1)/2;
        	i=i%MOD;
        	ans=ans%MOD;
        	q = (2*q)%MOD;
        	q+= ((i*n)%MOD);
        	q=q%MOD;
        	ans = (ans*q)%MOD;
        }
        ans=ans%MOD;
        if(ans<0)
        	ans+=MOD;
        cout<<ans<<'\n';
    }
	return 0;
}