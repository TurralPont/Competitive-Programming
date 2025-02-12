#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;
  vector<int> tamanos(N);
  for (int & x : tamanos) cin >> x;

  sort(tamanos.begin(), tamanos.end());

  int cuartetos=0, duetos=0;

  int prev=-1, actual=0;
  for (int i=0; i<N; i++){
    if (prev == tamanos[i]){
      actual++;
    } else {
      cuartetos += actual/4;
      duetos += (actual%4) / 2;
      actual=1;
    } 

    prev = tamanos[i];
  }
  
  cuartetos += actual/4;
  duetos += actual % 4 / 2;

  int total = min(cuartetos, duetos);

  if (duetos < cuartetos){
    total += (cuartetos-duetos) * 2 / 3;
  }

  cout << total << '\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}