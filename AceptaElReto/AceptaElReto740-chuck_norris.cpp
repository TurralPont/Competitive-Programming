#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool solve(){
  long long n; cin >> n;
  if (!cin) return false;

  int ordenados=0;
  long long prev=-1;
  
  for(int i = 0; i<n; i++){
    long long x; cin >> x;
    if (x >= prev) ordenados++;
    else ordenados=1;
    prev = x;
  } 

/* Intento de optimización (si funciona, pero mas lento):
  double dN = n, dZ = ordenados;
  int p = log2(dN/(dZ+1));

  while((int)(n/pow(2,p)) > ordenados) p++;

  cout << (int)(n/pow(2,p)) << "\n";
*/
  while(n>ordenados) n/=2;

  cout << n << "\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}