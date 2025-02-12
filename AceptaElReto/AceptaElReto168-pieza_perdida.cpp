#include <iostream>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  int total = N*(N+1)/2;
  for (int i=1; i<N; i++){
    int pieza; cin >> pieza;
    total-=pieza;
  }

  cout << total << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}