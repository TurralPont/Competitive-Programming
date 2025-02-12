#include <iostream>
#include <cmath>
#include <unordered_map>
// costo eh
using namespace std;

int getLen(int x){
  int l=0;
  while(x>0){
    x/=10;
    l++;
  }
  return l;
}

unordered_map<int,int> responses;

int digitsFirst(int n){
  int total=0, potencia, mod, first;
  int len = getLen(n);

  while(n>0){
    potencia = pow(10, len-1);
    mod = n % potencia;
    first = n/potencia;
    total += len * ((first-1)*potencia+mod+1);
    n = potencia-1; len--;
  }
  return total;
}

int digits(int n){
  if (n<=0) return 0;
  int total=0, potencia, mod, first;
  int len = getLen(n);
  potencia = pow(10, len-1);
  mod = n % potencia;
  first = n/potencia;
  total += len * ((first-1)*potencia+mod+1);
  n = potencia-1;
  total += responses[n];
  return total;
}

bool solve(){
  int start, end;
  cin >> start >> end;
  if (start==0) return false;

  int quit = digits(start-1);
  int totalDigits = digits(end) - quit;
  int best=0, min=start, max=end, mid, digis;

  while(min <= max){
    mid = (min+max)/2;
    digis = digits(mid) - quit;
    if(digis<=totalDigits/2) {
      best = mid;
      min = mid+1;
    } else {
      max = mid-1;
    } 
    if (digis == totalDigits/2) break;
  }

  cout << best << "\n";
  return true;
}

int main(){
  int p = 999999;
  while(p>0){
    responses[p] = digitsFirst(p);
    p /= 10;
  }
  while(solve());
  return 0;
}