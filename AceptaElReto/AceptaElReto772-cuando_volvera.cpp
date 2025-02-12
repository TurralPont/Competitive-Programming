#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool solve(){
  int year, veces; cin >> year >> veces;
  if (veces == 0) return false;
  
  cout << '[' << year + veces*74 << " .. " << year+ veces*79 << "]\n";

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}