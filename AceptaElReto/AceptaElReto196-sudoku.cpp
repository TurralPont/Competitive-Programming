#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(){
  cin.ignore();
  vector<string> sudoku(9);
  for (int i=0; i<9; i++){
    cin >> sudoku[i];
  }

  int rellenas=0;
  bool simetrico=true;
  for (int i=0; i<5 && simetrico; ++i){
    for (int j=0; j<9; ++j){
      if (i==4 && j== 5) break;
      bool a = sudoku[i][j]!='-';
      bool b = sudoku[8-i][8-j]!='-';
      if (a) {
        ++rellenas;
      }
      if (b && j!=4) ++rellenas;
      if (a!=b){
        simetrico=false;
        break;
      }
    }
  }
  cout << (simetrico && rellenas<=32? "SI\n" : "NO\n");
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}