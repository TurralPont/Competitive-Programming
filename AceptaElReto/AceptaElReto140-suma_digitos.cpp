#include <iostream>
#include <stack>

using namespace std;

bool solve(){
  int num;
  cin >> num;
  if (num <0) return false;

  stack<int> digitos;
  if (num==0) digitos.push(0);
  while (num > 0){
    digitos.push(num%10);
    num /= 10;
  }
  int suma = 0;
  while(digitos.size()>1){
    cout << digitos.top() << " + ";
    suma += digitos.top();
    digitos.pop();
  }
  cout << digitos.top() << " = " << suma + digitos.top() << endl;

  return true;
}

int main(){
  while(solve());
  return 0;
}