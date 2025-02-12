#include <iostream> 

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N == 0) return false;
  bool isIdentity=true;
  for (int i=0; i<N;i++){
    for (int j = 0; j< N; j++){
      int x; cin >> x;
      if (i==j){
        if (x!=1) isIdentity=false;
      } else {
        if (x!=0) isIdentity=false;
      }
    }
  }

  cout << (isIdentity? "SI\n" : "NO\n");
  return true;
}

int main(){
  while(solve());
  return 0;
}