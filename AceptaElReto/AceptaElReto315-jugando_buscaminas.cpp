#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> tablero;
vector<string> descubiertas;
vector<vector<bool> >visited;
const int changesFila[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int changesColumna[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool perdiste = false;

bool descubrir(int i, int j){
  if (tablero[i][j]=='*') {
    perdiste=true;
    return false;
  }
  int bombas=0;
  for (int k=0; k<8; k++){
    int ni = i+changesFila[k], nj = j+changesColumna[k];
    if (ni >= 0 && nj >= 0 && ni < tablero.size() && nj < tablero[0].size()){
      if (tablero[ni][nj]=='*') bombas++;
    }
  }
  if (bombas){
    descubiertas[i][j] = bombas+'0';
    return false;
  }
  descubiertas[i][j] = '-';
  return true;
}

void DFS(int i, int j){
  if (visited[i][j]) return;
  visited[i][j] = true;
  for (int k=0; k<8; k++){
    int ni = i+changesFila[k], nj = j+changesColumna[k];
    if (ni >= 0 && nj >= 0 && ni < tablero.size() && nj < tablero[0].size()){
      if (descubrir(ni, nj)) DFS(ni,nj);
    }
  }
}

bool solve(){
  int F, C;
  cin >> F >> C;
  if (!cin) return false;

  perdiste = false;
  tablero.assign(F, "");
  descubiertas.assign(F, string(C, 'X'));
  visited.assign(F, vector<bool>(C,false));

  for (int i=0; i<F; i++){
    cin >> tablero[i];
  }

  int T; cin >> T;
  for (int i=0; i<T;i++){
    int f, c;
    cin >> f >> c;
    f--; c--;
    if (descubrir(f,c)) DFS(f,c);
  }
  if (perdiste) cout << "GAME OVER\n";
  else {
    for (int i=0; i<F; i++){
    cout << descubiertas[i] << '\n';
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}