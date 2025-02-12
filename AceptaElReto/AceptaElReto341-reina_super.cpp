#include <iostream>
#include <queue>

using namespace std;

struct Caja {
  int numero, tiempo;

  Caja(int n, int t) : numero(n), tiempo(t) {}
};

bool operator<(Caja a, Caja b){
  if (b.tiempo < a.tiempo) return true;
  else if (b.tiempo == a.tiempo){
    return (b.numero < a.numero);
  } else {
    return false;
  }
}

bool solve(){
  int N, C; cin >> N >> C;

  if (!cin) return false;

  priority_queue<Caja> cajas;
  for (int i=1; i<=N; ++i){
    cajas.push(Caja(i, 0));
  }

  for (int i=0; i<C; i++){
    int tiempoActual; cin >> tiempoActual;
    Caja abierta = cajas.top(); cajas.pop();
    abierta.tiempo += tiempoActual;
    cajas.push(abierta);
  }

  cout << cajas.top().numero << '\n';
  return true;
}

int main(){
  while(solve());
  return 0;
}