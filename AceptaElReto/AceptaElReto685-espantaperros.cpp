#include <iostream>

using namespace std;

bool solve(){
  int xt, yt, xi, yi;
  cin >> xt >> yt >> xi >> yi;
  if (xt == xi && yt == yi) return false;

  if (xt == xi || yi==yt || abs(xt-xi) == abs(yt-yi)){
    cout << "SI\n";
  } else {  
    cout << "NO\n";
  }
  return true;
}

int main(){
  while(solve());
  return 0;
}