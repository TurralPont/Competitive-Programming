#include <iostream>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}


void solve() {
  int A, B; cin >> A >> B;
  if (B > A) swap(A, B);

  int d = gcd(A, B);
  A /= d; B /= d;

  cout << A+B-1 << '\n'; 
}

int main() {
  int T; cin >> T;

  while (T--) solve();
  return 0;
}