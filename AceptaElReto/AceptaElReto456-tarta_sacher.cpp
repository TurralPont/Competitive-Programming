#include <iostream>
#include <cmath>

using namespace std;

void solve(){
  int n, m, r; cin >> n >> m >> r;
  
  cout << ceil((double)r/(n*m)) << '\n';
}

int main(){
  int T; cin >> T;
  while(T--) solve();
  return 0;
}