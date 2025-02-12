#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(){
  int n, d;
  cin >> n >> d;
  deque<int> guirnaldas;
  if (n==0&&d==0) return false;
  while (n--)
  {
    int x; cin >> x;
    guirnaldas.push_back(x);
  }
  sort(guirnaldas.begin(), guirnaldas.end());
  
  int nGr=0;

  while(guirnaldas.size()>=2){
    if (guirnaldas.front()+guirnaldas.back()==d){
      nGr++;
      guirnaldas.pop_back();
      guirnaldas.pop_front();
    } else if (guirnaldas.front()+guirnaldas.back()>d){
      guirnaldas.pop_back();
    } else {
      guirnaldas.pop_front();
    }
  }

  cout << nGr << "\n";

  return true;
}

int main(){
  while(solve());
  return 0;
}