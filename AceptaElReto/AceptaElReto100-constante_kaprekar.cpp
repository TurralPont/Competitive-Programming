#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

// muy antiguo (esta pocho)

#define vi vector<int>

using namespace std;

vi getDigits(int x)
{
  vi digits;
  while (x > 0)
  {
    digits.push_back(x % 10);
    x /= 10;
  }
  while (digits.size() < 4)
  {
    digits.push_back(0);
  }
  return digits;
}

int joinDigits(vi x)
{
  int res = 0;
  for (int i = 0; i < x.size(); i++)
  {
    res += x[i] * pow(10, i);
  }
  return res;
}

bool isGreater(int x, int y)
{
  return x > y;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if (n == 6174) // la constante en si misma
    {
      cout << 0 << endl;
    }
    else if(n%1111==0){
      cout << 8 << endl;
    }
    else
    {
      int reps=0;
      while (n != 6174)
      {
        int aux = n;
        priority_queue<int> digits;
        for (int i = 0; i<4;i++){
          if (aux>0){
            digits.push(aux%10);
            aux/=10;
          } else {
            digits.push(0);
          }
        }
        int asc=0, desc=0;
        for (int i = 0; i < 4; i++){
          asc += digits.top() * pow(10, 3-i);
          desc += digits.top() * pow(10, i);
          digits.pop();
        }
        n = asc-desc;
        reps++;
      }
      cout << reps << endl;
    }
  }
}