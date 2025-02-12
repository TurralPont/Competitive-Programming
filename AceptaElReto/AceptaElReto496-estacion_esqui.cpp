#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define pii pair<int,int>
#define piii pair<int, pii>

const int INF = 1e9;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  vector<vector<pii> > subidas(3001);
  vector<vector<pii> > inversaSubidas(3001);
  set<int> puntosDeInteres;

  for (int i=0; i<N; i++){
    int u, v, c;
    cin >> u >> v >> c;
    subidas[u].push_back(pii(c,v));
    inversaSubidas[v].push_back(pii(c,u));

    puntosDeInteres.insert(u);
    puntosDeInteres.insert(v);
  }
  int O, D, M;
  cin >> O >> D >> M;

  puntosDeInteres.insert(O);
  puntosDeInteres.insert(D);

  vector<int> puntos;
  for (set<int>::iterator it = puntosDeInteres.begin(); it!=puntosDeInteres.end(); it++){
    puntos.push_back(*it);
  }

  vector<int> tiempoMinimo(3001, INF);
  priority_queue<pii, vector<pii>, greater<pii> > adyacentes;
  tiempoMinimo[D]=0;
  adyacentes.push(pii(0, D));
  while (!adyacentes.empty()){
    int coste = adyacentes.top().first, altura = adyacentes.top().second;
    adyacentes.pop();

    if (tiempoMinimo[altura] < coste) continue;

    for (pii vertice : inversaSubidas[altura]){
      int destino = vertice.second;
      int tiempo = vertice.first;

      if (tiempo+coste < tiempoMinimo[destino]){
        tiempoMinimo[destino] = tiempo+coste;
        adyacentes.push(pii(tiempo+coste, destino));
      }
    }

    for (int i=puntos.size()-1; i>=0; i--){
      int destino = puntos[i];
      if (destino > altura) {
        int tiempo = destino-altura;
        if (tiempo+coste < tiempoMinimo[destino]){
          tiempoMinimo[destino] = tiempo+coste;
          adyacentes.push(pii(tiempo+coste, destino));
        }
      } 
    }
  }

  if (tiempoMinimo[O]>M) {
    cout << "IMPOSIBLE\n";
    return true;
  }

  priority_queue<piii> pq;
  pq.push(piii(0, pii(0, O)));
  vector<int> bestBajada(3001, 0);

  while(!pq.empty()){
    int bajada = pq.top().first, altura = pq.top().second.second;
    int coste = pq.top().second.first;
    pq.pop();

    for (pii vertice : subidas[altura]){
      int destino = vertice.second;
      int tiempo = vertice.first;
      
      if (tiempo+coste + tiempoMinimo[destino] <= M){
        bestBajada[destino] = max(bestBajada[destino], bajada);
        pq.push(piii(bajada, pii(coste+tiempo, destino)));
      }
    }

    for (int i=puntos.size()-1; i>=0; i--){
      int destino = puntos[i];
      if (destino < altura) {
        int tiempo = altura-destino;

        if (tiempo+coste + tiempoMinimo[destino] <= M){
          bestBajada[destino] = max(bestBajada[destino], bajada+tiempo);
          pq.push(piii(bajada+tiempo, pii(coste+tiempo, destino)));
          break;
        }
        continue;;
      } 
    }
  }
  
  cout << bestBajada[D] << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}