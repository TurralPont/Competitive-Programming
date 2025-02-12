#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int,int>
#define ppi pair<int, pii>

const int INF = 1e9;

vector<int> dijkstra(int O, vector<vector<pii> > & Grafo){
  int V = Grafo.size()-1;
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  vector<int> dist(V+1, INF);

  pq.push(pii(0,O));
  dist[O] = 0;
  while(!pq.empty()){
    int coste = pq.top().first, v = pq.top().second;
    pq.pop();

    if (dist[v] < coste) continue;

    for (pii par : Grafo[v]){
      int w = par.second, c = par.first;
      if (coste+c < dist[w]){
        dist[w] = coste+c;
        pq.push(pii(coste+c, w));
      } 
    }
  }

  return dist;
}

bool solve(){
  int V, A;
  cin >> V >> A;
  if (!cin) return false;

  vector<vector<pii> > Calles(V+1);
  for (int i=0; i<A; ++i){
    int u, v, c;
    cin >> u >> v >> c;
    Calles[u].push_back(pii(c,v));
    Calles[v].push_back(pii(c,u));
  }

  vector<int> distOrigen = dijkstra(1, Calles), distFinal = dijkstra(V, Calles);
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  vector<int> dist(V+1, INF);

  // dijkstra modificado
  pq.push(pii(0,1));
  dist[1] = 0;
  while(!pq.empty()){
    int coste = pq.top().first, v = pq.top().second;
    pq.pop();

    if (dist[v] < coste) continue;

    for (pii par : Calles[v]){
      int w = par.second, c = par.first;

      // Esto es para evitar las aristas el mejor camino:
      if (coste+c < dist[w] &&  c + min(distOrigen[v]+ distFinal[w], distOrigen[w]+ distFinal[v]) != distOrigen[V]){
        dist[w] = coste+c;
        pq.push(pii(coste+c, w));
      } 
    }
  }

  if (dist[V] == INF) cout << "IMPOSIBLE\n";
  else cout << dist[V] << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false),
  cin.tie(NULL);

  while(solve());
  return 0;
}