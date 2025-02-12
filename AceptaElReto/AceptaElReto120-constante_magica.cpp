#include <iostream>

using namespace std;

bool solve(){
  int N, K; cin >> N >> K;
  if (N==0) return false;

  cout << (N * (2*K + N*N - 1)/2) << '\n';

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}