#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int,int> > > Grafo; // coste - vertice
vector<bool> visited;

bool BFS(int origen, int destino, int anchura){
  bool sePuede = false;

  queue<int> adyacentes;
  adyacentes.push(origen);

  while(!adyacentes.empty()){
    int w = adyacentes.front(); adyacentes.pop();
    if (visited[w]) continue;
    visited[w] = true;

    for (pair<int,int> v : Grafo[w]){
      if (v.first>=anchura){
        adyacentes.push(v.second);
        if (v.second==destino){
          sePuede=true;
          break;
        }
      }
    }
  }

  return sePuede;
}

bool solve(){
  int V, A;
  cin >> V >> A;
  if (!cin) return false;
  Grafo.assign(V+1, vector<pair<int,int> >());

  for (int i = 0; i<A; i++){
    int v, w, c;
    cin >> v >> w >> c;
    Grafo[v].push_back(make_pair(c,w));
    Grafo[w].push_back(make_pair(c,v));
  }

  int K; cin >> K;
  for (int i=0; i<K; i++){
    visited.assign(V+1, false);
    int o, d, a;
    cin >> o >> d >> a;
    cout << (BFS(o,d,a)? "SI\n" : "NO\n");
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}