#include<bits/stdc++.h>
using namespace std;
long long int dp[401][401]={-1};
int len;
long long int sum(int *a,int l,int r)
{
    long long int i,ans=0;
    for(i=l;i<=r;i++)
        ans=(ans+(*(a+i)));
    return ans;
}
long long int sol(int *a,int l,int r)
{
    if(l>=r)
        return 0;
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    else
    {
        int k;
        dp[l][r]=INT_MAX;
        for(k=l;k<r;k++)
        {
            dp[l][r]=min(dp[l][r],sol(a,l,k)+sol(a,k+1,r)+sum(a,l,k)+sum(a,k+1,r));
        }
        return dp[l][r];
    }
}
void printarr(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%lld - ",dp[i][j]);
		}
		printf("\n");
	}
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	int n;
    	scanf("%d",&n);
    	len=n;
        int a[n],i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<401;i++)
            for(int j=0;j<401;j++)
                dp[i][j]=-1;
        printf("%lld\n",sol(a,0,n-1));
        printarr(n);
    }
    return 0;
}