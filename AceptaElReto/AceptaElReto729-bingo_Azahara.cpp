#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  unordered_map<int, vector<int> > bingo; // número --> lista de personas que lo tienen
  vector<int> restantes(N,0); // cuántos números le faltan a cada persona
  vector<string> indexName(N);

  for (int i=0; i<N; i++){
    cin >> indexName[i];
    int n; cin >> n;
    while(n!=0){
      restantes[i]++;
      bingo[n].push_back(i);
      cin >> n;
    }
  }

  set<string> ganadores;
  int K; cin >> K;
  bool ganador = false;
  for (int i=0; i<K; ++i){
    int num; cin >> num;
   
    if (ganador) { // cuando ya hay algun ganador, se ignoran los siguientes números
      for (int j=i+1; j<K; ++j){
        cin >> num;
      }
      break;
    }

    for (int persona : bingo[num]){
      restantes[persona]--;

      if (restantes[persona] == 0){
        ganadores.insert(indexName[persona]);
        ganador=true;
      }
    }
  }

  cout << *(ganadores.begin());

  for (set<string>::iterator it = ++ganadores.begin(); it != ganadores.end(); ++it){
    cout << ' ' << *it;
  }

  cout << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}