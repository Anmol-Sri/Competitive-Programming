#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int att(int a,int b){
	return (((double)a/b)>=0.75?1:0);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int d,c=0;
		scanf("%d\n",&d);
		char s[d];
		int p=0;
		for(int i=0;i<d;i++){
			scanf("%c",&s[i]);
			if(s[i]=='P') p++;
		}
		if(att(p,d)){
			printf("0\n");
			continue;
		}
		else{
			int i=2;
			if(d<5){
				printf("-1\n");
				continue;
			}
			while(i<=d-3){
				if(s[i]=='A'){
					if((s[i-1]=='P' || s[i-2]=='P' )&&(s[i+1]=='P'||s[i+2]=='P')){
						p++;
						c++;
						if(att(p,d)){
							printf("%d\n",c);
							break;
						}
					}						
				}
				i++;
			}
			if(att(p,d)==0) printf("-1\n");
		}
	}
	return 0;
}