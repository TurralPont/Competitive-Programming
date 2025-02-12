#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(){
  int N, P;
  cin >> N >> P;
  if (N==0) return false;

  vector<int> pesos(N);
  for (int i=0; i<N; ++i){
    cin >> pesos[i];
  }
  sort(pesos.begin(), pesos.end());

  long long posibilidades=0;
  int j = N-1, i=0;
  while (i<N && i<j){
    long long suma = pesos[i] + pesos[j];
    if (suma <= P){
      posibilidades += j-i;
      ++i;
    } else {
      --j;
    }
  }

  cout << posibilidades << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}