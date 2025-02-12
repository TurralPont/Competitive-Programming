#include <iostream>
#include <vector>
#include <queue>
#include <vector>

using namespace std;

vector<string> teclado;
vector<vector<char> > Grafo;
vector<vector<bool> > visited;

int get(int i, int j){
  if (i<0){
    i = teclado.size()-1;
  } else if (i>=teclado.size()){
    i = 0;
  } else if (j<0){
    j = teclado[0].size()-1;
  } else if (j>=teclado[0].size()){
    j=0;
  }
  return teclado[i][j];
}

int BFS(char start, char end){
  vector<int> distance('Z'-'.'+1, -1);
  queue<char> adyacentes;
  adyacentes.push(start);
  distance[start-'.'] = 0;

  while(!adyacentes.empty()){
    int v = adyacentes.front(); adyacentes.pop();
    for (int i=0; i<Grafo[v-'.'].size();i++){
      char w = Grafo[v-'.'][i];
      if (distance[w-'.']==-1){
        distance[w-'.'] = distance[v-'.']+1;
        adyacentes.push(w);
      }
      if (w == end) return distance[w-'.'];
    }
  }

  return -1;
}

void hacerGrafo(int i, int j){
  int letra = teclado[i][j];
  visited[i][j] = true;
  Grafo[letra-'.'].push_back(get(i-1,j));
  Grafo[letra-'.'].push_back(get(i, j-1));
  int k=i+1;
  bool notValid=true;

  while(get(k,j)==letra){
    if (k>teclado.size()){
      notValid=false;
      break;;
    }
    k++;
  }

  if (notValid) Grafo[letra-'.'].push_back(get(k, j));
  k=j+1;
  notValid=true;
  while(get(i,k)==letra){
    if (k>teclado[0].size()){
      notValid=false;
      break;;
    }
    k++;
  }
  if (notValid) Grafo[letra-'.'].push_back(get(i, k));
}

bool solve(){
  int F, C, T;
  cin >> F >> C >> T;
  if (F==0) return false;
  teclado.assign(F, "");
  visited.assign(F, vector<bool>(C, false));
  Grafo.assign('Z'-'.'+1, vector<char>());

  for (int i=0; i<F; i++){
    cin >> teclado[i];
  }

  for (int i = 0; i<teclado.size(); i++){
    for (int j=0; j<teclado[0].size(); j++){
      if (Grafo[teclado[i][j]-'.'].empty()){
        hacerGrafo(i, j);
      }
    }
  }
  
  while(T--){
    string word; cin >> word;
    char prev=teclado[0][0];
    int min_dist=0;

    for (int i=0; i<(int)word.size(); i++){
      min_dist+= BFS(prev, word[i]);
      prev=word[i];
    }

    cout << min_dist << "\n";
  }

  cout << "---\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  while(solve());
  return 0;
}