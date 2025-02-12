#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

/* 
Funcion(i,j) -> minimo de corte
i -> inicio tablon
j -> final
(no se puede cortar los extremos, bruh)

casos basicos:
 i >= j -> 0
 no hay cortes -> 0
casos recursivos:
 se hace el minimo si cortases cada punto diferente primero, 
 funcion(i, c) + funcion(c, j) + (corte[j] - corte[i])*2

Hacemos solucion iterativa porque asi somos
*/

bool solve(){
  int L, C; cin >> L >> C;
  if (L==0) return false;

  vector<int> cortes(C+2);
  cortes[0] = 0;
  for (int i=1; i<=C; i++){
    cin >> cortes[i];
  }
  cortes[C+1] = L;

  vector<vector<int> > soluciones(C+2, vector<int>(C+2, 0));


  for (int i=C+1; i>=0; --i){
    for (int j=i+1; j<=C+1; ++j){
      int actual = INF;
      for (int k=j-1; k>i; k--){
        actual = min(actual, soluciones[i][k]+soluciones[k][j]);
      }
      soluciones[i][j] = (actual == INF ? 0 : actual + (cortes[j]-cortes[i])*2);
    }
  }

  cout << soluciones[0][C+1] << '\n';
  return true;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}