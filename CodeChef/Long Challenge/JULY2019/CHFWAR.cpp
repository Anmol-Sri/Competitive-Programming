#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    long long int t;
     scanf("%d",&t);
     while(t--){
      long long int n,f;
      scanf("%d",&n);
      vector<long long int> a(n);
      for(long long int i=1;i<n;i++)
        cin>>a[i];
      cin>>f;
      vector<long long int>newv;
      for(long long int i=0;i<n;i++){
        if(a[i]<=f)
         newv.push_back(i);
      }
      if(n<101){
        long long int result=-1;
        long long int calc=LONG_MAX;
        for(long long int j=0;j<newv.size();j++){   
          long long int w=newv[j];
          vector<long long int> u,y;
          for(long long int i=1;i<n;i++){
           if(i==w)
            u.push_back(0);
            u.push_back(a[i]);
          }
          long long int hash[1000002]{0};  
          hash[w-1]=2;
          long long int size=n;
          long long int i=0,p=0;
          long long int ans=0;
          while(size>2){
            if(i%n==(w-1)) i++;
            else if (hash[i%n]==0){
              p=0;
              while(hash[(i+1)%n]==1){
                i++;
                p++;
              }
              if(hash[(i+1)%n]==2){
                ans+=u[(i-p+n)%n];
                i+=1;
              }
              else{
                hash[(i+1)%n]=1;
                size--; 
                while(hash[(i+1)%n]==1)
                  i++;
              }
              i++;
            }
          }
          if(ans<calc){
            result=w;
            calc=ans;
          }
        }
        if(result!=-1){
          printf("possible\n");
          printf("%lld %lld\n",result,calc+f);
        }
        else printf("impossible\n");
      }
      else{
        long long int imp=1;
        long long int minimum=LONG_MAX;
        long long int pos=0;
        for(long long int i=1;i<n;i++){
         if(a[i]>f)
          imp++;
          else{
            long long int newv,ans=0,liq,w;
            newv=i-1;
            liq=n-(newv)/2-1;
            if(newv==0)
             w=n-1;
            else{
              if( newv%2==0) w=newv-1;
              else{
               w=newv;
               ans=ans+a[w];
              }
            }
            long long int num=1;
            long long int wsecond=w;
            long long int peri=1;
            while(1){
              if(liq%2==1){
                ans=ans+a[w];
                liq/=2;
                liq++;
              }
              else{
                long long int extra = (long long int)pow(2,num);
                if(newv==0)
                w=wsecond-extra-1; 
                else{
                 if(w-extra<=0)
                 peri=0;
                 if(peri)
                   w=w-extra;
                 else w=n-extra+(wsecond+1)/2;
                }
                liq/=2LL;
              }
              if(liq<=2) break;
              num=num+1;
            }
            if(minimum>ans){
              pos=newv+1;
              minimum=ans;
            }
          } 
        }
        if(imp!=n){
          printf("possible\n");
          printf("%lld %lld\n",pos,minimum+f);
        }
        else printf("impossible\n");
      }
    }
    return 0;
}