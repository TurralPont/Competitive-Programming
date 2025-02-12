#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (!cin) return false;

  stack<pair<int,string> > fechas;
  for (int i=0; i<N; ++i){
    string momento; cin >> momento;
    int muertes; cin >> muertes;
    while(true){
      if (fechas.empty()){
        cout << "NO HAY\n";
        break;
      }
      if (fechas.top().first > muertes){
        cout << fechas.top().second << '\n';
        break;
      } else {
        fechas.pop();
      }
    }
    fechas.push(make_pair(muertes, momento));
  }
  
  cout << "---\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}