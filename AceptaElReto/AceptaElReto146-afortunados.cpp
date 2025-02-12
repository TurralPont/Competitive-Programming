#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool solve(){
  int n; cin >> n;
  if (n==0) return false;
  queue<int> numeros;
  for (int i=1; i<=n;i++) numeros.push(i);

  for (int i = 2; !numeros.empty(); i++){
    if (numeros.size() < i) break;
    numeros.pop();
    int l = numeros.size();
    for (int j=1; j<=l;j++){
      if (j%i!=0) numeros.push(numeros.front());
      numeros.pop();
    }
  }
  cout << n << ':';
  stack<int> rea;
  while (!numeros.empty()) {
    rea.push(numeros.front());
    numeros.pop();
  }
  while (!rea.empty()) {
    cout << ' ' << rea.top();
    rea.pop();
  }
  cout << '\n';
  
  return true;
}

int main(){
  while(solve());
  return 0;
}