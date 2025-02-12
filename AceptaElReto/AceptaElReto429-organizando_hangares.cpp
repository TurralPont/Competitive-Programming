#include <iostream>
#include <queue>

using namespace std;

bool solve(){
  int H; cin >> H;
  if (H==0) return false;

  priority_queue<int> hangares;
  for (int i=0; i<H;i++){
    int espacio; cin >> espacio;
    hangares.push(espacio);
  }

  bool sePuede = true;
  int N; cin >> N;
  while (N--){
    int nave; cin >> nave;
    int espacioHangar = hangares.top(); hangares.pop();
    if (espacioHangar < nave){
      sePuede=false;
    } 
    hangares.push(espacioHangar-nave);
  }

  cout << (sePuede? "SI\n" : "NO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}