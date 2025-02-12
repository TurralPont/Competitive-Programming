#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000000;
vector<vector<pair<int,int> > > Comarca;
vector<vector<pair<int,int> > > VolverComarca;

vector<int> dijkstraIr(int o, bool volver){
  vector<int> distancias(Comarca.size(), INF);
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > adyacentes;
  adyacentes.push(pair<int,int>(0, o));
  distancias[o] = 0;
  while(!adyacentes.empty()){
    pair<int,int> vp = adyacentes.top(); adyacentes.pop();
    int cvt = vp.first, v = vp.second;

    if (cvt > distancias[v]) continue;

    for (pair<int,int> wp : (volver ? VolverComarca[v] : Comarca[v])){
      int cw = wp.first, w = wp.second;
      if (cvt + cw < distancias[w]){
        distancias[w] = cvt+cw;
        adyacentes.push(pair<int,int>(cvt+cw, w));
      }
    }
  }
  return distancias;
}

bool solve() {
  int V, A;
  cin >> V >> A;
  if (!cin) return false;
  Comarca.assign(V+1, vector<pair<int,int> >());
  VolverComarca.assign(V+1, vector<pair<int,int> >());

  for (int i=0; i<A; i++){
    int o, d, c;
    cin >> o >> d >> c;
    Comarca[o].push_back(pair<int,int>(c,d));
    VolverComarca[d].push_back(pair<int,int>(c,o));
  }

  int O, P;
  cin >> O >> P;
  int esfuerzo = 0;
  vector<int> ir = dijkstraIr(O, false);
  vector<int> volver = dijkstraIr(O, true);

  bool imposible = false;
  for (int i =0; i<P; i++){
    int destino; cin >> destino;
    if (ir[destino]==INF || volver[destino] == INF) imposible = true;
    if (!imposible) esfuerzo += ir[destino] + volver[destino];
  }

  if (imposible) cout <<  "Imposible\n";
  else cout << esfuerzo << '\n';
  return true;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}