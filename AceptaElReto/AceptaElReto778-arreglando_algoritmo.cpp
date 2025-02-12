#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18+1;

// MLE

bool solve() {
  int N; cin >> N;
  if (N==0) return false;

  long long maximo = -INF, total = 0;

  for (int i=0; i<N; ++i){
    long long x; cin >> x;
    if (x >= maximo) {
      maximo = x;
      total++;
    } else {
      total = 0;
    }
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