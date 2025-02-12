#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e9;

bool solve(){
  int p, N;
  cin >> p >> N;
  if (p==0) return false;

  queue<int> personas;
  int actual_tam = 0, min_vag=INF, act_vag=0;
  int pos=-1;

  for (int i=0; i<N; ++i){
    int vagon; cin >> vagon;
    actual_tam+=vagon;
    ++act_vag;
    personas.push(vagon);

    if (actual_tam >= p){
      while(actual_tam-personas.front() >= p){
        actual_tam-=personas.front();
        personas.pop();
        act_vag--;
      }
      if (min_vag > act_vag){
        min_vag=act_vag;
        pos = i-act_vag+2;
      }
    }
  }
  if (pos==-1){
    cout << "NO ENTRAN\n";
    return true;
  }
  cout << min_vag << ' ' << pos << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}