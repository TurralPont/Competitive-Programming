#include <iostream>
#include <map>
#include <string>

using namespace std;

bool solve(){
  int T; cin >> T;
  if (T==0) return false;
  cin.ignore();

  map<string, int> notas;
  for (int i=0; i<T; ++i){
    string nombre; getline(cin, nombre);
    string nota; getline(cin, nota);
    notas[nombre] += (nota == "CORRECTO" ? 1 : -1);
  }

  for (map<string, int>::iterator it = notas.begin(); it!=notas.end(); ++it){
    if ((*it).second == 0) continue;
    cout << (*it).first << ", " << (*it).second << '\n';
  }

  cout << "---\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}