#include <iostream>
#include <set>

using namespace std;

const int diasAno[48] = {
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

set<int> combinaciones;

bool solve(){
  int dias; cin >> dias;
  if (dias == 0) return false;
  // ventana deslizante principio (Ano 1) - final (Ano x)
  dias = dias % 1461;

  if (dias == 0 || dias == 30 || dias == 28 || dias == 29 || combinaciones.count(dias)){
    cout << "SI\n";
    return true;
  }
  
  cout << "NO\n";
  return true;
}

int main(){
  // calcular todas las posibilidades

  for (int i=0; i<48; ++i){
    int actual = diasAno[i]+diasAno[i+1];
    for (int j=i+2; j!=i; j= (j+1) % 48){
      combinaciones.insert(actual);
      actual += diasAno[j];
    }
  }

  while(solve());
  return 0;
}