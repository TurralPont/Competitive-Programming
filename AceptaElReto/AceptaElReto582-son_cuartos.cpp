#include <iostream>
#include <string>

using namespace std;

void solve(){
  string campanadas;
  getline(cin , campanadas);
  if (campanadas.length() > 71){ // Empieza con ding-dong
    cout << "SALIDA NULA\n";
  } else if (campanadas.length() == 71){ // 71 -> longitud si hay 12 dongs, dong+espacio = 6, * 12 y -1 al no haber espacio final
    cout << "CORRECTO\n";
  } else if (campanadas.length() == 0){
    cout << "MARISA NARANJO\n"; ///MRISA NO MELISA
  } else { // menor a 71
    cout << "TARDE\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int T; cin >> T;
  cin.ignore(); //Poder usar getline
  while(T--) solve(); 
  return 0;
}