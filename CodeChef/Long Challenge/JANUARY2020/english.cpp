/*#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int calc_prefix(string s1,string s2){
	int l1=s1.length();
	int l2=s2.length();
	string small,large;
	if(l1<l2){
		small=s1;
		large=s2;
	}
	else{
		small=s2;
		large=s1;
	}
	for(int i=0;i<small.length();i++){
		if(small[i]!=large[i])
			return i;
	}
	return small.length();
}

int calc_suffix(string s1,string s2){
	int l1=s1.length();
	int l2=s2.length();
	string small,large;
	if(l1<l2){
		small=s1;
		large=s2;
	}
	else{
		small=s2;
		large=s1;
	}
	for(int i=small.length()-1;i>=0;i--){
		if(small[i]!=large[i])
			return small.length()-i-1;
	}
	return small.length();
}
	
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		string l[n];
		
	}
	return 0;
}*/

#include <iostream>
#include <vector>
#include <string>
typedef unsigned long long int ulli;
using namespace std;
#include <algorithm>

struct Pairs
{
    ulli I,J,W;
};

ulli min(ulli a,ulli b)
{
    if (a<=b)
        return a;
   
    return b;
}

bool compare(Pairs a,Pairs b)
{
    return a.W>b.W;
}

int main()
{
    ulli t;
    cin>>t;
   
    while(t--)
    {
        ulli n,i,j;
        cin>>n;
        string str[n];
        bool visited[n];
       
        for(ulli i=0;i<n;i++)
        {
            cin>>str[i];
            visited[i] = 0;    
        }
       
        vector<Pairs> arr(n/2);
        ulli c=0;
       
        for(i=0;i<n-1;i++)
        {
            ulli leni = str[i].length();
            for(j=i+1;j<n;j++)
            {
                ulli lenj = str[j].length(),k=0;
                ulli lmin = min(leni, lenj);
                bool s=1,p=1;
                ulli pref = 0,suff = 0;
                while (1)
                {
                    if (k>=lmin)
                        break;
                    if((str[i].at(k)==str[j].at(k))&&p)
                        pref++;
                    else
                        p=0;
                   
                    if((str[i].at(leni-1-k)==str[j].at(lenj-1-k))&&s)
                        suff++;
                    else
                        s=0;
                       
                    k++;
                    if(!(s||p))
                        break;
                }
                 
                ulli wt=min(suff,pref);
                if(wt>0)
                {
                    arr.push_back({i,j,wt*wt});
                   
                }
            }
        }
        arr.shrink_to_fit();
        sort(arr.begin(),arr.end(),compare);
        ulli sum=0,count=0;
       
        for(auto i=arr.begin();i!=arr.end();i++)
        {
            if(count>(n/2))
                break;
               
            if (!(visited[(*i).I] || visited[(*i).J]))
            {
                count++;
                sum += (*i).W;
                visited[(*i).I]=1;
                visited[(*i).J]=1;
            }    
        }
       
        cout<<sum<<endl;
    }
}