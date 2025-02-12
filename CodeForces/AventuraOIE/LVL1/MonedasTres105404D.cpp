#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
  int N; long long price; 
  cin >> N >> price;

  vector<int> coins(N);
  for (int & x : coins) cin >> x;

  sort(coins.rbegin(), coins.rend());

  for (int coin : coins){
    if (price >= coin) price-=coin;
  }

  cout << price << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}