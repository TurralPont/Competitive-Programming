#include <iostream>

using namespace std;

const int exceptions[5] = {1,1,2,6,4};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;
  while(T--){
    int n; cin >> n;
    if (n>=5){
      cout << "0\n";
    } else {
      cout << exceptions[n] << '\n';
    }
  }
  return 0;
}