#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

bool solve(){
  int T; cin >>T;
  if (T==0) return false;

  priority_queue<int> esquis;
  priority_queue<int> personas;
  int diferencia=0;

  for(int i=0; i<T;i++){
    int n; cin >> n;
    personas.push(n);
  }
  for(int i=0; i<T;i++){
    int n; cin >> n;
    esquis.push(n);
  }

  while(T--){
    int a = esquis.top(); esquis.pop();
    int b = personas.top(); personas.pop();
    diferencia += abs(a-b);
  }
  
  cout << diferencia << "\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}