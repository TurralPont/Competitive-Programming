#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Instrumentos {
  int people, sheets;

  Instrumentos(int ppl, int shts) : people(ppl), sheets(shts) {}

  int mostAround(){
    return people / sheets + (people%sheets != 0);
  }

};

bool operator<(Instrumentos a, Instrumentos b){
  return (b.mostAround() >= a.mostAround());
}

bool solve(){
  int p, n; cin >> p >> n;
  if (!cin) return false;

  p -= n;
  priority_queue<Instrumentos> grupos;
  for (int i=0; i<n;++i){
    int ppl; cin >> ppl;
    grupos.push(Instrumentos(ppl, 1));
  }

  for (int i=0; i<p; ++i){
    Instrumentos concurrido = grupos.top(); grupos.pop();
    concurrido.sheets++;
    grupos.push(concurrido);
  }

  Instrumentos inst = grupos.top();
  cout << inst.mostAround() << '\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}