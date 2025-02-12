#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > minCharsWordLR; // memoria de resultados

// se podria mejorar el tiempo haciendo un bottom-up en vez de top-down (queria ver diferentes cosas)

int minChars(string & word, int l, int r){
  if (l >= r) { // caso basico
    return minCharsWordLR[l][r] = 0;
  } else if (minCharsWordLR[l][r] != -1){ // si ya se sabe
    return minCharsWordLR[l][r];
  } else if (word[l] == word[r]){ // no se necesita anadir letras
    return minCharsWordLR[l][r] = minChars(word, l+1, r-1);
  } else { // se comprueba si es mas rentable anadir letra por la derecha o izquierda
    return minCharsWordLR[l][r] = 1 + min(minChars(word, l+1, r), minChars(word, l, r-1));
  }
}

bool solve(){
  string word; cin >> word;
  if (!cin) return false;

  int n = word.size();
  minCharsWordLR.assign(n, vector<int>(n, -1));
  cout << minChars(word, 0, n-1) << '\n';

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}