#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool encontrado; int L;

int toInteger(vector<int> litros){
  int total=0;
  for (int i=0; i<litros.size(); ++i){
    total += litros[i] << 4*i; 
  }
  return total;
}

void DFS(vector<int> & envases, vector<bool> & visited, vector<int> agua){
  int actual = toInteger(agua);
  if (visited[actual] || encontrado) return;
  visited[actual] = true;

  for (int ag : agua){
    if (ag == L) {
      encontrado=true;
      return;
    }
  }

  for (int i=0; i<envases.size(); ++i){
    if (agua[i] < envases[i]) {
      vector<int> aux = agua; aux[i] = envases[i];

      DFS(envases, visited, aux);
    }
    if (agua[i] > 0){
      vector<int> aux = agua; aux[i] = 0;
      DFS(envases, visited, aux);
      
    }

    for (int j=i+1; j<envases.size(); ++j){
      if (agua[j] < envases[j] && agua[i] > 0){
        vector<int> aux = agua; 
        int total = envases[j] - aux[j];
        if (aux[i] >= total){
          aux[i] -= total;
          aux[j] = envases[j];
        } else {
          aux[j] += aux[i];
          aux[i] = 0;
        }
        DFS(envases, visited, aux);
      }
      if (agua[i] < envases[i] && agua[j] > 0){
        vector<int> aux = agua; 
        int total = envases[i] - aux[i];
        if (aux[j] >= total){
          aux[j] -= total;
          aux[i] += total;
        } else {
          aux[i] += aux[j];
          aux[j] = 0;
        }
        DFS(envases, visited, aux);
      }
    }
  }
}

bool solve(){
  int r;
  cin >> L; if (L==0) return false;
  cin >> r;

  encontrado = false;
  vector<int> envases(r);
  
  for (int i=0; i<r; ++i) cin >> envases[i];

  vector<int> litros(r, 0);
  vector<bool> visited(1 << r*4, false);
  DFS(envases, visited, litros);

  cout << (encontrado ? "SI\n" : "NO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}