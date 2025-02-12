#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

struct pii{
  int first;
  int second;
  pii(int n, int m) : first(n), second(m) {};
};

bool operator<(pii a, pii b){
  if (b.second-b.first >= a.second-a.first) return true;
  return false;
}

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  int res=0;
  priority_queue<pii> bases;
  for (int i=0; i<N; i++){
    int s, b, r;
    cin >> s >> b >> r;
    if (s <= b+r) res+=b+r;
    else bases.push(pii(b+r, s));
  }
  int requested=0;
  int restant=0;
  while(!bases.empty()){
    int minus = bases.top().first;
    int necessary = bases.top().second;
    bases.pop();
    if (necessary > restant){
      requested += necessary-restant;
      restant = necessary-minus;
    } else {
      restant -= minus;
    }
  }
  requested += (res <= restant? 0 : res-restant);

  cout << requested << '\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}