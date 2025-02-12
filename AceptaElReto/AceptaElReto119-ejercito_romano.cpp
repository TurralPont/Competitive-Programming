#include <iostream>
#include <cmath>

using namespace std;

bool solve(){
  int n; cin >> n;
  if (n==0) return false;

  int escudos = n;
  while(n>1){
    int sq = sqrt(n);
    escudos += sq*4;
    n -= sq*sq;
  }
  if (n) escudos+= 4;

  cout << escudos << "\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}