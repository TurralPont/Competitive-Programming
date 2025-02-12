#include <iostream>
#include <map>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N == 0) return false;

  map<int, long long> previo;

  long long total=0;
  
  for (int i=0; i<N; ++i){
    int color; cin >> color;

    if (previo.count(color)){
      total += i - previo[color]; 
    } 
    previo[color] = i;
  }

  cout << total << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  while(solve());
  return 0;
}