#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve(){
    int N; cin >> N;
    vector<int> art(N), ben(N);
    for (int & x : art) cin >> x;
    for (int & x : ben) cin >> x;
    
    sort(art.begin(), art.end());
    sort(ben.begin(), ben.end());
    
    int i=0, j=0;
    while(i < N && j < N){
        if (art[i] > ben[j]) {
            i++; j++;
        } else {
            ++i;
        }
    }
    
    cout << j << '\n';
}
 
int main() {
    int T; cin >> T;
    while(T--) solve();
    return 0;
}