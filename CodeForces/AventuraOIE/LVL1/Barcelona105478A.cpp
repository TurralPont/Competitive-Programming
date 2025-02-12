#include <iostream>
#include <cmath>

using namespace std;

int pointToDiag(int x, int y){
  return abs(x-y);
}

int minDistance(int x1, int x2, int y1, int y2, int fromDiag){
  int toDiag = pointToDiag(x2, y2) + fromDiag;

  int withoutDiag;
  if (x2/10 == x1/10){
    withoutDiag = min(x1%10 + x2%10, 10 - x1%10 + 10 - x2%10) + abs(y2-y1);
  } else if (y2/10 == y1/10) {
    withoutDiag = min(y1%10 + y2%10, 10 - y1%10 + 10 - y2%10) + abs(x2-x1);
  } else {
    withoutDiag = abs(x2-x1) + abs(y2-y1);
  }

  return min(toDiag, withoutDiag);
}

bool solve(){
  int X, Y, N; cin >> X >> Y >> N;
  if(!cin) return false;

  int fromDiag = pointToDiag(X, Y);

  int xn, yn; cin >> xn >> yn;
  cout << minDistance(X, xn, Y, yn, fromDiag);

  for (int i=1; i<N; ++i){
    int x, y; cin >> x >> y;
    cout << ' ' << minDistance(X, x, Y, y, fromDiag);
  }
  cout << '\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}