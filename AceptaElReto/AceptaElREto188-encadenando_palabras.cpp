#include <iostream>
#include <string>

using namespace std;

bool solve(){
  string words; getline(cin, words);
  if (!cin) return false;

  for (int i=0; i<words.size(); ++i){
    if (words[i]==' '){
      if (words[i-2] != words[i+1] || words[i-1] != words[i+2]){
        cout << "NO\n";
        return true;
      }
      i+=2;
    }
  }

  cout << "SI\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}