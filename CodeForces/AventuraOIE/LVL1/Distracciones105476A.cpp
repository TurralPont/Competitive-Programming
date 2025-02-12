#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;

  vector<int> prev(1, 1);
  vector<int> actual;

  for (int i=0; i<N; ++i){
    int prevNum= prev[0];
    int actualSeries=1;
    for (int j=1; j<prev.size(); ++j){
      if (prevNum == prev[j]){
        actualSeries++;
      } else {
        actual.push_back(actualSeries); actual.push_back(prevNum);
        actualSeries = 1;
        prevNum = prev[j];
      }
    }

    actual.push_back(actualSeries); actual.push_back(prevNum);
    prev = actual; actual.clear();
  }
  
  for (int n : prev){
    cout << n;
  }
  cout << '\n';
  return 0;
}