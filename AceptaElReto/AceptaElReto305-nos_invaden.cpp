#include <iostream>
#include <queue>

using namespace std;

bool solve(){
  int entrieLength;
  cin >> entrieLength;
  if (!cin) return false;
  int auxEL = entrieLength;
  priority_queue<int, vector<int>, greater<int> > invasores;
  priority_queue<int, vector<int>, greater<int> > defensas;
  while (entrieLength--)
  {
    int num;
    cin >> num;
    invasores.push(num);
  }
  while (auxEL--)
  {
    int num;
    cin >> num;
    defensas.push(num);
  }
  int ciudadesDefendidas=0;
  while(!invasores.empty() && !defensas.empty()){
    if (invasores.top() <= defensas.top()){
      ciudadesDefendidas++;
      defensas.pop();
      invasores.pop();
    } else {
      defensas.pop();
    }
  }
  cout << ciudadesDefendidas << "\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}