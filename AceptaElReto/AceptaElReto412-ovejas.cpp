#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Foto;
vector<vector<bool> > visited;
int blancas = 0;

const int modF[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
const int modC[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void DFS_Fondo(int i, int j){
  if (visited[i][j]) return;
  visited[i][j] = true;

  for (int k=0; k<8; k+=2){
    int ni = i+modF[k], nj = j+modC[k];
    if (ni >= 0 && nj >= 0 && ni < Foto.size() && nj < Foto[0].size() && Foto[ni][nj] == '.'){
      DFS_Fondo(ni, nj);
    }
  }
}

void DFS_marcarBlanco(int i, int j){
  if (visited[i][j]) return;
  visited[i][j] = true;

  for (int k=0; k<8; ++k){
    int ni = i+modF[k], nj = j+modC[k];
    if (ni >= 0 && nj >= 0 && ni < Foto.size() && nj < Foto[0].size() && Foto[ni][nj] == '.'){
      DFS_marcarBlanco(ni, nj);
    }
  }
}

void DFS_marcarNegra(int i, int j){
  if (visited[i][j]) return;
  visited[i][j] = true;

  for (int k=0; k<8; ++k){
    int ni = i+modF[k], nj = j+modC[k];
    if (ni >= 0 && nj >= 0 && ni < Foto.size() && nj < Foto[0].size()){
      if (Foto[ni][nj] == 'X'){
        DFS_marcarNegra(ni,nj);
      } else {
        if (!visited[ni][nj]){
          ++blancas;
          DFS_marcarBlanco(ni, nj);
        }
      }
    }
  }
}

bool solve(){
  int W, H; cin >> W >> H;
  if (!cin) return false;

  Foto.assign(H, "");
  visited.assign(H, vector<bool>(W, false));
  blancas = 0;

  for (int i=0; i<H; ++i){
    cin >> Foto[i];
  }

  DFS_Fondo(0, 0);

  for (int i=0; i<H; ++i){
    for (int j=0; j<W; ++j){
      if (Foto[i][j]=='X'){
        DFS_marcarNegra(i, j);
      }
    }
  }

  cout << blancas << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}