#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
  int total =0;
  int p; cin >> p;
  for (int i=0; i<p; ++i){
    int portero; cin >> portero;
    if (total < portero) total = portero;
  }

  int cantidades[3] = {0,0,0};
  vector<pair<int,int> > jugadores;

  for (int i=2; i>=0; --i){
    int c; cin >> c;
    for (int j=0; j<c; ++j){
      int puntos; cin >> puntos;
      jugadores.push_back(pair<int,int>(puntos,i));
    }
  }

  sort(jugadores.begin(), jugadores.end());

  int size = jugadores.size();

  for (int i=0; i < 10; ++i){
    int pos = size - i - 1;
    total += jugadores[pos].first;
    cantidades[jugadores[pos].second]++;
  }
  
  cout << total << ' ' << cantidades[2] << '-' << cantidades[1] << '-' << cantidades[0] << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
}