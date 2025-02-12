#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool solve(){
  int N, K; cin >> N >> K;
  if (N == 0) return false;
  
  long long actual=0, total=0; 
  queue<long long> actuales;
  long long canSec=0, canPri=0; 
  for (int i=0; i<K; ++i){
    int n; cin >> n;
    actuales.push(n);
    actual+=n;
  }
  canPri=actual;
  total=actual;

  for (int i=K; i<N; ++i){
    int n; cin >> n;
    total+=n;

    actual = actual - actuales.front() + n;

    if (actual >= canPri){
      canSec = canPri;
      
    }
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(solve());
  return 0;
}