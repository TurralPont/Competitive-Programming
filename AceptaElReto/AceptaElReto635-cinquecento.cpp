#include <iostream>

using namespace std;

void solve(){
  int year; cin >> year;
  cout << (year / 100) + (year%100 > 0) << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}