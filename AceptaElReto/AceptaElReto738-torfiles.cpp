#include <iostream>
#include <vector>

using namespace std;

/*
vector<bool> -> lineas horizontales (hay tofil??) menos N
vector<bool> -> diagonales (diagonal -> x-y + C (C=N-1)), espacio -> N - (x-y)
*/

// Mire una solucion para la parte del conteo (como se guarda no), lo escribi yo unos dias despues sin mirarlo

bool solve(){
  int N, P; cin >> N >> P;
  if (!cin) return false;

  vector<bool> horizontales(N,false);
  vector<bool> diagonales(N*2-1, false);
  int C = N-1;

  for (int i=0; i<P; ++i){
    int f, c; cin >> f >> c;
    --f; --c;
    horizontales[f] = true;
    diagonales[f - c + C] = true; 
  }

  vector<int> menores(N);
  int anteriores = 0;

  for (int i=0; i<N; i++){
    if (!horizontales[i]) anteriores++;
    menores[i] = anteriores;
  }

  long long total = 0;

  for (int i=0; i<N*2-1; ++i){
    if (diagonales[i]) continue;

    int ogDiag = i - C;

    if (ogDiag <= 0){
      int diagFinal = N + ogDiag - 1;
      total += menores[diagFinal];
    } else {
      int diagFinal = N-1;
      int diagInicial = ogDiag;
      total += menores[diagFinal] - menores[diagInicial-1];
    }
  }

  cout << total << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}