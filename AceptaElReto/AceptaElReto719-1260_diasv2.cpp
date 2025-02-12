#include <iostream>
#include <vector>

using namespace std;

const int diasAno[48] = {
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};
const int porCuatroAnos = 1461;

bool solve(){
  int dias; cin >> dias;
  if (dias == 0) return false;
  // ventana deslizante principio (Ano 1) - final (Ano x)
  int total= dias / porCuatroAnos;
  dias = dias % porCuatroAnos;
  int actual = 365*2;

  if (dias == 0 || dias == 30 || dias == 28 || dias == 29){
    cout << "SI\n";
    return true;
  }

  int i=0, j=24; 
  while (i < 48 && actual > 0)
  {
    if (actual == dias){
      cout << "SI\n";
      return true;
    }

    if (actual < dias){
      actual += diasAno[j];
      ++j; j%=48;
    } else {
      actual -= diasAno[i];
      ++i;
    } 
  }
  
  cout << "NO\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}