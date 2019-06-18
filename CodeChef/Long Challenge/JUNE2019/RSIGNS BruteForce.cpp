#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int k;
		scanf("%d",&k);
		unsigned long long int temp,count=0;
		unsigned long long int lim=(unsigned long long int)pow(10,k)-1;
		for(unsigned long long int i=0;i<=lim;i++){
			int flag=-1;
			int a=-1,b=-1;
			a=i%10;
			temp=i;
			while(temp!=0){
				if(b==-1){
					if(temp%10!=a && temp!=0) b=temp%10;	
				}
				else{
					if(temp%10!=a && temp%10!=b){
						flag=0;
						break;
					}
				}
				temp/=10;
			}
			if(flag==0)	continue;
			temp=lim-i;
			while(temp!=0){
				if(b==-1){
					if(temp%10!=a) b=temp%10;
				}
				if(temp%10!=a && temp%10!=b){
					flag=0;
					break;
				}
				temp/=10;
			}				
			if(flag==0) continue;
			count++;		
		}
		printf("%llu\n",count%MOD);
	}
	return 0;
}