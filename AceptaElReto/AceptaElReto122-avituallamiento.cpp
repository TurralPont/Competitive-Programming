#include <iostream>

using namespace std;

bool solve(){
  int prev; cin >> prev;
  if (prev == -1) return false;

  int i=1; 
  int actual; cin >> actual;
  int maxLength=0, maxIndex=0, actualIndex=0, actualLenght=0;
  while(actual != -1){
    if (prev == actual){
      actualLenght++;
    } else if (maxLength < actualLenght){
      maxLength = actualLenght;
      maxIndex=actualIndex;
      actualIndex = i;
      actualLenght = 0;
    } else {
      actualIndex=i;
      actualLenght=0;
    }

    prev = actual;
    cin >> actual;
    ++i;
  }

  if (maxLength < actualLenght){
    maxLength = actualLenght;
    maxIndex=actualIndex;
  }

  if (maxLength == 0) {
    cout << "HOY NO COMEN\n";
    return true;
  }

  cout << maxIndex << ' ' << maxLength << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}