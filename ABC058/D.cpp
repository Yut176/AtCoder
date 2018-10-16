#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<cstring>
using namespace std;
long long int mod = 1e9 + 7;
template <class T>
void inputV(vector<T> &x, int n){
  for(int i=0; i<n; i++) cin >> x[i];
}

int main() {
  int n, m; cin >> n >> m;
  vector<long long int> x(n);
  vector<long long int> y(m);
  for(int i=0; i<n; i++) scanf("%lld", &x[i]);
  for(int i=0; i<m; i++) scanf("%lld", &y[i]);

  long long int ansx = 0;
  for(int i=0; i<n; i++){
    ansx += x[i] * (2*i-n+1);
    ansx %= mod;
  }

  long long int ansy = 0;
  for(int i=0; i<m; i++){
    ansy += (y[i] * (2*i-m+1));
    ansy %= mod;
  }
  cerr << ansx << " " << ansy << endl;
  long long int ans = ((ansx%mod) * (ansy%mod))%mod;

  cout << ans << endl;

  return 0;
}
