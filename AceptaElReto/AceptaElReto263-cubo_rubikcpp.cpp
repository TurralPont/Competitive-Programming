#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int N;
vector<vector<char> > cuadrado;

void twistColumn(int c){
  int ax = c;
  c = abs(c)-1;
  swap(cuadrado[0][c], cuadrado[N-1][c]);
  if (ax<0){
    for (int i=0; i < N-2;i++){
      swap(cuadrado[i][c], cuadrado[i+1][c]);
    }
  } else {
    for (int i=N-1; i>1;i--){
      swap(cuadrado[i][c], cuadrado[i-1][c]);
    }
  }
  return;
}

void twistRow(int r){
  int ax = r;
  r = abs(r)-1;
  if (ax>0){
    char aux = cuadrado[r].back();
    cuadrado[r].pop_back();
    cuadrado[r].insert(cuadrado[r].begin(), aux);
  } else {
    char aux = cuadrado[r].front();
    cuadrado[r].erase(cuadrado[r].begin());
    cuadrado[r].push_back(aux);
  }
  return;
}

bool solve(){
  cin >> N;
  if (N==0) return false;
  cuadrado.assign(N, vector<char>(N));
  for (int i=0; i<N;i++){
    for (int j=0; j<N;j++){
      char c;
      cin >> c;
      cuadrado[i][j] = c;
    }
  }
  char pedido;
  cin >> pedido;
  while (pedido!='x')
  {
    int pos;
    cin >> pos;
    if (pedido=='c'){
      twistColumn(pos);
    } else {
      twistRow(pos);
    }
    cin >> pedido;
  }

  for (int i=0; i<N;i++){
    for (int j=0; j<N;j++){
      cout << cuadrado[i][j];
    }
    cout << "\n";
  }
  cout << "---\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}