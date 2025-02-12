#include <iostream>
#include <cmath>

using namespace std;

void solve(){
  int n; cin >> n;
  if (n%3 == 1) cout << "NO\n";
  else cout << "SI\n";
}

int main(){
  int T; cin >> T;
  while(T--) solve();
}