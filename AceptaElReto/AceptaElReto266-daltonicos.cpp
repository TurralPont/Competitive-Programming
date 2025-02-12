#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> letrasNuevas(26);

bool solve(){
  int I, J;
  cin >> I >> J;
  if (I==0) return false;
  for (int i=0;i<26;i++){
    letrasNuevas[i] = i+'A';
  }

  vector<string> cuadro(I);
  for (int i=0; i<I;i++){
    cin >> cuadro[i];
  }

  int T; cin >> T;
  for (int i =0; i<T;i++){
    char old, nw;
    cin >> old >> nw;
    for(int j=0; j<26;j++){
      if (letrasNuevas[j]==old){
        letrasNuevas[j] = nw;
      } 
    }
  }
  for (int i=0; i<I; i++){
    for (char c : cuadro[i]){
      cout << letrasNuevas[c-'A'];
    }
    cout << '\n';
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}