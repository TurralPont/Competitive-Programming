#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool solve(){
  int N; cin >> N;
  if (!cin) return false;

  int T; cin >> T;
  vector<int> filas;
  vector<int> columnas;
  for (int i = 0; i<T; i++){
    int x, y;
    cin >> x >> y;
    filas.push_back(x);
    columnas.push_back(y);
  }
  sort(filas.begin(), filas.end());
  sort(columnas.begin(), columnas.end());

  cout << (filas[(T-1)/2]) << ' ' << (columnas[(T-1)/2]) << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}