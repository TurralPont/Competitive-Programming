#include <iostream>
#include <cmath>
using namespace std;
 
int ask(int x, int y){
  cout << '?' << x << " " << y << '\n' << flush;
  int rp;
  cin >> rp;
  return rp;
}
// Si n (preguntado) es mayor que x (pensado), se imprime 0, si es menor o igual se imprime 1
int main(){
  
    int max = 100, min = 1, half, times = 0, x, y;
    while (0 < max - min){
      half = (max + min) / 2 +1;
      if (ask(half, half)){
        min = half;
      } else {
        max = half-1;
      }
      times += 1;
    }
    x = min;
    max = 100;
    min = 1;
    while (0 < max - min){
      half = (max + min) / 2 +1;
      if (ask(x, half)){
        min = half;
      } else {
        max = half-1;
      }
      times += 1;
    }
    y = min;
    cout << "! " << x << " " << y << '\n' << flush;
  
  return 0;
}