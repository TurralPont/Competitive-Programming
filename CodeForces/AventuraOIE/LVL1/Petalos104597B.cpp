#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e9;

void solve(){
  int N; cin >> N;

  priority_queue<int> flores;
  int minPetalos=INF;
  for (int i=0; i<N; i++){
    int n; cin >> n;
    flores.push(n);
    minPetalos = min(minPetalos, n);
  }

  int i=0;
  while(flores.top() != minPetalos){
    ++i;
    int x = flores.top(); flores.pop();
    x >>= 1;
    minPetalos= min(x, minPetalos);
    flores.push(x);
  }

  cout << i << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}