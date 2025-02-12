#include <iostream>
#include <vector>

using namespace std;

bool solve(){
  int N, M; cin >> N >> M;
  if (!cin) return false;

  vector<int> topings(M, 0);

  for (int i=0; i<N; ++i){
    int p; cin >> p;
    for (int j=0; j<p; ++j){
      int t; cin >> t;
      topings[t]++;
    }
  }

  bool esPosible = true;

  for (int tops : topings){
    if (tops % 8 != 0){
      cout << "NO\n";
      return true;
    }
  }

  cout << "SI\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}