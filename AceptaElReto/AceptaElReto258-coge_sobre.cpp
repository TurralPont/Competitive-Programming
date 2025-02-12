#include <iostream>
#include <queue>
#include <deque>

using namespace std;

void addMaximo(deque<int> & maximos, int num){
  while (!maximos.empty() && maximos.back() < num)
  {
    maximos.pop_back();
  }
  maximos.push_back(num);
}

bool solve(){
  int len, cuantosSobres;
  cin >> len >> cuantosSobres;
  if (len == 0 && cuantosSobres == 0) return false;
  deque<int> maximos;
  queue<int> tramo;
  for (int i = 0; i <cuantosSobres; i++){
    int num;
    cin >> num;
    tramo.push(num);
    addMaximo(maximos, num);
  }
  cout << maximos.front();
  for (int i = cuantosSobres; i<len;i++){
    int num;
    cin >> num;
    tramo.push(num);
    if (tramo.front()==maximos.front()){
      maximos.pop_front();
    }
    tramo.pop();
    addMaximo(maximos, num);
    cout << ' ' << maximos.front();
  }
  cout << "\n";
  return true;
}

int main(){
  while (solve());
  return 0;
}