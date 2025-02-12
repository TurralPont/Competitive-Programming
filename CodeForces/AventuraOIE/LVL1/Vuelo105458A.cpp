#include <iostream>
#include <vector>

using namespace std;

void solve(){
  int N; cin >> N;
  
  vector<int> precios(N, 0);

  int pos=-1, minimo=1e9;

  for (int i=0; i<N; i++){
    int a, b, c; cin >> a >> b >> c;
    if (a+b+c < minimo){
      minimo = a+b+c;
      pos = i;
    }
  }

  cout << pos + 1 << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
}