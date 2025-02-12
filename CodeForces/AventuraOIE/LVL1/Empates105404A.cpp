#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
  return a > b;
}

void solve(){
  int N, K; cin >> N >> K;

  vector<int> puntos(N);
  for (int & x : puntos) cin >> x;

  sort(puntos.begin(), puntos.end(), comp);

  cout << (puntos[K] == puntos[K-1] ? "EMPATE\n" : "BIEN\n");
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
}