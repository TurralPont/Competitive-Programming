#include <iostream>

using namespace std;

void solve(){
  int x, y;
  cin >> x;
  cin.ignore();
  cin >> y;
  if (x > y) swap(x,y);
  if (x%2==0 && y-x==1) cout << "SI\n";
  else cout << "NO\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while (T--) solve();
  return 0;
}