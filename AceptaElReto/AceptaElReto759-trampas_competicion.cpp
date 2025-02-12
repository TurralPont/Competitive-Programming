#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ufds {
  vector<int> p;

  ufds(int N) : p(N,-1) {};

  int find(int i){
    return (p[i] < 0 ? i : p[i] = find(p[i]));
  }

  void merge(int i, int j){
    int x = find(i), y = find(j);
    if (x==y) return;
    if (p[x] > p[y]) swap(x, y);
    p[y] += p[x]; p[x] = y;
  }

};

vector<int> visits;
vector<vector<int> > adyacentes;
bool bad;

void DFS(int w){
  if (visits[w]==1 || bad) {
    return;
  } else if(visits[w]==-1){
    bad = true;
    return;
  }

  visits[w] = -1;
  for (int v : adyacentes[w]){
    DFS(v);
  }
  visits[w] = 1;
}

vector<bool> zeroIncomes;

bool cyclic(){
  for (int i=1; i<adyacentes.size();i++){
    for (int u : adyacentes[i]){
      zeroIncomes[u] = false;
    }
  }
  for (int i=1; i<adyacentes.size();i++){
    if (zeroIncomes[i]) {
      DFS(i);
    }
  }

  for (int i=1; i<adyacentes.size();i++){
    if (!adyacentes[i].empty() && visits[i]!=1){
      bad=true;
      break;
    }
  }

  return bad;
}

bool solve(){
  int N, C;
  cin >> N >> C;

  if (!cin) return false;

  ufds Personas(N+1);
  queue<pair<int,int> > menores;

  for (int i=0; i<C; i++){
    int a, b;
    char comp;
    cin >> a >> comp >> b;

    if (comp=='='){
      Personas.merge(a,b);
    } else if (comp == '<'){
      menores.push(pair<int,int>(a,b));
    } else {
      menores.push(pair<int,int>(b,a));
    }
  }

  adyacentes.assign(N+1, vector<int>());
  visits.assign(N+1, 0);
  zeroIncomes.assign(N+1, true);
  bad=false;

  while(!menores.empty()){
    int u = menores.front().first, v = menores.front().second;
    u = Personas.find(u);
    v = Personas.find(v);
    menores.pop();
    adyacentes[u].push_back(v);
  }

  cout << (cyclic() ? "TRAMPAS\n" : "DESCONFIADO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(solve());
  return 0;
}