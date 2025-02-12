#include <iostream>

using namespace std;

double funcion(int * a, int grado, double num){
  double sum = 0;
  double termino =1;
  for (int i=0; i <= grado; ++i){
    sum += a[i]*termino;
    termino *= num;
  }
  return sum;
}

bool solve(){
  int grado; cin >> grado;
  if (grado == 20) return false;
  int coeficientes[grado+1];
  for (int i=0; i<=grado; i++){
    cin >> coeficientes[grado-i];
  }
  double rectangulos; cin >> rectangulos;
  double cain = 0;

  for (int i=0; i<rectangulos; ++i){
    double num = funcion(coeficientes, grado, (double)i/rectangulos);
    if (num > 1) num = 1;
    if (num > 0) cain += num / rectangulos; 
  }

  cout << (cain < 0.4995? "ABEL\n" : (cain > 0.5005? "CAIN\n" : "JUSTO\n"));
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}