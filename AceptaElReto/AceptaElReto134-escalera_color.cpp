#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

int convert(char n){
  if (n=='1') return 10;
  if (n <= '9') return n-'0';
  switch (n)
  {
  case 'A':
    return 14;
  case 'J':
    return 11;
  case 'Q':
    return 12;
  case 'K':
    return 13;
  default:
    break;
  }
  return 0;
}

char desConvert(int n){
  if (n==10) {
    cout << '1';
    return '0';
  }
  if (n <= 9) return n+'0';
  switch (n)
  {
  case 14:
    return 'A';
  case 11:
    return 'J';
  case 12:
    return 'Q';
  case 13:
    return 'K';
  default:
    break;
  }
  return 0;
}

bool solve(){
  string nilk; cin >> nilk;
  char n = nilk[0];
  int carta = convert(n);
  if (carta==0) return false;
  char palo; cin >> palo;
  priority_queue<int> cartas;
  cartas.push(carta);

  bool brick=false;
  int mx=carta, mn = carta;
  for (int i=0; i<3; i++){
    char c, p;
    string cr;
    cin >> cr >> p;
    c = cr[0];
    if (p==0) cin >> p;
    if (p != palo){
      brick=true;
    }
    int car = convert(c);
    if (car>mx) mx = car;
    else if (car<mn) mn=car; 
    cartas.push(car);
  }
  if (brick || mx-mn >= 5){
    cout << "NADA\n"; 
  }
  else if (mx-mn==3){
    cout << (mx<=13? desConvert(mx+1) : desConvert(mn-1)) << ' ' << palo << "\n";
  } else {
    int antCart = mx; cartas.pop();
    while (true)
    {
      int cart = cartas.top(); cartas.pop();
      if (antCart - cart!=1) {
        cout << desConvert(cart+1) << ' ' << palo << "\n";
        break;
      }
      antCart = cart;
    }
  }

  return true;
}

int main(){
  while(solve());
  return 0;
}