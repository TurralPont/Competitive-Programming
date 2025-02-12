#include <iostream>
#include <vector>

using namespace std;

bool solve(){
  int A;
  cin >> A;
  if (A==0) return false;
  int V;
  cin >> V;
  vector<int> gradoVertices(V,0);
  while (A--){
    int u, v;
    cin >> u >> v;
    u--; v--;
    gradoVertices[u]++;
    gradoVertices[v]++;
  }
  int gradosImpares=0;
  for (int i =0; i < V; i++){
    if (gradoVertices[i]%2 == 1){
      gradosImpares++;
    }
  }
  cout << (gradosImpares == 2 || gradosImpares == 0? "SI" : "NO") << "\n";
  return true;
}

int main(){
  while(solve());
  return 0;
}