#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
  int N; cin >> N;
  vector<int> nums(N);
  for (int & x : nums) cin >> x;

  sort(nums.begin(), nums.end());

  int estandar = nums[0] + nums[N-1];
  for (int i=1; i<(N/2); ++i){
    if (nums[i] + nums[N-i-1] != estandar){
      cout << "NO\n";
      return;
    }
  }

  cout << "SI\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
  return 0;
}