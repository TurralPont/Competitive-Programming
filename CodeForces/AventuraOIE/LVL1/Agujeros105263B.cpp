#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
  int N; cin >> N;

  int start, end=-1;
  int prev;
  cin >> start >> prev;
  vector<int> espacios;
  for (int i=1; i<N; i++){
    int s, e; cin >> s >> e;
    espacios.push_back(s-prev);
    prev = e;
  }
  end = prev;

  int total = end - start;
  sort(espacios.rbegin(), espacios.rend());

  cout << total;
  for (int i=0; i<N-1; ++i){
    total -= espacios[i];
    cout << ' ' << total;
  }
  cout << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}