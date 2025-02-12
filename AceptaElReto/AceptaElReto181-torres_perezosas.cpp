#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  vector<string> casillas(N);

  for (int i=0; i<N; ++i){
    cin >> casillas[i];
  }

  vector<int> linea(N); linea[0] = 1;

  for (int j=1; j<N; ++j){
    linea[j] = (casillas[N-1][j] == 'X' ? 0 : linea[j-1]);
  }

  for (int i=N-2; i>=0; --i){
    linea[0] = casillas[i][0] == 'X' ? 0 : linea[0]; 
    for (int j=1; j<N; ++j){
      linea[j] = casillas[i][j] == 'X' ? 0 : linea[j] + linea[j-1];
    }
  }

  cout << linea[N-1] << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}