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
  int V, A; cin >> V >> A;
  if (!cin) return false;
  Grafo.assign(V, vector<int>());
  visited.assign(V, false);
  for(int i =0; i<A; i++){
    int v, w; 
    cin >> v >> w;
    Grafo[v].push_back(w);
    Grafo[w].push_back(v);
  }
  bool isFree=true;
  
  if (A != V-1) {
    isFree = false;
  } else {
    dfs(0);
    for (int i =0; i<V; i++){
      if (!visited[i]){
        isFree = false;
        break;
      }
    }
  }

  cout << (isFree ? "SI" : "NO") << "\n";

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}