#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solve(){
  string tren; cin >> tren;
  if (!cin) return false;

  int parejas = 0;
  stack<char> hombres;
  for (char c : tren){
    switch (c) {
    case 'H':
      hombres.push(c);
      break;
    case 'h':
      hombres.push(c);
      break;
    case 'M':
      if (!hombres.empty() && hombres.top()=='H'){
        parejas++;
        hombres.pop();
      } else while(!hombres.empty()) hombres.pop();
      break;
    case 'm':
      if (!hombres.empty() && hombres.top()=='h'){
        parejas++;
        hombres.pop();
      } else while(!hombres.empty()) hombres.pop();
      break;
    case '@':
      while(!hombres.empty()) hombres.pop();
      break;
    default:
      break;
    }
  }

  cout << parejas << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}