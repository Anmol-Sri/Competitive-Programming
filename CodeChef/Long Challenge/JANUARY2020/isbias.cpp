#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
    int inc[n][2]={0};
    int dec[n][2]={0};
    int dec_count=0;
    int inc_count=0;
    int start=0,end=0;

    for (int i=0;i<=n;++i){
        if ((i>0 && arr[i-1]>=arr[i])||(i-1 != start && i==n)){
        	if(i-1==start){
        	     start++;
        	     continue;
        	}
        	else{
        		inc[inc_count][0]=start;
        		inc[inc_count][1]=i-1;
        		inc_count++;
        		start=i;
        	}
        }
    }
    start=0;
    for (int i=0;i<=n;++i){
        if ((i>0 && arr[i-1]<=arr[i])||(i-1 != start && i==n)){
        	if(i-1==start){
        	     start++;
        	     continue;
        	}
        	else{
        		dec[dec_count][0]=start;
        		dec[dec_count][1]=i-1;
        		dec_count++;
        		start=i;
        	}
        }
    }
    /*cout<<"INC"<<endl;
    for(int i=0;i<inc_count;i++)
    cout<<i<<" = "<<inc[i][0]<<" - "<<inc[i][1]<<endl;
    cout<<"DEC"<<endl;
    for(int i=0;i<dec_count;i++)
    cout<<i<<" = "<<dec[i][0]<<" - "<<dec[i][1]<<endl;*/

	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		int no_inc=0;
		int no_dec=0;
		bool traversal=true;
		int i=0;
		/*for(i=0;i<inc_count;i++){
			if(l<=inc[i][0] && r>inc[i][1]) no_inc++;
			else if(l>=inc[i][0] && l<inc[i][1] && r>inc[i][1]) no_inc++;
			else if(l<inc[i][0] && r>inc[i][0] && r<=inc[i][1]){
				no_inc++;
				break;
			}
			else if(l>=inc[i][0] && r<=inc[i][1]){
				no_inc++;
				break;
			}
			else if(r<inc[i][0]) break;
		}

		for(i=0;i<dec_count;i++){
			if(l<=dec[i][0] && r>dec[i][1]) no_dec++;
			else if(l>=dec[i][0] && l<dec[i][1] && r>dec[i][1]) no_dec++;
			else if(l<dec[i][0] && r>dec[i][0] && r<=dec[i][1]){
				no_dec++;
				break;
			}
			else if(l>=dec[i][0] && r<=dec[i][1]){
				no_dec++;
				break;
			}
			else if(r<dec[i][0]) break;
		}
*/

		if(((arr[l-1]>arr[l] && arr[r-2]<arr[r-1])||(arr[l-1]<arr[l] && arr[r-2]>arr[r-1]))&& r-l>1) printf("YES\n");
        else printf("NO\n");

        /*if(((arr[r-2]>arr[r-1] && arr[l-1]<arr[l])||(arr[r-2]<arr[r-1] && arr[l-1]>arr[l]))&& r-l>1) printf("YES\n");
        else printf("NO\n");*/
		/*while(traversal && i<inc_count){
			if(l>=inc[i][0] && l<=inc[i][1] && r>inc[i][1]) no_inc++;
			else if(l<inc[i][0] && r>inc[i][0] && r<inc[i][1]){
				no_inc++;
				traversal=false;
			}
			i++;	
		}
		traversal=true;
		i=0;
		while(traversal && i<dec_count){
			if(l>=dec[i][0] && l<=dec[i][1] && r>dec[i][1]) no_dec++;
			else if(l<dec[i][0] && r>dec[i][0] && r<dec[i][1]){
				no_dec++;
				traversal=false;
			}
			i++;	
		}*/
		/*
		if(no_dec==no_inc){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}*/
		/*for(int i=0;i<inc_count;i++){
			if(inc[i][0]>=l && inc[i][1]<=r) no_inc++;
			else if(inc[i][0]>r)
		}*/
	}
}