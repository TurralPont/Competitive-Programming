#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int convert(int x, int y, int M){
  return x*M+y;
}

bool valid(int x, int y, int N, int M){
  if (x<0 || y<0 || x>=N || y>=M) return false;
  return true;
}

struct ufds{
  vector<int> p;

  ufds(int N) : p(N, -1) {}

  int find(int v) {
    return (p[v] < 0 ? v : p[v] = find(p[v]));
  }

  bool canTravel(int n, int m){
    if (find(0) == find(n*m-1)) return true;
    return false;
  }

  void merge(int i, int j){
    int x = find(i), y = find(j);
    if (p[x] < p[y]) swap(x, y);
    else if (x==y) return;
    p[x]+=p[y]; p[y] = x;
  }
};

bool solve(){
  int N, M, K, n;
  cin >> N >> M >> K >> n;
  if (!cin) return false;
  N++; M++;
  ufds caminos(N*M);
  vector<bool> hayArbol(N*M);
  stack<pair<int,int> > arboles;

  hayArbol[0] = true;
  hayArbol[N*M-1] = true;
  for (int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    arboles.push(pair<int,int>(x,y));
  }

  while(!arboles.empty()){
    pair<int,int> pos = arboles.top(); arboles.pop();
    int x = pos.first, y = pos.second;
    int ogPos = convert(x,y,M);
    hayArbol[ogPos] = true;
    for (int i=-K; i<=K; i++){
      for (int j=-K; j<=K; j++){
        int nx = x+i, ny = y+j;
        if (nx<0 || nx>=N) break;
        
        int pos = convert(nx, ny, M);
        if (sqrt(i*i+j*j) <= K && valid(nx, ny, N, M) && hayArbol[pos]){
          caminos.merge(pos, ogPos);
        }
      }
    }
    if (caminos.canTravel(N, M)){
      cout << x << ' ' << y << '\n';
      return true;
    }
  }

  cout << "NUNCA SE PUDO\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}