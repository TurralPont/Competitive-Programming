#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

const int INF = pow(2, 31)-1;
vector<vector<pair<int,int> > > Grafo;
vector<int> distancia;

bool solve(){
  int A, V;
  cin >> V >> A;
  if (!cin) return false;
  Grafo.assign(V+1, vector<pair<int,int> >());
  distancia.assign(V+1, INF);
  vector<int> maneras(V+1, 0);

  for (int i = 0; i<A; i++){
    int v, w, c;
    cin >> v >> w >> c;
    Grafo[v].push_back(pair<int,int>(c,w));
    Grafo[w].push_back(pair<int,int>(c,v));
  }

  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > adyacentes;
  adyacentes.push(pair<int,int>(0, 1));
  distancia[1] = 0;
  maneras[1] = 1;

  while(!adyacentes.empty()){
    pair<int,int> vp = adyacentes.top(); adyacentes.pop();
    int v = vp.second, vd = vp.first;

    if (distancia[v] < vd) continue;

    for (pair<int,int> wp : Grafo[v]){
      int w = wp.second, wc = wp.first;
      if (vd + wc < distancia[w]){
        distancia[w] = vd + wc;
        adyacentes.push(pair<int,int>(vd+wc, w));
        maneras[w]=maneras[v];
      } else if (vd + wc == distancia[w]){
        maneras[w]+=maneras[v];
      }
    }
  }

  cout << maneras[V] << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}