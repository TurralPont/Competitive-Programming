#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(){
  int fotogramas, copias; cin >> fotogramas >> copias;
  if (fotogramas == 0) return false;
  char coma;

  vector<pair<int,int> > restaurados;

  for (int i=0; i<copias; ++i){
    int partes; cin >> partes;
    for (int j=0; j<partes; ++j){
      int inicio, final; cin >> inicio >> coma >> final;
      restaurados.push_back(pair<int,int>(inicio,final));
    }
  }
  sort(restaurados.begin(), restaurados.end());

  int maximo = 0;
  for (int i=0; i<restaurados.size(); ++i){
    if (restaurados[i].first > maximo+1){
      cout << "NO\n";
      return true;
    }

    maximo = max(maximo, restaurados[i].second);
  }

  cout << (maximo >= fotogramas ? "SI\n" : "NO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(solve());
  return 0;
}