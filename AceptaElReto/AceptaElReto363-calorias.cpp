#include <iostream>

using namespace std;

bool solve(){
  int E; cin >> E;
  if (E==0) return false;

  int C; cin >> C;
  int total=0;

  for (int i=0; i<C; ++i){
    int EC; cin >> EC;
    total+=EC;
  }
 
  cout << total / E + (total % E != 0) << '\n'; // = ceil(total / E)
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}