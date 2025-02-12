#include <iostream>
#include <queue>
#include <vector>
#include <numeric>

using namespace std;

bool solve(){
  int start, end;
  cin >> start >> end;
  if (!cin) return false;

  if (start==end){
    cout << 0 << "\n";
    return true;
  }
  queue<int> adyacentes;
  adyacentes.push(start);
  vector<int> distance(10000, -1);
  distance[start] = 0;
  while(!adyacentes.empty()){
    int v = adyacentes.front(); adyacentes.pop();
    int w1 = (v+1) % 10000, 
        w2 = v * 2 % 10000,
        w3 = v / 3 % 10000;
    if (w1==end || w2 == end || w3 == end){
      cout << distance[v] + 1 << "\n";
      return true;
    }
    if (distance[w1]==-1){
      distance[w1] = distance[v]+1;
      adyacentes.push(w1);
    } 
    if (distance[w2]==-1){
      distance[w2] = distance[v]+1;
      adyacentes.push(w2);
    } 
    if (distance[w3]==-1){
      distance[w3] = distance[v]+1;
      adyacentes.push(w3);
    } 
  }

  cout << "IMPOSIBLE\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}