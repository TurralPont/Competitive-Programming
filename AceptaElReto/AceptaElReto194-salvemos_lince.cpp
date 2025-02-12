#include <iostream>
#include <string>

using namespace std;

void solve(){
  string carretera;
  getline(cin, carretera);
  int tuneles=0;
  for (int i = 0; i<carretera.size();i++){
    if (carretera[i]== '.'){
      tuneles++;
      i+=2;
    } 
  }
  cout << tuneles << "\n";
}

int main(){
  int t; cin >> t;
  cin.ignore();
  while(t--) solve();
  return 0;
}