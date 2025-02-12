#include <iostream>
#include <vector>

using namespace std;

bool solve(){
  int maximo, tipos; cin >> maximo >> tipos;
  if (maximo == 0) return false;
  
  int total=0;

  vector<int> limite(tipos);
  for (int & n : limite){
    cin >> n;
  }

  for (int i=0; i<tipos; ++i){
    int cantidad; cin >> cantidad;
    total+=cantidad;
    if (limite[i] < cantidad) {
      for (int j=i+1; j<tipos; ++j){
        int n; cin >> n;
      }

      cout << "NO\n";
      return true;
    }
  }

  cout << (total <= maximo ? "SI\n" : "NO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}