#include <iostream>
#include <vector>

using namespace std;

bool solve(){
  int N; cin >> N;
  if (N==0) return false;

  vector<int> times(N);
  for (int i=0; i<N; i++){
    cin >> times[i];
  }

  int time=0, maxT = 0;
  for (int i=0; i<10; i++) time+=times[i];

  maxT = time;
  int start=0;

  for (int i=10; i<N; i++){
    time = time + times[i] - times[i-10];
    if (maxT >= time){
      maxT=time;
      start = i-9; // -10+1 (-10 --> elimina, antes)
    }
  }

  cout << start*100 << '-' << (start+10)*100 << ' ' << maxT/60 << ':';
  if (maxT%60 < 10) cout << '0';
  cout << maxT%60 << '\n';

  return true;
}

int main(){
  while(solve());
  return 0;
}