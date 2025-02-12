#include <iostream>
#include <string>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;
  char negro; cin >> negro;

  cout << '|';
  for (int i=0; i<8*N; i++){
    cout << '-';
  }
  cout << "|\n";

  string primera = "|";
  string segunda = "|";
  for (int i=0; i<8; ++i){
    for (int j=0; j<N; j++){
      primera.push_back((i%2==0 ? negro : ' '));
      segunda.push_back(i%2!=0 ? negro : ' ');
    }
  }

  primera.append("|\n");
  segunda.append("|\n");

  for (int i=0; i<8; i++){
    for (int j=0; j<N; j++){
      if (i%2==0){
        cout << segunda;
      } else {
        cout << primera;
      }
    }
  }

  cout << '|';
  for (int i=0; i<8*N; i++){
    cout << '-';
  }
  cout << "|\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}