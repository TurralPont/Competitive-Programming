#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > Grafo;
vector<bool> visited;

int DFS_Length(int v){
  if (visited[v]) return 0;
  visited[v] = true;

  int longitud=1;
  for (int w : Grafo[v]){
    longitud += DFS_Length(w);
  }

  return longitud;
}

void solve(){
  int V, A;
  cin >> V >> A;
  Grafo.assign(V+1, vector<int>());
  visited.assign(V+1, false);

  for (int i = 0; i<A; i++){
    int v, w;
    cin >> v >> w;
    Grafo[v].push_back(w);
    Grafo[w].push_back(v);
  }

  int max_length=0;
  for (int i = 1; i<=V;i++){
    if (!visited[i]){
      max_length = max(max_length, DFS_Length(i));
    }
  }
  
  cout << max_length << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}