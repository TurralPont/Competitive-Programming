#include <iostream>
#include <string>

using namespace std;

int main(){
  int T; cin >> T;
  while(T--){
    cin.ignore(4); 
    string name; cin >> name;
    cout << "Hola, " << name << ".\n";
  }
}