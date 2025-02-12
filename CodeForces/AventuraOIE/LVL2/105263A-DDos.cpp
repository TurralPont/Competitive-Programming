#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long
#define pl pair<ll,ll>

ll IpToInt(ll x, ll y, ll z, ll w){
  ll total = x + (y<<8) + (z<<16) + (w<<24);
  return total;
}

void solve(){
  int Q; cin >> Q;
  ll minTime, maxBytes, maxAccepted;

  unordered_map<ll, vector<pl> > IPS;
  for (int i=0; i<Q; ++i){
    int T; cin >> T;
    if (T==2){
      cin >> maxAccepted >> maxBytes >> minTime;
      continue;
    }

    int x,y,z,w; char p;
    cin >> x >> p >> y >> p >> z >> p >> w;

    ll IP = IpToInt(x,y,z,w);
    ll currTime, bytes; cin >> currTime >> bytes;
    if (!IPS.count(IP)){
      cout << "ac\n";
      IPS[IP] = vector<pl>(1, pl(currTime, bytes));
      continue;
    }
    ll objTime = currTime - minTime + 1;

    vector<pl> & enviosAC = IPS[IP];

    ll deMomento = enviosAC.back().second;
    
   if (enviosAC.back().first < objTime){
    cout << "ac\n";
    enviosAC.push_back(pl(currTime, bytes+deMomento));
    continue;
   }

    int l=0, r = enviosAC.size(), mid;
    while(r > l){
      mid = (l+r) / 2;
      if (objTime < enviosAC[mid].first){
        r = mid-1;
      } else if (objTime > enviosAC[mid].first) {
        l = mid+1;
      } else {
        break;
      }
    }
    mid = (enviosAC[l].first < objTime ? l+1 : l);

    if (enviosAC.size() - mid >= maxAccepted){
      cout << "ig\n";
      continue;
    }

   
    if (deMomento - (mid > 0 ? enviosAC[mid-1].second : 0) >= maxBytes){
      cout << "ig\n";
      continue;
    }

    cout << "ac\n";
    enviosAC.push_back(pl(currTime, bytes+deMomento));
  }

  cout << "--\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  while(T--) solve();
}