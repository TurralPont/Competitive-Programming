#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(){
  string word; cin >> word;
  if (!cin) return false;

  vector<int> veces(26, 0);
  for (char letra : word){
    veces[letra-'a'] +=1;
  }

  string palindormo="";
  char aux='0';
  for (int i=0; i<26;i++){
    if (veces[i]%2){
      if (aux!='0'){
        cout << "NO HAY\n";
        return true;
      }
      aux = i+'a';
    }
    for (int j=0; j<veces[i]/2;j++){
      palindormo.push_back(i+'a');
    }
  }

  cout << palindormo;
  if (aux!='0') cout << aux;
  reverse(palindormo.begin(), palindormo.end());
  cout << palindormo << "\n";

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  while (solve());
  return 0;
}