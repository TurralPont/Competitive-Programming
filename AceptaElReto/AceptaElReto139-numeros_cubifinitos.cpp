#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int sumDigitsCube(int x){
  int sum = 0;
  while (x>0)
  {
    sum += pow(x%10,3);
    x/=10;
  }
  return sum;
}

bool solve(){
  int num;
  cin >> num;
  int ogNum = num;
  if (num==0) return false;
  set<int> numerosRepetidos;
  bool notCubifinito = false;
  cout << num << " -";
  while (num != 1){
    numerosRepetidos.insert(num);
    num = sumDigitsCube(num);
    cout << ' ' << num << " -";
    if (numerosRepetidos.count(num)) {
      notCubifinito = true;
      break;
    }
  }
  cout << "> " << (notCubifinito? "no cubifinito.\n" : "cubifinito.\n");
  return true; 
}

int main(){
  while(solve());
  return 0;
}