#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int,int>
#define ppi pair<int, pii>

vector<vector<int> > Alturas;
vector<vector<bool> > visited;


const int modF[4] = {-1, 0, 1, 0};
const int modC[4] = {0, 1, 0, -1};

int minimun=0;
int C, F;

bool notValid(int f, int c){
  return (f<0 || c<0 || f>=F || c>=C);
}

int DFS(int f, int c){
  if (visited[f][c]) return 0;
  visited[f][c]=true;
  int tam = 1;
  for (int i=0; i<4;i++){
    int nf = f+modF[i], nc = c+modC[i];
    if (notValid(nf, nc)) continue;
    if (Alturas[nf][nc]<=minimun){
      tam += DFS(nf, nc);
    }
  }
  return tam;
}

bool solve(){
  cin >> C >> F;
  if (!cin) return false;

  Alturas.assign(F, vector<int>(C));
  visited.assign(F, vector<bool>(C, false));

  minimun=0;
  int maxi=0;
  for (int i=0; i<F;i++){
    for (int j = 0; j < C; j++)
    {
      int n; cin >>n;
      Alturas[i][j]=n;
      maxi = max(n, maxi);
    }
  }

  int t=0;
  int low = 0, top = maxi;
  int mid;
  while(low<=top){
    mid = (low+top)/2;
    minimun= mid;
    visited.assign(F, vector<bool>(C, false));
    t = DFS((F-1)/2, 0);
    if (low==top) break;
    if (t>(F*C)/2){
      top = mid;
    } else {
      low = mid+1;
    }
  }
  cout << minimun << ' ' << t << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}