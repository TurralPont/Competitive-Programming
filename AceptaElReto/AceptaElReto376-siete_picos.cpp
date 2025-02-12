#include <iostream>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  if (N==2){
    int n1, n2; cin >> n1 >> n2;
    if (n1 != n2) cout << "1\n";
    else cout << "0\n";
    return true;
  }

  int first; cin >> first;
  int actual; cin >> actual;
  bool p = first > actual;
  int prev = first, picos=0;
  int next;
  for (int i=2; i<N;i++){
    cin >> next;
    if (actual > next && actual > prev) picos++;
    prev = actual;
    actual = next;
  }
  if (p && first>next) picos++;
  if (prev < next && next > first) picos++;

  cout << picos << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}