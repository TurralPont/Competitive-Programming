#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > memoriaFS; // first - second

int maxSubsequence(string & one, string & two, int first, int second){
  int & res = memoriaFS[first][second];

  if (first >= one.size() || second >= two.size()){
    return 0;
  } else if (res != -1){
    return res;
  } else if (one[first] == two[second]){
    return res = 1 + maxSubsequence(one, two, first+1, second+1);
  } else {
    return res = max(maxSubsequence(one, two, first+1, second), maxSubsequence(one, two, first, second+1));
  }
}

bool solve(){
  string one, two; cin >> one >> two;
  if (!cin) return false;

  memoriaFS.assign(one.size(), vector<int>(two.size(), -1));

  cout << maxSubsequence(one, two, 0, 0) << '\n';
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}