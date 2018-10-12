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
int n;
vector< vector<int> > d;
vector< vector<int> > c;
vector< vector<int> > ans;

void init() {
  c.resize(n+50, vector<int> (n+50));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      c[i+1][j+1] = d[i][j];
    }
  }
  for(int i=0; i<n+1; i++){
    for(int j=0; j<n; j++){
      c[i][j+1] += c[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n+1; j++){
      c[i+1][j] += c[i][j];
    }
  }
  for(int i=0; i<n+1; i++){
    for(int j=0; j<n+1; j++){
      cerr << c[i][j] << " ";
    }
    cerr << endl;
  }
  ans.resize(100, vector<int>(100, -1));
}

int func(int h, int w){
  if(ans[h][w] != -1) return ans[h][w];
  int ret = 0;
  for(int i=0; i+h<n+1; i++){
    for(int j=0; j+w<n+1; j++){
      int tmp = c[i+h][j+w] - c[i][j+w] - c[i+h][j] + c[i][j];
      ret = max(ret, tmp);
    }
  }
  ans[h][w] = ret;
  return ret;
}

int solve(int p) {
  int ret = 0;
  for(int i=1; i<=p; i++){
    for(int j=1; j<=p; j++){
      if(i*j > p) continue;
      if(i > n) continue;
      if(j > n) continue;
      ret = max(ret, func(i, j));
      ret = max(ret, func(j, i));
    }
  }
  return ret;
}

int main() {
  cin >> n;
  d.resize(n, vector<int>(n));
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> d[i][j];
  init();
  int q; cin >> q;
  for(int i=0; i<q; i++){
    int p;
    cin >> p;
    cout << solve(p) << endl;
  }

  return 0;
}
//
