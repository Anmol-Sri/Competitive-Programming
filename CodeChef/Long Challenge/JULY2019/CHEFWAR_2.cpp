#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    long long int  t,n,f;
    scanf("%lld",&t);
    while(t--){
     	scanf("%lld",&n); 
	vector<long long int> a(n);
    for(long long int i=1;i<n;i++)
    scanf("%lld",&a[i]);
    scanf("%lld",&f);
    vector<long long int> newv;
 	for(long long int i=1;i<n;i++){
    	if(a[i]<=f)
    		newv.push_back(i);
    }
	if(n<101){
    	long long int ansi=-1,cal=LONG_MAX;
	for(long long int j=0;j<newv.size();j++){   
    	long long int w=newv[j];
    	vector<long long int> u,y;
    	for(long long int i=1;i<n;i++){
    	if(i==w)
    		u.push_back(0);
    		u.push_back(a[i]);
    	} 
 		long long int arr[1000002]{0};  
 		arr[w-1]=2;
   		long long int siz=n,i=0,p=0,sum=0;
		while(siz>2)
   		{
     		if(i%n==(w-1)){ 
     		i++; 
     		}
     		else if (arr[i%n]==0){
     			p=0;
     			while(arr[(i+1)%n]==1){
     				i++;
     				p++;
     			}
       		if(arr[(i+1)%n]==2){
       			sum+=u[(i-p+n)%n];
       			i+=1;
       		}
        	else{
            	arr[(i+1)%n]=1;
            	siz--; 
            	while(arr[(i+1)%n]==1)
            		i++;
        	}
        	i+=1;
        	}
   		}
  		if(sum<cal)
   		{
   		  ansi=w;
   		  cal=sum;
   		}
	}
	if(ansi!=-1){
    	printf("possible\n");
		printf("%lld %lld\n",ansi,cal+f);
	}
		else printf("impossible\n");
	}
	else{
    	long long int imp=1,mini=LONG_MAX,pos=0;
    
for(long long int i=1;i<n;i++){ if(a[i]>f) imp++;
    else{
      long long int newv,ans=0,weight,w;
      newv=i-1;
      weight=n-1-(newv)/2;
      if(newv==0) w=n-1; else{
    if( newv%2==0){
    ans+=0LL;w=newv-1;}
    else { 
    	w=newv;
    	ans+=a[w];
    }
      }
    long long int num=1,wsecond=w,zxc=1;
    while(1)
    {
        if(weight%2){
        ans+=a[w];
        weight/=2; weight++;
        }
        else{
         	long long int qwer= (long long int)pow(2,num);
            if(newv==0) w=wsecond-qwer-1; 
        else
        {
        	 if(w-qwer<=0) zxc=0;
        	 if(zxc)w-=qwer;
        	  else
            w=(wsecond+1)/2-qwer+n;   
        	}  
        	weight/=2LL;}
       		 if(weight<=2)
        	break;
        	 num++;
    		}
    		if(mini>ans)
    		{
       			pos=newv+1;
        		mini=ans;
    		}
    		} 
		}
		if(imp!=n){
    		printf("possible\n");
			printf("%lld %lld\n",pos,mini+f);
		}
		else printf("impossible\n");


		}	
	}	
    return 0;
}