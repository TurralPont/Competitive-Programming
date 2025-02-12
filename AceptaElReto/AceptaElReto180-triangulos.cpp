#include <iostream>

using namespace std;

void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  if (b>a) swap(a,b);
  if (c>a) swap(a,c);

  if (b+c<=a){
    cout << "IMPOSIBLE\n";
  }
  else if (b*b+c*c==a*a){
    cout << "RECTANGULO\n";
  } else if (b*b+c*c>a*a){
    cout << "ACUTANGULO\n";
  } else {
    cout << "OBTUSANGULO\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}
