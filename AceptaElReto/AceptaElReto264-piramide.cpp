#include <iostream>
#include <cmath>

using namespace std;

bool solve(){
  int n; cin >> n;
  if (!cin) return false;
  int db = n*2;
  for (int i=sqrt(db); i>0; i--){

    if ((db - i * (i + 1)) % (2 * i) == 0){
      cout << i << '\n';
      return true;
    }
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}