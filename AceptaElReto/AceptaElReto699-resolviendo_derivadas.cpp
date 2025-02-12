#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(){
  string ecuation; cin >> ecuation;
  if (!cin) return false;
  vector<int> numeros(20, 0);
  int n=1, l = ecuation.size();
  for (int i=0; i<l;i++){

    if (ecuation[i]=='x'){
      if (i < l-2){
        if (ecuation[i+1]=='^'){
          int exp = ecuation[i+2]-'0';
          int mx = i+2;
          for (int j=i+3; j<l && ecuation[j]!='+';j++){
            exp = exp*10 + ecuation[j]-'0';
            mx = j;
          }
          numeros[exp-1] = n*exp;
          i=mx;
        } else {
          numeros[0] = n;
        } 
      } else {
        numeros[0] = n;
      }
      n = 1;
    } else if (ecuation[i]=='+'){
      n = 0;
      int mx = i;
      for (int j=i+1; j<l && ecuation[j]!='x';j++){
        n = n*10 + ecuation[j]-'0';
        mx = j;
      }
      i = mx;
      if (n==0) n=1;
    } else if (i==0){
      int mx = 0;
      n=0;
      for (int j=0; j<l && ecuation[j]!='x';j++){
        n = n*10 + ecuation[j]-'0';
        mx=j;
      }
      i = mx;
    }
  }
  bool something=false;
  for (int i=19; i>1; i--){
    if (numeros[i]){
      if (something) cout << '+';
      cout << numeros[i] << 'x' << '^' << i;
      something=true;
    }
  }
  if (l > 1 && numeros[1]){
    if (something) cout << '+';
    cout << numeros[1] << 'x';
    something=true;
  } 
  if (numeros[0]){
    if (something) cout << '+';
    cout << numeros[0];
    something=true;
  } 
  if (!something) cout << 0;
  cout << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}