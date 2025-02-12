#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

vector<bool> visitados;
vector<pii> guardias;
bool imposiblePasar = false;
int H, W, N;

void DFS(int pos){
  if (visitados[pos] || imposiblePasar) return;
  visitados[pos] = true;

  int x = guardias[pos].first, y = guardias[pos].second;

  if (x >= W-10){
    imposiblePasar = true;
    return;
  }

  for (int i=pos+1; i<N; ++i){
    int nx = guardias[i].first, ny = guardias[i].second;
    if (nx-x > 20) break;
    if (sqrt((nx-x)*(nx-x) + (ny-y)*(ny-y)) <= 20){
      DFS(i);
    }
  }
  for (int i=pos-1; i>=0; --i){
    int nx = guardias[i].first, ny = guardias[i].second;
    if (x-nx > 20) return;
    if (sqrt((nx-x)*(nx-x) + (ny-y)*(ny-y)) <= 20){
      DFS(i);
    }
  }
}

bool solve(){
  cin >> W;
  if (W==0) return false;
  cin >> H >> N;

  guardias.clear();
  visitados.assign(N, false);
  imposiblePasar = false;

  for (int i=0; i<N; ++i){
    int x, y;
    cin >> x >> y;
    guardias.push_back(pii(x,y));
  }

  sort(guardias.begin(), guardias.end());

  for (int i=0; i<N; ++i){
    if (guardias[i].first <= 10){
      DFS(i);
    } else {
      break;
    }
  }

  cout << (imposiblePasar? "NO\n" : "SI\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(solve());
  return 0;
}