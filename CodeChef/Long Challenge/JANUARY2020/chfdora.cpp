#include<bits/stdc++.h>
#include <iostream>
#include<stdio.h>
using namespace std;
int mini(int a,int b,int c,int d){
	int arr[4]={a,b,c,d};
	sort(arr,arr+4);
	return arr[0];
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		int arr[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				scanf("%d",&arr[i][j]);
		}
		int i,j,z,k,sub_length;
		long long int ans=n*m;
		bool sub_row_palin=true,sub_col_palin=true;
		for(i=1;i<n-1;i++){
			for(j=1;j<m-1;j++){
				/*sub_length=min(i,j);
				sub_row_palin=true;
				sub_col_palin=true;

				for(k=sub_length;k>0;k--){
					//check sub_columns palindrome if true for max check for max sub_rows ans then add it to ans
				}*/

				//---------------------------------------------------

				sub_length=mini(i,j,n-i-1,m-j-1);
				sub_row_palin=true;
				sub_col_palin=true;
				for(k=1;k<=sub_length;k++){
					//check sub_columns Palindrome
					int start=i-k;
					int end=i+k;
					for(;start<i;start++,end--){
						if(arr[start][j]!=arr[end][j]){
							sub_col_palin=false;
							break;
						}
					}
					if(sub_col_palin==false) break;
					//check sub_rows palindrome
					start=j-k;
					end=j+k;
					for(;start<j;start++,end--){
						if(arr[i][start]!=arr[i][end]){
							sub_row_palin=false;
							break;
						}
					}
					if(sub_row_palin==false) break;
					ans++;
				}

				//-----------------------------------------------

				/*if(i<j){
					sub_length=i;
					for(z=0;z)
					while(sub_length>0){
						int start=i-sub_length;
						for(k=i-sub_length;k<i;k++){
							if(arr[k][j]!=arr[i+sub_length-k][j])
						}
						sub_length--;
					}
				}
				else{
					sub_length=j;
				}
				*/
			}
		}
		printf("%lld\n",ans);
	}
}