#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool solve() {
  long long prev; scanf("%lld", &prev);
  if (prev == 0) return false;

  long long maximo = prev;
  long long actual; scanf("%lld", &actual);

  while (actual != 0) {
    maximo = max(actual + prev, maximo);
    prev = actual;

    scanf("%lld", &actual);
  }

  printf("%lld\n", maximo);
  return true;
}

int main() {
  while (solve());
  return 0;
}