#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t)
	{
	    t--;
	    int n;
	    cin>>n;int a[n];int b[n];int x=0;int y=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]%2!=0)
	        {
	            x++;
	        }
	        a[i]=a[i]/2;
	    }
	     for(int i=0;i<n;i++)
	    {
	        cin>>b[i];
	        if(b[i]%2!=0)
	        {
	            y++;
	        }
	        b[i]=b[i]/2;
	    }
	    double sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum=sum+a[i]+b[i];
	    }
	    int p=x>y?y:x;
	    long long int answer=sum+p;
	    cout<<answer<<endl;
	}
	return 0;
}