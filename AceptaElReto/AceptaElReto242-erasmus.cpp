#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  vector<int> estudiantes;

  for(int i=0; i<N; ++i){
    int x; cin >> x;
    estudiantes.push_back(x);
  }

  long long parejas=0;
  long long suma=0;
  
  for (int i=0; i<N; ++i){
    parejas += estudiantes[i]*suma;
    suma += estudiantes[i];
  }

  cout << parejas << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}