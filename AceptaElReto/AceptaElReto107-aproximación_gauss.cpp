#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> prime(1e5+3, true);
vector<int> piFunc(1e5+3);

void computePrimes(){ // criba de eratóstenes
  for (int i=3; i<1e5+3; i+=2){
    if (!prime[i]) continue;
    for (int j=i+i; j<1e5+3; j+=i){
      prime[j] = false;
    }
  }
  int pi = 1;
  for (int i=3; i<=1e5+3; i+=2){ // calculamos π(i)
    if (prime[i]) pi++;
    piFunc[i] = pi;
    piFunc[i+1] = pi;
  }
  piFunc[2] = 1;
}

bool solve(){
  int n, m; cin >> n >> m;
  if (n==0) return false;

  double dif = 1 / pow(10, m);
  double pi = piFunc[n];
  double error = abs(pi / n - 1 / log1p(n-1));

  cout << (error > dif ? "Mayor\n" : (error == dif ? "Igual\n" : "Menor\n"));
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  piFunc[1] = 0;
  piFunc[2] = 1;
  computePrimes();
  while(solve());
  return 0;
}