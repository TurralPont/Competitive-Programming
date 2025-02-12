#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool solve(){
  int cases; cin >> cases;
  if (cases==0) return false;
  unordered_map<string, int> listaArmas;
  int tam_armas, armas;
  string nombre; 
  while(cases--){
    cin >> nombre >> armas;
    if (nombre=="?"){
      tam_armas=0;
      while(armas--){
        string pers; cin >> pers;
        tam_armas += listaArmas[pers];
        listaArmas[pers]=0;
      }
      cout << tam_armas << "\n";
    } else {
      listaArmas[nombre] += armas;
    }
  }
  cout << "---\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while(solve());
  return 0;
}