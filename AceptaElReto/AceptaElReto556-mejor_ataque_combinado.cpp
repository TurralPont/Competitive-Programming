#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

// este si que lo copie, pero lo entendi y lo use para el problema "El Movil de Mama"

using namespace std;

bool solve(){
  int mana, N;
  cin >> mana;
  if (0==mana) return false;
  cin >> N;
  vector<int> cartas;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    cartas.push_back(x);
  }
  int max_poder = 0;
  for (int i = 1; i < (1<<N); i++){
    int poder=0;
    for (int j = 0; j <= N; j++){
      if (i & (1<<j)){
        poder+=cartas[j];
      }
    }

    if (poder <= max_poder || poder > mana) continue;

    priority_queue<int, vector<int>, greater<int> > actuales;
    for (int j = 0; j <= N; j++){
      if (i & (1<<j)){
        actuales.push(cartas[j]);
      }
    }

    int actualMana=0;
    while(actuales.size()>1 && actualMana <= mana){
      int c1 = actuales.top(); actuales.pop();
      int c2 = actuales.top(); actuales.pop();
      actuales.push(c1+c2);
      actualMana += c1+c2;
    }

    if (actualMana <= mana){
      max_poder = max(max_poder, poder);
    }
  }

  cout << max_poder << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}