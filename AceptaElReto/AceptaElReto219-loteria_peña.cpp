#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;
  while(T--){
    int n; cin >> n;
    int pares=0;
    while (n--){
      int decimo; cin >> decimo;
      if (decimo%2==0) ++pares;
    }
    cout << pares << '\n';
  }
  return 0;
}