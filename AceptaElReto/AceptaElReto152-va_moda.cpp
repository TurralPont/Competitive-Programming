#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;
  vector<int> numeros;
  while(N--){
    int n; cin >> n;
    numeros.push_back(n);
  }

  sort(numeros.begin(), numeros.end());
  int prev=-1, actual=-1, max_tam=-1, pos;

  for (int n : numeros){
    if (n==prev) actual++;
    else actual=1;

    prev = n;
    
    if (actual>max_tam){
      max_tam=actual;
      pos=n;
    }
  }

  cout << pos << '\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}