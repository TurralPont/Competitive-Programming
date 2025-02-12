#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

#define pii pair<int,int>
#define ppi pair<int, pii>

const int INF = 1e9;

void ilegalizar(set<ppi> & ilegales, vector<vector<pii> > & previus, vector<bool> & processd, int v){
  if (v==1 || processd[v]) return;
  processd[v] = true;
  for (pii x : previus[v]){
    int u = x.first, c = x.second;
    ilegales.insert(ppi(u, pii(v,c)));
    ilegales.insert(ppi(v, pii(u,c)));
    ilegalizar(ilegales, previus, processd, u);
  }
}

bool solve(){
  int V, A;
  cin >> V >> A;
  if (!cin) return false;

  vector<vector<pii> > Calles(V+1);
  for (int i=0; i<A; ++i){
    int u, v, c;
    cin >> u >> v >> c;
    Calles[u].push_back(pii(v,c));
    Calles[v].push_back(pii(u,c));
  }

  priority_queue<pii, vector<pii>, greater<pii> > pq;
  vector<int> dist(V+1, INF);
  vector<vector<pii> > prev(V+1);

  pq.push(pii(0,1));
  dist[1] = 0;
  while(!pq.empty()){
    int coste = pq.top().first, v = pq.top().second;
    pq.pop();

    if (dist[v] < coste) continue;

    for (pii par : Calles[v]){
      int w = par.first, c = par.second;
      if (coste+c < dist[w]){
        dist[w] = coste+c;
        prev[w].clear();
        prev[w].push_back(pii(v, c));
        pq.push(pii(coste+c, w));
      } else if (coste+c == dist[w]){
        prev[w].push_back(pii(v, c));
      }
    }
  }

  set<ppi> ilegales;
  vector<bool> processed(V+1, false);
  ilegalizar(ilegales, prev, processed, V);

  vector<vector<pii> > NuevasCalles(V+1);

  for (int i=1; i<V+1; i++){
    for (pii par : Calles[i]){
      if (!ilegales.count(ppi(i, par))){
        NuevasCalles[i].push_back(par);
      }
    }
  }

  pq.push(pii(0,1));
  dist.assign(V+1, INF);
  dist[1] = 0;

  while(!pq.empty()){
    int coste = pq.top().first, v = pq.top().second;
    pq.pop();

    if (dist[v] < coste) continue;

    for (pii par : NuevasCalles[v]){
      int w = par.first, c = par.second;
      if (coste+c < dist[w]){
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