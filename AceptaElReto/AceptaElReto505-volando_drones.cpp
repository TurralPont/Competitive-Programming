#include <iostream> 
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool solve(){
  int drones, pilas9, pilas15;
  scanf("%d", &drones);
  scanf("%d", &pilas9);
  cin >> pilas15;
  if (!cin) return false;
  priority_queue<int> pilasGrandes;
  priority_queue<int> pilasChicas;
  while(pilas9--){
    int n;
    scanf("%d", &n);
    pilasGrandes.push(n);
  }
  while(pilas15--){
    int n;
    cin >> n;
    pilasChicas.push(n);
  }
  while(true){
    vector<int> a, b;
    for (int i = 0; i<drones && !pilasGrandes.empty() && !pilasChicas.empty();i++){
        a.push_back(pilasGrandes.top());
        b.push_back(pilasChicas.top());
        pilasGrandes.pop(); pilasChicas.pop();
      }
    
    int horasTotales=0;
    while (!a.empty()){
      int gr = a.back();
      int sm = b.back();
      int mn = min(gr,sm);

      horasTotales+=mn;
      a.pop_back();
      b.pop_back();
      if (gr!=sm){
        (gr > sm)? pilasGrandes.push(gr-sm) : pilasChicas.push(sm-gr);
      }
    }
    printf("%d", horasTotales);
    if (pilasGrandes.empty() || pilasChicas.empty()){
      break;
    } else {
      printf(" ");
    }
  }
  printf("\n");
  return true;
}

int main(){
  while(solve());
  return 0;
}