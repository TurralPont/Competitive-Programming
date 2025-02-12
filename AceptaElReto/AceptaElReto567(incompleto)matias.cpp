#include <iostream>
#include <vector>

using namespace std;

#define pii pair<int,int>

vector<vector<pii> > Grafo;
vector<int> value;

vector<bool> visitedNormal;

vector<int> stateImpar;
vector<int> statePar;
vector<pii> previosPar; // par - impar
vector<pii> previosImpar; // par - impar
// ciclos: 0 -> no visitado, -1 -> visitandose (es un ciclo), 1 -> ya visitado 

// a + b - b -c + c + d --> a + d
// - a - b + b + c - c -d --> - a - d -> -(a+d)
vector<bool> visitedPar;
vector<bool> visitedImpar;

int sumaActual=-1;

void DFS_Normal(int v){
  if (visitedNormal[v]) return;
  visitedNormal[v]=true;

  for (pii par : Grafo[v]){
    value[par.second] = par.first - value[v];
    DFS_Normal(par.second);
  }
}

void DFS_CaminosImpares(int v, int nota, int objetivo, bool par){

}

void recorrerPrevios(int n, int sum, int og, bool par){
  if (n==og){
    cout << "5\n";
    value[n] = sum/2;
    DFS_Normal(n);
  }
  cout << "4\n";

  if (par){
    recorrerPrevios(previosPar[n].first, sum - previosPar[n].second, og, !par);
  } else {
    recorrerPrevios(previosImpar[n].first, sum + previosImpar[n].second, og, !par);
  }
}
// hitler vuelve y matame
void DFS_CiclosImpares(int v, bool par){
  cout << v << ' ' << par << '\n';
  if (par){
    if (estadoPar[v]){
      return;
    }
    estadoPar[v] = true;
  }
  else {
    if (stateImpar[v] == 1) return;
    else if (stateImpar[v]==-1) {
      for (int i=1; i<=3; i++){
        cout << previosImpar[i].first << ' ' << previosImpar[i].second << '\n';
        cout << previosPar[i].first << ' ' << previosPar[i].second << '\n';
        cout << "-----\n";
      }
      exit(0);
      recorrerPrevios(previosImpar[v].first, previosImpar[v].second, v, true);
    }
    stateImpar[v] = -1;
  }
  cout << "2\n";

  for (pii arista : Grafo[v]){
    int w = arista.second;
    if (par && !estadoPar[w]) previosImpar[w] = pii(v, arista.first); 
    else if (!par && stateImpar[w] != 1) previosPar[w] = pii(v, arista.first); 
    cout << "2.1\n";
    DFS_CiclosImpares(w, !par);
  }
  cout << "3\n";

  if (!par) stateImpar[v] = 1;
}

bool solve(){
  int estudiantes, corregidos, examenes;
  cin >> estudiantes >> corregidos >> examenes;

  if (estudiantes==0 && corregidos==0 && examenes==0) return false;

  Grafo.assign(estudiantes+1, vector<pii>());
  visitedNormal.assign(estudiantes+1, false);
  stateImpar.assign(estudiantes+1, 0);
  estadoPar.assign(estudiantes+1, false);
  value.assign(estudiantes+1, -1);
  previosPar.assign(estudiantes+1, pii(-1,-1));
  previosImpar.assign(estudiantes+1, pii(-1,-1));
  /*visitedPar.assign(estudiantes+1, false);
  visitedImpar.assign(estudiantes+1, false);*/

  vector<int> conocidos;

  for (int i=0; i<corregidos; ++i){
    int n; cin >> n;
    int v, u, c;
    if (n==1){
      cin >> v >> c;
      value[v]=c;
      conocidos.push_back(v);
    } else {
      cin >> v >> u >> c;
      Grafo[v].push_back(pii(c,u));
      Grafo[u].push_back(pii(c,v));
    }
  }

  for (int w : conocidos){
    DFS_Normal(w);
  }

  for (int i=1; i<=estudiantes; ++i){
    if (!visitedNormal[i] && !estadoPar[i]){
      cout << "1\n";
      DFS_CiclosImpares(i, true);
    }
  }

  for (int i=0; i<examenes; ++i){
    int n; cin >> n;
    if (n==1){
      int u; cin >> u;
      if (value[u]!=-1){
        cout << value[u] << '\n';
      } else {
        cout << "CUIDADO\n";
      }
    } else {
      int u, v; cin >> u >> v;
      if (value[u]!=-1 && value[v]!=-1){
        cout << value[u]+value[v] << '\n';
      } else {
        visitedPar.assign(estudiantes+1, false);
        visitedImpar.assign(estudiantes+1, false);
        sumaActual=-1;
        DFS_CaminosImpares(u, 0, v, false);
        if (sumaActual!=-1){
          cout << sumaActual << '\n';
        } else {
          cout << "CUIDADO\n";
        }
      }
    }
  }

  cout << "---\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}