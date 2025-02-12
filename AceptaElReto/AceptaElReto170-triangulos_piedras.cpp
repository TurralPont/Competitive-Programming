#include <iostream>
#include <cmath>

using namespace std;

bool solve(){
  int n; cin >> n;
  if (n == 0) return false;
  int result = (-1+sqrt(8*n + 1)) / 2;

  cout << result << ' ' << n - result*(result+1) / 2 << "\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}