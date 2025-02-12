#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> mayusuclas, minusuclas, vocales;

bool solve(){
  string texto;
  getline(cin,texto);

  int constanteMagica = - texto.front() + 'p';
  string desencriptado;
  for (int i =0; i<texto.size();i++){
    if (texto[i] < 'A' || texto[i]>'z' || texto[i]<'a' && texto[i] > 'Z'){
      desencriptado.push_back(texto[i]);
      continue;
    }
    int newChar;
    if (texto[i]<='Z'){
      newChar = texto[i]-'A' + constanteMagica;
      newChar%=26;
      if (newChar<0) newChar += 26;
      desencriptado.push_back(mayusuclas[newChar]);
    } else {
      newChar = texto[i]-'a' + constanteMagica;
      newChar%=26;
      if (newChar<0) newChar += 26;
      desencriptado.push_back(minusuclas[newChar]);
    }
  }
  if (desencriptado=="pFIN") return false;
  int totalVocals=0;
  for (int i = 1; i<desencriptado.size();i++){
    bool isVocal=false;
    for (int j = 0; j<10;j++){
      if (desencriptado[i]==vocales[j]){
        isVocal=true;
        break;
      }
    }
    if (isVocal) totalVocals++;
  }
  cout << totalVocals << endl;
  return true;
}

int main(){
  for (char i = 'A';i<='Z';i++){
    mayusuclas.push_back(i);
    minusuclas.push_back(i+'a'-'A');
  }
  vocales.push_back('a');
  vocales.push_back('e');
  vocales.push_back('i');
  vocales.push_back('o');
  vocales.push_back('u');
  vocales.push_back('A');
  vocales.push_back('E');
  vocales.push_back('I');
  vocales.push_back('O');
  vocales.push_back('U');
  while (solve());
  return 0;
}