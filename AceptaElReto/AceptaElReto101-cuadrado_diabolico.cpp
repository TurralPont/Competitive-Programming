#include <iostream>
#include <vector>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  vector<vector<int> > cuadrado(N, vector<int>(N));
  vector<bool> nuevo(N*N+1, true);
  vector<int> columnas(N, 0);
  bool estoterico = true;
  bool diabla = true;

  int magica;

  for (int i=0; i<N; i++){
    int actual=0;
    for (int j=0; j<N; j++){
      int num; cin >> num;
      columnas[j] += num;
      actual+=num;
      if (estoterico && num >= 1 && num <= N*N && nuevo[num]){
        nuevo[num] = false;
      } else {
        estoterico = false;
      }
      cuadrado[i][j] = num;
    }
    if (i==0) magica = actual;

    if (magica != actual){
      diabla = false;
    }
  }

  if (!diabla){
    cout << "NO\n";
    return true;
  } 

  for (int i=0; i<N; i++){
    if (columnas[i] != magica){
      cout << "NO\n";
      return true;
    }
  }

  int sumaDgnIzq = 0;
  int sumaDgnDcha = 0;
  for (int i=0; i<N; ++i){
    sumaDgnIzq += cuadrado[i][i];
    sumaDgnDcha += cuadrado[N-1-i][i];
  }

  if (sumaDgnDcha != sumaDgnIzq && sumaDgnDcha != magica){
    cout << "NO\n";
    return true;
  }

  if (!estoterico) {
    cout << "DIABOLICO\n";
    return true;
  }

  int CM2 = 4 * magica / N;
 
  // se podria simplificar con bucles pero

  int esquinas = cuadrado[0][0] + cuadrado[0][N-1] + cuadrado[N-1][0] + cuadrado[N-1][N-1];
  int centroLados = cuadrado[N/2][0] + cuadrado[(N-1)/2][0];
  centroLados += cuadrado[0][N/2] + cuadrado[0][(N-1)/2];
  centroLados += cuadrado[N/2][N-1] + cuadrado[(N-1)/2][N-1];
  centroLados += cuadrado[N-1][N/2] + cuadrado[N-1][(N-1)/2];
  int centro = cuadrado[N/2][N/2] + cuadrado[(N-1)/2][(N-1)/2] + cuadrado[N/2][(N-1)/2] + cuadrado[(N-1)/2][N/2];

  if (esquinas == CM2){
    if (centro == CM2){
      if (centroLados == 2*CM2){
        cout << "ESOTERICO\n";
        return true;
      }
    }
  }

  cout << "DIABOLICO\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}