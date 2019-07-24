#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long int value[405];
int n;
long long int mcmf(long long int ,long long int );
int main()
{
    int t;
	scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&value[i]);
        printf("%lld\n",mcmf(0,0));
    }
    return 0;
}
//applying matrix chain multiplication by keeping a count with bitset method....some areas of code taken from GeeksForGeeks
long long int mcmf(long long int count,long long int sum){
    long long int y=__builtin_popcount (count);
    if(y==(n-1)) return sum;
    long long int ans=LONG_MAX;
    for(int i=0;i<n;i++){
        long long int q=(count&(1LL<<i));	//trick taken from GeeksForGeeks to keep count the count of the set bit...or the ith value that is being processed
        if(q==0){
            int c=i;
            for(int k=0;k<n;k++){
            	long long int t1,t2,t3;
                c++;
                if(c>=n) c=0;
                q=count&(1LL<<c);
                if(q==0){
                    t1=value[c]+value[i];
                    t2=value[i];
                    t3=value[c];
                    value[i]=t1;
                    ans=min(mcmf(count|(1<<c),t1+sum),ans);
                    value[i]=t2;
                    value[c]=t3;
                    break;
                }
            }
            c=i;
            for(int k=0;k<n;k++){
                c--;
                if(c<0) c=n-1;
                q=count&(1LL<<c);
                long long int t1,t2,t3;
                if(q==0){
                    t1=value[c]+value[i];
                    t2=value[i];
                    t3=value[c];
                    value[i]=t1;
                    ans=min(mcmf(count|(1<<c),t1+sum),ans);
                    value[i]=t2;
                    value[c]=t3;
                    break;
                }
            }
        }
    }
    return ans;
}