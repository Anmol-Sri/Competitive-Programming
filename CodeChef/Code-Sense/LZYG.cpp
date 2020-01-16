    #include <stdio.h>
    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    int main(){
    	int t;
    	scanf("%d",&t);
    	while(t--){
    		int r,c;
    		int destr=0,destc=0;
    		int srcr=0,srcc=0;
    		scanf("%d %d",&r,&c);
    		int arr[r][c];
    		for(int i=0;i<r;i++){
    			for(int j=0;j<c;j++){
    				scanf("%d",&arr[i][j]);
    				if(arr[i][j]==1){
    					destr=i;
    					destc=j;
    				}
    				if(arr[i][j]==9){
    					srcr=i;
    					srcc=j;
    				}
    			}
    		}
    		int diag=0;
    		float ans=0.0;
    		if(destc<srcc){
    			if(destr<srcr){
    				while(destr != srcr && destc!=srcc){
    					diag++;
    					srcr--;
    					srcc--;
    				}
    			}
    			else{
    				while(destr != srcr && destc!=srcc){
    					diag++;
    					srcr++;
    					srcc--;
    				}
    			}
    		}
    		else{
    			if(destr<srcr){
    				while(destr != srcr && destc!=srcc){
    					diag++;
    					srcr--;
    					srcc++;
    				}
    			}
    			else{
    				while(destr != srcr && destc!=srcc){
    					diag++;
    					srcr++;
    					srcc++;
    				}
    			}
    		}
    		ans=diag*1.414;
    		if(destr!=srcr && destc==srcc){
    			ans+=(max(destr,srcr)-min(destr,srcr));
    		}
    		else if(destc!=srcc && destr==srcc){
    			ans+=(max(destc,srcc)-min(destc,srcc));	
    		}
    
    		int temp=(int)(ans*1000);
    		if(temp%1000==0){
    			printf("%.2f\n",ans);
    		}
    		else{
    			printf("%.3f\n",ans);
    		}
    	}
    }