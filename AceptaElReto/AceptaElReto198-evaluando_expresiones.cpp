#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool solve(){
  string op;
  getline(cin, op);
  if (!cin) return false;
  stack<long long> numsSt;
  queue<long long> numsQu;
  bool nStErr=false, nQuErr=false;
  for (int i=0; i<op.size(); i++){
    char ch = op[i];
    if (ch >= '0' && ch <= '9'){
      numsSt.push(ch-'0');
      numsQu.push(ch-'0');
    } else { 
      long long nq2=0, nq1=0, ns1=0, ns2 = 0;
      if (numsQu.size()>=2){
        nq2 = numsQu.front(); numsQu.pop();
        nq1 = numsQu.front(); numsQu.pop();
      } else {
        nQuErr=true;
      }
      if (numsSt.size()>=2){
        ns2 = numsSt.top(); numsSt.pop();
        ns1 = numsSt.top(); numsSt.pop();
      } else {
        nStErr=true;
      }

      switch (ch)
      {
      case '+':
        numsQu.push(nq1+nq2);
        numsSt.push(ns1+ns2);
        break;
      case '-':
        numsQu.push(nq1-nq2);
        numsSt.push(ns1-ns2);
        break;
      case '*':
        numsQu.push(nq1*nq2);
        numsSt.push(ns1*ns2);
        break;
      case '/':
        if (nq2!=0) numsQu.push(nq1/nq2); else nQuErr = true;
        if (ns2!=0) numsSt.push(ns1/ns2); else nStErr = true;
        break;
      default:
        break;
      }
    }
  }

  if (numsSt.size() == 0) nStErr = true;
  if (numsQu.size() == 0) nQuErr = true;

  if (nStErr&&nQuErr) cout << "ERROR = ERROR\n";
  else {
    if (nStErr) cout << "ERROR";  else  cout << numsSt.top();
    cout << (numsSt.top()==numsQu.front() ? " = " : " != " );
    if (nQuErr) cout << "ERROR";  else  cout << numsQu.front();

    cout << "\n";
  }
  return true;
}

int main(){
  while(solve());
  return 0;
}