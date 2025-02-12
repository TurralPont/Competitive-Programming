#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pi pair<int,int>

const int INF = 1e9;

void solve(){
  int N, M; cin >> N >> M;

  vector<int> minDist(M, INF); // arrriba
  minDist[0] = 0;
  for (int i=0; i<N; ++i){
    int a, b; cin >> a >> b;
    minDist[b] = min(minDist[b], minDist[a] + 1);
  }

  if (minDist[M-1] >= INF) cout << "Imposible\n";
  else cout << minDist[M-1] << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}