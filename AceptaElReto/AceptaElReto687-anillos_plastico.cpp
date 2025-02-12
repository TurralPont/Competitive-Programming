#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > Grafo;
vector<bool> visited;

void dfs(int v){
  if (visited[v]) return;
  visited[v]=true;
  for (int i=0; i < (int)Grafo[v].size(); i++){
    dfs(Grafo[v][i]);
  }
  return;
}

bool solve(){
  int V; cin >> V;
  if (V==0) return false;
  Grafo.assign(V, vector<int>());
  visited.assign(V, false);
  int A=0;
  while(true){
    int v, w; 
    cin >> v >> w;
    if (v==0) break;
    v--; w--;
    A++;
    if (find(Grafo[v].begin(), Grafo[v].end(), w) == Grafo[v].end()){
      Grafo[v].push_back(w);
      Grafo[w].push_back(v);
    }
  }
  int componentes=0;
  for (int i =0; i<V; i++){
    if (!visited[i]){
      componentes++;
      dfs(i);
    }
  }
  
  cout << (A - V + componentes) << "\n";

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}