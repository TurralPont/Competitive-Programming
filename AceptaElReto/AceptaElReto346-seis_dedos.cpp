#include <iostream>
#include <queue>

using namespace std;

bool solve(){
  int N, T;
  cin >> N >> T;
  if (N==0) return false;

  queue<int> personas;
  int actual_tam = 0, max_tam=0;
  for (int i=0; i<N; ++i){
    int ano; cin >> ano;
    actual_tam++;
    personas.push(ano);
    while(personas.front() <= ano-T) {
      personas.pop();
      actual_tam--;
    }
    max_tam = max(max_tam, actual_tam);
  }

  cout << max_tam << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}