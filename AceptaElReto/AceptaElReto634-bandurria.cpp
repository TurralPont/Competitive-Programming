#include <iostream>
#include <string>

using namespace std;

void solve(){
  string notas;
  cin >> notas;

  int total = 0, prev=0;
  for (char nota : notas){
    if (nota=='O'){
      prev+=10;
      total+=prev;
    } else {
      prev=0;
    }
  }

  cout << total << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}