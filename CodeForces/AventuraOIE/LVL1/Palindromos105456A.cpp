#include <iostream>

using namespace std;

void solve(){
  int a, b, c; cin >> a >> b >> c;

  char impar = '-';

  if (a % 2 == 1){
    impar = 'A';
    a--;
  }

  if (b % 2 == 1){
    if (impar == 'A'){
      cout << "ROP\n";
      return;
    }

    impar = 'B';
    b--;
  }

  if (c % 2 == 1){
    if (impar != '-'){
      cout << "ROP\n";
      return;
    }

    impar = 'C';
    c--;
  }

  a /= 2; b/= 2; c/=2;

  for (int i=0; i<a; ++i){
    cout << 'A';
  }
  for (int i=0; i<b; ++i){
    cout << 'B';
  }
  for (int i=0; i<c; ++i){
    cout << 'C';
  }

  if (impar != '-') cout << impar;
  
  for (int i=0; i<c; ++i){
    cout << 'C';
  }
  for (int i=0; i<b; ++i){
    cout << 'B';
  }
  for (int i=0; i<a; ++i){
    cout << 'A';
  }
  
  cout << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}