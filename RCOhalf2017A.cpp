#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<random>
#include<map>
#include<queue>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int h, w, k;
int block = 1;
vector< pair<int, int> > ans;

vector< vector<int> > search2(vector<string> s, vector< vector<int> > b, int x, int y, bool one){
  if( b[y][x] != 0 ) return b;

  vector< vector<int> > tmp = b;
  queue< pair<int, int> > q;
  vector< pair<int, int> > anstmp;
  anstmp.push_back( make_pair(x, y) );
  q.push( make_pair(x, y) );
  tmp[y][x] = block;

  while( !q.empty() ){
    pair<int, int> p = q.front();
    q.pop();

    int mx = 0;
    int ppx = p.first;
    int ppy = p.second;
    vector< vector<int> > tmp2 = tmp;
    tmp2[p.second][p.first] = block;

    for(int j=0; j<anstmp.size(); j++){
      for(int i=0; i<4; i++){
        int nx = anstmp[j].first + dx[i];
        int ny = anstmp[j].second + dy[i];

        if( nx < 0 || ny < 0 || nx >= w || ny >= h ) continue;
        if( tmp2[ny][nx] != 0 ) continue;
        if( s[ny][nx] == '0' ) continue;
        if( one && s[ny][nx] == '1' ) continue;

        tmp2[ny][nx] = block;
        if( mx < s[ny][nx]-'0' ){
          mx = s[ny][nx]-'0';
          ppx = nx;
          ppy = ny;
        }
      }
    }
    tmp[ppy][ppx] = block;
    if( ppx == p.first && ppy == p.second ) continue;
    q.push(make_pair(ppx, ppy));
    anstmp.push_back(make_pair(ppx, ppy));

    if( anstmp.size() == 8 ) break;
  }
  if( anstmp.size() == 8 ){
    for(int i=0; i<8; i++) ans.push_back( anstmp[i] );
    for(int i=0; i<8; i++) tmp[anstmp[i].second][anstmp[i].first] = block;
    block++;
    return tmp;
  }

  return b;
}

int main(){

  cin >> h >> w >> k;
  vector<string> s(h);
  for(int i=0; i<h; i++) cin >> s[i];
  vector< vector<int> > b(h, vector<int>(w, 0));

  for(int target=9; target>=0; target--){
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if( s[i][j] == '0' ) continue;
        if( s[i][j]-'0' != target ) continue;
        b = search2(s, b, j, i, true);
      }
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if( s[i][j] == '0' ) continue;
      b = search2(s, b, j, i, false);
    }
  }
  cout << block-1 << endl;
  for(int i=0; i<ans.size(); i++){
    cout << ans[i].second+1 << " " << ans[i].first+1 << endl;
  }

  return 0;
}








// EOF
