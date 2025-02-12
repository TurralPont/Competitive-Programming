#include <iostream>
#include <queue>

using namespace std;

struct User
{
  int hora, id, periodo;
};

bool operator>(User a, User b){
  if (a.hora > b.hora) return true;
  else if (a.hora==b.hora) {
    if (a.id > b.id) return true;
    else return false;
  } else {
    return false;
  }
}

bool solve(){
  int n; cin >> n;
  if (n==0) return false;
  priority_queue<User, vector<User>, greater<User> > usuarios;
  for (int i = 0; i<n; i++){
    int acId, acPeriodo;
    cin >> acId >> acPeriodo;
    User u = {acPeriodo,acId,acPeriodo};
    usuarios.push(u);
  }
  int k; cin >> k;
  for (int i = 0; i<k; i++){
    User myUs = usuarios.top(); usuarios.pop();
    cout << myUs.id << '\n';
    myUs.hora += myUs.periodo;
    usuarios.push(myUs);
  }

  cout << "---\n";
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while(solve());
  return 0;
}