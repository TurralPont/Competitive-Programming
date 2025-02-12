#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// se pasa a base nueve (falta ese digito, que da igual cual es)

bool solve(){
  int x, num;
  cin >> num >> x;
  if (num==0 && x==0) return false;
  vector<int> digits;
  while(num>0){
    digits.push_back(num%9);
    num/=9;
  }
  for(int i=digits.size()-1; i>=0; i--){
    cout << (digits[i] >= x? digits[i]+1 : digits[i]);
  }
  cout << "\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}