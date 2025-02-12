#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
  int N; cin >> N;

  vector<int> pares, impares;
  int fila; cin >> fila;
  int num; cin >> num; 
  if (num % 2 == 0) pares.push_back(num);
  else impares.push_back(num);

  bool buenaFila = true;
  for (int i=1; i<N; i++){
    int f, c; cin >> f >> c;
    if (f != fila) buenaFila = false;

    if (c % 2 == 0) pares.push_back(c);
    else impares.push_back(c);
  }

  if (!buenaFila){
    cout << "NO\n";
    return;
  }

  sort(pares.begin(), pares.end());
  sort(impares.begin(), impares.end());
  
  if (!pares.empty()){
    for (int i=0; i< (int)pares.size()-1; ++i){
      if (pares[i+1] - pares[i] != 2){
        cout << "NO\n";
        return;
      }
    }
  }
  
  if (!impares.empty()){
    for (int i=0; i< (int)impares.size()-1; ++i){
      if (impares[i+1] - impares[i] != 2){
        cout << "NO\n";
        return;
      }
    }
  }

  if (impares.empty() || pares.empty()){
    cout << "SI\n";
    return;
  }

  cout << (impares[0] == 1 && pares[0] == 2 ? "SI\n" : "NO\n");
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}