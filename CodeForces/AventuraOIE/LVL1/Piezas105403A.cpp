#include <iostream>

using namespace std;

void solve(){
  int N, M; cin >> N >> M;

  int total = 0;

  total += N * (M/3);
  M = M % 3;
  
  total += (N / 3) * M;

  N = N % 3;
  if (N==0 || M==0){

  } else if (N == M && N==2){
    total += 4;
  } else if (N==1 && M==1){
    total += 3;
  } else {
    total += 2;
  }

  cout << total << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}