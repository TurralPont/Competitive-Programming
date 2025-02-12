#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

bool solve(){
  int N,M; 
  cin >> N;
  if (!cin) return false;
  vector<int> localizaciones(N);
  vector<int> tiempo(N);

  for (int i=0; i<N; ++i){
    cin >> localizaciones[i];
  }
  for (int i=0; i<N; ++i){
    cin >> tiempo[i];
  }
  cin >> M;

  vector<int> curr(M+1, 0);

  for (int pos = N - 2; pos >= 0; --pos) {
    int diferencia = localizaciones[pos + 1] - localizaciones[pos];
    int conCampamentoPrev = curr[M-diferencia], tiempoActual = tiempo[pos];
    int auxSubida;
    for (int subida = M; subida >= 0; --subida) {
      int nuevaSubida = subida - diferencia;

      if (nuevaSubida < 0) {
        auxSubida = subida;
        break;
      } else {
        curr[subida] = min(conCampamentoPrev + tiempoActual, curr[nuevaSubida]);
      }
    }

    for (int s = auxSubida; s >=0; --s){
      curr[s] = conCampamentoPrev + tiempoActual;
    }
  }

  cout << curr[M - localizaciones[0]] << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(solve());
  return 0;
}