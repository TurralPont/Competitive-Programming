#include <iostream>

using namespace std;

void solve(){
  int F, C, N; cin >> F >> C >> N;

  if (C == 1){
    cout << "AMBOS\n";
    return;
  }

  int fila = N / C - (N%C==0);
  N = (N%C == 0 ? C : N%C);
  bool normal = (fila % 2 == 0);

  if (N == 1){
    cout << (normal ? "VENTANA\n" : "PASILLO\n");
  } else if (N==C){
    cout << (normal ? "PASILLO\n" : "VENTANA\n");
  } else {
    cout << ":(\n";
  }
}

int main(){
  int T; cin >> T;
  while(T--) solve();
  return 0;
}