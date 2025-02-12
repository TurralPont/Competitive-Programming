#include <iostream>

using namespace std;

bool solve(){
  int l; cin >> l;
  if (l==0) return false; 
  bool top=true, bottom = true;
  for (int i = 0; i<l; i++){
    for (int j=0; j<l; j++){
      int n; cin >> n;
      if (i==j) continue;
      if (n!=0) {
        if (i>j) top = false;
        else bottom = false;
      }
    }
  }

  cout << (bottom || top ? "SI\n" : "NO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}