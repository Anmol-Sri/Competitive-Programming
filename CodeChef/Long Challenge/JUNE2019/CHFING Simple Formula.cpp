#include<bits/stdc++.h>
#include<algorithm>
typedef long long int ll;
typedef unsigned long long int ull;
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define bs binary_search
#define full(a) a.begin(),a.end()
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define test int t;cin>>t; while(t--)
#define MOD 1000000007
#define ff(n) for(ll i=0;i<n;i++)
#define rf(n) for(ll i=n-1;i>=0;i--)
#define dff(n,m) for(ll i=0;i<n;i++) for(ll j=0;j<m;j++)
using namespace std;

int main() {
    fast;
    test
    {
        ll n,k;
        cin >> n>>k;
        
            ll d = (n-1);
            ll m = (k - n);
            ll ans = (k-1);
            ll terms = 0;
            if(k>n) terms=ceil(double(m)/double(d));
            terms = terms%MOD;
            d = -1*d;
            ll l = (m+(terms-1)*d);
            //cout << "terms : " << terms <<" k-n : "<< m <<" n-1 : "<< d << endl;
            ans = (ans + ((terms*(m+l))/2))%MOD;
            cout << ans <<endl;
    }
	return 0;
}
