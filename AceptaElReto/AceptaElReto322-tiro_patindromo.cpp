#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reconstruir(vector<vector<int> > & memoria, string & result, string & word, int l, int r){
  if (l==r){
    result.push_back(word[r]);
  } else if (l>r){
    return;
  } else if (word[l] == word[r]){
    result.push_back(word[l]);
    reconstruir(memoria, result, word, l+1, r-1);
    result.push_back(word[r]);
  } else if (memoria[l+1][r] == memoria[l][r]){
    reconstruir(memoria, result, word, l+1, r);
  } else {
    reconstruir(memoria, result, word, l, r-1);
  }
}

bool solve(){
  string word; cin >> word;
  if (!cin) return false;

  int n = (int)word.size();
  vector<vector<int> > maximoLR(n, vector<int>(n, 0));

  for (int i=0; i<n; ++i){
    maximoLR[i][i] = 1;
  }

  for (int i=1; i<n; i++){
    for (int j=0; j+i<n; ++j){
      int & res = maximoLR[j][j+i];
      int l = j, r = j+i;
      if (word[l]==word[r]){
        res = 2 + maximoLR[l+1][r-1];
      } else {
        res = max(maximoLR[l+1][r], maximoLR[l][r-1]);
      }
    }
  }

/*
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cout << maximoLR[i][j] << ' ';
    }
    cout << '\n';
  }
*/

  string result;
  reconstruir(maximoLR, result, word, 0, n-1);

  cout << result << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}