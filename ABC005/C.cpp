#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<numeric>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

int main(void) {

  int t, n, m;
  cin >> t >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  cin >> m;
  vector<int> b(m);
  for(int i=0; i<m; i++) cin >> b[i];

  if( n < m ){
    cout << "no" << endl;
    return 0;
  }

  int q = 0;
  for(int i=0; i<n; i++){
    cerr << a[i] << " " << t << " " << b[q] << endl;
    if( a[i] <= b[q] && a[i] + t >= b[q] ){
      q++;
    }
  }
  cout << (q == m ? "yes" : "no") << endl;

  return 0;
}










//
