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
long long int gcd(long long int a, long long int b){
  if( a == 0 || b == 0 ) return 0;
  long long int c;
  while( a != 0 ){
    c = a; a = b%a; b = c;
  }
  return b;
}
long long int lcm(long long int a, long long int b){
  if( a == 0 || b == 0 ) return 0;
  return ( a / gcd(a, b) ) * b;
}

int main() {
  long long int n, m; cin >> n >> m;
  string s, t;
  cin >> s >> t;
  long long int lp = lcm(n, m);
  long long int ln = lp/n;
  long long int lm = lp/m;
  long long int p = lcm(ln, lm);
  for(long long int i=0; i<lp; i+=p){
    if(i%ln == 0 && i%lm == 0){
      if(s[i/ln] != t[i/lm]){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << lp << endl;

  return 0;
}
