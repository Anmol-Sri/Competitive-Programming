#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    long long int n;
		scanf("%lld",&n);
	    long long int b=1,a=0,c=0,i=0;
 	    int p=log2(n);
 		long long int index=pow(2,(int)p);
        long long int count= index-1;
        for(int i=2;i<=count;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        printf("%lld\n",b%10);
	}
	
	return 0;
}