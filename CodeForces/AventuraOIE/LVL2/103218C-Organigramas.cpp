#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define vi vector<int>
#define vii vector<vi>

void printSet(set<int> a){
  for (set<int>::iterator it = a.begin(); it != a.end(); ++it){
    cout << ' ' << *it;
  }
  cout << '\n';
}

set<int> intersection(set<int> & a, set<int> & b){
  if (a.size() > b.size()) swap(a,b);

  set<int> res;

  for (set<int>::iterator it = a.begin(); it != a.end(); ++it){
    if (b.count(*it)){
      res.insert((*it) * 2); res.insert((*it) * 2 + 1);
    }
  }

  return res;
}

set<int> sumOne(set<int> & st){
  set<int> res;
  for (set<int>::iterator it = st.begin(); it != st.end(); ++it){
    res.insert(*it); res.insert(*it + 1);
  }
  return res;
} 

set<int> func(int i, vii & h, vector<set<int> > & dp){
  if (!dp[i].empty()) return dp[i];

  if (h[i].empty()){
    set<int> r; r.insert(1); r.insert(0);
    return dp[i] = r;
  } else if (h[i].size() == 1){
    set<int> hijo = func(h[i][0], h, dp);
    return dp[i] = sumOne(hijo);
  } else {
    set<int> izq = func(h[i][0], h, dp), dcha = func(h[i][1], h, dp);

    return dp[i] = intersection(izq, dcha);
  }
}

void solve(){
  int N; cin >> N;
  vector<vector<int> > hijos(N, vector<int>());
  vector<set<int> > posibles(N);

  for (int i=1; i<N; ++i){
    int p, h; cin >> p >> h;
    hijos[p].push_back(h);
  }

  cout << *func(0, hijos, posibles).rbegin() << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
}