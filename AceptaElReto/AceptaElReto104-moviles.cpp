#include <iostream>

using namespace std;

bool balanced = true;

int peso(){
  int p1, d1, p2, d2;
  cin >> p1 >> d1 >> p2 >> d2;

  if (p1==0){
    p1 = peso();
  }
  if (p2==0){
    p2 = peso();
  }

  if (p1*d1 != p2*d2) balanced = false;

  return p1+p2;
}

bool solve(){
  balanced=true;

  int p1, d1, p2, d2;
  cin >> p1 >> d1 >> p2 >> d2;
  if (p1==0 && d1==0 && p2==0 && d2==0) return false;

  if (p1==0){
    p1 = peso();
  }
  if (p2==0){
    p2 = peso();
  }

  if (p1*d1 != p2*d2) balanced = false;

  cout << (balanced? "SI\n" : "NO\n");
  return true;
}

int main(){
  while(solve());
  return 0;
}