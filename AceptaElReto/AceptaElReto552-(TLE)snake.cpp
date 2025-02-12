#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool> > serpiente;
queue<pair<int,int> > eliminar;
bool eliminado;
int timotj;

void prnt(){
  for (int i=0; i<21;i++){
    for (int j=0; j<21; j++){
      cout << (int)serpiente[i][j];
    }
    cout <<'\n';
  }
  cout << "----------\n";
}

pair<int,int> direction(char d){
  switch (d)
  {
  case 'U':
    return pair<int,int>(-1,0);
  case 'R':
    return pair<int,int>(0,1);
  case 'D':
    return pair<int,int>(1,0);
  case 'L':
    return pair<int,int>(0,-1);
  default:
    return pair<int,int>(0,0);
    break;
  }
}

pair<int,int> pasar(int i, int j, int t, char d){
  pair<int,int> mod = direction(d);
  while (t--){
    timotj++;
    i += mod.first;
    j += mod.second;
    eliminar.push(make_pair(i,j));
    if (timotj%10) {
      serpiente[eliminar.front().first][eliminar.front().second] = false;
      eliminar.pop();
    }
    if (i<0 || j<0 || i>=21 || j>= 21) {
      eliminado= true;
      return make_pair(0,0);
    } else if (serpiente[i][j]) {
      eliminado= true;
      return make_pair(0,0);
    }
    serpiente[i][j] = true;
  }
  return pair<int,int>(i,j);
}

bool solve(){
  int K; cin >> K;
  if (K==0) return false;
  timotj=0;
  eliminado = false;
  serpiente.assign(21, vector<bool>(21, false));
  while(!eliminar.empty()) eliminar.pop();

  for (int i=9; i>=0;i--){
    serpiente[10+i][10] = true;
    eliminar.push(pair<int,int>(10+i,10));
  }

  pair<int,int> pos(10,10);
  char ld = 'U';
  for (int i=0; i<K; i++){
    int t;
    char d;
    cin >> t >> d;
    int past = t-timotj;
    pos = pasar(pos.first,pos.second,past,ld);

    ld = d;
    if (eliminado){
      cout << timotj << '\n';
      return true;
    }
  }

  pasar(pos.first,pos.second,22,ld);
  cout << timotj-1 << '\n';

  return true;
}

int main(){
  while(solve());
  return 0;
}