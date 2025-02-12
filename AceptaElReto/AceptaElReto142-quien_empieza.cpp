#include <iostream>
#include <queue>

using namespace std;

bool solve(){
  int ninyos, cadaCuanto;
  cin >> ninyos >> cadaCuanto;
  if (ninyos == 0 && cadaCuanto == 0) return false;
  queue<int> ninyosRestantes;
  for (int i=1;i<=ninyos;i++) ninyosRestantes.push(i);
  while (ninyosRestantes.size()>1){
    for (int i = 0; i < cadaCuanto; ++i){
      ninyosRestantes.push(ninyosRestantes.front());
      ninyosRestantes.pop();
    }
    ninyosRestantes.pop();
  }
  cout << ninyosRestantes.front() << endl;
  return true;
}

int main(){
  while (solve());
  return 0;
}