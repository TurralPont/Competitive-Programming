#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int changesI[4] = {-1, 0, 1, 0};
const int changesJ[4] = {0, 1, 0, -1};
bool imposible = false;
vector<string> Jardin;

void marcar(int x, int y, int nivel){
  bool direcs[4] = {false,false,false,false};
  for (int i=1; i<=nivel; i++){
    if (x-i<0) direcs[0]=true;
    if (x+i>=Jardin.size()) direcs[2] = true;
    if (y-i<0) direcs[3]=true;
    if (y+i >=Jardin[0].size()) direcs[1] = true;
    for (int j=0; j<4;j++){
      if (direcs[j]) continue;
      int nx = x + changesI[j]*i;
      int ny = y + changesJ[j]*i;
      if (Jardin[nx][ny]=='.') Jardin[nx][ny]='*';
      else if (Jardin[nx][ny]=='#') direcs[j] = true;
      else if (Jardin[nx][ny]=='E'|| Jardin[nx][ny]=='P'){
        imposible=true;
      }
    }
  }
}


void solve(){
  imposible= false;
  int J, I;
  cin >> J >> I;
  cin.ignore();
  Jardin.assign(I, "");
  for (int i=0;i<I; i++){
    getline(cin, Jardin[i]);
  }
  int inicio=-1;
  bool nohayFinal = true;
  for (int i = 0; i<I; i++){
    for (int j=0; j<J;j++){
      if (Jardin[i][j] >= '0' && Jardin[i][j] <='9'){
        marcar(i,j,Jardin[i][j]-'0');
      } else if (Jardin[i][j] == 'E'){
        inicio = i*J + j;
      } else if (Jardin[i][j]=='P'){
        nohayFinal = false;
      }
    }
  }

  if (inicio == -1 || imposible || nohayFinal) { 
    cout << "NO\n";
    return;
  }

  vector<int> dis(I*J, -1);
  queue<int> adyacentes;
  adyacentes.push(inicio);
  dis[inicio] = 0;

  while (!adyacentes.empty()) {
    int v = adyacentes.front(); adyacentes.pop();
    int i = v / J;
    int j = v % J;
    for (int k=0; k<4;k++){
      int ni = i + changesI[k];
      int nj = j + changesJ[k];
      if (ni >= 0 && nj>=0 && ni<I && nj<J){
        int w = ni*J + nj;
        if (dis[w]!=-1) continue;
        if (Jardin[ni][nj]=='.'){
          adyacentes.push(w);
          dis[w] = dis[v]+1;
        } else if (Jardin[ni][nj]=='P'){
          cout << dis[v]+1 << '\n';
          return;
        }
      }
    }
  }
  
  cout << "NO\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}