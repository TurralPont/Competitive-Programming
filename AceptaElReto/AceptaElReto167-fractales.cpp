#include <iostream>
#include <cmath>
using namespace std;

bool solve(){
  int n; cin >> n;
  if (!cin) return false;
  int suma=0;
  for (int i=0; n>0; n/=2,i++) suma += n*pow(2,2*i);
  cout << 4*suma << '\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}