#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool solve(){
  int n; cin >> n;
  if (n==0) return false;

  vector<int> migas(n);
  for (int i=0; i<n; i++){
    cin >> migas[i];
  }

  int maxF = -1, sum = migas[n-1];
  int pos = -1;
  for (int i = n-2; i>=0; i--){
    if (migas[i]==sum && maxF <= migas[i]){
      maxF = migas[i];
      pos = i+1;
    } 
    sum+=migas[i];
  }

  if (maxF==-1) cout << "NO\n";
  else cout << "SI " << pos << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}