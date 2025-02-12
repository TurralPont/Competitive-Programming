#include <iostream>
#include <string>

using namespace std;

int getIndex(char c){
  switch (c)
  {
  case 'h':
    return 0;
  case 'o':
    return 1;
  case 'l':
    return 2;
  case 'a':
    return 3;
  default:
    return 4;
  }
}

int main(){
  int T; cin >> T;

  while(T--){
    string word; cin >> word;

    if (word.length() != 4){
      cout << "NO\n";
    } else {
      int n = 0;
      bool letras[5] = {true, true, true, true, false};

      for (char c : word){
        if (letras[getIndex(c)]) {
          n++;
          letras[getIndex(c)] = false;
        }
      }

      cout << (n == 4 ? "SI\n" : "NO\n");
    }
  }

  return 0;
}