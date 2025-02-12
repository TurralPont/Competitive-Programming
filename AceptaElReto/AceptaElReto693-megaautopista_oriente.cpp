#include <iostream>
#include <vector>

using namespace std;

bool solve(){
  int N, K; cin >> N >> K;
  if (!cin) return false;

  vector<int> dp(N, -1);
  vector<int> pos(N); for (int & x : pos) cin >> x;
  vector<int> beneficios(N); for (int & x : beneficios) cin >> x;
  int last=N-1; dp[N-1] = beneficios[N-1];

  for (int i=N-2; pos.back() - pos[i] < K && i >= 0; --i){
    dp[i] = max(dp[i+1], beneficios[i]);
    last = i;
  }

  int prev = N; // se va reduciendo
  for (int i = last-1; i>=0; --i){
    int proximo = lower_bound(pos.begin()+i, pos.begin()+prev, pos[i]+K) - pos.begin();
    prev = proximo+1;
    dp[i] = max(dp[i+1], dp[proximo]+beneficios[i]);
  }

  cout << dp[0] << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}