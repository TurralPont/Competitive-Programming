#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > Grafo;
vector<bool> visited;

void DFS(int i){
  if (visited[i]) return;
  visited[i] = true;

  for (int j=0; j<(int)Grafo[i].size(); j++){
    DFS(Grafo[i][j]);
  }
}

bool solve(){
  int n; cin >> n;
  if (!cin) return false;
  Grafo.assign(n+1, vector<int>());
  for (int i = 1; i<=n; i++) {
    int x; cin >> x;
    Grafo[i].push_back(x);
    Grafo[x].push_back(i);
  }
  int componentes=0;
  visited.assign(n+1, false);

  for (int i=1; i<=n;i++){
    if (!visited[i]){
      componentes++;
      for (int j=0; j<(int)Grafo[i].size(); j++){
        DFS(Grafo[i][j]);
      }
    }
  }

  cout << componentes << "\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}