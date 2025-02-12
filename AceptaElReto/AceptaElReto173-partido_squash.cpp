#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayScore(string scores){
  int A=0, B=0, goal=9;
  char saque = 'A';
  bool newSet =true;
  for (int i=0; i<scores.size();i++){
    if(scores[i]==saque){
      if (saque=='A'){
        A++;
      } else {
        B++;
      }
    }

    saque = scores[i];
    if (saque != 'F'){
      newSet = false;
    }
    if (((A>=goal || B>=goal) && abs(A-B)>=2) || scores[i]== 'F'){
      if (newSet){
        break;
      }
      cout << A << '-' << B;
      A = 0;
      B = 0;
      if (scores[i]!='F' && i != scores.size()-2){
      cout << ' ';
      }
      newSet=true;
    }
  }
  cout << endl;
}

int main(){
  while (true){
    string scores;
    cin >> scores;
    if (scores.front()=='F'){
      break;
    }
    displayScore(scores);
  }
}