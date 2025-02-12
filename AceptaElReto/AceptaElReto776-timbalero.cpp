#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
  int N; cin >> N;
  if (N==0) return false;

  vector<int> tiempos(N*2);
  for (int & n : tiempos) cin >> n;

  int platillo; cin >> platillo;
  long long total=0;
  vector<int>::iterator l=tiempos.begin(), r = tiempos.end();

  while (platillo != 0){
    vector<int>::iterator it = lower_bound(l,r, platillo);
    l = it;

    if ((it - tiempos.begin()) % 2 == 0 && *it != platillo) ++total;  
    cin >> platillo;
  }

  cout << total << '\n';
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (solve());
  return 0;
}