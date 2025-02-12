#include <iostream>

using namespace std;

bool solve(){
  char dosPuntos;
  int hora, minuto; cin >> hora >> dosPuntos >> minuto;
  if (hora==0 && minuto == 0) return false;

  cout << (23-hora) * 60 + 60-minuto << '\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}