#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b){
  if (b==0) return a;
  return gcd(b, a%b);
}

bool solve(){
  int r, L;
  cin >> L; if (L==0) return false;
  cin >> r;

  int cants[4] = {0,0,0,0};
  for (int i=0; i<r; ++i) cin >> cants[i];
  
  int maximo=0;
  for (int i=0; i<r; ++i){
    maximo = max(cants[i], maximo);
  }

  int prev = cants[0];
  for (int i=1; i<r; ++i){
    prev = gcd(prev, cants[i]);
  }

  cout << (L <= maximo && L % prev == 0 ? "SI\n" : "NO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}