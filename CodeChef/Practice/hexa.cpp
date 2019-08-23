#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <long long> vll;
typedef pair <long long, long long> pll;
typedef pair <int, int> pii;
typedef vector <int> vii;
typedef complex <double> Point;
 
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mp make_pair
#define fst first
#define snd second
 
long long t, n, m, u, v, q, k;
const int N = 5e4 + 50;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 61LL;
 
long long arr[N];
string str, ss;
map <char, int> f;
long long fact[N], ifact[N], inv[N];
void pre() {
    fact[1] =fact[0] = ifact[0] = ifact[1] = inv[0] = inv[1] =1;
    for (int i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % mod;
    for (int i = 2; i < N; ++i) inv[i] = (((-(mod/ i) * inv[mod % i]) % mod) + mod) % mod;
    for (int i = 2; i < N; ++i) ifact[i] = (ifact[i - 1] * inv[i]) % mod;
    for (int i = 2; i < N; ++i) {
        if ((fact[i] * ifact[i] % mod) != 1) assert(0);
    }
}
long long cnt[N];
long long C(long long n, long long k) {
    return 0;
}
long long mult = 1, ddiv = 1;
int main(){
  csl;
  cin >> str;
  pre();
  //cout << fact[16] << endl;
  cnt[0] = 1;
  for (int i = 0; i < str.size(); ++i) {
    f[str[i]]++;
  }
  int ct = 0;
  for (map <char, int> :: iterator ii = f.begin(); ii != f.end(); ++ii) {
      if (ii -> first != '0') ct++;
      else continue;
      for (int i = 2000; i >= 0; --i) {
          for (int j = 1; j <= ii -> second; ++j) {
              cnt[i + j] += (cnt[i] * ifact[j]) % mod;
              cnt[i + j] %= mod;
          }
      }
  }
  long long sol = 0;
  for (int i = 1; i <= 2000; ++i) {
     // if (i < 10) cout << cnt[i] << endl;
      for (int j = 0; j <= f['0']; ++j) {
         sol += (((((cnt[i] * fact[i + j - 1]) % mod) * (1LL * i)) % mod) * ifact[j]) % mod;
        sol %= mod;
      }
      //cout << sol << endl;
  }
  if (f['0']) sol++;
  sol %= mod;
  cout << sol << endl;
  return 0;
}
