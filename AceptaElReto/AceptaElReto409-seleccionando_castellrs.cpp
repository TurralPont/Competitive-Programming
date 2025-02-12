#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solve(){
  int porNivel, tam_ppl;
  cin >> porNivel >> tam_ppl;

  deque<int> nivel;
  vector<int> castellrs;
  for (int i = 0; i<tam_ppl; i++){
    int num;
    cin >> num;
    castellrs.push_back(num);
  }

  if (porNivel>tam_ppl)
  {
    cout << 0 << "\n";
    return;
  }
  
  sort(castellrs.begin(), castellrs.end());

  for (int i=0; i<porNivel && i<tam_ppl; i++){
    nivel.push_back(castellrs[i]);
  }
  int max_niveles=0;

  if (nivel.back() - nivel.front() <= 15){
    max_niveles++;
    nivel.clear();
  }
  for (int i = porNivel; i < tam_ppl; i++)
  {
    if (nivel.empty()){
      for (int j=i; j<porNivel+i && j<tam_ppl; j++){
        nivel.push_back(castellrs[j]);
      }
      i+=porNivel-1;
    } else {
      nivel.pop_front();
      nivel.push_back(castellrs[i]);
    }
    if (nivel.back() - nivel.front() <= 15 && (int)nivel.size()==porNivel){
      max_niveles++;
      nivel.clear();
    }
  }
  
  cout << max_niveles << "\n";
}

int main(){
  int t; cin >> t;
  while (t--) solve();
  return 0;
}