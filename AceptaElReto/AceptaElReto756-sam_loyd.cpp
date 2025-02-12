#include <iostream>
#include <vector>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (!cin) return false;

  int cambios=0;
  vector<int> previos;
  previos.push_back(N);

  for (int i=1; i<16; ++i){
    int n; cin >> n;

    for (int num : previos){
      if (num > n){
        cambios++;
      }
    }

    previos.push_back(n);
  }

  cout << (cambios % 2 == 0 ? "SI\n" : "NO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(solve());
  return 0;
}