#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string str;
		int l;
		cin>>str;
		l=str.length();
		int point=0;
		int i,pre=0,pos=0;
		for(i=0;i<l;i++)
		{
			if(str[i]=='0'){
				if(pre==0){
					pre=1;
					pos=i;
				}
			}
			else if(str[i]=='1'){
				if(pre!=0){
					for(int j=pos;j<=i;j++){
						str[j]='9';
					}
					pre=0;
					pos=-9;
				}
				else
				{
					str[i]='9';
				}
				if(str[i+1]=='1') str[i+1]='0';
				else if(str[i+1]=='0') str[i+1]='1';
			}
		}
		for(i=0;i<l;i++){
			if(str[i]=='0'){
				point=1;
				break;
			}
		}
		if(point!=1) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}