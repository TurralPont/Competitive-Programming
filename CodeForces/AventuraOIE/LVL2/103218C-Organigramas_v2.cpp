#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define vii vector<vi>

int func(int i, vii & h, vector<int> & dp){
  if (dp[i] != -1) return dp[i];

  if (h[i].empty()){
    return dp[i] = 1;
  } else if (h[i].size() == 1){
    return dp[i] = func(h[i][0], h, dp)+1;
  } else {
    return dp[i] = 2*min(func(h[i][0], h, dp), func(h[i][1], h, dp)) + 1;
  }
}

void solve(){
  int N; cin >> N;
  vector<vector<int> > hijos(N, vector<int>());
  vector<int> posibles(N, -1);

  for (int i=1; i<N; ++i){
    int p, h; cin >> p >> h;
    hijos[p].push_back(h);
  }

  cout << func(0, hijos, posibles) << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
}