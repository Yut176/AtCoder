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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main() {
  int n;
  cin >> n;
  if(n*n <= 201800){
    for(int i=0; i<n; i++){
      cout << string(n, 'X') << endl;
    }
    return 0;
  }
  vector<string> s(n, string(n, 'O'));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if((i+2*j)%5 == 0) s[i][j] = 'X';
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(s[i][j] == 'X'){
        for(int k=0; k<4; k++){
          int nx = j + dx[k];
          int ny = i + dy[k];
          if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
          s[ny][nx] = '.';
        }
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(s[i][j] == 'O') s[i][j] = 'X';
    }
    cout << s[i] << endl;
  }


  return 0;
}
