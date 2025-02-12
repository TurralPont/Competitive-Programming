#include <iostream>

using namespace std;

void solve(){
  int n; cin >> n;
  if (n==1){
    cout << "1\n";
    return;
  } 
  int a=1, b=1;
  int total = 2;
  int i=2;
  while(total < n){
    ++i;
    int aux = b;
    b = 2*a + b;
    total+=b;
    a = aux;
  }
  cout << i << '\n';
}

int main(){
  int T; cin >> T;
  while(T--) solve();
  return 0;
}