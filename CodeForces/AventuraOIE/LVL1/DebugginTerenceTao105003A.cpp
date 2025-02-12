#include <iostream>

using namespace std;

void solve(){
  int N; cin >> N;

  int a=1, b=1;
  while(b < N && a < N){
    a = a+b;
    b = b+a;
  }

  if (a < N) cout << a << '\n';
  else cout << "OK\n";
}

int main(){
  int T; cin >> T;
  while(T--) solve();
  return 0;
}