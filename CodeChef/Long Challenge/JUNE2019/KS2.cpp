#include <iostream>
#include<stdio.h>
using namespace std;
unsigned long long int checksum(unsigned long long int a){
	unsigned long long int sum=0;
	while(a!=0){
		sum+=(a%10);
		a/=10;
	}
	return (sum%10==0);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		unsigned long long int n;
		scanf("%llu",&n);
		n=n*10-1;
		do{
			n++;
			if(checksum(n)==1){
				printf("%llu\n",n);
				break;
			}
		}while(true);
	}
	return 0;
}