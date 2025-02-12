#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool solve(){
  int lenCalcetines;
  cin >> lenCalcetines;
  if (lenCalcetines==0) return false;
  set<int> calcetinesSueltos;
  int maximosCalcetines=0;
  while(lenCalcetines--){
    int calcetin;
    cin >> calcetin;
    if (calcetinesSueltos.count(calcetin)){
      calcetinesSueltos.erase(calcetin);
    } else {
      calcetinesSueltos.insert(calcetin);
    }
    maximosCalcetines = max(maximosCalcetines, (int)calcetinesSueltos.size());
  }
  cout << maximosCalcetines << "\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}