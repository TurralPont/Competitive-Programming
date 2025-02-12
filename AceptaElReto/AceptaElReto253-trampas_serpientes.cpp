#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

bool solve(){
  int N, K, S, E;
  cin >> N >> K >> S >> E;
  if (N==0) return false;
  unordered_map<int, int> saltos;
  for(int i = 0; i<S+E; i++){
    int o, d;
    cin >> o >> d;
    saltos[o] = d;
  }
  unordered_map<int, int> dist;
  queue<int> adyacentes;
  dist[1]=0;
  adyacentes.push(1);
  while(!adyacentes.empty()){
    int v = adyacentes.front(); adyacentes.pop();
    for (int i=1; i<=K; i++){
      if (v+i > N*N) break;
      int w;
      if (saltos.find(v+i)!=saltos.end()){
        w = saltos[v+i];
      } else {
        w = v+i;
      }

      if (dist.find(w) == dist.end()){
        dist[w] = dist[v]+1;
        adyacentes.push(w);
        if (w == N*N){
          cout << dist[w] << "\n";
          return true;
        }
      }
    }
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while(solve());
  return 0;
}