#include <iostream>
#include <cmath>

using namespace std;

int getLength(int n){
  int l=0;
  while (n>0)
  {
    n/=10;
    l++;
  }
  return l;
}

bool solve(){
  int num;
  cin >> num;
  if (num==0) return false;
  int squared = num*num;
  int suma, division=10, modulo=1;
  bool isNum = false;
  for (int i=1;division>9;i++){
    int ten = pow(10,i);
    division = squared / ten;
    modulo = squared % ten;
    suma = division + modulo;
    if (suma == num && modulo != 0){
      isNum = true;
      break;
    }
  }
  cout << (isNum? "SI" : "NO")<< "\n";
  return true;
}

int main(){
  while (solve());
  return 0;
}