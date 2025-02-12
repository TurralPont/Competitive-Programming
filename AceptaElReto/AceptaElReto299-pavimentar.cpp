#include <iostream>
#include <vector>
#include <algorithm>
// Librerias que vamos a usar.
using namespace std;

#define pi pair<int,int> // Acortamos las declaraciones
#define ppi pair<int,pi>

struct ufds { // Estructura UFDS básica
  int numSet;
  vector<int> p;

  ufds(int N) : numSet(N), p(N+1, -1) {}

  int find(int i){
    return p[i] < 0 ? i : p[i] = find(p[i]); // Encontrar raíz
  }

  bool related(int i, int j){ // Devolver true si tienen misma raíz
    return find(i) == find(j);
  }

  void join(int i, int j){ // Unir dos conjuntos disjuntos
    int x = find(i), y = find(j);
    if (x==y) return;
    if (p[x]>p[y]) swap(x,y);
    p[y] += p[x]; p[x] = y;
    numSet--;
  }
};

bool solve(){
  int V, A; // V->vertices, A->aristas
  cin >> V >> A;
  if (!cin) return false;

  ufds Ciudad(V);
  vector<ppi> caminos; //almacenamos las aristas
  for (int i=0; i<A; i++){
    int u, v, c; // u y v, nombres comunes para nodos y c para coste
    cin >> u >> v >> c;
    caminos.push_back(ppi(c, pi(u,v)));
  }

  if (V==1){ // consideramos caso concreto.
    cout <<"0\n";
    return true;
  }

  sort(caminos.begin(), caminos.end()); // Se ordenan las arsitas (Algoritmo de Kruskal)

  int total=0;
  for (ppi camino : caminos){
    int coste = camino.first; // Mismos nombres que antes
    int u = camino.second.first;
    int v = camino.second.second;
    if (!Ciudad.related(u,v)){ // Si no están unidas se unen con el camino, que es el más corto
      total+=coste; // Se suma el coste
      Ciudad.join(u,v);
    }
    if (Ciudad.numSet==1){ // Si la ciudad ya está conectada se acaba el programa
      cout << total << '\n';
      return true;
    }
  }

  cout << "Imposible\n"; // Si no se pudo conectar toda la ciudad es imposible
  return true;
}

int main(){
  ios::sync_with_stdio(false); // Optimización del códgigo, al ser un juez online.
  cin.tie(NULL);

  while (solve()); // Mientras haya otro caso de prueba sigue funcionando el programa
  return 0;
}