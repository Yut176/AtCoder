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
int INF = 1000000000;

string dir = "ULDR";
string dirR = "DRUL";
int h, w, k, sr, sc;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
vector<int> fr;
vector<int> fc;
vector<int> f;
vector<int> d;
vector<bool> b;
int n;

char search2(vector< vector<int> > field, int sx, int sy, int gx, int gy){
  queue< pair<int, int> > q;
  q.push( make_pair(gx, gy) );
  string s = "";

  while( !q.empty() ){

    pair<int, int> p = q.front();
    q.pop();
    for(int i=0; i<4; i++){
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if( nx < 0 || ny < 0 || nx >= w || ny >= h ) continue;
      if( field[ny][nx] != field[ p.second ][ p.first ] - 1 ) continue;

      q.push( make_pair(nx, ny) );
      s += dirR[i];
      break;
    }

  }
  if( s.size() == 0 ) return '-';
  return s[s.size()-1];
}

char search(vector<string> s, int x, int y){
  vector< vector<int> > field(h, vector<int>(w, INF));

  queue< pair<int, int> > q;
  q.push( make_pair(x, y) );

  field[y][x] = 0;
  while( !q.empty() ){
    pair<int, int> p = q.front();
    q.pop();

    for(int j=0; j<4; j++){
      int nx = p.first + dx[j];
      int ny = p.second + dy[j];
      if( nx < 0 || ny < 0 || nx >= w || ny >= h ) continue;
      if( s[ny][nx] == '#' ) continue;
      if( field[ny][nx] <= field[p.second][p.first] + 1 ) continue;

      field[ny][nx] = field[p.second][p.first] + 1;
      q.push( make_pair(nx, ny) );

    }
  }
  int mn = INF;
  int target = INF;
  for(int i=0; i<n; i++){
    if( !b[i] && mn > field[ fr[i] ][ fc[i] ] && f[ i ] - field[ fr[i] ][ fc[i] ] * d[i] >= 0 ){
      mn = field[ fr[i] ][ fc[i] ];
      target = i;
    }
  }
  if( target == INF ) return '-';

  int gx = fc[ target ];
  int gy = fr[ target ];
  return search2(field, x, y, gx, gy);
}



int main(){

  cin >> h >> w >> k >> sr >> sc;
  sr--;
  sc--;
  vector<string> s(h);
  for(int i=0; i<h; i++) cin >> s[i];

  cin >> n;
  fr.resize(n);
  fc.resize(n);
  f.resize(n);
  d.resize(n);
  b.resize(n, false);
  for(int i=0; i<n; i++){
    cin >> fr[i] >> fc[i] >> f[i] >> d[i];
    fr[i]--;
    fc[i]--;
  }


  string ans = "";
  int turn = 1;
  int x = sc;
  int y = sr;


  while( turn != k ){


    ans += search(s, x, y);
    if( ans[ans.size()-1] == 'U' ) y--;
    else if( ans[ans.size()-1] == 'D' ) y++;
    else if( ans[ans.size()-1] == 'L' ) x--;
    else if( ans[ans.size()-1] == 'R' ) x++;


    for(int i=0; i<n; i++){
      if( x == fc[i] && y == fr[i] ) b[i] = true;
      f[i] -= d[i];
    }
    turn++;
  }
  cout << ans;

  for(int i=0; i<k-ans.size(); i++) cout << "-";
  cout << endl;

  return 0;
}








// EOF
