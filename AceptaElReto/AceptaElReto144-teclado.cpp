#include <iostream>
#include <list>

using namespace std;

bool solve(){
  string entrada; getline(cin, entrada);
  if (!cin) return false;

  list<char> palabra;
  list<char>::iterator it=palabra.begin();
  for (char c : entrada){
    if (c=='+'){
      it=palabra.end();
    } else if (c=='-'){
      it=palabra.begin();
    } else if (c=='*'){
      if (it!=palabra.end()) ++it;
    } else if (c=='3'){
      if (palabra.end()!=it) it = palabra.erase(it);
    } else {
      palabra.insert(it, c);

    }
  }
  
  for (char c : palabra) cout << c;

  cout <<'\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}