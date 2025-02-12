#include <iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--){
    int c, n;
    cin >> c >> n;
    int res =  n + n / (c - 1); // usando mates x - x/c = n (simplificar para x)
    cout << res - (n % (c-1) == 0) << ' ' << res << "\n";

  }
}