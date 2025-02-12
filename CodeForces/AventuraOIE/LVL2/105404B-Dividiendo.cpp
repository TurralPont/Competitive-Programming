#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
  int N; cin >> N;
  vector<int> nums(N);
  for (int & x : nums) cin >> x;
  sort(nums.begin(), nums.end());

  int divisor = nums[0];
  if (divisor == 1){
    cout << "SI\n";
    return;
  }
  
  for (int i=1; i<N; ++i){
    if (nums[i] % divisor != 0){
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
}