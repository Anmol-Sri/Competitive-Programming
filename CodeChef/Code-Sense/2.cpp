#include<bits/stdc++.h>
using namespace std;
bool check(int mid, int arr[], int n, int K){
    int c = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid)
            return false;
        sum += arr[i];
        if (sum > mid) {
            c++;
            sum = arr[i];
        }
    }
    c++;
    if (c <= K)
        return true;
    return false;
}
int solve(int arr[], int n, int K){
    int s = 1;
    int e = 0;
    for (int i = 0; i < n; i++) e += arr[i];
    int ans=0;
    while (s<=e) {
        int mid=(s+e)/2;
        if (check(mid, arr, n, K)) {
            ans = mid;
            e = mid - 1;
        }
        else s=mid+1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++)
        cin>>arr[i];
        int m;
        cin>>m;
        if(m>n){
             cout<<-1<<endl;
         continue;
         }
       cout << solve(arr,n,m) <<endl;
       
    }
}