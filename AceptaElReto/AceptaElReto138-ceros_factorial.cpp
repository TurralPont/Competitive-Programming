#include <iostream>

using namespace std;

void solve(){
  int n; cin >> n;
  int zeros = 0, d = n/5;
  while(d){
    zeros+=d;
    d/=5;
  }
  
  cout << zeros << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}