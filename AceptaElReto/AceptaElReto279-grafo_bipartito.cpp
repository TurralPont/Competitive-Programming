#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > Grafo;
vector<bool> visited;
vector<bool> colors;
bool isBipartito = true;


void dfs(int vertice, bool clor){
  if (!isBipartito) return;

  if (visited[vertice]){
    if (colors[vertice] != clor){
      isBipartito=false;
    }
    return;
  }

  colors[vertice] = clor;
  visited[vertice] = true;

  for (int i = 0; i < Grafo[vertice].size();i++){
    dfs(Grafo[vertice][i], !clor);
  }

  return;
}

bool solve(){
  int V, A;
  cin >> V >> A;
  isBipartito = true;
  if (!cin) return false;

  Grafo.assign(V, vector<int>(0));
  visited.assign(V, false);
  colors.assign(V, false);

  while (A--)
  {
    int u, v;
    cin >> u >> v;
    Grafo[u].push_back(v);
    Grafo[v].push_back(u);
  }

  for (int i = 0; i<V; i++){
    if (!visited[i]){
      dfs(i, false);
    }
  }

  cout << (isBipartito? "SI":"NO") << "\n";

  return true;
}

int main(){
  while (solve());
  return 0;
}
