#include <iostream>
#include <vector>

using namespace std;

bool solve(){
  int N, L;
  cin >> N >> L;
  if (!cin) return false;

  vector<int> agujeros(N);
  for (int i=0; i<N;i++) cin >> agujeros[i];

  int parches=0, i=0;
  while (i<N){
    int max = agujeros[i]+L;
    parches++;

    while(i<N && agujeros[i]<=max) i++;
  }

  cout << parches << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}