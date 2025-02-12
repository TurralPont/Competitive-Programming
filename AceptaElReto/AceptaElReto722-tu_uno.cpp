#include <iostream>

using namespace std;

bool solve(){
  long long fila1, fila2, ninyo1, ninyo2;
  cin >> fila1 >> fila2 >> ninyo1 >> ninyo2;
  if (fila1==0) return false;

  if (ninyo1 == ninyo2){
    if (fila1 != fila2){
      cout << "NO\n";
    } else {
      cout << (fila1 % ninyo1 == 0 ? "SI\n" : "NO\n");
    }
    return true;
  }

  /*
  sistema de ecuaciones:
   -> n1x + n2y = f1
   -> n2x + n1y = f2
  comprobamos si x, y ∈ ℕ ∧ x, y ≥ 0; (x, y ∈ ℕ0)
  */

  long long arriba = fila2*ninyo1 - fila1*ninyo2;
  long long abajo = ninyo1*ninyo1 - ninyo2*ninyo2;

  long long y = arriba / abajo;

  if (arriba % abajo == 0 && y >= 0){
    cout << ((fila1 - ninyo2 * (arriba/abajo)) % ninyo1 == 0 && fila1 >= ninyo2 * (arriba/abajo) ? "SI\n" : "NO\n");
    return true;
  } 

  cout << "NO\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}