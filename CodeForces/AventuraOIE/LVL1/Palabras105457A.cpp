#include <iostream>
#include <string>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (!cin) return false;
  string a, b; cin >> a >> b;

  for (int i=0; i<N; ++i){
    if (a[i] == '?') a[i] = 'a';
    if (b[i] == '?') b[i] = 'z';

    if (a[i] > b[i]){
      cout << "no\n";
      return true;
    } else if (a[i] < b[i]){
      cout << "si\n";
      return true;
    }
  }

  cout << "no\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}