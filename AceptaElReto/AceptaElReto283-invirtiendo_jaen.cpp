#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> parcelas;
vector<vector<bool> > visited;
int modF[4] = {-1, 0, 1, 0};
int modC[4] = {0, 1, 0, -1};

int dfs(int f, int c){
  if (visited[f][c]) return 0;
  visited[f][c] = true;
  int tamanyo=1;
  for (int i=0; i<4;i++){
    int y = c + modC[i];
    int x = f + modF[i];

    if (x >= parcelas.size() || x<0 || y<0 || y >= parcelas[0].size()){
      continue;
    } 

    if (!visited[x][y] && parcelas[x][y]=='#'){
      tamanyo += dfs(x, y);
    }
  }
  return tamanyo;
}

bool solve(){
  int filas, columnas;
  cin >> filas >> columnas;
  if(!cin) return false;
  cin.ignore();
  parcelas.assign(filas, "");
  visited.assign(filas, vector<bool>(columnas, false));
  for (int i=0; i<filas; i++){
    getline(cin, parcelas[i]);
  }

  int max_tam=0;
  for (int i=0; i<filas; i++){
    for (int j=0; j<columnas; j++){
      if (parcelas[i][j]=='#' && !visited[i][j]){
        max_tam = max(max_tam, dfs(i,j));
      }
    }
  }

  cout << max_tam << "\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}