#include <iostream>

using namespace std;

bool solve(){
  int D, N;
  cin >> D >> N;

  if (!cin) return false;

  int prev; cin >> prev;
  int actual, sum=0;
  bool offLimit = false;
  for (int i = 1; i<N; ++i){
    cin >> actual;

    if (actual > prev){
      sum += actual-prev;
    } else {
      if (sum > D){
        offLimit=true;
      }
      sum = 0;
    }

    prev=actual;
  }

  if (sum>D) offLimit=true;

  cout << (offLimit? "NO APTA\n" : "APTA\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}