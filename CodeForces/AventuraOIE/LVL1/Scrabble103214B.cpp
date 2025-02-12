#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
  return a.size() > b.size();
}

int main(){
  int N; cin >> N;

  vector<string> palabras(N);
  for (int i=0; i<N; ++i){
    cin >> palabras[i];
  }
  sort(palabras.begin(), palabras.end(), comp);

  vector<int> letras(26,0);

  for (int i=0; i<7; ++i){
    char c; cin >> c;
    letras[c-'A']++;
  }


  for (string word : palabras){
    vector<int> aux = letras;
    bool esPosible = true;
    
    for (char c : word){
      if (aux[c-'A'] == 0) {
        esPosible = false;
        break;
      }
      else {
        aux[c-'A']--;
      }
    }

    if (esPosible) {
      cout << (word.size() > 3 ? word.size()*2 : word.size()) << '\n';
      return 0;
    }
  }

  cout << "0\n";
  return 0;
}