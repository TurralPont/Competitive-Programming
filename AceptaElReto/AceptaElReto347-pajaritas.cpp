#include <iostream>

using namespace std;

int cuadrados(int H, int W){
  if (H < 10 || W < 10) return 0;
  if (W > H) swap(H, W);// H > W
  
  int sumaTotal = H / W;
  sumaTotal += cuadrados(H%W, W);
  return sumaTotal;
}

bool solve(){
  int alto, ancho; cin >> alto >> ancho;
  if (alto == 0 && ancho == 0) return false;

  cout << cuadrados(alto, ancho) << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}