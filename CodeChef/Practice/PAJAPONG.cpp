#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
  int t;
  cin >> t;
  while(t--){
    ll x, y, k;
    cin >> x >> y >> k ;
    ll ans = (x+y)/k;
    if(ans%2 != 0)
      cout << "Paja\n";
    else{
      cout << "Chef\n";
    }
  }
}
