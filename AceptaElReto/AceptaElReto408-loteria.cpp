#include <iostream>
// NO
using namespace std;

int solve(){
  int N, d, s, m;
  cin >> N >> d >> s >> m;

  int dias=1, semanas=0, meses=0;
  int sacadoDias=1, sacadoSemanas=0;
  int total = d;

  while(total < N){
    ++dias;
    if (sacadoDias++ == 3){
        sacadoDias=0;
        total+= d-1;
      }
    if (dias==8) {
      dias=1; semanas++;
      if (sacadoSemanas == 3){
        sacadoDias=0;
        total+= s-1;
      }
      if (semanas==5){
        meses++;
        total+=m;
        semanas = 1;
      }
    }
  }

  cout << meses << ' ' << semanas << ' ' << dias << '\n';
}

int main(){
  int T; cin >> T;
  while(T--) solve();
  return 0;
}