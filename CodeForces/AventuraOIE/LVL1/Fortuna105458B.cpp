#include <iostream>
#include <string>

using namespace std;

bool isOlder(string a, string b){
  for (int i=4; i<7;i++){ // Miran letras
    if (a[i] < b[i]) return true;
    else if (a[i] > b[i]) return false;
  }

  for (int i=0; i<4; ++i){ // Miran numeros
    if (a[i] < b[i]) return true;
    else if (a[i] > b[i]) return false;
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string minima = "aaaaaaa";

  int T; cin >> T;
  for (int i=0; i<T; ++i){
    string placa; cin >> placa;
    if (isOlder(placa, minima)) minima = placa;
  }

  cout << minima << '\n';
  return 0;
}