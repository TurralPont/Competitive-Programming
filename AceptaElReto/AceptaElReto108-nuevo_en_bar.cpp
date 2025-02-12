#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int getIndex(char categoria){
  switch (categoria)
  {
  case 'D':
    return 0;
  case 'A':
    return 1;
  case 'M':
    return 2;
  case 'I':
    return 3;
  case 'C':
    return 4;
  default:
    return -1;
  }
}

string getName(int categoria){
  switch (categoria)
  {
  case 0:
    return "DESAYUNOS";
  case 1:
    return "COMIDAS";
  case 2:
    return "MERIENDAS";
  case 3:
    return "CENAS";
  case 4:
    return "COPAS";
  case 5:
    return "EMPATE";
  default:
    return "ERROR";
  }
}

bool solve(){
  vector<double> ganancias(5,0);

  char apartado; double dinero;
  cin >> apartado >> dinero;
  if (!cin) return false;
  int clientes=0, comidas=0;
  while(apartado != 'N'){
    clientes++;
    if (apartado=='A') comidas++;

    ganancias[getIndex(apartado)] += dinero;

    cin >> apartado >> dinero;
  }

  double minBenef=1e9, maxBenef=-1;
  int minChar, maxChar;

  double mediaDia=0;

  for (int i=0; i<5; ++i){
    double gans = ganancias[i];
    mediaDia += gans;

    if (minBenef > gans){
      minBenef = gans;
      minChar = i;
    } else if (minBenef == gans){
      minChar = 5;
    }

    if (maxBenef < gans){
      maxBenef = gans;
      maxChar = i;
    } else if (maxBenef == gans){
      maxChar = 5;
    }
  }

  mediaDia /= clientes;
  double mediaComida = ganancias[1] / comidas;

  cout << getName(maxChar) << '#' << getName(minChar) << '#' << (mediaComida > mediaDia ? "SI\n" : "NO\n");
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}