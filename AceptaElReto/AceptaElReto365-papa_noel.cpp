#include <iostream>
#include <vector>

using namespace std;

void solve(){
  int tam_ninos, aitor;
  cin >> tam_ninos >> aitor;
  vector<int> ninos;
  while (tam_ninos--)
  {
    int x; cin >> x;
    ninos.push_back(x);
  }
  int tiempo=0;
  for (int i =0; ninos[aitor-1] > 0; i = (i+1) % ninos.size()){
    if (ninos[i]) {
      tiempo += 2;
      ninos[i]--;
    }
  }
  cout << tiempo << "\n";

  return;
}

int main(){
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}