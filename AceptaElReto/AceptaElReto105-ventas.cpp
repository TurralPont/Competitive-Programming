#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string dias[6] = {"MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};

bool solve(){
  double martes; cin >> martes;
  if (martes == -1) return false;
  double min = martes, max = martes, sum = martes;
  int maxDia=0, minDia = 0;
  bool empateMax = false, empateMin = false;
  double domingo;

  for (int i=0; i<5; ++i){
    double dia; cin >> dia;
    sum += dia;
    if (dia > max){
      max = dia;
      empateMax = false;
      maxDia = i+1;
    } else if (dia == max){
      empateMax = true;
    } else if (dia < min){
      min = dia;
      minDia = i+1;
      empateMin = false;
    } else if (dia == min){
      empateMin = true;
    }
    if (i==4) domingo = dia;
  }
  
  cout << (empateMax ? "EMPATE" : dias[maxDia]) << ' ' 
       << (empateMin ? "EMPATE" : dias[minDia]) 
       << (domingo > sum/6 ? " SI\n":" NO\n");

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}