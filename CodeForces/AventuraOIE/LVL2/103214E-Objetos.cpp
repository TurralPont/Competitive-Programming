#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

const ll int INF = 3 * 1e18;

ll getRank(int pos, int a, vector<ll> & multPesos, vector<ll> & sumPesos){
  ll actual = 0;

  actual += a * ( 2 * (pos == 0 ? 0 : sumPesos[pos-1]) - sumPesos.back());
  actual += (multPesos.back() - 2 * (pos == 0 ? 0 : multPesos[pos-1]));

  return actual;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  vector<ll> positions(N), pesos(N);

  for (ll & x : positions) cin >> x;
  for (ll & x : pesos) cin >> x;

  vector<ll> sumaPesos(N); sumaPesos[0] = pesos[0];
  for (int i=1; i<N; i++){
    sumaPesos[i] = pesos[i] + sumaPesos[i-1];
  }

  vector<ll> multpPesos(N); multpPesos[0] = pesos[0]*positions[0];
  for (int i=1; i<N; i++){
    multpPesos[i] = pesos[i]*positions[i] + multpPesos[i-1];
  }

  ll minimo = INF; int minPos;
  for (int i=0; i<N; i++){
    ll actual = getRank(i, positions[i], multpPesos, sumaPesos);
    if (actual < minimo){
      minimo = actual;
      minPos = i;
    }
  }

  cout << minPos << '\n';
  return 0;
}