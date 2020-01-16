#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target ("avx2,avx,fma")
#define ll long long int
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for(i=l;i<r;i++)
#define bep(i,l,r) for(i=l;i>=r;i--)
#define all(v) v.begin(),v.end()
#define ld long double
#define ff first
#define ss second
#define pii pair<ll,ll>
#define pi 3.1415926535897932384626433832
#define mod 1000000007
ll powe(ll i,ll j)
{
    if(j==0)
        return 1;
    ll ans=1;
    while(j>0)
    {
        if(j%2!=0)
            ans=((ans%mod)*(i%mod))%mod;
            i=((i%mod)*(i%mod))%mod;
            j/=2;
    }
    return ans;
}
int main()
{
    io;
    ll i,j,t;
    cin>>t;
    vector<ll>fact(100005);
    fact[0]=1;
    rep(i,1,100005)
    fact[i]=(fact[i-1]*i)%mod;
    rep(i,0,t)
    {
        int n;
        cin>>n;
        vector<ll>x(2*n);
        bool f1=1;
        bool f2=1;
        rep(j,0,2*n)
        {
        cin>>x[j];
        if(x[j]>0)
            f2=0;
        if(x[j]<0)
            f1=0;
        }
        sort(x.begin(),x.end());
        bool f=1;
        ll ans=1;
        map<pii,ll>m;
        if(f1)
        {
            if(x[x.size()-1]!=x[x.size()-2])
                f=0;
            rep(j,0,(x.size()-2)/2)
            if(x[j]+x[x.size()-3-j]!=x[x.size()-1])
            {
                f=0;
                break;
            }
            else if(m.find(mp(x[j],x[x.size()-3-j]))!=m.end())
                m[mp(x[j],x[x.size()-3-j])]++;
            else
                m[mp(x[j],x[x.size()-3-j])]=1;
        }
        else if(f2)
        {
            reverse(x.begin(),x.end());
            if(x[x.size()-1]!=x[x.size()-2])
                f=0;
            rep(j,0,(x.size()-2)/2)
            if(x[j]+x[x.size()-3-j]!=x[x.size()-1])
            {
                f=0;
                break;
            }
            else if(m.find(mp(x[j],x[x.size()-3-j]))!=m.end())
                m[mp(x[j],x[x.size()-3-j])]++;
            else
                m[mp(x[j],x[x.size()-3-j])]=1;
        }
        else if(!f1&&!f2)
        {
            ll sum=x[0]+x[x.size()-1];
            vector<ll>v;
            int cnt=0;
            rep(j,0,x.size())
            if(x[j]!=sum||cnt<2)
            {
                v.pb(x[j]);
             //   m[x[j]]++;
                cnt++;
            }
            if(cnt!=2)
                f=0;
            rep(j,0,v.size()/2)
            if(v[j]+v[v.size()-1-j]!=sum)
            {
                f=0;
                break;
            }
            else if(m.find(mp(v[j],v[v.size()-1-j]))!=m.end())
                m[mp(v[j],v[v.size()-1-j])]++;
            else
                m[mp(v[j],v[v.size()-1-j])]=1;
        cout<<sum<<" "<<m.size()<<" ";
        }
        if(n==1&&x[0]!=x[1])
           f=0;
        if(!f)
        {
            cout<<0<<"\n";
            continue;
        }
        ll k=0;
        map<pii,ll>m1;
        for(auto e:m)
        if(e.ff.ff==e.ff.ss)
            k+=e.ss;
        else
            m1[e.ff]=e.ss;
        ll left=n-1-k;
        ans=(((fact[n-1]*powe(fact[k],mod-2))%mod)*powe(fact[n-1-k],mod-2))%mod;
        for(auto e:m1)
        {
            ans=(((((fact[left]*powe(fact[e.ss],mod-2))%mod)*powe(fact[left-e.ss],mod-2))%mod)*((ans*2)%mod));
           // cout<<left<<" "
            left-=e.ss;
        }
        cout<<ans<<"\n";
    }
    return 0;
}


//================================================================================================================================================================================================


#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli unsigned long long int
//Code taken from geeksgorgeeks Modular exponentation Link - https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
long long int power(long long int x, unsigned long long int y, long long int p) 
{ 
    int res = 1;
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
        //int freq[2000000003];
        unordered_map<int,int> freq;
        unsigned long long int sum=0;
        for(int i=0;i<len;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
            /*if(arr[i]<0){
                int temp=1000000001+(arr[i]*-1);
                freq[temp]++;
            }
            else{
                freq[arr[i]]++;
            }*/
            freq[arr[i]]++;
        }
        lli pref=sum/(n+1);
        if(sum%(n+1)!=0){
            printf("0\n");
        }
        else if(sum%2!=0){
            printf("0\n");
        }
        else if(pref>0 && freq[pref]<2){
            printf("0\n");
        }
        /*else if(pref<0 && freq[1000000001 + (pref*-1)]<2){
            printf("0\n");
        }*/
        else if(n==1){
            if(arr[0]==arr[1]){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else{
            /*int pref_index=0;
            if(pref<0){
                pref_index=1000000001 + (pref*-1);
            }
            else{
                pref_index=pref;
            }*/
            lli ans=fact[n-1];
            lli denominator=1;
            int no_of_pairs=0;
            //freq[pref_index]-=2;
            freq[pref]-=2;
            for(int i=0;i<len;i++){
                int x=arr[i];
                int pairs=0;
                /*int p1=(x>0)?x:1000000001+(x*-1);
                int p2=((pref-x)>0)?pref-x:1000000001+((pref-x)*-1);*/
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
                printf("%llu\n",(ans%mod));
            }

        }
    }
    return 0;
}