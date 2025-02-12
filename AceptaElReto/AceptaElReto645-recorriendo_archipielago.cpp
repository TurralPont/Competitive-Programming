#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define pi pair<int,int>
#define ppi pair<int, pi >

struct ufds {
  int numSets;
  vector<int> p;

  ufds(int N) : numSets(N), p(N+1, -1) {}

  int find(int i) {
    return p[i] < 0 ? i : p[i] = find(p[i]);
  }

  bool related(int i, int j){
    return find(i)==find(j);
  }

  void join(int i, int j){
    int x = find(i), y = find(j);
    if (x==y) return;
    if (p[x]<p[y]) swap(x,y);
    p[x] += p[y]; p[y] = x;
    numSets--;
  }

};

bool solve(){
  int N, P;
  cin >> N >> P;
  if (!cin) return false;

  ufds Caminos(N);
  priority_queue<ppi, vector<ppi>, greater<ppi> > puentes;

  for (int i=0; i<P; i++){
    int u, v, c;
    cin >> u >> v >> c;
    puentes.push(ppi(c, pi(u,v)));
  }

  if (N==1){
    cout << "0\n";
    return true;
  }

  int costeTotal=0;
  while(!puentes.empty()){
    int u = puentes.top().second.first, v = puentes.top().second.second;
    int c = puentes.top().first;
    puentes.pop();
    
    if (!Caminos.related(u, v)){
      Caminos.join(u,v);
      costeTotal+=c;
    }

    if (Caminos.numSets==1){
      cout << costeTotal << '\n';
      return true;
    }
  }

  cout << "No hay puentes suficientes\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}