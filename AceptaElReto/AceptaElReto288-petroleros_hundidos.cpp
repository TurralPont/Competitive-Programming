#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ufds {
  int numSets, maxSize;
  vector<int> p;

  ufds(int N) : numSets(N), p(N,-1), maxSize(-1) {}

  int find(int i){
    return (p[i]<0)? i : p[i] = find(p[i]);
  }

  void merge(int i, int j){
    int x = find(i), y = find(j);
    if (p[x] < p[y]) swap(x,y);
    if (x==y) return;
    p[y] += p[x]; p[x] = y;
    if (p[y] < maxSize) maxSize = p[y];
    --numSets;
  }

  int sizcilio() {
    return -maxSize;
  }

};


int modF[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int modC[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int filas, columnas;

int pos(int i, int j){
  return i*columnas+j;
}

bool solve(){
  cin >> filas >> columnas;
  if (!cin) return false;
  vector<string> parcelas(filas, "");
  cin.ignore();

  ufds UFDS(filas*columnas);

  for (int i=0; i<filas; i++){
    getline(cin, parcelas[i]);
  }

  bool pachi=false;
  for (int i=0; i<filas; i++){
    for (int j=0; j<columnas; j++){
      if (!(parcelas[i][j]=='#')) continue;
      int ni, nj;
      pachi = true;
      for (int k=2; k<6;k++){
        ni = i+modF[k]; nj=j+modC[k];
        if (ni >= 0 && nj >= 0 && ni < filas && nj < columnas){
          if (parcelas[ni][nj]=='#') UFDS.merge(pos(ni,nj), pos(i,j));
        }
      }
    }
  }
  if (pachi){
    cout << UFDS.sizcilio();
  } else {
    cout << 0;
  }

  int T; cin >> T;
  for (int i=0; i<T;i++){
    int f, c; cin >> f >> c;
    --f; --c;
    parcelas[f][c] = '#';
    for (int k=0; k<8;k++){
      int ni = f+modF[k], nj=c+modC[k];
      if (ni >= 0 && nj >= 0 && ni < filas && nj < columnas){
        if (parcelas[ni][nj]=='#') UFDS.merge(pos(ni,nj), pos(f,c));
      }
    }
    cout << ' ' << UFDS.sizcilio();
  }

  cout << "\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(solve());
  return 0;
}