#include <iostream>

using namespace std;

bool solve(){
  long long num, den;
  cin >> num >> den;
  if (den > num) return false;
  long long product=1;

  while (num > den) {
    product *= num;
    num--;
  }
  cout << product << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}