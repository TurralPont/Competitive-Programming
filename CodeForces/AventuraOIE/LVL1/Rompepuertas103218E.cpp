#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M; cin >> N >> M;
  vector<int> puertas(N);
  vector<int> fuerzas(M);
  
  for (int & x : puertas) cin >> x;
  for (int & x : fuerzas) cin >> x;

  int total = 0;
  int p=0, f=0;
  while (f < M && p<N){
    if (fuerzas[f] >= puertas[p]) {
      fuerzas[f]-= puertas[p];
      ++p; total++;
    } else {
      f++;
    }
  }

  cout << total << '\n';
  return 0;
}