#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> getDigits(int n){
  vector<int> digits;
  while(n>0){
    digits.push_back(n%10);
    n/=10;
  }
  return digits;
}

void solve(){
  int num;
  cin >> num;
  set<int> sumas;
  vector<int> digitos = getDigits(num);
  reverse(digitos.begin(), digitos.end());
  for (int i = 0; i < pow(2, digitos.size()-1); i++){
    int suma=0;
    int res = digitos.front();
    for (int j = 1; j< (int)digitos.size();j++){
      if ((1 << (j-1)) & i){
        suma += res;
        res=digitos[j];
      } else {
        res = res*10 + digitos[j];
      }
    }
    suma+=res;
    sumas.insert(suma);
  }

  for (set<int>::iterator it = sumas.begin(); *it != *sumas.rbegin(); it++){
    cout << *it << ' ';
  }
  cout << *sumas.rbegin() << "\n";
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}