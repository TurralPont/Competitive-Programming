#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Sombrilla {
  int x, y, r;

  Sombrilla(int xi, int yi, int ri) : x(xi), y(yi), r(ri) {}

  bool solapan(Sombrilla a){
    return sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y)) < r + a.r;
  }
};

void solve(){
  int N; cin >> N;
  vector<Sombrilla> playa;

  for (int i=0; i<N; ++i){
    int x, y, r;
    cin >> x >> y >> r;
    Sombrilla sombri(x,y,r);
    playa.push_back(sombri);
  }

  int solapadas = 0;

  for (int i=0; i<N; i++){
    Sombrilla actualSombrilla = playa[i];
    for (int j=i+1; j<N; ++j){
      Sombrilla comparadaSombrilla = playa[j];
      if (actualSombrilla.solapan(comparadaSombrilla)){
        ++solapadas;
      }
    }
  }

  cout << solapadas << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}