#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Semaforo
{
  int distancia;
  int cerrado;
  int abierto;
};


bool solve(){
  int lenSemaforos, maxSpeed;
  cin >> lenSemaforos >> maxSpeed;
  if (lenSemaforos==0 && maxSpeed==0) return false;
  vector<Semaforo> semaforos;
  while(lenSemaforos--){
    int d, c, a;
    cin >> d >> c >> a;
    d += (!semaforos.empty() ? semaforos.back().distancia : 0);
    Semaforo S;
    S.abierto=a;
    S.distancia=d;
    S.cerrado=c;
    semaforos.push_back(S);
  }
  priority_queue<int, vector<int>, greater<int> > velocidades;

  for (int i=0; i<semaforos.size();i++){
    for (int j = 0; j < velocidades.size(); j++){

    }
  }

  return true;
}

int main(){
  while(solve());
  return 0;
}