#include <iostream>
#include <vector>

using namespace std;

void solve(){
  int N; cin >> N;

  vector<int> lista(N);
  cin >> lista[N-1];
  for (int i=0; i<N-1; i++){
    cin >> lista[i];
  }

  bool ordenada=true;

  for (int i=0; i<N-1; ++i){
    if (lista[i] > lista[i+1]){
      ordenada = false;
      break;
    }
  }

  if (!ordenada){
    cout << lista[0];
    for (int i=1; i<N; ++i){
      cout << ' ' << lista[i];
    }
    cout << '\n';
  } else {
    cout << lista[N-2] << ' ' << lista[N-1];

    for (int i = 0; i<N-2; ++i){
      cout << ' ' << lista[i];
    }
    cout << '\n';
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}