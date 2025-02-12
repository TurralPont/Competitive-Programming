#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int,int>

const int INF = 1e9;

bool solve(){
  int N; cin >> N;
  if (!cin) return false;

  vector<int> carga(N+1);
  for (int i=1; i<=N; ++i) cin >> carga[i];

  int M; cin >> M;
  vector<vector<pii> > enlaces(N+1);
  for (int i=0; i<M; ++i){
    int u, v, c;
    cin >> u >> v >> c;
    enlaces[u].push_back(pii(c,v));
  }

  priority_queue<pii, vector<pii>, greater<pii> > pq;
  vector<int> tiempo(N+1, INF);
  pq.push(pii(carga[1], 1));
  tiempo[1] = carga[1];

  while(!pq.empty()){
    int coste = pq.top().first, v = pq.top().second;
    pq.pop();

    if (coste > tiempo[v]) continue;

    for (pii par : enlaces[v]){
      int c = par.first, w = par.second;

      if (coste+c+carga[w] < tiempo[w]){
        tiempo[w] = coste+c+carga[w];
        pq.push(pii(coste+c+carga[w], w));
      }
    }
  }

  if (tiempo[N]==INF) cout << "IMPOSIBLE\n";
  else cout << tiempo[N] << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}