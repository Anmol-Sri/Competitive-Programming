#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#define MOD 1000000007 
#define inputl(x) scanf("%lld",&x)
using namespace std;
int main(){
    long long int t;
    inputl(t);
    while(t--){
        long long int n,m;
        scanf("%lld %lld",&n,&m);
        long long int maxlim=((n*(n-3))/2)+(2*n);
        long long int sum=(n*(n+1))/2;
        if(n==1 && m>1)
            printf("-1\n");
        else if(n==1 && m==0)
            printf("0\n");
        else if(m>sum)
            printf("-1\n");
        else if(n==1 && m==1)
            printf("1\n");
        else if(n>1 && m==0)
            printf("-1\n");
        else if(n==2 && m==1)
            printf("1\n");
        else if(n>1 && m<n-1)
            printf("-1\n");
        else if(maxlim<m)
            printf("-1\n");
        else if(m>=(n+2)&&m<=(2*n))
            printf("3\n");
        else if(m>=(n-1)&&m<=(n+1))
            printf("2\n");
        else {
            double k=m-2*n;
            double k1=2*k/n;
            cout<<(3+ceil(k1))<<"\n";
        }
    }
    return 0;
}        