#include <iostream>

using namespace std;

bool solve(){
  int a, b, c; cin >> a >> b >> c;
  if (!cin) return false;

  if (a < b) swap(a,b);
  if (a < c) swap(a,c);

  cout << (a < b+c ? "si\n" : "no\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}